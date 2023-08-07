//
// Created by yzy on 2023/8/2.
//

#include "Stack.h"

SqStack* CreateSqStack(int capacity) {
    SqStack* stack = (SqStack*) malloc(sizeof (SqStack));
    if (stack == NULL) {
        printf("Memory allocation failed when creating the stack!\n");
        return NULL;
    }

    stack->array = (int*) malloc(capacity * sizeof (int));
    if (stack->array == NULL) {
        printf("Memory allocation failed when creating the stack array!\n");
        free(stack);
        return NULL;
    }

    stack->top = -1; // 栈为空时，top设为-1
    stack->capacity = capacity;
    return stack;
}

void DestroySqStack(SqStack* stack) {
    if (stack == NULL) {
        return;
    }

    free(stack->array);
    free(stack);
}

bool IsSqStackEmpty(SqStack* stack) {
    return stack->top == -1;
}

bool IsSqStackFull(SqStack* stack) {
    return stack->top == stack->capacity - 1;
}

bool PushSqStack(SqStack* stack, int item) {
    if (IsSqStackFull(stack)) {
        printf("Stack overflow! Cannot PushSqStack element.\n");
        return false;
    }

    stack->top++;
    stack->array[stack->top] = item;
    return true;
}


int PopSqStack(SqStack* stack) {
    if (IsSqStackEmpty(stack)) {
        printf("Stack is empty! Cannot PopSqStack element.\n");
        return -1; // 返回一个特定值表示栈为空
    }

    int item = stack->array[stack->top];
    stack->top--;
    return item;
}

bool PeekSqStack(SqStack* stack, int* element) {
    if (IsSqStackEmpty(stack)) {
        printf("Stack is empty! Cannot PeekSqStack element.\n");
        return false; // 返回一个特定值表示栈为空
    }

    *element = stack->array[stack->top];
    return true;
}

void SqStackTest() {
    int capacity = 5; // 设置栈的容量为5
    SqStack* stack = CreateSqStack(capacity);

    // 测试入栈操作
    printf("Pushing elements to the stack...\n");
    for (int i = 1; i <= 5; i++) {
        if (PushSqStack(stack, i * 10)) {
            printf("Pushed: %d\n", i * 10);
        }
    }

    // 测试栈满的情况
    if (!PushSqStack(stack, 100)) {
        printf("Stack is full! Cannot PushSqStack 100.\n");
    }

    // 测试查看栈顶元素
    int element = 0;
    PeekSqStack(stack,&element);
    printf("Top element of the stack: %d\n", element);

    // 测试出栈操作
    printf("Popping elements from the stack...\n");
    while (!IsSqStackEmpty(stack)) {
        int item = PopSqStack(stack);
        printf("Popped: %d\n", item);
    }

    // 测试栈空的情况
    if (PopSqStack(stack) == -1) {
        printf("Stack is empty! Cannot PopSqStack element.\n");
    }

    // 销毁栈，释放内存
    DestroySqStack(stack);
}

// 初始化链栈
LinkedStack* CreateLinkedStack() {
    LinkedStack* stack = (LinkedStack*)malloc(sizeof(LinkedStack));
    if (stack == NULL) {
        printf("Memory allocation failed when creating the linked stack!\n");
        return NULL;
    }

    stack->top = NULL;
    return stack;
}

// 销毁链栈，释放内存
void DestroyLinkedStack(LinkedStack* stack) {
    if (stack == NULL) {
        return;
    }

    StackNode* currentNode = stack->top;
    while (currentNode != NULL) {
        StackNode* temp = currentNode;
        currentNode = currentNode->next;
        free(temp);
    }

    free(stack);
}

// 判断链栈是否为空
bool IsLinkedStackEmpty(LinkedStack* stack) {
    return stack->top == NULL;
}

// 入栈
bool PushLinkedStack(LinkedStack* stack, int data) {
    StackNode* newStackNode = (StackNode*)malloc(sizeof(StackNode));
    if (newStackNode == NULL) {
        printf("Memory allocation failed when pushing to the linked stack!\n");
        return false;
    }

    newStackNode->data = data;
    newStackNode->next = stack->top;
    stack->top = newStackNode;
    return true;
}

// 出栈
int PopLinkedStack(LinkedStack* stack) {
    if (IsLinkedStackEmpty(stack)) {
        printf("Linked stack is empty! Cannot PopSqStack element.\n");
        return -1; // 返回一个特定值表示栈为空
    }

    int data = stack->top->data;
    StackNode* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

// 查看栈顶元素但不出栈
int PeekLinkedStack(LinkedStack* stack, int* element) {
    if (IsLinkedStackEmpty(stack)) {
        printf("Linked stack is empty! Cannot PeekSqStack element.\n");
        return false; // 返回一个特定值表示栈为空
    }

    *element = stack->top->data;
    return true;
}

// 链栈测试函数
void LinkedStackTest() {
    LinkedStack* stack = CreateLinkedStack();

    // 测试入栈操作
    printf("Pushing elements to the stack...\n");
    for (int i = 1; i <= 5; i++) {
        if (PushLinkedStack(stack, i * 10)) {
            printf("Pushed: %d\n", i * 10);
        }
    }

    // 测试查看栈顶元素
    int element = 0;
    PeekLinkedStack(stack,&element);
    printf("Top element of the stack: %d\n", element);

    // 测试出栈操作
    printf("Popping elements from the stack...\n");
    while (!IsLinkedStackEmpty(stack)) {
        int item = PopLinkedStack(stack);
        printf("Popped: %d\n", item);
    }

    // 测试栈空的情况
    if (PopLinkedStack(stack) == -1) {
        printf("Stack is empty! Cannot pop element.\n");
    }

    // 销毁栈，释放内存
    DestroyLinkedStack(stack);
}