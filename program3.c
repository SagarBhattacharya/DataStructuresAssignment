#include <stdio.h>
#include <limits.h>
#define MAX 10

typedef struct stack {
  int top;
  int items[MAX];
} Stack;

void push(Stack *s, int item){
  if (s->top == MAX - 1) {
    printf("Stack overflow\n");
  } else {
    s->items[++s->top] = item;
  }
}

int pop(Stack *s){
  if (s->top == -1) {
    printf("Stack underflow\n");
    return INT_MIN;
  } else {
    return s->items[s->top--];
  }
}

void display(Stack *s){
  if (s->top == -1) {
    printf("Stack is empty\n");
  } else {
    printf("Stack elements : [ ");
    for(int i=0; i<=s->top; i++){
      printf("%d ", s->items[i]);
    }
    printf("] TOP\n");
  }
}

int main(){
  Stack s;
  s.top = -1;
  int choice, item;
  while(1){
    printf("Menu\n1. push\n2. pop\n3. display\n4. exit\nEnter choice: ");
    scanf("%d", &choice);
    switch(choice){
      case 1:
        printf("Enter element to push : ");
        scanf("%d", &item);
        push(&s, item);
        break;
      case 2:
        item = pop(&s);
        if(item != INT_MIN){
          printf("Popped element : %d\n", item);
        }
        break;
      case 3:
        display(&s);
        break;
      case 4:
        return 0;
      default:
        printf("Invalid choice\n");
    }
  }
}