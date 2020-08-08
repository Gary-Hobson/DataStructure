#include <list.h>
#include <stdio.h>
#include <string.h>

int visit(uint16_t index,void *data);
int str_to_list(char *str,list_t ** list );
int list_to_str(char *str, list_t * list);
int list_addition(list_t *addend, list_t * augend,list_t **sum);

list_t *addend=NULL, *augend=NULL, *sum=NULL;
char buff[128];

int main()
{
    printf("请输入加数:");
    scanf("%s",buff);
    fflush(stdin);
    printf("加数为:%s\n",buff);
    str_to_list(buff,&addend);
    
    printf("请输入被加数:");
    fflush(stdin);
    scanf("%s",buff);
    fflush(stdin);
    printf("被加数为:%s\n",buff);
    str_to_list(buff,&augend);

    /*计算两个数字链表的加法，结果保存在新链表sum中*/
    list_addition(addend,augend,&sum);
    list_to_str(buff,sum);
    printf("两数相加为：%s\n",buff);
}

/* 
  **  数字字符串转为倒序链表，
  **  例如字符串"1234"转换为4 -> 3 -> 2 -> 1 
  **  即个位在链表头部
*/
int str_to_list(char * str, list_t ** list)
{
    list_creat(list,sizeof(uint16_t),0);
    
    uint16_t ch, len=strlen(str);
    char * num=str+len-1;

    for (int i =len; i>0; i--)
    {
        ch=(uint16_t)(*num-'0');
        list_append(*list,1,&ch);
        num--;
    }
    
    printf("\n");
    return 1;
}


/*
  **打印链表节点元素的遍历函数，调试用
*/
int visit(uint16_t index,void *data)
{
    printf("%d",*(uint16_t *)data);
    fflush(stdout);
    return 1;
}

/*
  **计算两个链表的和，计算    
*/
int list_addition(list_t *addend, list_t * augend,list_t **sum)
{
    uint16_t num1,num2,carry,temp;

    /*初始化结果链表*/
    list_creat(sum,sizeof(uint16_t),0);

    /*先将相同位数的数字相加*/
    while ((list_length(addend)!=0)&&(list_length(augend)!=0))
    {
        list_delete(addend,1,1,&num1);
        list_delete(augend,1,1,&num2);
        temp=(num1+num2+carry)%10;
        carry=(num1+num2+carry)/10;
        list_append(*sum,1,&temp);
    }

    list_t *current=(list_length(addend)!=0)?addend:augend;

    /*计算剩余长度数据*/
    while(list_length(current)!=0)
    {
        list_delete(current,1,1,&num1);
        temp=(num1+carry)%10;
        carry=(num1+carry)/10;
        list_append(*sum,1,&temp);
    }

    if(carry>0)
    {
        list_append(*sum,1,&carry);
    }

    return 1;
}

/*将倒序的链表转换为顺序的字符串*/
int list_to_str(char *str, list_t * list)
{
    uint16_t len= list_length(list);
    uint16_t ch;
    for (size_t i = 0; i < len ; i++)
    {
        list_read(list,len-i,1,&ch);
        str[i]=(char)ch+'0';
    }
    // list_traverse(list,visit);    //查看链表元素，调试用

    return 1;
}
