#include <stdio.h>
int main(void)
{
	int step, low, upper;
	float fahr,cel;
	low = 30; step = 20; upper = 300;
	fahr = low;
	while(fahr<= upper){
		cel = (5)*(fahr -32)/9;
		printf("%3.0f%6.1f\n",cel, fahr);
		fahr += step;
	}
	return 0;
}
