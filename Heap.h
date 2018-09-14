#pragma once

#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <stdlib.h>

#define ADD_SIZE 5//增长因数

typedef int HPDataType;

typedef struct Heap
{
	HPDataType* _a;//存放元素的数组
	int _size;//存入元素个数
	int _capacity;//数组空间
}Heap;

void HeapInit(Heap* hp, HPDataType* a, int n);//初始化
void HeapDestory(Heap* hp);//销毁
void HeapPush(Heap* hp, HPDataType x);//添加元素
void HeapPop(Heap* hp);//弹出根节点元素
HPDataType HeapTop(const Heap* hp);//根节点元素
int HeapSize(const Heap* hp);//存入元素多少
int HeapEmpty(const Heap* hp);//判空
void HeapSort(HPDataType* a, int n);//堆排序

void TestHeap();