//
// Created by yzy on 2023/7/27.
//

#include "ArrayList.h"

// 初始化线性表函数
static void InitArrayList(ArrayList L) {
    L->data = (int *) malloc(INIT_SIZE * sizeof(int));
    if (L->data == NULL) {
        printf("Memory allocation failed!\n");
        exit(-1);
    }
    L->MaxSize = INIT_SIZE;
    L->length = 0;
}

// 通过数组初始化线性表函数
static void InitArrayListByArray(ArrayList L, int *arr, int length) {
    // 初始化线性表
    InitArrayList(L);

    // 数组合法插入到线性表中
    for (int i = 0; i < length; i++) {
        ArrayListInsert(L, i, arr[i]);
    }
}

// 创建线性表函数
ArrayList CreateArrayList() {
    List *newList = (List *) malloc(sizeof(List));
    if (newList == NULL) {
        printf("Memory allocation failed!\n");
        exit(-1);
    }
    InitArrayList(newList);
    return newList;
}

// 通过数组创建线性表函数
ArrayList CreateArrayListByArray(int *arr, int length) {
    // 创建新的线性表
    List *newList = (List *) malloc(sizeof(List));
    if (newList == NULL) {
        printf("Memory allocation failed!\n");
        exit(-1);
    }

    // 初始化线性表
    InitArrayListByArray(newList, arr, length);

    // 返回新的线性表
    return newList;
}


// 销毁线性表函数
void DestroyArrayList(ArrayList L) {
    free(L->data);
    L->data = NULL;
    L->MaxSize = 0;
    L->length = 0;
}

// 自动扩容函数
bool IncreaseSize(ArrayList L, int newLength) {
    if(newLength <= L->MaxSize) {
        return true; //不需要扩容
    }

    int *newData = (int *)realloc(L->data, newLength * sizeof (int));
    if(newData == NULL) {
        printf("Failed to allocate memory for ArrayList!\n");
        return false; //扩容失败
    }

    L->data = newData;
    L->MaxSize = newLength;
    return true;
}

// 追加元素到线性表末尾
bool ArrayListAppend(ArrayList L,int element) {
    // 判断是否需要扩容
    if (L->length == L->MaxSize) {
        // 当线性表满时，增加容量
        if (!IncreaseSize(L, L->MaxSize * 2)) {
            return false;
        }
    }

    L->data[L->length] = element;
    L->length++;

    return true;
}

// 将整数数组中的元素逐一追加到线性表中
bool ArrayListAppendByArray(ArrayList L, int *arr, int length) {
    // 先检查是否需要扩容，避免多次扩容
    if (L->length + length > L->MaxSize) {
        // 计算新的容量，可以根据实际需求选择扩容大小
        int newLength = L->MaxSize + length;
        if (!IncreaseSize(L, newLength)) {
            return false; // 扩容失败返回错误标志
        }
    }

    // 逐个追加元素
    for (int i = 0; i < length; i++) {
        if(!ArrayListAppend(L, arr[i])) {
            return false; // 追加元素发生错误，返回错误标志
        }
    }

    return true; // 添加成功，返回成功标志
}


// 按下标插入函数
bool ArrayListInsert(ArrayList L, int index, int element) {
    if (index < 0 || index > L->length) {
        // 索引越界，插入失败
        printf("Index out of bounds, insert failed!");
        return false;
    }

    // 判断是否需要扩容
    if (L->length == L->MaxSize) {
        // 当线性表满时，增加容量
        if(!IncreaseSize(L, L->MaxSize * 2)) {
            return false; // 扩容失败，返回错误标志
        }
    }

    // 将 index 位置之后的元素都后移一位
    for (int i = L->length - 1; i >= index; i--) {
        L->data[i + 1] = L->data[i];
    }

    // 插入新元素
    L->data[index] = element;
    L->length++;

    return true; // 插入成功
}

// 按下标删除函数
bool ArrayListDelete(ArrayList L, int index, int *deletedElement) {
    if (index < 0 || index >= L->length) {
        // 索引越界，删除失败
        printf("Index out of bounds, delete failed!");
        return false;
    }

    // 获取被删除的元素
    *deletedElement = L->data[index];

    // 将 index 位置之后的元素都前移一位
    for (int i = index; i < L->length - 1; i++) {
        L->data[i] = L->data[i + 1];
    }

    L->length--;

    return true; // 删除成功
}

// 查找元素函数
int FindElementInArrayList(ArrayList L, int target) {
    for (int i = 0; i < L->length; i++) {
        if (L->data[i] == target) {
            // 找到了目标元素，返回元素的索引
            return i;
        }
    }

    // 没有找到目标元素，返回一个特定的标识，例如 -1
    return -1;
}

// 通过下标获取函数
bool GetElementByIndexInArrayList(ArrayList L, int index, int *element) {
    if (index >= 0 && index < L->length) {
        // 索引在有效范围内，返回对应位置的元素值
        *element = L->data[index];
        return true;
    } else {
        // 索引越界，返回一个特定的标识，例如 -1
        return false;
    }
}

// 打印线性表中的所有元素函数
void PrintArrayList(ArrayList L) {
    for (int i = 0; i < L->length; i++) {
        printf("%d ", L->data[i]);
    }
    printf("\n");
}

// 计算顺序表的有效长度函数
int GetArrayListEffectiveLength(ArrayList L) {
    return L->length;
}

// 计算顺序表的分配长度函数
int GetArrayListAllocatedLength(ArrayList L) {
    return L->MaxSize;
}

// 计算顺序表的利用率函数
double GetArrayListUtilizationRatio(ArrayList L) {
    int effectiveLength = GetArrayListEffectiveLength(L);
    int allocatedLength = GetArrayListAllocatedLength(L);

    if (effectiveLength == 0) {
        return 0;
    }

    return (double) effectiveLength/ allocatedLength;
}

// 判断顺序表是否为空函数
bool IsEmpty(ArrayList L) {
    return L->length == 0;
}

// 查找线性表中的最大值
bool FindMaxInArrayList(ArrayList L, int *max) {
    if (IsEmpty(L)) {
        printf("ArrayList is empty!\n");
        return false;
    }

    *max = L->data[0];
    for (int i = 1; i < L->length; i++) {
        if (L->data[i] > *max) {
            *max = L->data[i];
        }
    }

    return true;
}

// 查找线性表中的最小值
bool FindMinInArrayList(ArrayList L, int *min) {
    if (IsEmpty(L)) {
        printf("ArrayList is empty!\n");
        return false;
    }

    *min = L->data[0];
    for (int i = 1; i < L->length; i++) {
        if (L->data[i] < *min) {
            *min = L->data[i];
        }
    }

    return true;
}

// 反转线性表函数
void ReverseArrayList(ArrayList L) {
    int start = 0;
    int end = L->length-1;

    while (start < end) {
        int temp = L->data[start];
        L->data[start] = L->data[end];
        L->data[end] = temp;
        start++;
        end--;
    }
}

// 线性表测试函数
void ArrayListTest() {
    // 创建线性表并追加元素
    ArrayList list1 = CreateArrayList();
    printf("Testing ArrayListAppend and automatic resizing:\n");
    for (int i = 1; i <= 11; i++) {
        ArrayListAppend(list1, i);
    }
    printf("List1: ");
    PrintArrayList(list1); // 应输出 1 2 3 4 5 6 7 8 9 10 11

    // 检测线性表的实际长度、分配内存和利用率
    int effectiveLength1 = GetArrayListEffectiveLength(list1);
    int allocatedLength1 = GetArrayListAllocatedLength(list1);
    double utilizationRatio1 = GetArrayListUtilizationRatio(list1);
    printf("Effective length of list1: %d\n", effectiveLength1); // 应输出 Effective length of list1: 11
    printf("Allocated length of list1: %d\n", allocatedLength1); // 应输出 Allocated length of list1: 20
    printf("Utilization ratio of list1: %.2f\n", utilizationRatio1); // 应输出 Utilization ratio of list1: 0.55

    // 通过数组追加元素触发自动扩容机制
    int arr[] = {12, 13, 14, 15, 16, 17,18, 19, 20, 21};
    int arrLength = sizeof(arr) / sizeof(arr[0]);
    printf("Testing ArrayListAppendByArray and automatic resizing:\n");
    ArrayListAppendByArray(list1, arr, arrLength);
    printf("List1 after appending array: ");
    PrintArrayList(list1); // 应输出 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21

    // 插入元素
    printf("Testing ArrayListInsert:\n");
    ArrayListInsert(list1, 0, 100); // 在索引 0 处插入元素 100
    printf("List1 after insert: ");
    PrintArrayList(list1); // 应输出 100 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21

    // 删除元素
    printf("Testing ArrayListDelete:\n");
    int deletedElement;
    ArrayListDelete(list1, 6, &deletedElement); // 删除索引 6 处的元素
    printf("Deleted element: %d\n", deletedElement); // 应输出 Deleted element: 7
    printf("List1 after delete: ");
    PrintArrayList(list1); // 应输出 100 1 2 3 4 5 6 8 9 10 11 12 13 14 15 16 17 18 19 20 21

    // 查找元素
    printf("Testing FindElementInArrayList:\n");
    int target = 5;
    int index = FindElementInArrayList(list1, target);
    if (index != -1) {
        printf("Element %d found at index %d\n", target, index); // 应输出 Element 5 found at index 5
    } else {
        printf("Element %d not found in the ArrayList\n", target);
    }

    // 按下标查找元素
    printf("Testing GetElementByIndexInArrayList:\n");
    int element;
    if (GetElementByIndexInArrayList(list1, 2, &element)) {
        printf("Element at index 2: %d\n", element); // 应输出 Element at index 2: 2
    } else {
        printf("Failed to get element at index 2\n");
    }

    // 查找元素的最大值和最小值
    printf("Testing FindMaxInArrayList and FindMinInArrayList:\n");
    int max, min;
    FindMaxInArrayList(list1, &max);
    FindMinInArrayList(list1, &min);
    printf("Max element: %d\n", max); // 应输出 Max element: 100
    printf("Min element: %d\n", min); // 应输出 Min element: 1

    // 判断是否为空
    printf("Testing IsEmpty:\n");
    bool isEmpty1 = IsEmpty(list1);
    printf("Is list1 empty? %s\n", isEmpty1 ? "Yes" : "No"); // 应输出 Is list1 empty? No

    // 反转线性表
    printf("Testing ReverseArrayList:\n");
    ReverseArrayList(list1);
    printf("List1 after reverse: ");
    PrintArrayList(list1); // 应输出 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 5 4 3 2 1 100

    // 通过数组创建线性表并初始化
    printf("Testing CreateArrayListByArray:\n");
    ArrayList list2 = CreateArrayListByArray(arr, arrLength);
    printf("List2: ");
    PrintArrayList(list2); // 应输出 12 13 14 15 16 17 18 19 20 21

    // 测试自动扩容是否在新创建的线性表中生效
    printf("Testing automatic resizing in list2:\n");
    for (int i = 1; i <= 20; i++) {
        ArrayListAppend(list2, i);
    }
    printf("List2 after automatic resizing: ");
    PrintArrayList(list2); // 应输出 12 13 14 15 16 17 18 19 20 21 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20

    // 销毁线性表
    DestroyArrayList(list1);
    DestroyArrayList(list2);
}
