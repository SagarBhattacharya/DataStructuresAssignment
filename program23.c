#include <stdio.h>

void printArray(int size, int* arr) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void merge(int mid, int size, int* arr){
  int temp[size];
  int i = 0, j = mid, k = 0;
  while(i < mid && j < size){
    if(arr[i] < arr[j]){
      temp[k++] = arr[i++];
    }else{
      temp[k++] = arr[j++];
    }
  }
  while(i < mid) temp[k++] = arr[i++];
  while(j < size) temp[k++] = arr[j++];
  for(int i = 0; i < size; i++) arr[i] = temp[i];
}

void mergeSort(int size, int* arr){
  if(size > 1){
    int mid = size / 2;
    mergeSort(mid, arr);
    mergeSort(size - mid, arr + mid);
    merge(mid, size, arr);
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
  mergeSort(size, arr);
  printf("Sorted array: ");
  printArray(size, arr);
}