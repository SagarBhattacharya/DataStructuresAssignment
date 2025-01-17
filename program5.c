#include <stdio.h>
#include <limits.h>
#define MAX 10

typedef struct queue {
  int front;
  int rear;
  int array[MAX];
} Queue;

void enqueue(Queue *q, int data) {
  if (q->rear == MAX - 1) {
    printf("Queue is full\n");
    return;
  }
  if(q->front == -1) {
    q->front = 0;
  }
  q->array[++q->rear] = data;
}

int dequeue(Queue *q) {
  if(q->front == -1) {
    printf("Queue is empty\n");
    return INT_MIN;
  }
  int data = q->array[q->front];
  if(q->front == q->rear) {
    q->front = q->rear = -1;
    return data;
  }
  q->front++;
  return data;
}

void display(Queue *q) {
  if (q->front == -1) {
    printf("Queue is empty\n");
    return;
  }
  printf("Queue: FRONT [ ");
  for (int i = q->front; i <= q->rear; i++) {
    printf("%d ", q->array[i]);
  }
  printf("] REAR\n");
}

int main() {
  Queue q;
  q.front = -1;
  q.rear = -1;
  int choice, data;
  while (1) {
    printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        printf("Enter data: ");
        scanf("%d", &data);
        enqueue(&q, data);
        break;
      case 2:
        data = dequeue(&q);
        if (data != INT_MIN) {
          printf("Dequeued element: %d\n", data);
        }
        break;
      case 3:
        display(&q);
        break;
      case 4:
        return 0;
      default:
        printf("Invalid choice\n");
    }
  }
  return 0;
}