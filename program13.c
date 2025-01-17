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

Node* previous(Node* head, int data){
  Node* ptr = head;
  Node* ptr1 = head->next;
  while(ptr1 != NULL && ptr1->data < data){
      ptr = ptr->next;
      ptr1 = ptr1->next;
  }
  return ptr;
}

int main(){
  Node* head = createNode(0);
  Node* newnode, *curr;
  int data, size;
  printf("Enter No. of Elements you want to Insert : ");
  scanf("%d", &size);
  printf("Enter List Elements : ");
  for(int i = 0; i < size; i++){
      scanf("%d", &data);
      newnode = createNode(data);
      curr = previous(head, data);
      newnode->next = curr->next;
      curr->next = newnode;
  }

  printf("Linked List : ");
  printList(head);
  freeList(head);
  free(head);
}