#include <stdio.h>
#include <string.h>

int main(){
  char str[100];
  printf("Enter a string : ");
  fgets(str, 100, stdin);
  
  int len = strlen(str);
  char stack[len], top = -1;

  for(int i=0; i<len; i++){
    if(str[i] == '(' || str[i] == '{' || str[i] == '['){
      stack[++top] = str[i];
    }else{
      if(str[i] == ')'){
        if(top == -1 || stack[top] != '('){
          printf("RESULT : Unbalanced parentheses\n");
          return 0;
        }
      }else if(str[i] == '}'){
        if(top == -1 || stack[top] != '{'){
          printf("RESULT : Unbalanced parentheses\n");
          return 0;
        }
      }else if(str[i] == ']'){
        if(top == -1 || stack[top] != '['){
          printf("RESULT : Unbalanced parentheses\n");
          return 0;
        }
      }
      top--;
    }
  }
  printf("RESULT : Balanced parentheses\n");
  return 0;
}