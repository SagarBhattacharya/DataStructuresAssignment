#include <stdio.h>
#define left(i) (2*(i) + 1)
#define right(i) (2*(i) + 2)

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int size, int* arr){
    for(int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void siftDown(int size, int* arr){
    int j = 0, maxindex;
    while(left(j) < size){
        maxindex = left(j);
        if(right(j) < size && arr[left(j)] < arr[right(j)]){
            maxindex = right(j);
        }
        if(arr[maxindex] <= arr[j]) break;
        swap(arr + maxindex, arr + j);
        j = maxindex;
    }
}

void heapify(int size, int* arr){
  for(int i = size - 1; i >= 0; i--){
    siftDown(size - 1 - i, arr + i);
  }
}

void heapSort(int size, int* arr){
  heapify(size, arr);
  for(int i = size - 1; i >= 0; i--){
    swap(arr, arr + i);
    siftDown(i, arr);
  }
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
  heapSort(n, arr);
  printf("Sorted array: \n");
  printArray(n, arr);
}
