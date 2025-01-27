#include <stdio.h>

void printArray(int size, int* arr) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void merge(int start, int mid, int end, int* arr){
  int size = end - start;
  int temp[size];
  int i = start, j = mid, k = 0;
  while(i < mid && j < end){
    if(arr[i] < arr[j]){
      temp[k++] = arr[i++];
    }else{
      temp[k++] = arr[j++];
    }
  }
  while(i < mid) temp[k++] = arr[i++];
  while(j < end) temp[k++] = arr[j++];
  for(int i = 0; i < size; i++) arr[start + i] = temp[i];
}

void mergeSortIterative(int size, int* arr) {
  for(int step = 1; step < size; step *= 2){
    for(int i = 0; i < size; i += 2 * step){
      int mid = i + step < size ? i + step : size;
      int end = i + 2 * step < size ? i + 2 * step : size;
      merge(i, mid, end, arr);
    }
  }
}

int main(){
  int size;
  printf("Enter the number of elements: ");
  scanf("%d", &size);

  int arr[size];
  printf("Enter the elements: ");
  for (int i = 0; i < size; i++) {
    scanf("%d", &arr[i]);
  }

  printf("Original array: ");
  printArray(size, arr);
  mergeSortIterative(size, arr);
  printf("Sorted array: ");
  printArray(size, arr);
}