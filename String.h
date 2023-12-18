//
// Created by yzy20 on 2023/11/22.
//

#ifndef STUDY_STRING_H
#define STUDY_STRING_H

#endif //STUDY_STRING_H
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    char *data;
    int length;
} String;

// 初始化串
void initString(String* str, const char* initial);
// 获取字符串长度
int strLength(String* str);
// 打印字符串
void printString(String* str);
// 连接两个字符串
String* concatString(String* str1, String* str2);
// 分割字符串
String* subString(String* str, int start, int length);
// 字符串比较
int compareString(String* str1, String* str2);
// 复制字符串
void copyString(String* str1, String* str2);