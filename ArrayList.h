#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INIT_SIZE 10

// 定义线性表结构体
typedef struct {
    int *data;       // 指向存储数据的数组
    int MaxSize;     // 线性表最大容量
    int length;      // 线性表当前长度
} List, *ArrayList;

// 初始化线性表函数
static void InitArrayList(ArrayList L);

// 通过数组初始化线性表函数
static void InitArrayListByArray(ArrayList L, int *arr, int length);

// 创建线性表函数
ArrayList CreateArrayList();

// 通过数组创建线性表函数
ArrayList CreateArrayListByArray(int *arr, int length);

// 销毁线性表函数
void DestroyArrayList(ArrayList L);

// 自动扩容函数
bool IncreaseSize(ArrayList L, int newLength);

// 追加元素到线性表末尾
bool ArrayListAppend(ArrayList L, int element);

// 将整数数组中的元素逐一追加到线性表中
bool ArrayListAppendByArray(ArrayList L, int *arr, int length);

// 按下标插入元素到线性表中
bool ArrayListInsert(ArrayList L, int index, int element);

// 按下标删除线性表中的元素，并通过指针返回被删除的元素值
bool ArrayListDelete(ArrayList L, int index, int *deletedElement);

// 查找元素在线性表中的索引
int FindElementInArrayList(ArrayList L, int target);

// 通过下标获取线性表中的元素值
bool GetElementByIndexInArrayList(ArrayList L, int index, int *element);

// 打印线性表中的所有元素
void PrintArrayList(ArrayList L);

// 计算线性表的有效长度
int GetArrayListEffectiveLength(ArrayList L);

// 计算线性表的分配长度
int GetArrayListAllocatedLength(ArrayList L);

// 计算线性表的利用率
double GetArrayListUtilizationRatio(ArrayList L);

// 判断线性表是否为空
bool IsEmpty(ArrayList L);

// 查找线性表中的最大值
bool FindMaxInArrayList(ArrayList L, int *max);

// 查找线性表中的最小值
bool FindMinInArrayList(ArrayList L, int *min);

// 反转线性表
void ReverseArrayList(ArrayList L);

// 线性表测试函数
void ArrayListTest();

#endif //ARRAYLIST_H
