#include <stdio.h>
#include <stdbool.h>
#define IN true
#define OUT false
main(void){
  bool state = OUT;
  int count = 0, letter;

  while((letter = getchar()) != EOF){
    if(letter == '\n' || letter == '\t' || letter ==  ' '){
      if(state == IN)++count;
      state = OUT;
    }else state = IN;
    putchar(letter);
  }
  printf("\nword-count: %d", count);
}
