#include <stdio.h>
#define MAX 10

typedef struct queue {
  int front;
  int rear;
  int array[MAX];
} Queue;

void init(Queue *q) {
  q->front = q->rear = -1;
}

void enqueue(Queue* q, int data){
  if((q->rear + 1) % MAX == q->front){
    printf("Queue is full\n");
    return;
  }
  if(q->front == -1) q->front = 0;
  q->rear = (q->rear + 1) % MAX;
  q->array[q->rear] = data;
}

int dequeue(Queue* q){
  if(q->front == -1){
    printf("Queue is empty\n");
    return -1;
  }
  int data = q->array[q->front];
  if(q->front == q->rear) q->front = q->rear = -1;
  else q->front = (q->front + 1) % MAX;
  return data;
}

void display(Queue* q){
  if(q->front == -1){
    printf("Queue is empty\n");
    return;
  }
  int i = q->front;
  do{
    printf("%d ", q->array[i]);
    i = (i + 1) % MAX;
  }while(i != (q->rear + 1) % MAX);
}

int main(){
  Queue q;
  int choice, data;

  init(&q);

  while(1) {
    printf("\nMenu:\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        printf("Enter data to enqueue: ");
        scanf("%d", &data);
        enqueue(&q, data);
        break;
      case 2:
        data = dequeue(&q);
        if(data != -1) {
          printf("Dequeued data: %d\n", data);
        }
        break;
      case 3:
        display(&q);
        break;
      case 4:
        return 0;
      default:
        printf("Invalid choice, please try again.\n");
    }
  }
  return 0;
}