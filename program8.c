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

void insert(Node* head, int data) {
  Node* curr = head;
  while (curr->next) curr = curr->next;
  curr->next = createNode(data);
}

Node* search(Node* head, int data) {
  for (Node* curr = head->next; curr; curr = curr->next) {
    if (curr->data == data) return curr;
  }
  return NULL;
}

void unionList(Node* uhead, Node* head1, Node* head2) {
  for (Node* h1 = head1->next; h1; h1 = h1->next) {
    if (!search(uhead, h1->data)) insert(uhead, h1->data);
  }
  for (Node* h2 = head2->next; h2; h2 = h2->next) {
    if (!search(uhead, h2->data)) insert(uhead, h2->data);
  }
}

void intersectionList(Node* ihead, Node* head1, Node* head2) {
  for (Node* h1 = head1->next; h1; h1 = h1->next) {
    if (search(head2, h1->data)) insert(ihead, h1->data);
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

int main() {
  Node* head1 = createNode(0);
  Node* head2 = createNode(0);
  Node* uhead = createNode(0);
  Node* ihead = createNode(0);

  printf("Create first linked list:\n");
  createLinkedList(head1);
  printf("Create second linked list:\n");
  createLinkedList(head2);

  unionList(uhead, head1, head2);
  printf("Union of the two lists: ");
  printList(uhead);

  intersectionList(ihead, head1, head2);
  printf("Intersection of the two lists: ");
  printList(ihead);

  freeList(head1);
  freeList(head2);
  freeList(uhead);
  freeList(ihead);
  free(head1);
  free(head2);
  free(uhead);
  free(ihead);

  return 0;
}