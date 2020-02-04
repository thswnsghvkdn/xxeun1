#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define null NULL

typedef struct {
	int key;
	char name[100];
	char command;
	int index;
}element;

typedef struct HeapType {
	element heap[100];
	int heap_size;
}HeapType;

void init(HeapType* h);
void insert_min_heap(HeapType* h, element item);
element delete_min_heap(HeapType* h);

void inorder(HeapType root, int index) 
{
	
	if (index <= root.heap_size) {
		inorder(root, index * 2);
		printf("%d %s", index, root.heap[index].name);
		inorder(root , index * 2 + 1);
	}
}

int main()
{
	int key = 0;
	HeapType h;
	element e;
	FILE* fp;
	fp = fopen("data1.txt", "r");

	init(&h);

	while (fscanf(fp, "%c", &e.command) > 0)
	{
		switch (e.command) {
		case 'i':
			key++;
			e.key = key;
			fgets(e.name, 100, fp);

			printf("\n>>손님 입장 : %s ", e.name);
			printf("<<히프 중위 순회 출력>>\n\n");

			insert_min_heap(&h, e);
			inorder(h, 1);
			break;

		case 'o':
			e = delete_min_heap(&h);
			printf("\n>>손님 퇴장 :%s ", e.name);
			printf("<<히프 중위 순회 출력>>\n\n");
			inorder(h, 1);
			break;
		}
	}



}

void init(HeapType* h)
{
	h->heap_size = 0;
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
	h->heap[i].index = i;
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