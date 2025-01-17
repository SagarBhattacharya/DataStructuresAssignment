#include <stdio.h>

void swap(int* a, int* b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

void selectionSort(int size, int* arr){
  int minIndex;
  for(int i = 0; i < size; i++){
    minIndex = i;
    for(int j = i+1; j < size; j++){
      if(arr[j] < arr[minIndex]){
        minIndex = j;
      }
    }
    swap(&arr[i], &arr[minIndex]);
  }
}

void printArray(int size, int* arr){
  for(int i = 0; i < size; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main(){
  int size;
  printf("Enter the size of the array: ");
  scanf("%d", &size);
  int arr[size];
  printf("Enter the elements of the array: ");
  for(int i = 0; i < size; i++){
    scanf("%d", &arr[i]);
  }
  printf("The original array is: ");
  printArray(size, arr);
  selectionSort(size, arr);
  printf("The sorted array is: ");
  printArray(size, arr);
}