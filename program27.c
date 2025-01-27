#include <stdio.h>

void printArray(int size, int* arr){
  for(int i = 0; i < size; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void linearSearch(int size, int* arr, int key){
  for(int i = 0; i < size; i++){
    if(arr[i] == key){
      printf("Element found!\n", i);
      return;
    }
  }
  printf("Element not found!\n");
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
  linearSearch(size, arr, key);
}