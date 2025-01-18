#include <stdio.h>

int main(){
  int size1, size2;
  printf("Enter size of first array : ");
  scanf_s("%d", &size1);
  printf("Enter size of second array : ");
  scanf_s("%d", &size2);

  int arr1[size1], arr2[size2];
  printf("Enter elements of first array : ");
  for(int i=0; i<size1; i++){
    scanf_s("%d", &arr1[i]);
  }
  printf("Enter elements of second array : ");
  for(int i=0; i<size2; i++){
    scanf_s("%d", &arr2[i]);
  }
  
  const int size3 = size1 + size2;
  int arr3[size3];

  for(int i = 0; i < size3; i++){
    if(i < size1){
      arr3[i] = arr1[i];
    }else{
      arr3[i] = arr2[i-size1];
    }
  }

  printf("Merged array : ");
  for(int i=0; i<size3; i++){
    printf("%d ", arr3[i]);
  }
}