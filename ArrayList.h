#ifndef STUDY_ARRAYLIST_H
#define STUDY_ARRAYLIST_H

#define INIT_SIZE 10

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *data;
    int MaxSize;
    int length;
} List, *ArrayList;

// 初始化线性表函数
static void InitArrayList(ArrayList L);
// 通过数组初始化线性表函数
static void InitArrayListByArray(ArrayList L, int *arr, int length);
// 创建线性表函数
ArrayList CreateArrayList();
// 通过数组创建线性表函数
ArrayList CreateArrayListByArray(int *arr, int length);
// 自动扩容函数
bool IncreaseSize(ArrayList L, int newLength);
// 按下标插入函数
bool ArrayListInsert(ArrayList L, int index, int element);
// 按下标删除函数
bool ArrayListDelete(ArrayList L, int index, int *deletedElement);
// 查找元素函数
int FindElementInArrayList(ArrayList L, int target);
// 通过下标获取函数
bool GetElementByIndexInArrayList(ArrayList L, int index, int *element);
// 打印线性表中的所有元素函数
void PrintArrayList(ArrayList L);
// 计算顺序表的有效长度函数
int GetArrayListEffectiveLength(ArrayList L);
// 计算顺序表的分配长度函数
int GetArrayListAllocatedLength(ArrayList L);
// 计算顺序表的利用率函数
double GetArrayListUtilizationRatio(ArrayList L);
// 判断顺序表是否为空函数
bool IsEmpty(ArrayList L);
// 销毁线性表函数
void DestroyArrayList(ArrayList L);
// 线性表测试函数
void ArrayListTest();
#endif // STUDY_ARRAYLIST_H
