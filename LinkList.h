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

// 初始化带头结点的单链表
LinkList CreateLinkList();
//
void DestroyLinkList(LinkList head);
// 向链表表尾添加元素
bool LinkListAppend(LinkList L, int data);
// 按下表添加元素
bool LinkListInsert(LinkList L, int index, int data);
bool LinkListDelete(LinkList L, int index);
int FindElementInLinkList(LinkList L, int target);
int GetElementByIndexInLinkList (LinkList L, int index);
void printLinkList(LinkList L);

#endif //STUDY_LINKLIST_H