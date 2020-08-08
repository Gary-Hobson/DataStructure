/*
 * @Descripttion: 线性表测试文件,连续式和链式通用
 * @version: V1.0
 * @Author: Hobson
 * @Date: 2020-08-08 23:33:23
 * @History: V1.0   V1.0  线性表测试文件
 * @LastEditTime: 2020-08-08 23:59:17
 */
#include "list.h"
#include <stdio.h>

int print_list(uint16_t index, void * data);

int main()
{
    list_t *list;
    int array[16]={1,2,3,4,5,6,7,8,9,10};
    int buff[16];
    int res,data=9;
    char * info[]={"未查找到元素:","查找到元素，index:"};

    res=list_creat(&list,sizeof(int),16);
    printf("list list_creat result :%d\n",res);

    res = list_append(list,5,array);
    list_traverse(list , print_list);

    printf("*****插入元素****\n");
    res = list_insert(list,2,3,array+6);
    list_traverse(list , print_list);

    printf("*****删除元素****\n");
    res = list_delete(list,3,4,buff);
    list_traverse(list , print_list);

    printf("*****读取元素****\n");
    res = list_read(list,2,3,buff);
    printf("%d %d %d\n",buff[0],buff[1],buff[2]);

    printf("*****查找元素****\n");
    res = list_find(list,&data);
    printf("%s%d\n",info[(res>0)?1:0],(res==0)?data:res);
    
    if(res<0)
    {
        printf("errer :%d\n",res);
        return 0;
    }
    
    if(list_length(list)>128)
    {
        list_clear(list);
        printf("*********************************\n");
        printf("list length :%d\n",list_length(list));
    }

    /*释放列表*/
    list_destroy(list);
    printf("list list_destroy success！\n");

    return 1;
}

int print_list(uint16_t index, void * data)
{
    printf("list index %d:%d\n",index,*(int *)data);
    return 1;
}
