#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} Node;

Node* createNode(int data) {
  Node* n = (Node*) calloc(1, sizeof(Node));
  n->data = data;
  n->next = NULL;
  return n;
}

void createLinkedList(Node* head) {
  int n, data;
  Node* curr = head;
  printf("Enter number of elements: ");
  scanf("%d", &n);
  if(n % 2 != 0){
    printf("ERROR : List size must be even\n");
    return;
  }
  printf("Enter list elements: ");
  for (int i = 0; i < n; i++) {
    scanf("%d", &data);
    curr->next = createNode(data);
    curr = curr->next;
  }
}

void printList(Node* head) {
  for (Node* curr = head->next; curr; curr = curr->next) {
    printf("%d ", curr->data);
  }
  printf("\n");
}

void freeList(Node* head) {
  Node* current = head->next;
  while (current) {
    Node* temp = current;
    current = current->next;
    free(temp);
  }
  head->next = NULL;
}

void interchangeOddEven(Node* head){
    Node* ptr = head;
    while(ptr->next != NULL){
        Node* ptr1 = ptr->next;
        Node* ptr2 = ptr1->next;
        Node* ptr3 = ptr2->next;

        ptr->next = ptr2;
        ptr2->next = ptr1;
        ptr1->next = ptr3;

        ptr = ptr1;
    }
}

void main(){
  Node* head = createNode(0);
  printf("Enter list elements in even number \n");
  createLinkedList(head);
  printf("Original list: ");
  printList(head);
  
  interchangeOddEven(head);
  printf("Modified list: ");
  printList(head);
  
  freeList(head);
  free(head);
}