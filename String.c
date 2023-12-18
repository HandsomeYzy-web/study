//
// Created by yzy20 on 2023/11/22.
//

#include "String.h"

void initString(String* str, const char* initial) {
    int len = 0;
    while(initial[len] != '\0') {
        len++;
    }
    if(len != 0) {
        str->data = (char *) malloc(sizeof (char) * (len + 1));
        str->length = len;
        for(int i = 0; i < len; i++) {
            str->data[i] = initial[i];
        }
        str->data[len] = '\0';
    } else {
        printf("Invalid input!");
    }
}

int strLength(String* str) {
    return str->length;
}

void printString(String* str) {
    printf("%s\n", str->data);
}

String* concatString(String* str1, String* str2) {
    int newLength = str1->length + str2->length;
    String* newString = (String*) malloc(sizeof (String));
    newString->length = newLength;
    newString->data = (char*) malloc(sizeof (char) * (newLength + 1));
    int currentLength = 0;
    for(int i = 0; i < str1->length; i++) {
        newString->data[currentLength] = str1->data[i];
        currentLength++;
    }
    for(int i = 0; i < str2->length; i++) {
        newString->data[currentLength] = str2->data[i];
        currentLength++;
    }
    newString->data[currentLength] = '\0';
    return newString;
}

String* subString(String* str, int start, int length) {
    if(start < 0 || (start + length - 1) > str->length || length <= 0) {
        printf("Invalid input!");
        return NULL;
    }
    String* newString = (String*) malloc(sizeof (String));
    newString->length = length;
    newString->data = (char*) malloc(sizeof (char) * (length + 1));
    for(int i = 0; i < length; i++) {
        newString->data[i] = str->data[i + start];
    }
    newString->data[length] = '\0';
    return newString;
}

int compareString(String* str1, String* str2) {
    int position = 0;
    while(str1->data[position] != '\0' && str2->data[position] != '\0') {
        if(str1->data[position] != str2->data[position]) {
            return str1->data[position] - str2->data[position];
        }
        position++;
    }
    return str1->data[position] - str2->data[position];
}

void copyString(String* str1, String* str2) {
    int len = str2->length;
    str1->data = (char*) malloc(sizeof (char) * (len + 1));
    str1->length = len;
    for (int i = 0; i < len; i++) {
        str1->data[i] = str2->data[i];
    }
    str1->data[len] = '\0';
}