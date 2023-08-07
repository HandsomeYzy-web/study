//
// Created by yzy on 2023/8/4.
//

#ifndef STUDY_QUEUE_H
#define STUDY_QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 10

typedef struct {
    int array[MAX_SIZE];
    int front;
    int rear;
}ArrayQueue;

typedef struct QueueNode{
    int data;
    struct QueueNode* next;
} QueueNode;

typedef struct {
    QueueNode* front;
    QueueNode* rear;
} LinkedQueue;

void InitArrayQueue(ArrayQueue* queue);

bool IsArrayQueueEmpty(ArrayQueue* queue);

bool IsArrayQueueFull(ArrayQueue* queue);

bool EnArrayQueue(ArrayQueue* queue, int item);

bool DeArrayQueue(ArrayQueue* queue, int* item);

bool GetArrayQueueHead(ArrayQueue* queue, int * item);

void ArrayQueueTest();

void InitLinkedQueue(LinkedQueue* queue);

bool IsLinkedQueueEmpty(LinkedQueue* queue);

bool EnLinkedQueue(LinkedQueue* queue, int data);

bool DeLinkedQueue(LinkedQueue* queue, int* data);

bool GetLinkedQueueHead(LinkedQueue* queue, int* item);

void DestroyLinkedQueue(LinkedQueue* queue);

void LinkedQueueTest();

#endif //STUDY_QUEUE_H
