#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
	int key;
}element;
typedef struct {
	element heap[MAX_SIZE];
	int heap_size;
} HeapType;

void init(HeapType* h)
{
	h->heap_size = 0;
}

void insert_max_heap(HeapType* h, element item)
{
	int i;
	i = ++(h->heap_size);

	// �ε����� 2�̻��� ��� �θ���� ���ϸ� ���� ����
	while ((i != 1) && (item.key > h->heap[i / 2].key))
	{
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}

	// �ݺ����� ���� ��쿡 ������ �ε����� ������ ����
	h->heap[i] = item;
}

element delete_max_heap(HeapType* h)
{
	int parent, child; // ���� ����� �ڽ� ���� �θ� ����� �ε���
	element item, temp; // 

	item = h->heap[1]; // ��Ʈ��� ����
	temp = h->heap[(h->heap_size)--]; // ��Ʈ ��忡 ������ ���� ������ ��� 
	parent = 1;
	child = 2;

	// �ڽĳ���� �ε����� ����� �������� ���� ���� �ݺ�
	while (child <= h->heap_size) {
		// �ڽĳ��� Ű���� ���Ѵ�.
		if ((child < h->heap_size) && (h->heap[child].key) < h->heap[child + 1].key) child++;
		// �θ��尡 �ڽĳ�庸�� ���� ū��� �����Ѵ�. 
		if (temp.key >= h->heap[child].key) break;

		// �θ��带 �ڽĳ��� ������
		h->heap[parent] = h->heap[child];
		// �θ��ε����� ������ �ڽ� �ε����� �ǰ� �ڽ��ε����� *2�� ���� ���� �ε����� �Ѿ��.
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}



void heap_sort(element a[], int n) {

	int i;
	HeapType h;

	init(&h);
	// �Ķ���ͷ� ���� �迭�� ������ŭ �ݺ��Ͽ� ���� ������ �����Ѵ�.
	for (i = 0; i < n; i++)
	{
		insert_max_heap(&h, a[i]);
	}

	//���� ���Ҹ� �����ϸ� �迭�� �����Ͽ� ������ �����Ѵ�.
	for (i = (n - 1); i >= 0; i--)
	{
		a[i] = delete_max_heap(&h);
	}
}

void insert_min_heap(HeapType* h, element item)
{
	int i;
	i = ++(h->heap_size);

	while ((i != 1) && (item.key < h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
}
element delete_min_heap(HeapType* h)
{
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;

	while (child <= h->heap_size) {

		if (child < h->heap_size && h->heap[child].key > h->heap[child + 1].key) child++;

		if (temp.key <= h->heap[child].key) break;

		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;

	}

	h->heap[parent] = temp;
	return item;
}

void main()
{
	element item; 
	HeapType h;
	element min_array[MAX_SIZE], max_array[MAX_SIZE];
	int num, choice;
	FILE* fp;
	fopen_s(&fp, "data2.txt", "r");

	h.heap_size = 0;

	printf("������ �����Ͻÿ�(�������� 1, �������� 2) :");
	scanf("%d", &choice);


	if (choice == 2) {

		while (fscanf(fp, "%d", &item.key) > 0) {
			insert_max_heap(&h, item);
		}

		int j = h.heap_size;
		for (int i = 0; i <= j - 1; i++)
		{
			max_array[i] = delete_max_heap(&h);
		}

		for (int i = 0; i <= j - 1; i++)
		{
			printf("%d ", max_array[i]);
		}

	}
	else {

		while (fscanf(fp, "%d", &item.key) > 0) {
			insert_min_heap(&h, item);
		}

	
		int j = h.heap_size;
		for (int i = 0; i <= j - 1; i++)
		{
			min_array[i] = delete_min_heap(&h);
		}

		for (int i = 0; i <= j - 1; i++)
		{
			printf("%d ", min_array[i]);
		}


	}
	


}