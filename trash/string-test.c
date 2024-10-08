#include <stdio.h>
#include <string.h>
main(void){
	char * a = "abc";
	a[(strlen(a))] = "d";
	a[strlen(a)+1] = "\0";
	printf("%s", a);
}
