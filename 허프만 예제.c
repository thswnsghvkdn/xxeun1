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

	// 인덱스가 2이상인 경우 부모노드와 비교하며 삽입 진행
	while ((i != 1) && (item.key > h->heap[i / 2].key))
	{
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}

	// 반복문이 끝난 경우에 지정된 인덱스로 아이템 삽입
	h->heap[i] = item;
}

element delete_max_heap(HeapType* h)
{
	int parent, child; // 비교할 대상인 자식 노드와 부모 노드의 인덱스
	element item, temp; // 

	item = h->heap[1]; // 루트노드 대입
	temp = h->heap[(h->heap_size)--]; // 루트 노드에 대입할 가장 마지막 노드 
	parent = 1;
	child = 2;

	// 자식노드의 인덱스가 노드의 개수보다 작을 동안 반복
	while (child <= h->heap_size) {
		// 자식끼리 키값을 비교한다.
		if ((child < h->heap_size) && (h->heap[child].key) < h->heap[child + 1].key) child++;
		// 부모노드가 자식노드보다 값이 큰경우 종료한다. 
		if (temp.key >= h->heap[child].key) break;

		// 부모노드를 자식노드로 내린다
		h->heap[parent] = h->heap[child];
		// 부모인덱스는 이전의 자식 인덱스가 되고 자식인덱스는 *2를 통해 다음 인덱스로 넘어간다.
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
	// 파라미터로 들어온 배열의 갯수만큼 반복하여 힙의 삽입을 진행한다.
	for (i = 0; i < n; i++)
	{
		insert_max_heap(&h, a[i]);
	}

	//힙의 원소를 삭제하며 배열에 삽입하여 정렬을 진행한다.
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

	printf("정렬을 선택하시오(오름차순 1, 내림차순 2) :");
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