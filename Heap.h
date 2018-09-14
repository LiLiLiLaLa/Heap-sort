#pragma once

#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <stdlib.h>

#define ADD_SIZE 5//��������

typedef int HPDataType;

typedef struct Heap
{
	HPDataType* _a;//���Ԫ�ص�����
	int _size;//����Ԫ�ظ���
	int _capacity;//����ռ�
}Heap;

void HeapInit(Heap* hp, HPDataType* a, int n);//��ʼ��
void HeapDestory(Heap* hp);//����
void HeapPush(Heap* hp, HPDataType x);//���Ԫ��
void HeapPop(Heap* hp);//�������ڵ�Ԫ��
HPDataType HeapTop(const Heap* hp);//���ڵ�Ԫ��
int HeapSize(const Heap* hp);//����Ԫ�ض���
int HeapEmpty(const Heap* hp);//�п�
void HeapSort(HPDataType* a, int n);//������

void TestHeap();