//
// Created by yzy on 2023/8/2.
//

#ifndef STUDY_STACK_H
#define STUDY_STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 线性栈
typedef struct {
    int *array;
    int capacity;
    int top;
} SqStack;

// 链栈节点结构
typedef struct StackNode {
    int data;                // 数据域
    struct StackNode* next;  // 指向下一个节点的指针
} StackNode;

// 链栈结构
typedef struct {
    StackNode* top;          // 指向栈顶的指针
} LinkedStack;

// 初始化栈
SqStack* CreateSqStack(int capacity);

// 销毁栈
void DestroySqStack(SqStack* stack);

// 判断栈是否为空
bool IsSqStackEmpty(SqStack* stack);

// 判断栈是否已满
bool IsSqStackFull(SqStack* stack);

// 入栈
bool PushSqStack(SqStack* stack, int item);

// 出栈
int PopSqStack(SqStack* stack);

// 查看栈顶元素但不出栈
int PeekSqStack(SqStack* stack);

// 顺序栈测试函数
void SqStackTest();

// 初始化链栈
LinkedStack* CreateLinkedStack();

// 销毁链栈，释放内存
void DestroyLinkedStack(LinkedStack* stack);

// 判断链栈是否为空
bool IsLinkedStackEmpty(LinkedStack* stack);

// 入栈
bool PushLinkedStack(LinkedStack* stack, int data);

// 出栈
int PopLinkedStack(LinkedStack* stack);

// 查看栈顶元素但不出栈
int PeekLinkedStack(LinkedStack* stack);

// 链栈测试函数
void LinkedStackTest();

#endif //STUDY_STACK_H
