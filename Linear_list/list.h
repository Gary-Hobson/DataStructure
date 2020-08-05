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
int     creat(list_t ** list ,uint16_t size,uint16_t length);
int     insert(list_t *list, uint16_t loca, uint16_t num, void *data);
int     pop(list_t *list, uint16_t loca, uint16_t num, void *data);
int     read(list_t *list, uint16_t loca, uint16_t num,void *data);
int     find(list_t *list, void * data);
int     traverse(list_t *list, int (*visit)(uint16_t index,void *data));
int     append(list_t *list, uint16_t num, void *data);
int     clear(list_t *list);
int     destroy(list_t *list);
int     length(list_t *list);


#endif
