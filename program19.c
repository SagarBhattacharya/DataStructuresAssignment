#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node* left;
  struct node* right;
} Node;

Node* createNode(int data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

void insert(Node** root, int data){
    if(*root == NULL){
        *root = createNode(data);
        return;
    }
    if((*root)->data > data){
        insert(&(*root)->left, data);
    }else{
        insert(&(*root)->right, data);
    }
}

void createTree(Node** root){
  int size, data;
  printf("Enter Number of Nodes : ");
  scanf("%d", &size);
  printf("Enter Tree Nodes : ");
  for(int i = 0; i < size; i++){
    scanf("%d", &data);
    insert(root, data);
  }
}

void preorder(Node* root){
    if(root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void freeTree(Node** root){
  if(*root == NULL) return;
  freeTree(&(*root)->left);
  freeTree(&(*root)->right);
  free(*root);
  *root = NULL;
}

void inorderIterative(Node* root){
    Node* stack[100];
    int top = -1;
    Node* current = root;
    while(current != NULL || top != -1){
        while(current != NULL){
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        printf("%d ", current->data);
        current = current->right;
    }
}

int main(){
  Node* root = NULL;
  createTree(&root);
  printf("Preorder Traversal: ");
  preorder(root);
  printf("\n");
  printf("Inorder Traversal: ");
  inorderIterative(root);
  printf("\n");
  freeTree(&root);
  return 0;
}

