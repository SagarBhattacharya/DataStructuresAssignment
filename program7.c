#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int data;
  struct node *next;
} Node;

Node* createNode(int data){
  Node* n = (Node*) calloc(1, sizeof(Node));
  n->data = data;
  n->next = NULL;
  return n;
}

void insertAfter(Node* head, int data, int pos){
  Node* current = head;
  Node* newNode = createNode(data);
  for(int i = 0; i < pos && current != NULL; i++){
    current = current->next;
  }
  if(current != NULL){
    newNode->next = current->next;
    current->next = newNode;
  }else printf("Invalid position to insert after!\n");
}

int countNodes(Node* head){
  int count = 0;
  for(Node* current = head->next; current != NULL; current = current->next) count++;
  return count;
}

void deleteAt(Node* head, int pos){
  if (pos > 0) {
    Node* current = head;

    for(int i = 1; i < pos && current->next != NULL; i++){
      current = current->next;
    }

    if(current->next != NULL){
      Node* temp = current->next;
      current->next = temp->next;
      free(temp);
    }else printf("Invalid position to delete!\n");
  }
}

void deleteEnd(Node* head){
  deleteAt(head, countNodes(head));
}

void freeList(Node* head){
  Node* current = head->next;
  while(current != NULL){
    Node* temp = current;
    current = current->next;
    free(temp);
  }
  head->next = NULL;
}

void separateIntoOddEven(Node* head, Node* odd, Node* even){
  freeList(odd);
  freeList(even);
  int oddCount = 0, evenCount = 0;
  for(Node* current = head->next; current != NULL; current = current->next){
    if(current->data % 2 == 0){
      insertAfter(even, current->data, evenCount);
      evenCount++;
    } else {
      insertAfter(odd, current->data, oddCount);
      oddCount++;
    }
  }
}

void printList(Node* head){
  Node* current = head->next;
  while(current != NULL){
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

void collectMemory(Node* head, Node* even, Node* odd){
  freeList(head);
  freeList(odd);
  freeList(even);
  free(head);
  free(odd);
  free(even);
}

int main(){
  Node* head = createNode(0);
  Node* odd = createNode(0);
  Node* even = createNode(0);
  int choice, data, pos;

  while(1) {
    printf("\nMenu:\n");
    printf("1. Insert After\n");
    printf("2. Delete At\n");
    printf("3. Delete End\n");
    printf("4. Separate Into Odd and Even\n");
    printf("5. Print List\n");
    printf("6. Print Odd List\n");
    printf("7. Print Even List\n");
    printf("8. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        printf("Enter data to insert: ");
        scanf("%d", &data);
        printf("Enter position to insert after: ");
        scanf("%d", &pos);
        insertAfter(head, data, pos);
        break;
      case 2:
        printf("Enter position to delete: ");
        scanf("%d", &pos);
        deleteAt(head, pos);
        break;
      case 3:
        deleteEnd(head);
        break;
      case 4:
        separateIntoOddEven(head, odd, even);
        break;
      case 5:
        printf("List: ");
        printList(head);
        break;
      case 6:
        printf("Odd List: ");
        printList(odd);
        break;
      case 7:
        printf("Even List: ");
        printList(even);
        break;
      case 8:
        collectMemory(head, odd, even);
        exit(0);
      default:
        printf("Invalid choice!\n");
    }
  }
  collectMemory(head, odd, even);
}