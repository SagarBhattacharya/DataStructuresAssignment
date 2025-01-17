#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
} Node;

Node* createNode(int data) {
    Node *newNode = (Node*) calloc(1, sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
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

void printList(Node* head) {
  for (Node* curr = head->next; curr; curr = curr->next) {
    printf("%d ", curr->data);
  }
  printf("\n");
}

void createLinkedList(Node* head){
    Node* newnode, *curr = head;
    int data, size;
    printf("Enter No. of Elements you want to Insert : ");
    scanf("%d", &size);
    printf("Enter List Elements : ");
    for(int i = 0; i < size; i++){
        scanf("%d", &data);
        newnode = createNode(data);
        newnode->prev = curr;
        curr->next = newnode;
        curr = newnode;
    }
}

void deleteAtPosition(Node* head, int pos){
    Node* curr = head;
    for(int i = 0; i < pos && curr != NULL; i++){
        curr = curr->next;
    }
    if (curr != NULL) {
      curr->prev->next = curr->next;
      if (curr->next != NULL) {
        curr->next->prev = curr->prev;
      }
      free(curr);
    }
}

void main(){
  Node* head = createNode(0);

  printf("Enter elements to create linked list\n");
  createLinkedList(head);
  printf("Original List: ");
  printList(head);

  int pos;
  printf("Enter position to delete: ");
  scanf("%d", &pos);

  deleteAtPosition(head, pos);
  printf("List after deletion: ");
  printList(head);

  freeList(head);
  free(head);
}