#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int evaluate(char* postfix){
  int stack[100];
  int top = -1;
  for(int i = 0; i < strlen(postfix); i++){
    if(isdigit(postfix[i])){
      int num = 0;
      while(isdigit(postfix[i])){
          num = num*10 + (postfix[i] - '0');
          i++;
      }
      i--;
      stack[++top] = num;
    }else if(postfix[i] == ' '){
      continue;
    }else{
      int op2 = stack[top--];
      int op1 = stack[top--];
      switch(postfix[i]){
        case '+': stack[++top] = op1 + op2; break;
        case '-': stack[++top] = op1 - op2; break;
        case '*': stack[++top] = op1 * op2; break;
        case '/': stack[++top] = op1 / op2; break;
      }
    }
  }
  return stack[top];
}

int main(){
  char postfix[100];
  printf("Enter the postfix expression: ");
  scanf("%[^\n]s", postfix);
  printf("The postfix expression is: %s\n", postfix);
  printf("The result of the expression is: %d\n", evaluate(postfix));
  return 0;
}