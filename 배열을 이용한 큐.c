#include <stdio.h>
#define MAX_ELEMENT 200
typedef struct {
	int key;
}element;
typedef struct {
	element heap[MAX_ELEMENT];
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
		child * 2;
	}
	h->heap[parent] = temp;
	return item;
}



void heap_sort(element a[], int n){

	int i;
	HeapType h;

	init(&h);
	// �Ķ���ͷ� ���� �迭�� ������ŭ �ݺ��Ͽ� ���� ������ �����Ѵ�.
	for (i = 0; i < n; i++)
	{
		insert_max_heap(&h,a[i]);
	}

	//���� ���Ҹ� �����ϸ� �迭�� �����Ͽ� ������ �����Ѵ�.
	for (i = (n - 1); i >= 0; i--)
	{
		a[i] = delete_max_heap(&h);
	}
}

void main()
{
	element e1 = { 10 }, e2 = { 5 }, e3 = { 30 };
	element e4, e5, e6;
	HeapType heap;
	init(&heap);

	insert_max_heap(&heap, e1);
	insert_max_heap(&heap, e2);
	insert_max_heap(&heap, e3);
	
	e4 = delete_max_heap(&heap);
	printf("< %d >", e4.key);
	e5 = delete_max_heap(&heap);
	printf("< %d >", e5.key);
	e6 = delete_max_heap(&heap);
	printf("< %d >", e6.key);

}