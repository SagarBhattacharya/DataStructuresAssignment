#include <stdio.h>

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int low, int high, int* arr){
  int pivot = arr[high];
  int index = low;
  for(int k = low; k <= high; k++){
    if(arr[k] <= pivot){
      swap(&arr[k], &arr[index]);
      index++;
    }
  }
  return index-1;
}

void quickSortIterative(int size, int* arr){
  int stack[size];
  int top = -1;
  stack[++top] = 0;
  stack[++top] = size - 1;
  while(top != -1){
    int end = stack[top--];
    int start = stack[top--];
    if (start < end) {
      int pivot = partition(start, end, arr);
      stack[++top] = start;
      stack[++top] = pivot - 1;
      stack[++top] = pivot + 1;
      stack[++top] = end;
    }
  }
}

void printArray(int size, int* arr){
    for(int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
  int n;
  printf("Enter the number of elements: ");
  scanf("%d", &n);

  int arr[n];
  printf("Enter the elements: ");
  for(int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  printf("Original array: \n");
  printArray(n, arr);

  quickSortIterative(n, arr);

  printf("Sorted array: \n");
  printArray(n, arr);

  return 0;
}
