#include <stdio.h>

main(void){
  int blankCount = 0, letter;
  while((letter = getchar()) != EOF){
    if(letter == ' '){
      if(blankCount == 0)blankCount++;
      else continue;
    }else blankCount = 0;
    putchar(letter);
  }
}
