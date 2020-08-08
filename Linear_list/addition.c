#include <list.h>
#include <stdio.h>
#include <string.h>

int str_to_list(char *str,list_t ** list );
int list_addition(list_t *addend, list_t * augend,list_t **sum);
int list_to_str(char *str, list_t * list);
int visit(uint16_t index,void *data);

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

    list_addition(addend,augend,&sum);
    list_to_str(buff,sum);
    printf("两数相加为：%s\n",buff);
}

int str_to_list(char * str, list_t ** list)
{
    creat(list,sizeof(uint16_t),0);
    
    uint16_t ch, len=strlen(str);
    char * num=str+len-1;

    for (int i =len; i>0; i--)
    {
        ch=(uint16_t)(*num-'0');
        append(*list,1,&ch);
        num--;
    }
    
    printf("\n");
    return 1;
}

int visit(uint16_t index,void *data)
{
    printf("%d",*(uint16_t *)data);
    fflush(stdout);
    return 1;
}


int list_addition(list_t *addend, list_t * augend,list_t **sum)
{
    uint16_t num1,num2,carry,temp;

    creat(sum,sizeof(uint16_t),0);
    while ((length(addend)!=0)&&(length(augend)!=0))
    {
        pop(addend,1,1,&num1);
        pop(augend,1,1,&num2);
        temp=(num1+num2+carry)%10;
        carry=(num1+num2+carry)/10;
        append(*sum,1,&temp);
    }

    list_t *current=(length(addend)!=0)?addend:augend;

    while(length(current)!=0)
    {
        pop(current,1,1,&num1);
        temp=(num1+carry)%10;
        carry=(num1+carry)/10;
        append(*sum,1,&temp);
    }
    if(carry>0)
    {
        append(*sum,1,&carry);
    }
    return 1;
}

int list_to_str(char *str, list_t * list)
{
    uint16_t len= length(list);
    uint16_t ch;
    for (size_t i = 0; i < len ; i++)
    {
        read(list,len-i,1,&ch);
        str[i]=(char)ch+'0';
    }
    return 1;
}
