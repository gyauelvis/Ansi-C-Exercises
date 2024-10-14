#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void lineNumbers(Stack *stack);
int syntax_chars(char c);

int main(){
  Stack stack;
  stack = init();
  lineNumbers(&stack);
  display(stack); 
}

int syntax_chars(char c){
  if(c == '\'' || c == '"')return 0;
  char opening[] = {'<', '(', '{', '['}; 
  char closing[] = {'>', '}', ')', ']'};
  for(int i = 0; i < sizeof(opening)/sizeof(opening[0]); i++){
    if(c == opening[i])return 1;
    if(c == closing[i]) return 2;
  }
  return 3;
}

void lineNumbers(Stack *stack){
  int letter, i = 1, k;
  printf("%d ", i); 
  while((letter = getchar()) != EOF){
    if(letter == '\n')
      printf("%d ", ++i);
    else if((k = syntax_chars(letter)) != 3){
      if(k == 1)push(stack, letter);
      else if(k == 0){
        if(top(stack) != letter)push(stack, letter);
        else{
          pop(stack);
        }
      }
    }
  }
}

