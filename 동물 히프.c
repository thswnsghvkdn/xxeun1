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

	// 인덱스가 2이상인 경우 부모노드와 비교하며 삽입 진행
	while ((i != 1) && (item.key > h->heap[i / 2].key))
	{
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}

	// 반복문이 끝난 경우에 지정된 인덱스로 아이템 삽입
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
	char f_char[100]; // 파일의 문자
	int f_number;// 파일의 숫자
	int count ; // 파일이 가져오는 데이터의 수
	HeapType h; 
	element e;
	FILE* fp;
	fp = fopen( "data.txt", "r");
	
	if (fp == NULL) exit(1);
	init(&h);

	// 파일에서 우선순위와 동물이름을 가져온다.
	while (fscanf(fp, "%d %s", &e.key, e.name) > 0)
	{
		
		printf(">>%d %s\n", e.key, e.name);
		insert_max_heap(&h, e);

		for (int i = 1; i <= h.heap_size; i++) {
			printf("%d %s >", h.heap[i].key, h.heap[i].name);
		}
		printf("\n");
	}


	// 사용자에게 받은 우선순위와 동물이름을 히프에 추가 시킨 후에 출력한다.
	while (1) {
		printf("히프에 데이터를 넣을 동물의 우선순위와 이름을 입력하시오(완료시 우선순위 0)");
		printf("\n>>");
		scanf("%d %s", &e.key, e.name); if (e.key == 0) break;
		insert_max_heap(&h, e);
		
		for (int i = 1; i <= h.heap_size; i++) {
			printf("%d %s >", h.heap[i].key, h.heap[i].name);
		}
		printf("\n");
	}

}