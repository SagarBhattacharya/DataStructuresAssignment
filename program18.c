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

// BST

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

Node* search(Node* root, int data){
    if(root == NULL) return NULL;
    if(root->data == data) return root;
    if(root->data > data) return search(root->left, data);
    else return search(root->right, data);
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

void inorder(Node* root){
    if(root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(Node* root){
    if(root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int countLeaves(Node* root){
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}

int countInternalNodes(Node* root){
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) return 0;
    return 1 + countInternalNodes(root->left) + countInternalNodes(root->right);
}

void swapNodeData(Node** node1, Node** node2) {
    int temp = (*node1)->data;
    (*node1)->data = (*node2)->data;
    (*node2)->data = temp;
}

void deleteNode(Node** root, int data){
    if(*root == NULL) return;
    if((*root)->data > data){
        deleteNode(&(*root)->left, data);
    }else if((*root)->data < data){
        deleteNode(&(*root)->right, data);
    }else{
        if((*root)->left == NULL && (*root)->right == NULL){
            free(*root);
            *root = NULL;
            return;
        }else{
            if((*root)->right != NULL){
                Node** successor = &(*root)->right;
                while((*successor)->left != NULL){
                    successor = &(*successor)->left;
                }
                swapNodeData(root, successor);
                deleteNode(successor, data);
            }else if((*root)->left != NULL){
                Node** predecessor = &(*root)->left;
                while((*predecessor)->right != NULL){
                    predecessor = &(*predecessor)->right;
                }
                swapNodeData(root, predecessor);
                deleteNode(predecessor, data);
            }
        }
    }
}

void displayLevelWise(Node* root){
    if(root == NULL) return;
    Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while(front < rear){
        Node* current = queue[front++];
        printf("%d ", current->data);
        if(current->left != NULL) queue[rear++] = current->left;
        if(current->right != NULL) queue[rear++] = current->right;
    }
}

void prettyPrint(Node* root, int space){
    if(root == NULL) return;
    space += 5;
    prettyPrint(root->right, space);
    printf("\n");
    for(int i = 5; i < space; i++) printf(" ");
    printf("%d\n", root->data);
    prettyPrint(root->left, space);
}

void freeTree(Node** root){
  if(*root == NULL) return;
  freeTree(&(*root)->left);
  freeTree(&(*root)->right);
  free(*root);
  *root = NULL;
}

int main() {
  Node* root = NULL;
  int choice, data;

  while(1) {
    printf("\nMenu:\n");
    printf("1. Create Tree\n");
    printf("2. Insert Node\n");
    printf("3. Search Node\n");
    printf("4. Delete Node\n");
    printf("5. Inorder Traversal\n");
    printf("6. Preorder Traversal\n");
    printf("7. Postorder Traversal\n");
    printf("8. Count Leaves\n");
    printf("9. Count Internal Nodes\n");
    printf("10. Display Level Wise\n");
    printf("11. Pretty Print\n");
    printf("12. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        createTree(&root);
        break;
      case 2:
        printf("Enter data to insert: ");
        scanf("%d", &data);
        insert(&root, data);
        break;
      case 3:
        printf("Enter data to search: ");
        scanf("%d", &data);
        Node* found = search(root, data);
        if(found != NULL) {
          printf("Node found with data: %d\n", found->data);
        } else {
          printf("Node not found\n");
        }
        break;
      case 4:
        printf("Enter data to delete: ");
        scanf("%d", &data);
        deleteNode(&root, data);
        break;
      case 5:
        printf("Inorder Traversal: ");
        inorder(root);
        printf("\n");
        break;
      case 6:
        printf("Preorder Traversal: ");
        preorder(root);
        printf("\n");
        break;
      case 7:
        printf("Postorder Traversal: ");
        postorder(root);
        printf("\n");
        break;
      case 8:
        printf("Number of leaves: %d\n", countLeaves(root));
        break;
      case 9:
        printf("Number of internal nodes: %d\n", countInternalNodes(root));
        break;
      case 10:
        printf("Level Wise Display: ");
        displayLevelWise(root);
        printf("\n");
        break;
      case 11:
        printf("Pretty Print:\n");
        prettyPrint(root, 0);
        break;
      case 12:
        freeTree(&root);
        exit(0);
      default:
        printf("Invalid choice, please try again.\n");
    }
  }
}