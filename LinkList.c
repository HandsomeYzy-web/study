#include "LinkList.h"

// 创建单链表函数
LinkList CreateLinkList() {
    LinkList head = (LinkList) malloc(sizeof (Node));
    if (head == NULL) {
        printf("Memory allocation failed when creating link list!\n");
        exit(-1);
    }

    head->next = NULL;
    return head;
}

// 通过数组创建单链表函数
LinkList CreateLinkListByArray(const int *arr, int length) {
    LinkList head = CreateLinkList();
    if (head == NULL) {
        printf("Memory allocation failed when creating link list!\n");
        exit(-1);
    }

    // 用一个临时指针指向链表头部，以便后续插入元素时保持链表头部位置不变
    LinkList current = head;

    for (int i = 0; i < length; i++) {
        LinkList newNode = (LinkList) malloc(sizeof(Node));
        if (newNode == NULL) {
            printf("Memory allocation failed when inserting array elements!\n");
            // 遇到内存分配失败，应该释放之前分配的节点内存
            DestroyLinkList(head);
            exit(-1);
        } else {
            newNode->data = arr[i];
            newNode->next = NULL;
            // 将新节点插入到链表末尾
            current->next = newNode;
            // 更新临时指针指向新插入的节点
            current = newNode;
        }
    }

    return head;
}

// 销毁单链表函数
void DestroyLinkList(Node *node) {
    Node* currentNode = node;
    while (currentNode != NULL) {
        Node* temp = currentNode;
        currentNode = currentNode->next;
        free(temp);
    }

    // 在销毁链表后，将头指针置为 NULL，避免野指针
    node = NULL;
}

// 在单链表头部插入一个元素函数
bool LinkListInsertAtHead(LinkList L, int data) {
    if (L == NULL) {
        printf("Invalid link list!\n");
        return false;
    }

    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed when inserting at head!\n");
        return false;
    }

    newNode->data = data;
    newNode->next = L->next;
    L->next = newNode;

    return true;
}

// 在单链表尾部插入一个元素
bool LinkListInsertAtTail(LinkList L, int data) {
    if (L == NULL) {
        printf("Invalid link list!\n");
        return false;
    }

    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed when inserting at tail!\n");
        return false;
    }

    newNode->data = data;
    newNode->next = NULL;

    Node *currentNode = L;
    while (currentNode->next != NULL) {
        currentNode = currentNode->next;
    }

    currentNode->next = newNode;

    return true;
}

// 在单链表尾部插入一组元素函数
bool LinkListInsertArrayAtTail(LinkList L,const int *arr, int length) {
    if (L == NULL) {
        printf("Invalid link list!\n");
        return false;
    }

    Node *currentNode = L;
    while (currentNode->next != NULL) {
        currentNode = currentNode->next;
    }

    // 找到末尾节点，记录节点，便于在出现异常时释放已开辟的空间，使链表恢复原样
    Node *tail = currentNode;


    for (int i = 0; i < length; i++) {
        Node *newNode = (Node *)malloc(sizeof(Node));
        if (newNode == NULL) {
            DestroyLinkList(tail->next);
            printf("Memory allocation failed!\n");
            return false;
        }

        newNode->data = arr[i];
        newNode->next = NULL;
        currentNode->next = newNode;
        currentNode = currentNode->next;
    }

    return true;
}

// 在指定位置插入一个元素到单链表中
bool LinkListInsert(LinkList L, int index, int data) {
    if (L == NULL) {
        printf("Invalid link list!\n");
        return false;
    }

    // 寻找要插入的位置
    Node *currentNode = L;
    int currentPosition = 0;
    while (currentNode->next != NULL && currentPosition < index) {
        currentNode = currentNode->next;
        currentPosition++;
    }

    // 判断输入下标是否合法
    if (currentNode == NULL) {
        printf("Invalid index when inserting element!\n");
        return false;
    }

    // 插入元素
    Node *newNode = (Node *) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed when inserting element!\n");
        return false;
    }

    newNode->data = data;
    newNode->next = currentNode->next;
    currentNode->next = newNode;
    return true;
}

// 按下标删除单链表中的元素
bool LinkListDelete(LinkList L, int index) {
    if (L == NULL) {
        printf("Invalid link list!\n");
        return false;
    }

    // 找到要删除节点的前一个节点
    Node* currentNode = L;
    int currentPosition = 0;
    while (currentNode->next != NULL && currentPosition < index) {
        currentNode = currentNode->next;
        currentPosition++;
    }

    if (currentNode->next == NULL) {
        printf("Invalid index when deleting element!\n");
        return false;
    }

    // 执行删除操作
    Node* toDelete = currentNode->next;
    currentNode->next = currentNode->next->next;
    free(toDelete);

    return true;
}

// 查找元素在单链表中的索引
int FindElementInLinkList(LinkList L, int target) {
    if (L == NULL) {
        printf("Invalid link list!\n");
        return false;
    }

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


// 通过下标获取单链表中的元素值
bool GetElementByIndexInLinkList(LinkList L, int index, int *element) {
    if (L == NULL) {
        printf("Invalid link list!\n");
        return false;
    }

    Node *currentNode = L;
    int currentPosition = 0;
    while (currentNode->next != NULL && currentPosition < index) {
        currentNode = currentNode->next;
        currentPosition++;
    }

    // 判断输入下标是否合法
    if (currentNode == NULL || currentPosition > index) {
        printf("Invalid index!\n");
        return false;
    }

    *element = currentNode->next->data;
    return true;
}

// 获取单链表的长度函数
int GetLinkListLength(LinkList L) {
    if (L == NULL) {
        printf("Invalid link list!\n");
        return -1;
    }

    int length = 0;
    Node *currentNode = L->next;
    while (currentNode != NULL) {
        length++;
        currentNode = currentNode->next;
    }
    return length;
}

// 打印单链表的元素函数
void PrintLinkList(LinkList L) {
    if (L == NULL) {
        printf("Empty link list!\n");
        return;
    }

    Node *currentNode = L->next;
    if (currentNode == NULL) {
        printf("Empty link list!\n");
        return;
    }

    while (currentNode != NULL) {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("\n");
}

// 单链表测试函数
void LinkListTest() {
    // 创建链表并在头部插入元素
    LinkList list1 = CreateLinkList();
    printf("Testing LinkListInsertAtHead:\n");
    for (int i = 1; i <= 5; i++) {
        LinkListInsertAtHead(list1, i);
    }
    printf("List1 after inserting at head: ");
    PrintLinkList(list1); // 应输出 5 4 3 2 1

    // 在尾部插入元素
    printf("Testing LinkListInsertAtTail:\n");
    for (int i = 6; i <= 10; i++) {
        LinkListInsertAtTail(list1, i);
    }
    printf("List1 after inserting at tail: ");
    PrintLinkList(list1); // 应输出 5 4 3 2 1 6 7 8 9 10

    // 在指定位置插入元素
    printf("Testing LinkListInsert:\n");
    LinkListInsert(list1, 2, 100); // 在索引 2 处插入元素 100
    printf("List1 after insert: ");
    PrintLinkList(list1); // 应输出 5 4 100 3 2 1 6 7 8 9 10

    // 删除元素
    printf("Testing LinkListDelete:\n");
    LinkListDelete(list1, 5); // 删除索引 5 处的元素
    printf("List1 after delete: ");
    PrintLinkList(list1); // 应输出 5 4 100 3 2 6 7 8 9 10

    // 在尾部插入数组
    printf("Testing LinkListInsertArrayAtTail:\n");
    int array[] = {10,20,30,40};
    int length = sizeof (array) / sizeof (array[0]);
    LinkListInsertArrayAtTail(list1,array,length); // 在链表表尾插入数组
    printf("List1 after inserting array at tail: ");
    PrintLinkList(list1); // 应输出 5 4 100 3 2 6 7 8 9 10 10 20 30 40

    // 查找元素
    printf("Testing FindElementInLinkList:\n");
    int target = 3;
    int index = FindElementInLinkList(list1, target);
    if (index != -1) {
        printf("Element %d found at index %d\n", target, index); // 应输出 Element 3 found at index 3
    } else {
        printf("Element %d not found in the LinkList\n", target);
    }

    // 按下标查找元素
    printf("Testing GetElementByIndexInLinkList:\n");
    int element;
    if (GetElementByIndexInLinkList(list1, 2, &element)) {
        printf("Element at index 2: %d\n", element); // 应输出 Element at index 2: 100
    } else {
        printf("Failed to get element at index 2\n");
    }

    // 获取链表的长度
    printf("Testing GetLinkListLength:\n");
    int LinkListLength = GetLinkListLength(list1);
    printf("Length of list1: %d\n", LinkListLength); // 应输出 Length of list1: 14

    // 通过数组创建链表
    printf("Testing CreateLinkListByArray:\n");
    int arr[] = {11, 12, 13, 14, 15};
    int arrLength = sizeof(arr) / sizeof(arr[0]);
    LinkList list2 = CreateLinkListByArray(arr, arrLength);
    printf("List2 created by array: ");
    PrintLinkList(list2); // 应输出 11 12 13 14 15

    // 销毁链表
    DestroyLinkList(list1);
    DestroyLinkList(list2);
}

// 创建双链表函数
DLinkList CreateDLinkList() {
    DLinkList head = (DNode *) malloc(sizeof (DNode));
    if (head == NULL) {
        printf("Memory allocation failed when creating link list!\n");
        exit(-1);
    }

    head->prior = NULL;
    head->next = NULL;
    return head;
}

bool DLinkListInsertAtHead(DLinkList L, int data) {
    if (L == NULL) {
        printf("Invalid link list!\n");
        return false;
    }

    DNode *newDNode = (DNode *)malloc(sizeof(DNode));
    if (newDNode == NULL) {
        printf("Memory allocation failed when inserting at head!\n");
        return false;
    }

    newDNode->prior = L;
    newDNode->data = data;
    newDNode->next = L->next;
    L->next = newDNode;

    return true;
}

bool DLinkListInsertAtTail(DLinkList L, int data) {
    if (L == NULL) {
        printf("Invalid link list!\n");
        return false;
    }

    DNode *newDNode = (DNode *)malloc(sizeof(DNode));
    if (newDNode == NULL) {
        printf("Memory allocation failed when inserting at tail!\n");
        return false;
    }

    newDNode->data = data;
    newDNode->next = NULL;

    DNode *currentDNode = L;
    while (currentDNode->next != NULL) {
        currentDNode = currentDNode->next;
    }

    currentDNode->next = newDNode;
    newDNode->prior = currentDNode;

    return true;
}

bool DLinkListInsert(DLinkList L, int index, int data) {
    if (L == NULL) {
        printf("Invalid link list!\n");
        return false;
    }

    // 寻找要插入的位置
    DNode *currentNode = L;
    int currentPosition = 0;
    while (currentNode->next != NULL && currentPosition < index) {
        currentNode = currentNode->next;
        currentPosition++;
    }

    // 判断输入下标是否合法
    if (currentNode == NULL) {
        printf("Invalid index when inserting element!\n");
        return false;
    }

    // 插入元素
    DNode *newDNode = (DNode *) malloc(sizeof(DNode));
    if (newDNode == NULL) {
        printf("Memory allocation failed when inserting element!\n");
        return false;
    }

    newDNode->data = data;
    newDNode->next = currentNode->next;
    currentNode->next = newDNode;
    return true;
}