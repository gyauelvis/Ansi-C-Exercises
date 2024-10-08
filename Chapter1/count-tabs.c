#include <stdio.h>

main(){
int letter, count = 0;
for(int i = 0; (letter = getchar()) != EOF; i++){
	if(letter =='\t') ++count;
}
printf("\nnumber of tabs: %d", count);
}
