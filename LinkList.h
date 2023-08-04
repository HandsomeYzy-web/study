//
// Created by yzy on 2023/7/28.
//

#ifndef STUDY_LINKLIST_H
#define STUDY_LINKLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 单链表
typedef struct Node {
    int data;
    struct Node *next;
} Node, *LinkList;

// 双链表
typedef struct DNode {
    struct DNode *prior;
    int data;
    struct DNode *next;
} DNode, *DLinkList;

// 创建单链表函数
LinkList CreateLinkList();

// 通过数组创建单链表函数
LinkList CreateLinkListByArray(const int *arr, int length);

// 销毁单链表函数
void DestroyLinkList(Node *node);

// 在单链表头部插入一个元素函数
bool LinkListInsertAtHead(LinkList L, int data);

// 在单链表尾部插入一个元素
bool LinkListInsertAtTail(LinkList L, int data);

// 在单链表尾部插入一组元素函数
bool LinkListInsertArrayAtTail(LinkList L,const int *arr, int length);

// 在指定位置插入一个元素到单链表中
bool LinkListInsert(LinkList L, int index, int data);

// 按下标删除单链表中的元素
bool LinkListDelete(LinkList L, int index);

// 查找元素在单链表中的索引
int FindElementInLinkList(LinkList L, int target);

// 通过下标获取单链表中的元素值
bool GetElementByIndexInLinkList(LinkList L, int index, int *element);

// 获取单链表的长度函数
int GetLinkListLength(LinkList L);

// 打印单链表的元素函数
void PrintLinkList(LinkList L);

// 单链表测试函数
void LinkListTest();

// 创建双链表函数
DLinkList CreateDLinkList();



#endif //STUDY_LINKLIST_H