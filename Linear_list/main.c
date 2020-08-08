#include "list.h"
#include <stdio.h>

int print_list(uint16_t index, void * data);

int main()
{
    list_t *list;
    int res;
    int array[16]={1,2,3,4,5,6,7,8,9,10};
    int buff[16];
    int data=9;
    char * info[]={"查找到元素，index:","未查找到元素"};

    res=creat(&list,sizeof(int),16);
    printf("list creat result :%d\n",res);

    while (1)
    {
        res=1;
        res += append(list,5,array);
        traverse(list , print_list);

        printf("*****插入元素****\n");
        res *= insert(list,2,3,array+6);
        traverse(list , print_list);

        printf("*****删除元素****\n");
        res *= pop(list,3,4,buff);
        traverse(list , print_list);

        printf("*****读取元素****\n");
        res *= read(list,2,3,buff);
        printf("%d %d %d\n",buff[0],buff[1],buff[2]);

        printf("*****查找元素****\n");
        res *= find(list,&data);
        printf("%s%d\n",info[res%1],(res==0)?data:res);
        
        if(res<0)
        {
            printf("errer :%d\n",res);
            return 0;
        }
        
        if(length(list)>128)
        {
            clear(list);
            printf("*********************************\n");
            printf("list length :%d\n",length(list));
        }
    }
    
    

    /*释放列表*/
    destroy(list);
    printf("list destroy success！\n");

    return 1;
}

int print_list(uint16_t index, void * data)
{
    printf("list index %d:%d\n",index,*(int *)data);
    return 1;
}
