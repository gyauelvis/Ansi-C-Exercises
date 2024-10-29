// Write a program to determine the ranges of char, short, int, and long variables, both signed and unsigned, by printing appropriate values from standard headers and by direct computation. Harder if you compute them: determine the ranges of the various floating-point types.

#include <stdio.h>
#include <time.h>

int main(void){
  signed char elem = 0b00000000;
  unsigned char elem1 = 0b00000000;
  while(1){
    int conv = elem, conv1 = elem1;
    printf("%3d  %3d\n", conv, conv1);
    elem += 0b00000001;
    elem1 += 0b00000001;
    clock_t start_time = clock();
    while(clock() < start_time + 1000000);
  }
  return 0;
}
