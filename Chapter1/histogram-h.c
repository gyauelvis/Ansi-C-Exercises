#include <stdio.h>

main(void){
  int digits[10];
  for(int i = 0; i<10; i++)digits[i] = 0;
  int character;
  while((character = getchar()) != EOF)
    if(character >= '0' && character <= '9')++digits[character - '0'];
  printf("\n");
  for(int i = 0; i<10; i++){
    printf("%d || ", i);

    for(int k = 0; k<digits[i]; k++)printf("-");
    printf("\n"); 
  }
  for(int i = 0; i<20; i++){
    if(i == 0)printf("  ==");
    else printf("==");
  }

}
