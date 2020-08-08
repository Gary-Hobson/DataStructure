#include "list.h"
#include <string.h>

typedef struct  _link_node_t node_t;

struct _list_t 
{
    node_t      * next;           /*数据基地址*/
    uint16_t    length;         /*已使用数据长度*/
    uint16_t    size;           /*元素大小*/
};

typedef struct  _link_node_t
{
    node_t * next;
    void * data;
}node_t;


/*偏置链表到指定位置*/
static node_t * jump_offset(list_t *list, uint16_t loca)
{
    node_t *current=(node_t *)list;
    uint16_t offset=0;

    /*查找待插入节点位置*/
    while ((current != NULL) && offset < (loca - 1))
    {
        current=current->next;
        offset++;
    }
    
    if((current == NULL) && (offset < loca-1))
    {
        return NULL;      /*插入位置错误*/
    }

    return current;
}

int  creat(list_t ** list ,uint16_t size ,uint16_t length)
{
    *list=malloc(sizeof(list_t));

    (*list)->next=NULL;
    (*list)->length=0;
    (*list)->size=size;
    return 1;
}

int insert(list_t *list, uint16_t loca, uint16_t num, void *data)
{
    node_t *current=(node_t *)list;
    uint16_t offset=0;

    /*查找待插入节点位置*/
    while ((current != NULL) && offset < (loca - 1))
    {
        current=current->next;
        offset++;
    }
    
    if((current == NULL) && (offset < loca-1))
    {
        return -3;      /*插入位置错误*/
    }

    for (int i = 0; i < num; i++)
    {
        /*插入一个节点*/
        node_t *new_node_t=malloc(sizeof(node_t *)+sizeof(list->size));

        new_node_t->next=current->next;
        memcpy((void *)(new_node_t) + sizeof(node_t *), data+i*list->size, list->size);
        current->next=new_node_t;

        current=new_node_t;               /*切换到下一节点*/
        list->length++;
    }

    return 1;
}

inline int append(list_t *list, uint16_t num, void *data)
{
    return insert(list, list->length+1,num,data);
}

int traverse(list_t *list, int (*visit)(uint16_t index,void *data))
{
    node_t * current=list->next;

    for (int i = 0; i < list->length; i++)
    {
        if(visit(i+1, (void *)current + sizeof(node_t *)) < 0)
        {
            return -1;
        }
        current = current->next;
    }
    
    return 1;
}

int pop(list_t *list, uint16_t loca, uint16_t num, void *data)
{
    /*偏置到待删除节点*/
    node_t *current = jump_offset(list,loca);

    if(loca+num -1> list->length)
    {
        return -2;
    }

    /*非法位置*/
    if(current==NULL)
    {
        return -3;
    }

    /*逐个删除链表节点*/
    for (int i = 0; i < num; i++)
    {
        node_t *delete_item = current->next;

        if(data != NULL )
        {
            memcpy(data + list->size*i , (void *)delete_item + sizeof(node_t *), list->size);
        }

        /*指向下一个节点,并释放内存*/
        current->next = delete_item->next;
        free(delete_item);
        list->length--;
    }
    
    return 1;
}

int read(list_t *list, uint16_t loca, uint16_t num,void *data)
{
    /*偏置到待读取节点*/
    node_t *current = jump_offset(list,loca+1);

    /*非法位置*/
    if(current==NULL)
    {
        return -3;
    }

    for (int i = 0; i < num; i++)
    {
        if(data != NULL )
        {
            memcpy(data + list->size*i , (void *)current + sizeof(node_t *), list->size);
        }

        /*指向下一个节点`*/
        current = current->next;  
    }
    
    return 1;
}

int clear(list_t *list)
{
    node_t * current=list->next;
    node_t * next ;
    while(current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
        list->length--;
    }
    list->next=NULL;
    
    return 1;
}

int destroy(list_t *list)
{
    clear(list);
    free(list);

    return 1;
}

int length(list_t *list)
{
    return list->length;
}

int find(list_t * list, void *data)
{
    node_t *current=list->next;
    for (int i = 0; i < list->length ; i++)
    {
        if(memcmp( (void *)current + sizeof(node_t *), data,list->size) == 0)
        {
            return i+1;
        }
        current = current->next;
    }

    return 0;
}

