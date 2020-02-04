#include <stdio.h>

typedef struct TreeNode{
	int key;
	char name[100];
}element;

typedef struct {
	element heap[100];
	int heap_size;
}HeapType;

void init(HeapType* h);
void insert_max_heap(HeapType* h, element item);
element delete_max_heap(HeapType* h);


void init(HeapType* h) {
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

element delete_max_heap(HeapType* h) {
	int p = 1, c = 2;
	element item = h->heap[h->heap_size];
	element tmp = h->heap[1];

	while (c <= h->heap_size)
	{
		if (h->heap[c].key < h->heap[c + 1].key) c++;
		if (h->heap[p].key > h->heap[c].key)  break;

		h->heap[p] = h->heap[c];
		p = c;
		c *= 2;

	}

	h->heap[p] = tmp;
	return item;

}

int main() {
	char f_char[100]; // ������ ����
	int f_number;// ������ ����
	int count ; // ������ �������� �������� ��
	HeapType h; 
	element e;
	FILE* fp;
	fp = fopen( "data.txt", "r");
	
	if (fp == NULL) exit(1);
	init(&h);

	// ���Ͽ��� �켱������ �����̸��� �����´�.
	while (fscanf(fp, "%d %s", &e.key, e.name) > 0)
	{
		
		printf(">>%d %s\n", e.key, e.name);
		insert_max_heap(&h, e);

		for (int i = 1; i <= h.heap_size; i++) {
			printf("%d %s >", h.heap[i].key, h.heap[i].name);
		}
		printf("\n");
	}


	// ����ڿ��� ���� �켱������ �����̸��� ������ �߰� ��Ų �Ŀ� ����Ѵ�.
	while (1) {
		printf("������ �����͸� ���� ������ �켱������ �̸��� �Է��Ͻÿ�(�Ϸ�� �켱���� 0)");
		printf("\n>>");
		scanf("%d %s", &e.key, e.name); if (e.key == 0) break;
		insert_max_heap(&h, e);
		
		for (int i = 1; i <= h.heap_size; i++) {
			printf("%d %s >", h.heap[i].key, h.heap[i].name);
		}
		printf("\n");
	}

}