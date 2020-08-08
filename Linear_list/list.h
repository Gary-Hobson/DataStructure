/*
 * @Descripttion:  线性表接口文件
 * @version: V1.0
 * @Author: Hobson
 * @Date: 2020-08-08 23:22:15
 * @History: V1.0 创建连续式和链表式线性表
 * @LastEditTime: 2020-08-08 23:39:40
 */

#ifndef LINEAR_LIST_H
#define LINEAR_LIST_H

#include <stdint.h>
#include <stdlib.h>

typedef struct _list_t list_t;

/**
 * @description: 创建线性表
 * @param   list :指向线性表指针的地址，用于初始化链表
 * @param   size :数据大小，单位字节
 * @param   length:线性表的初始化长度，对链式表无效
 * @return : 返回执行结果
 * @note:    list_t *dome;  list_creat(&dome);   
 */
int     list_creat(list_t ** list ,uint16_t size,uint16_t length);

/**
 * @description: 向线性表指定位置插入数据
 * @param   list :线性表指针
 * @param   loca :插入位置,从1开始
 * @param   num:插入数量
 * @param   data:待写入数据
 * @return : 返回执行结果
 * @note:    None
 */
int     list_insert(list_t *list, uint16_t loca, uint16_t num, void *data);

/**
 * @description: 向线性表指定位置删除数据,并读取数据
 * @param   list :线性表指针
 * @param   loca :删除位置,从1开始
 * @param   num:删除数量
 * @param   data:读取数据缓冲区,为空(NULL)时,直接删除数据
 * @return : 返回执行结果,1为成功,<0失败
 * @note:    None
 */
int     list_delete(list_t *list, uint16_t loca, uint16_t num, void *data);

/**
 * @description: 读取线性表指定位置数据
 * @param   list :线性表指针
 * @param   loca :读取数据起始位置,从1开始
 * @param   data:读取数据缓冲区,不可为空
 * @param   num:读取数量
 * @return : 返回执行结果,1为成功,<0失败
 * @note:    None
 */
int     list_read(list_t *list, uint16_t loca, uint16_t num,void *data);

/**
 * @description: 查找线性表指定数据第一次出现的位置
 * @param   list :线性表指针
 * @param   data:需要查找的数据
 * @return : 返回执行结果 n; 
 *           n=0为未查找到该数据, n>0该数据的索引, <0发生错误
 * @note:    None
 */
int     list_find(list_t *list, void * data);

/**
 * @description: 读取线性表尾部追加数据
 * @param   list :线性表指针
 * @param   num:插入数据数量
 * @param   data:待插入的数据指针,不可为空
 * @return : 返回执行结果,1为成功,<0失败
 * @note:    None
 */
int     list_append(list_t *list, uint16_t num, void *data);

/**
 * @description: 遍历线性表所有数据
 * @param   list :线性表指针
 * @param   visit:遍历使用的函数指针,返回值为int型,表示执行结果<0时,中断遍历
 * @param   index:向遍历函数指针传递的参数, 数据的索引
 * @param   data:向遍历函数传递的参数,数据指针
 * @return : 返回执行结果 n;
 * @note:    None
 */
int     list_traverse(list_t *list, int (*visit)(uint16_t index,void *data));

/**
 * @description: 获取线性表长度
 * @param   list :线性表指针
 * @return : 返回线性表长度,<0线性表未初始化
 * @note:    None
 */
int     list_length(list_t *list);

/**
 * @description: 清空线性表数据
 * @param   list :线性表指针
 * @return : 返回执行结果,1为成功,<0失败
 * @note:    None
 */
int     list_clear(list_t *list);

/**
 * @description: 删除线性表
 * @param   list :线性表指针
 * @return : 返回执行结果,1为成功,<0失败
 * @note:    None
 */
int     list_destroy(list_t *list);

#endif
