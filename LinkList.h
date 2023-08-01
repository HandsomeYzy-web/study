//
// Created by yzy on 2023/7/28.
//

#ifndef STUDY_LINKLIST_H
#define STUDY_LINKLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node, *LinkList;

// 创建链表函数
LinkList CreateLinkList();

// 通过数组创建链表函数
LinkList CreateLinkListByArray(const int *arr, int length);

// 销毁链表函数
void DestroyLinkList(Node *node);

// 在链表头部插入一个元素函数
bool LinkListInsertAtHead(LinkList L, int data);

// 在链表尾部插入一个元素
bool LinkListInsertAtTail(LinkList L, int data);

// 在链表尾部插入一组元素函数
bool LinkListInsertArrayAtTail(LinkList L,const int *arr, int length);

// 在指定位置插入一个元素到链表中
bool LinkListInsert(LinkList L, int index, int data);

// 按下标删除链表中的元素
bool LinkListDelete(LinkList L, int index);

// 查找元素在链表中的索引
int FindElementInLinkList(LinkList L, int target);

// 通过下标获取链表中的元素值
bool GetElementByIndexInLinkList(LinkList L, int index, int *element);

// 获取链表的长度函数
int GetLinkListLength(LinkList L);

// 打印链表的元素函数
void PrintLinkList(LinkList L);

// 链表测试函数
void LinkListTest();

#endif //STUDY_LINKLIST_H