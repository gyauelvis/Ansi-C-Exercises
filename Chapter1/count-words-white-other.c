#include <stdio.h>

main(void){
  int character, whiteCount, otherCount;
  otherCount = whiteCount = 0;
  int ndigits[10];

  for(int i = 0; i<10; i++){
    ndigits[i] = 0;
  }

  while((character = getchar()) != EOF){
    if(character >= '0' && character <= '9')++ndigits[character - '0']; 
    else if(character ==  '\t' || character == '\n' || character ==  ' ')
      ++whiteCount;
    else ++otherCount;
  }

  for(int i = 0; i<10; i++){
    printf("%d count: %d\n", i, ndigits[i]); 
  }
  printf(", white space = %d, other = %d\n",
         whiteCount, otherCount);
}
