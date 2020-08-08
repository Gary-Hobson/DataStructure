#ifndef LINEAR_LIST_H
#define LINEAR_LIST_H

#include <msp.h>

typedef struct _list_t list_t;

/*
  @描述: 创建链表
  @参数1: list:链表指针
  @参数2: size:链表大小
  @参数3: length:链表长度
*/
int     list_creat(list_t ** list ,uint16_t size,uint16_t length);
int     list_insert(list_t *list, uint16_t loca, uint16_t num, void *data);
int     list_delete(list_t *list, uint16_t loca, uint16_t num, void *data);
int     list_read(list_t *list, uint16_t loca, uint16_t num,void *data);
int     list_find(list_t *list, void * data);
int     list_traverse(list_t *list, int (*visit)(uint16_t index,void *data));
int     list_append(list_t *list, uint16_t num, void *data);
int     list_clear(list_t *list);
int     list_destroy(list_t *list);
int     list_length(list_t *list);


#endif
