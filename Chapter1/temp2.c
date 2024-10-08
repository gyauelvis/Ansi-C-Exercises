#include <stdio.h>

main(void){
	int fahr = 300;
	for(fahr; fahr>0; fahr -= 30){
		float cel = (5.0/9.0)*(fahr - 32);
		printf("%3d%6.1f\n", fahr, cel);
	}
}
