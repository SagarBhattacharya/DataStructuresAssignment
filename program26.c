#include <stdio.h>

void swap(int *a, int *b){
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

void quickSort(int size, int* arr){
  if(size > 1){
    int pivot = partition(0, size-1, arr);
    quickSort(pivot, arr);
    quickSort(size-pivot-1, arr+pivot+1);
  }
}

void binarySearch(int size, int* arr, int key){
  quickSort(size, arr);
  int low = 0, high = size-1;
  while(low <= high){
    int mid = (low+high)/2;
    if(arr[mid] == key){
      printf("Element found!\n", mid);
      return;
    }
    else if(arr[mid] < key) low = mid+1;
    else high = mid-1;
  }
  printf("Element not found!\n");
}

void printArray(int size, int* arr){
  for(int i = 0; i < size; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main(){
  int size, key;
  printf("Enter the size of the array: ");
  scanf("%d", &size);
  int arr[size];
  printf("Enter the elements of the array: ");
  for(int i = 0; i < size; i++){
    scanf("%d", &arr[i]);
  }
  printf("Enter the element to be searched: ");
  scanf("%d", &key);
  binarySearch(size, arr, key);
  return 0;
}