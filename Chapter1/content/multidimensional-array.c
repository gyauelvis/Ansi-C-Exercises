#include <stdio.h>

int main(void){
  char arr[2][2] = {
    {'a','b'},{'c','d'}
  };
  int length = sizeof(arr)/sizeof(arr[0][0]);
  printf("%d", length);
  return 0;
}
