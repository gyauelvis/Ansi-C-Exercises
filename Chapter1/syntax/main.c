#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "hashmap.h"
#include "
//max number of errors we will keep track of
#define MAXELE 10

void lineNumbers(Stack *stack, Map *dict);
int syntax_chars(char c);
void logErrors(int loc);
  
//list of columns and line numbers where to locate incorrect chars
int locOfSyntax[2][MAXELE];

int main(){
  Stack stack;
  Map dict;
  dict = mapInit();
  stack = init();
  lineNumbers(&stack, &dict);
}

void mapKeyToValue(Map *dict){
  char opening[] = {'<', '(', '{', '['}; 
  char closing[] = {'>', '}', ')', ']'};
  for(int i = 0; i<sizeof(opening)/sizeof(opening[0]); i++)
    insert(dict,closing[i], opening[i]); 
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

void lineNumbers(Stack *stack, Map *dict){
  int letter, i = 1, k, col = 0, loc = 0;
  printf("%d ", i); 
  while((letter = getchar()) != EOF){
    col++;
    if(letter == '\n'){
      printf("%d ", ++i);
      col = 0;
    }
    else if((k = syntax_chars(letter)) != 3){
      if(k == 1)push(stack, letter);
      else if(k == 0){
        if(top(stack) != letter)push(stack, letter);
        else{
          pop(stack);
        }
      }else{
        if(find(*dict, letter) == top(stack))
          pop(stack);
        else{
          // keep track of the line number and column location of the element
          if(loc < 10){ 
            locOfSyntax[0][loc] = i;
            locOfSyntax[1][loc] = col;
            loc++;
          }
        }
      }
    }
  }
  logErrors(loc);
}

void logErrors(int loc){
  printf("\n");
  for(int i = 0; i<10; i++)printf("==");
  printf("\n");
  for(int i = 0; i<loc; i++){
    printf("row = %d, column = %d\n", 
           locOfSyntax[0][i], locOfSyntax[1][i]);   
  };
};
