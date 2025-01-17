#include <stdio.h>
#include <stdlib.h>

typedef struct pn {
  int coef;
  int exp;
  struct pn *next;
} Node;

Node* createNode(int coef, int exp) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->coef = coef;
  newNode->exp = exp;
  newNode->next = NULL;
  return newNode;
}

void insert(Node* head, int coef, int exp) {
  Node *newNode = createNode(coef, exp);
  if(head->next == NULL) {
    head->next = newNode;
  } else {
    Node *temp = head->next;
    while(temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = newNode;
  }
}

void createPolynomial(Node* head) {
  int coef, exp, size;

  printf("Enter the number of terms: ");
  scanf("%d", &size);

  for(int i = 0; i < size; i++) {
    printf("Enter the coefficient for term %d: ", i + 1);
    scanf("%d", &coef);
    printf("Enter the exponent for term %d: ", i + 1);
    scanf("%d", &exp);
    insert(head, coef, exp);
  }
}

void freePolynomial(Node* head) {
  Node *temp;
  while(head != NULL) {
    temp = head;
    head = head->next;
    free(temp);
  }
}

Node* search(Node* head, int exp) {
  for(Node *temp = head->next; temp != NULL; temp = temp->next)
    if(temp->exp == exp)
      return temp;
  return NULL;
}

void addPolynomials(Node* head1, Node* head2, Node* head3){
  if(head2->next != NULL || head3->next != NULL){
    for(Node* ptr = head2->next; ptr != NULL; ptr = ptr->next) {
      Node* key = search(head3, ptr->exp);
      if(key == NULL) {
        insert(head1, ptr->coef, ptr->exp);
      } else {
        insert(head1, ptr->coef + key->coef, ptr->exp);
      }
    }
    for(Node* ptr = head3->next; ptr != NULL; ptr = ptr->next) {
      Node* key = search(head1, ptr->exp);
      if(key == NULL) {
        insert(head1, ptr->coef, ptr->exp);
      }
    }
  }
}

void printPolynomials(Node* head) {
  for(Node *temp = head->next; temp != NULL; temp = temp->next) {
    printf("%dx^%d", temp->coef, temp->exp);
    if(temp->next != NULL)
      printf(" + ");
  }
  printf("\n");
}

int main(){
  Node* poly1 = createNode(0, 0);
  Node* poly2 = createNode(0, 0);
  Node* result = createNode(0, 0);

  printf("Create first polynomial:\n");
  createPolynomial(poly1);

  printf("Create second polynomial:\n");
  createPolynomial(poly2);

  addPolynomials(result, poly1, poly2);

  printf("First Polynomial: ");
  printPolynomials(poly1);

  printf("Second Polynomial: ");
  printPolynomials(poly2);

  printf("Resultant Polynomial: ");
  printPolynomials(result);

  freePolynomial(poly1->next);
  freePolynomial(poly2->next);
  freePolynomial(result->next);

  free(poly1);
  free(poly2);
  free(result);

  return 0;
}