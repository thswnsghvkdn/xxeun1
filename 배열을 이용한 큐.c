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
		child * 2;
	}
	h->heap[parent] = temp;
	return item;
}



void heap_sort(element a[], int n){

	int i;
	HeapType h;

	init(&h);
	// 파라미터로 들어온 배열의 갯수만큼 반복하여 힙의 삽입을 진행한다.
	for (i = 0; i < n; i++)
	{
		insert_max_heap(&h,a[i]);
	}

	//힙의 원소를 삭제하며 배열에 삽입하여 정렬을 진행한다.
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