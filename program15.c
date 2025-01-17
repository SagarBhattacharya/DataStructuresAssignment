#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(Node* top, int data){
    Node *newNode = createNode(data);
    newNode->next = top->next;
    top->next = newNode;
}

int pop(Node* top){
    if(top->next == NULL){
        printf("Stack is empty\n");
        return -1;
    }
    Node *temp = top->next;
    int data = temp->data;
    top->next = temp->next;
    free(temp);
    return data;
}

void display(Node* top){
    Node *temp = top->next;
    printf("Stack: TOP [ ");
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("]\n");
}

void freeStack(Node* top){
    Node *temp = top->next;
    while(temp != NULL){
        Node *next = temp->next;
        free(temp);
        temp = next;
    }
    top->next = NULL;
}

int main(){
  Node *top = createNode(0);
  int choice, value;

  do {
    printf("\nMenu:\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Display\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter value to push: ");
        scanf("%d", &value);
        push(top, value);
        break;
      case 2:
        value = pop(top);
        if (value != -1) {
          printf("Popped value: %d\n", value);
        }
        break;
      case 3:
        display(top);
        break;
      case 4:
        freeStack(top);
        printf("Exiting...\n");
        break;
      default:
        printf("Invalid choice. Please try again.\n");
    }
  } while (choice != 4);

  free(top);
}