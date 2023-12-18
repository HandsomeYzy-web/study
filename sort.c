//
// Created by yzy on 2023/7/27.
//

#include "sort.h"

void bubble_sort(int arr[], int length) {
    int isSort = 1;
    for (int i = 0; i < length - 1; i++) {
        isSort = 1;
        for (int j = 0; j < length - 1 - i; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = 0;
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                isSort = 0;
            }
        }
        if (isSort == 1) {
            break;
        }
    }
}

void quick_sort(int* arr, int left, int right) {
    if(left >= right) {
        return;
    }
    int key = arr[left];
    int i = left;
    int j = right;
    while (i < j) {
        while (i < j && arr[j] >= key) {
            j--;
        }
        while (i < j && arr[i] <= key) {
            i++;
        }
        if(i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    arr[left] = arr[i];
    arr[i] = key;
    quick_sort(arr, left, i - 1);
    quick_sort(arr, j + 1, right);
}