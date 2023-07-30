//
// Created by yzy on 2023/7/28.
//

#include "LinkList.h"

LinkList CreateLinkList() {
    LinkList head = (LinkList) malloc(sizeof(Node));
    if (head == NULL) {
        printf("Memory allocation failed!\n");
        exit(-1);
    }
    head->next = NULL;
    return head;
}

LinkList CreateLinkListByArray(int *arr, int length) {
    LinkList head = (LinkList) malloc(sizeof (Node));
    if (head == NULL) {
        printf("Memory allocation failed!\n");
        exit(-1);
    }
    head->next = NULL;


}

void DestroyLinkList(LinkList head) {
    Node* currentNode = head;
    while (currentNode != NULL) {
        Node* temp = currentNode;
        currentNode = currentNode->next;
        free(temp);
    }
}

bool LinkListAppend(LinkList L, int data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(-1);
    }
    newNode->data = data;
    newNode->next = NULL;

    // 寻找链表最后一个节点
    Node *currentNode = L;
    while (currentNode->next != NULL) {
        currentNode = currentNode->next;
    }

    //将要插入的值插入到链表的末端
    currentNode->next = newNode;
    return true;
}

bool LinkListInsert(LinkList L, int index, int data) {
    // 寻找要插入的位置
    Node *currentNode = L;
    int currentPosition = 0;
    while (currentNode->next!=NULL || currentPosition < index) {
        currentNode = currentNode->next;
        currentPosition++;
    }

    // 判断输入下标是否合法
    if(currentNode == NULL) {
        printf("Invalid index!\n");
        return false;
    }

    // 插入元素
    Node *newNode = (Node *) malloc(sizeof (Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return false;
    }

    newNode->data = data;

    newNode->next = currentNode->next;
    currentNode->next = newNode;

    return true;
}

bool LinkListDelete(LinkList L, int index) {
    // 找到要删除节点的前一个节点
    Node* currentNode = L;
    int currentPosition = 0;
    while (currentNode->next != NULL && currentPosition < index) {
        currentNode = currentNode->next;
        currentPosition++;
    }

    if (currentNode->next == NULL) {
        printf("Invalid index!\n");
        return false;
    }

    // 执行删除操作
    Node* toDelete = currentNode->next;
    currentNode->next = currentNode->next->next;
    free(toDelete);

    return true;
}

int FindElementInLinkList(LinkList L, int target) {
    int index = 0;
    Node* currentNode = L->next; // 跳过头结点，从第一个数据节点开始遍历
    while (currentNode != NULL) {
        if (currentNode->data == target) {
            return index; // 找到目标值，返回索引位置
        }
        currentNode = currentNode->next;
        index++;
    }
    return -1; // 没有找到目标值，返回-1
}

int GetElementByIndexInLinkList (LinkList L, int index) {
    Node *currentNode = L;
    int currentPosition = 0;
    while (currentNode->next!=NULL || currentPosition < index) {
        currentNode = currentNode->next;
        currentPosition++;
    }

    // 判断输入下标是否合法
    if(currentNode == NULL) {
        printf("Invalid index!\n");
        return -1;
    }

    return currentNode->data;
}

void printLinkList(LinkList L) {
    Node* currentNode = L->next; // 跳过头结点，从第一个数据节点开始遍历
    while (currentNode != NULL) {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("\n");
}