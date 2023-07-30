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