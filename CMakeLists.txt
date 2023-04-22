cmake_minimum_required(VERSION 3.25)
project(C C)

set(CMAKE_C_STANDARD 11)

include_directories(数据结构/二叉树/整体)

add_executable(C
        数据结构/二叉树/Demo/Demo01.c
        数据结构/二叉树/Demo/二叉树练习.c
        数据结构/二叉树/Demo/完整二叉树.c
        数据结构/二叉树/整体/Btree.c
        数据结构/二叉树/整体/Btree.h
        数据结构/二叉树/整体/test.c
        数据结构/二叉树作业/作业.c
        数据结构/二叉树作业/判断满二叉树.c
        算法/冒泡排序.c
        算法/插入排序.c)
