#include <stdio.h>

main(void){
int letter, count = 0;
while((letter = getchar()) != EOF){
	if(letter == ' ') ++count;
}
printf("\nnumber of blanks: %d", count);
}
