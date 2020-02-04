#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define ARRIVAL 1
#define ORDER 2
#define LEAVE 3

int free_seats = 10;
double profit = 0.0;

#define MAX_ELEMENT 100

typedef struct {
	int type; // �̺�Ʈ ����
	int key; // �̺�Ʈ �߻� �ð�
	int number; // �մԼ�
} element;

typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;


void init(HeapType* h)
{
	h->heap_size = 0;

}
int is_empty(HeapType* h)
{
	if (h->heap_size == 0)
		return TRUE;
	else return FALSE;
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
		
		if ( child < h->heap_size && h->heap[child].key > h->heap[child + 1].key) child++;

		if ( temp.key <= h->heap[child].key ) break;

		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	
	}
	
	h->heap[parent] = temp;
	return item;
}


//0 �� n������ ���� ���� ���� �Լ�
int random(int n)
{
	// rand()�� RAND_MAX�� ��� n
	// �� �� ���� ���ʴ�� ������ ������ ���´�.
	return (int)(n * rand() / (double)RAND_MAX);
}

// �ڸ��� �����ϸ� ���ڸ� ���� ��� ����ŭ ���ҽ�Ų��.
int is_seat_available(int number)
{
	printf("%d�� �� ����\n", number);
	if (free_seats >= number) {
		free_seats -= number;
		return TRUE;
	}
	else {
		printf("�ڸ��� ��� ����\n");
		return FALSE;
	}
}

void order(int scoops) {
	printf("���̽�ũ�� %d�� �ֹ� ����\n", scoops);
	profit += 0.35 * scoops;
}

int leave(int number) {
	printf("%d���� ������ ����\n", number);
	free_seats += number;
}

//�̺�Ʈ ó�� ����
void process_event(HeapType* heap, element e) 
{
	int i = 0;
	element new_event; 
	// �̺�Ʈ ������ �ð��� ���� ������ ������Ʈ �� �̺�Ʈ ����ü

	printf("���� �ð� = %d��\n", e.key);
	switch (e.type)
	{
	case ARRIVAL:
		// �ֹ� ���·� ������ �̺�Ʈ �߻��ð��� ������ ���� ����
		if (is_seat_available(e.number)) {
			new_event.type = ORDER;
			new_event.key = e.key + 1 + random(4);
			new_event.number = e.number;
			insert_min_heap(heap, new_event);
		}
		break;
	case ORDER:
		// �մ��� �� ��ŭ order �Լ��� ȣ���Ѵ�.
		for (i = 0; i < e.number; i++) {
			order(1 + random(3)); // �μ���ŭ ���Ϳø�
		}
		new_event.type = LEAVE;
		new_event.key = e.key + 1 + random(10);
		new_event.number = e.number;
		insert_min_heap(heap, new_event);
		break;

	case LEAVE:
		leave(e.number); // ���̺� �� ����
		break;
	}
}

int main() {
	element event; 
	HeapType heap;
	unsigned int t = 0; // �ʱ� �̺�Ʈ ������ ���� �ݺ��� ����

	init(&heap);

	// ó���� �� �� �ʱ� �̺�Ʈ�� ������Ų��.
	while (t < 5)
	{
		// t�� ������ ���ذ��� �ݺ�Ƚ���� ���Ѵ�.
		t += random(6);

		// event ����ü�� ���¸� ����, �����ð��� t, �մԼ��� ������ �����Ѵ�.
		event.type = ARRIVAL;
		event.key = t;
		event.number = 1 + random(4);
		insert_min_heap(&heap, event);
	}

	// ���� ���� ��� ���� �� ���� �ݺ�
	while (!is_empty(&heap)) {
		event = delete_min_heap(&heap);
		process_event(&heap, event);
	}

	printf("��ü �������� = %f�Դϴ�.\n", profit);
}