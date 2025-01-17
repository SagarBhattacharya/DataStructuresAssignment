#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int priority(char ch){
  if(ch == '+' || ch == '-'){
    return 1;
  }else if(ch == '*' || ch == '/'){
    return 2;
  }else{
    return 0;
  }
}

int contains(char* str, char ch){
  for(int i = 0; i < strlen(str); i++){
    if(str[i] == ch) return 1;
  }
  return 0;
}

void convertToPostfix(char* infix, char* postfix){
  char stack[100];
  int top = -1;
  int j = 0;
  for(int i = 0; i < strlen(infix); i++){
    if(isalnum(infix[i])){
      postfix[j++] = infix[i];
    }else if(infix[i] == '('){
      stack[++top] = infix[i];
    }else if(infix[i] == ')'){
      while(stack[top] != '('){
        postfix[j++] = stack[top--];
      }
      top--;
    }else{
      while(top != -1 && priority(stack[top]) >= priority(infix[i])){
        postfix[j++] = stack[top--];
      }
      stack[++top] = infix[i];
    }
  }
  while(top != -1){
    postfix[j++] = stack[top--];
  }
  postfix[j] = '\0';
}

int main(){
  char infix[100], postfix[100];
  printf("Enter the infix expression: ");
  scanf("%s", infix);
  convertToPostfix(infix, postfix);
  printf("The postfix expression is: %s\n", postfix);
  return 0;
}