#include "list.h"
#include <stdlib.h>
#include <string.h>

struct _list_t 
{
    uint8_t   * base_addr;       /*数据基地址*/
    uint16_t    current_length;  /*已使用数据长度*/   
    uint16_t    list_length;     /*列表容量*/
    uint16_t    elem_size;       /*元素大小*/
};

int  creat_list(list_t * list ,uint16_t size ,uint16_t length)
{
    list=malloc(sizeof(list_t));

    /*分配列表空间*/
    list->base_addr=malloc(size*length);

    if(list->base_addr==NULL)
    {
        return -1;
    }

    list->current_length=0;
    list->list_length=length;
    list->elem_size=size;
    return 1;
}

int destroy_list (list_t *list)
{
    free(list->base_addr);
    list->elem_size=0;
    list->list_length=0;
    list->current_length=0;
    return 1;
}

int insert_list_elem(list_t *list, uint16_t loca, uint16_t num, void * data)
{
    /*非法指针错误*/
    if(list==NULL||data==NULL)
    {
        return -1;
    }

    /*local参数错误*/
    if((loca < 1) || (loca > (list->current_length + 1) ) )
    {
        return -2;
    }

    /*列表容量不足*/
    if((loca + num) >= list->list_length)
    {
        return -3;
    }

    void *  des_add = list->base_addr + (list->elem_size*(loca+num-1) );
    void *  src_add = list->base_addr + (list->elem_size*(loca-1) );

    if(loca <= list->current_length)
    {
        /*插入位置元素后移*/
        uint16_t offsset = (list->current_length - loca + 1)*list->elem_size;
        memmove(des_add, src_add, offsset);
    }

    /*复制数据到插入位置*/
    memcpy(src_add, data, list->elem_size * num);
    list->current_length += num;

    return 1;
}


int  traverse_list(list_t *list, int (*visit)(uint16_t index,void *data))
{
    int i=0;
    for ( i = 1; i <= list->current_length ; i++)
    {
        if(visit(i, list->base_addr+list->elem_size*(i-1)) < 0)
        {
            return -1;
        }
    }
    return 1;
}

int delete_list_elem(list_t *list, uint16_t loca, uint16_t num, void *data)
{
    if(list==NULL)
    {
        return -1;
    }

    if(list->list_length < loca+num)
    {
        return -2;
    }

    if(data != NULL)
    {
        memcpy(data,list->base_addr+(loca - 1)*list->elem_size, num * list->elem_size);
    }

    void *  src_addr = list->base_addr + (list->elem_size*(loca+num-1) );
    void *  des_addr = list->base_addr + (list->elem_size*(loca-1) );
    uint16_t offsset = (list->current_length - loca - num + 1)*list->elem_size;

    memmove(des_addr,src_addr,offsset);
    list->current_length=list->current_length - num;

    return 1;
}

int get_list_length(list_t *list)
{
    if(list==NULL)
    {
        return -1;
    }

    return list->current_length;
}
