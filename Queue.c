//
// Created by yzy on 2023/8/4.
//

#include "Queue.h"

void InitArrayQueue(ArrayQueue* queue) {
    queue->front = 0;
    queue->rear = 0;
}

bool IsArrayQueueEmpty(ArrayQueue* queue) {
    return queue->front == queue->rear;
}

bool IsArrayQueueFull(ArrayQueue* queue) {
    return (queue->rear + 1) % MAX_SIZE == queue->front;
}

bool EnArrayQueue(ArrayQueue* queue, int item) {
    if (IsArrayQueueFull(queue)) {
        printf("Queue overflow! Cannot enqueue element.\n");
        return false;
    }

    queue->array[queue->rear] = item;
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    return true;
}

bool DeArrayQueue(ArrayQueue* queue, int* item) {
    if (IsArrayQueueEmpty(queue)) {
        printf("Queue is empty! Cannot dequeue element.\n");
        return false;
    }

    *item = queue->array[queue->front];
    queue->front = (queue->front + 1) % MAX_SIZE;
    return true;
}

bool GetArrayQueueHead(ArrayQueue* queue, int * item) {
    if (IsArrayQueueEmpty(queue)) {
        printf("Queue is empty! Cannot get head element.\n");
        return false;
    }

    *item = queue->array[queue->front];
    return true;
}

void ArrayQueueTest() {
    ArrayQueue queue;
    InitArrayQueue(&queue);

    printf("Enqueuing elements to the queue...\n");
    for (int i = 1; i <= 10; i++) {
        if (EnArrayQueue(&queue, i * 10)) {
            printf("Enqueued: %d\n", i * 10);
        }
    }

    // Test queue full condition
    if (!EnArrayQueue(&queue, 100)) {
        printf("Queue is full! Cannot enqueue 100.\n");
    }

    // Test get head element
    int head;
    if (GetArrayQueueHead(&queue, &head)) {
        printf("Front element of the queue: %d\n", head);
    }

    printf("DeQueuing elements from the queue...\n");
    while (!IsArrayQueueEmpty(&queue)) {
        int item;
        if (DeArrayQueue(&queue, &item)) {
            printf("Dequeued: %d\n", item);
        }
    }

    // Test queue empty condition
    if (!DeArrayQueue(&queue, &head)) {
        printf("Queue is empty! Cannot dequeue element.\n");
    }
}

void InitLinkedQueue(LinkedQueue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

bool IsLinkedQueueEmpty(LinkedQueue* queue) {
    return queue->front == NULL;
}

bool EnLinkedQueue(LinkedQueue* queue, int data) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    if (newNode == NULL) {
        printf("Memory allocation failed when enqueueing element!\n");
        return false;
    }

    newNode->data = data;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        queue->rear = newNode;
        queue->front = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }

    return true;
}

bool DeLinkedQueue(LinkedQueue* queue, int* data) {
    if (IsLinkedQueueEmpty(queue)) {
        printf("Queue is empty! Cannot dequeue element.\n");
        return false;
    }

    QueueNode* temp = queue->front;
    *data = temp->data;
    queue->front = temp->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);
    return true;
}

// 获取队列头部元素但不出队列
bool GetLinkedQueueHead(LinkedQueue* queue, int* item) {
    if (IsLinkedQueueEmpty(queue)) {
        printf("Queue is empty! Cannot get head element.\n");
        return false;
    }

    *item = queue->front->data;
    return true;
}

void DestroyLinkedQueue(LinkedQueue* queue) {
    while (queue->front != NULL) {
        QueueNode* temp = queue->front;
        queue->front = queue->front->next;
        free(temp);
    }

    queue->rear = NULL; // 防止野指针
}

void LinkedQueueTest() {
    LinkedQueue queue;
    InitLinkedQueue(&queue);

    printf("Enqueuing elements to the queue...\n");
    for (int i = 1; i <= 5; i++) {
        EnLinkedQueue(&queue, i * 10);
        printf("Enqueued: %d\n", i * 10);
    }

    // Test get head element
    int head;
    if (GetLinkedQueueHead(&queue, &head)) {
        printf("Front element of the queue: %d\n", head);
    }

    printf("DeQueuing elements from the queue...\n");
    while (!IsLinkedQueueEmpty(&queue)) {
        int item;
        if (DeLinkedQueue(&queue, &item)) {
            printf("Dequeued: %d\n", item);
        }
    }

    DestroyLinkedQueue(&queue);
}