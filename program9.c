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

void insertFront(Node* head, int data){
  Node* newnode = createNode(data);
  newnode->next = head->next;
  head->next = newnode;
}

void reverse(Node* rhead, Node* head){
  for(Node* ptr = head->next; ptr; ptr = ptr->next)
    insertFront(rhead, ptr->data);
}

int main() {
  Node* head = createNode(0);
  Node* rhead = createNode(0);

  printf("Enter elements for the linked list\n");
  createLinkedList(head);
  printf("Original list: ");
  printList(head);

  reverse(rhead, head);
  printf("Reversed list: ");
  printList(rhead);

  freeList(head);
  freeList(rhead);
  free(head);
  free(rhead);

  return 0;
}