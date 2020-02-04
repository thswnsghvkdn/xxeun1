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
	int type; // 이벤트 종류
	int key; // 이벤트 발생 시간
	int number; // 손님수
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


//0 과 n사이의 정수 난수 생성 함수
int random(int n)
{
	// rand()가 RAND_MAX일 경우 n
	// 그 밑 부터 차례대로 정수가 몫으로 나온다.
	return (int)(n * rand() / (double)RAND_MAX);
}

// 자리가 가능하면 빈자리 수를 사람 수만큼 감소시킨다.
int is_seat_available(int number)
{
	printf("%d명 고객 입장\n", number);
	if (free_seats >= number) {
		free_seats -= number;
		return TRUE;
	}
	else {
		printf("자리가 없어서 퇴장\n");
		return FALSE;
	}
}

void order(int scoops) {
	printf("아이스크림 %d개 주문 받음\n", scoops);
	profit += 0.35 * scoops;
}

int leave(int number) {
	printf("%d명이 매장을 떠남\n", number);
	free_seats += number;
}

//이벤트 처리 과정
void process_event(HeapType* heap, element e) 
{
	int i = 0;
	element new_event; 
	// 이벤트 종류와 시간을 더해 히프에 업데이트 할 이벤트 구조체

	printf("현재 시간 = %d시\n", e.key);
	switch (e.type)
	{
	case ARRIVAL:
		// 주문 상태로 변경후 이벤트 발생시간을 난수를 더해 대입
		if (is_seat_available(e.number)) {
			new_event.type = ORDER;
			new_event.key = e.key + 1 + random(4);
			new_event.number = e.number;
			insert_min_heap(heap, new_event);
		}
		break;
	case ORDER:
		// 손님의 수 만큼 order 함수를 호출한다.
		for (i = 0; i < e.number; i++) {
			order(1 + random(3)); // 인수만큼 수익올림
		}
		new_event.type = LEAVE;
		new_event.key = e.key + 1 + random(10);
		new_event.number = e.number;
		insert_min_heap(heap, new_event);
		break;

	case LEAVE:
		leave(e.number); // 테이블 수 복구
		break;
	}
}

int main() {
	element event; 
	HeapType heap;
	unsigned int t = 0; // 초기 이벤트 생성을 위한 반복문 변수

	init(&heap);

	// 처음에 몇 개 초기 이벤트를 생성시킨다.
	while (t < 5)
	{
		// t에 난수를 더해가며 반복횟수를 정한다.
		t += random(6);

		// event 구조체에 상태를 도착, 도착시간을 t, 손님수를 난수로 설정한다.
		event.type = ARRIVAL;
		event.key = t;
		event.number = 1 + random(4);
		insert_min_heap(&heap, event);
	}

	// 들어온 팀이 모두 나갈 때 까지 반복
	while (!is_empty(&heap)) {
		event = delete_min_heap(&heap);
		process_event(&heap, event);
	}

	printf("전체 순이익은 = %f입니다.\n", profit);
}