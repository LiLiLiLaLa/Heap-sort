#include "Heap.h"

static void Swap(HPDataType* a1, HPDataType* a2)
{
	HPDataType a3 = *a1;
	assert(a1&&a2);
	*a1 = *a2;
	*a2 = a3;
}

static void AdjustUp(HPDataType* a, int size, int child)
{
	int parent = (child - 1) / 2;
	assert(a);
	while (child > 0)
	{
		if (a[parent] < a[child])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

static void AdjustDown(HPDataType* a, int size, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	assert(a);
	while (child < size)
	{
		if ((child + 1 < size) && (a[child + 1] > a[child]))
		{
			child++;
		}
		if (a[child]>a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

static void PrintHeap(const Heap* hp)
{
	int i = 0;
	assert(hp);
	for (i = 0; i < hp->_size; i++)
	{
		printf("%d ", hp->_a[i]);
	}
		printf("\n");
}

void HeapInit(Heap* hp, HPDataType* a, int n)
{
	int i = 0; 
	assert(hp&&a);
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType)*n);
	hp->_capacity = n;
	hp->_size = n;
	for (i = 0; i < n; i++)
	{
		hp->_a[i] = a[i];
	}
	for (i = (n - 2) / 2; i >= 0; i--)//找最后一个叶子节点的双亲结点
	{
		AdjustDown(hp->_a, hp->_size, i);
	}
}

void HeapDestory(Heap* hp)
{
	assert(hp);
	free(hp->_a);
	hp->_a = NULL;
	hp->_capacity = hp->_size = 0;
}

void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp);
	if (hp->_capacity == hp->_size)//需要扩容
	{
		hp->_a = (HPDataType*)realloc(hp->_a, sizeof(HPDataType)*(hp->_capacity + ADD_SIZE));
		assert(hp->_a);//可能扩容失败，扩容失败返回空指针
		hp->_capacity += ADD_SIZE;
	}
	(hp->_size)++;
	hp->_a[hp->_size - 1] = x;
	AdjustUp(hp->_a, hp->_size, hp->_size - 1);//第三个参数表示开始向上调整的下标
}

void HeapPop(Heap* hp)
{
	assert(hp);
	Swap(&hp->_a[0], &hp->_a[hp->_size - 1]);
	hp->_size--;
	AdjustDown(hp->_a, hp->_size, 0);
}

HPDataType HeapTop(const Heap* hp)
{
	assert(hp);
	return hp->_a[0];
}

int HeapSize(const Heap* hp)
{
	assert(hp);
	return hp->_size;
}

int HeapEmpty(const Heap* hp)
{
	assert(hp);
	return hp->_size == 0 ? 0 : 1;
}

void HeapSort(HPDataType* a, int n)
{
	int end = n - 1;
	int i = 0;
	assert(a);
	//建堆
	for (i = (n - 2) / 2; i >= 0; --i)
	{
		AdjustDown(a, end, i);
	}
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		end--;
	}
}

void TestHeap()
{
	Heap hp;
	int a[] = { 53, 17, 78, 9, 45, 65, 87, 23, 31 };
	//HeapInit(&hp, a, sizeof(a) / sizeof(a[0]));
	//PrintHeap(&hp);
	//HeapDestory(&hp);
	//PrintHeap(&hp);
	HeapSort(a, sizeof(a) / sizeof(a[0]));
	/*HeapPush(&hp, 100);
	PrintHeap(&hp);
	HeapPop(&hp);*/
	PrintHeap(&hp);
}