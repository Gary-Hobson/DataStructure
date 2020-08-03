#ifndef LINEAR_LIST_H
#define LINEAR_LIST_H

#include <msp.h>



typedef struct _list_t list_t;

int     creat_list(list_t * list ,uint16_t size,uint16_t length);
int     destroy_list (list_t *list);
int     get_list_length(list_t *list);
int     insert_list_elem(list_t *list, uint16_t loca, uint16_t num, void *data);
int     delete_list_elem(list_t *list, uint16_t loca, uint16_t num, void *data);
int     read_list_elem(list_t *list, uint16_t loca, uint16_t num,void *data);
int     find_list_elem(list_t *list, void * data);
int     traverse_list(list_t *list, int (*visit)(uint16_t index,void *data));

#endif
