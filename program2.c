#include <stdio.h>

void inputMatrix(int rows, int cols, int matrix[rows][cols]) {
  for(int i=0; i<rows; i++){
    for(int j=0; j<cols; j++){
      scanf("%d", &matrix[i][j]);
    }
  }
}

void printMatrix(int rows, int cols, int matrix[rows][cols]) {
  for(int i=0; i<rows; i++){
    for(int j=0; j<cols; j++){
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int rowA, colA, rowB, colB;
  printf("Enter number of rows and columns of first matrix : ");
  scanf("%d %d", &rowA, &colA);
  printf("Enter number of rows and columns of second matrix : ");
  scanf("%d %d", &rowB, &colB);

  int matrixA[rowA][colA], matrixB[rowB][colB];

  printf("Enter elements of first matrix : ");
  inputMatrix(rowA, colA, matrixA);

  printf("Enter elements of second matrix : ");
  inputMatrix(rowB, colB, matrixB);

  int choice;
  printf("Enter 1 to multiply A x B, 2 to transpose A : ");
  scanf("%d", &choice);

  if(choice == 1){
    if(colA != rowB){
      printf("Matrix multiplication not possible\n");
      return 0;
    }

    int result[rowA][colB];
    for(int i=0; i<rowA; i++){
      for(int j=0; j<colB; j++){
        result[i][j] = 0;
        for(int k=0; k<colA; k++){
          result[i][j] += matrixA[i][k] * matrixB[k][j];
        }
      }
    }

    printf("Resultant matrix : \n");
    printMatrix(rowA, colB, result);

  }else if(choice == 2){
    int transposeA[colA][rowA];

    for(int i=0; i<rowA; i++){
      for(int j=0; j<colA; j++){
        transposeA[j][i] = matrixA[i][j];
      }
    }

    printf("Transpose of first matrix : \n");
    printMatrix(colA, rowA, transposeA);
    
  }else{
    printf("Invalid choice\n");
  }
}