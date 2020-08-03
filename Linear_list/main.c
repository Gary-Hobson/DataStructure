#include "list.h"
#include <stdio.h>

int print_list(uint16_t index, void * data);

int main()
{
    list_t list;
    int res;
    int array[16]={1,2,3,4,5,6,7,8,9,10};


    res=creat_list(list,sizeof(int),16);
    printf("list creat result :%d\n",res);

    insert_list_elem(list,1,5,array);
    traverse_list(list , print_list);

    printf("*****插入元素****\n");
    insert_list_elem(list,2,3,array+6);
    traverse_list(list , print_list);

    printf("*****删除元素****\n");
    delete_list_elem(list,4,3,NULL);
    traverse_list(list , print_list);
    
    destroy_list(list);

    return 1;
}

int print_list(uint16_t index, void * data)
{
    printf("list index %d:%d\n",index,*(int *)data);
    return 1;
}
