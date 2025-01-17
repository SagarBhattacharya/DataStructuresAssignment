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

void swapKthNode(Node* head, int k){
  if(k > 0){
    Node* ptr1 = head;
    Node* ptr = head->next;
    for(int i = 1; i < k && ptr != NULL; i++){
        ptr1 = ptr1->next;
        ptr = ptr->next;
    }
    Node* ptr2 = ptr->next;
    if(ptr2 != NULL){
      Node* ptr3 = ptr2->next;
      ptr1->next = ptr2;
      ptr2->next = ptr;
      ptr->next = ptr3;
    }
  }
}

void main(){
  Node* head = createNode(0);
  printf("Enter elements for the linked list\n");
  createLinkedList(head);
  printf("Original list: ");
  printList(head);

  int k;
  printf("Enter the position of the node to swap with its next node: ");
  scanf("%d", &k);

  swapKthNode(head, k);
  printf("List after swapping: ");
  printList(head);

  freeList(head);
  free(head);
}