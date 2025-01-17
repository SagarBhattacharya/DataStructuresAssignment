#include <stdio.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void printArray(int size, int* arr) {
  for(int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void selectionSort(int size, int* arr){
  for(int i = 0; i < size - 1; i++){
    int min = i;
    for(int j = i + 1; j < size; j++){
      if(arr[j] < arr[min]){
        min = j;
      }
    }
    swap(&arr[min], &arr[i]);
    printf("After pass %d: ", i + 1);
    printArray(size, arr);
  }
}

void insertionSort(int size, int* arr){
  for(int i = 1; i < size; i++){
    int key = arr[i];
    int j = i - 1;
    while(j >= 0 && arr[j] > key){
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
    printf("After pass %d: ", i);
    printArray(size, arr);
  }
}

int main() {
  int choice, size;
  printf("Enter the number of elements: ");
  scanf("%d", &size);
  int arr[size], copiedArr[size];
  printf("Enter the elements: ");
  for(int i = 0; i < size; i++) {
    scanf("%d", &arr[i]);
  }
  for (int i = 0; i < size; i++){
    copiedArr[i] = arr[i];
  }
  
  while(1) {
    printf("\nMenu:\n");
    printf("1. Selection Sort\n");
    printf("2. Insertion Sort\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice){
      case 1:
        printf("\nSelection Sort:\n\n");
        selectionSort(size, arr);
        printf("\nSorted array: ");
        printArray(size, arr);
        break;
      case 2:
        printf("\nInsertion Sort:\n\n");
        insertionSort(size, copiedArr);
        printf("\nSorted array: ");
        printArray(size, copiedArr);
        break;
      case 3:
        return 0;
      default:
        printf("Invalid choice. Please try again.\n");
    }
  }
}