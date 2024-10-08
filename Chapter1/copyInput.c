Rinclude <stdio.h>

main(void){
	int count = 0, cha;
	while((cha = getchar()) != EOF){
		if(cha == '\n')count++;
	}
	printf("\nnumber of letters: %d", count);
}
