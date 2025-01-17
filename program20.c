#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int size, int* arr){
  for(int i = 0; i < size; i++){
    int swapped = 0;
    for(int j = 0; j < size - i - 1; j++){
      if(arr[j] > arr[j + 1]){
        swap(&arr[j], &arr[j + 1]);
        swapped = 1;
      }
    }
    if(!swapped){
      break;
    }
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
  printf("Enter the number of elements: ");
  scanf("%d", &size);

  int arr[size];
  printf("Enter the elements: ");
  for(int i = 0; i < size; i++) {
    scanf("%d", &arr[i]);
  }

  printf("Unsorted array: ");
  printArray(size, arr);

  bubbleSort(size, arr);

  printf("Sorted array: ");
  printArray(size, arr);

  return 0;
}