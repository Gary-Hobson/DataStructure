#include "list.h"
#include <string.h>

struct _list_t 
{
    void       * base;           /*数据基地址*/
    uint16_t    length;         /*已使用数据长度*/   
    uint16_t    cacapacity;     /*列表容量*/
    uint16_t    size;           /*元素大小*/
};

int  creat(list_t ** list ,uint16_t size ,uint16_t length)
{
    *list=malloc(sizeof(list_t));

    /*分配列表空间*/
    (*list)->base=malloc(size*length);

    if((*list)->base==NULL)
    {
        return -1;
    }

    (*list)->length=0;
    (*list)->cacapacity=length;
    (*list)->size=size;
    return 1;
}

int destroy(list_t *list)
{
    free(list->base);
    free(list);

    return 1;
}

int insert(list_t *list, uint16_t loca, uint16_t num, void * data)
{
    /*非法指针错误*/
    if(list==NULL||data==NULL)
    {
        return -1;
    }

    /*local参数错误*/
    if((loca < 1) || (loca > (list->length + 1) ) )
    {
        return -2;
    }

    /*列表容量不足*/
    if((loca + num) >= list->cacapacity)
    {
        return -3;
    }

    void *  des_add = list->base + (list->size*(loca+num-1) );
    void *  src_add = list->base + (list->size*(loca-1) );

    if(loca <= list->length)
    {
        /*插入位置元素后移*/
        uint16_t offsset = (list->length - loca + 1)*list->size;
        memmove(des_add, src_add, offsset);
    }

    /*复制数据到插入位置*/
    memcpy(src_add, data, list->size * num);
    list->length += num;

    return 1;
}


int  traverse(list_t *list, int (*visit)(uint16_t index,void *data))
{
    int i=0;
    for ( i = 1; i <= list->length ; i++)
    {
        if(visit(i, list->base+list->size*(i-1)) < 0)
        {
            return -1;
        }
    }

    return 1;
}

int pop(list_t *list, uint16_t loca, uint16_t num, void *data)
{
    if(list==NULL)
    {
        return -1;
    }

    if(list->cacapacity < loca+num)
    {
        return -2;
    }

    if(data != NULL)
    {
        memcpy(data,list->base+(loca - 1)*list->size, num * list->size);
    }

    void *  src_addr = list->base + (list->size*(loca+num-1) );
    void *  des_addr = list->base + (list->size*(loca-1) );
    uint16_t offsset = (list->length - loca - num + 1)*list->size;

    memmove(des_addr,src_addr,offsset);
    list->length=list->length - num;

    return 1;
}

int read(list_t *list, uint16_t loca, uint16_t num, void *data)
{
    void *  src_addr = list->base + (list->size*(loca+num-1) );
    void *  des_addr = list->base + (list->size*(loca-1) );
    uint16_t offsset = (list->length - loca - num + 1)*list->size;

    memmove(des_addr,src_addr,offsset);
    list->length=list->length - num;

    return 1;
}

int length(list_t *list)
{
    if(list==NULL)
    {
        return -1;
    }

    return list->length;
}

int find(list_t * list ,void *data)
{
    int index = 0;

    if(list==NULL)
    {
        return -1;
    }

    for (int i = 0; i < list->length; i++)
    {
        int res=-1;
        void * item=list->base+list->size*i;

        res=memcmp(item,data,list->size);
        if(res==0)
        {
            index = i;
            break;
        }
    }
    return index;
}

inline int append(list_t *list, uint16_t num, void *data)
{
    return insert(list,list->length,num,data);
}

int clear(list_t *list)
{
    if(list==NULL)
    {
        return -1;
    }

    list->length=0;
    
    return 1;
}
