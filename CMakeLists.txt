cmake_minimum_required(VERSION 3.25)
project(study C)

set(CMAKE_C_STANDARD 11)

add_executable(study sort.c sort.h test.c ArrayList.c ArrayList.h LinkList.c LinkList.h)
