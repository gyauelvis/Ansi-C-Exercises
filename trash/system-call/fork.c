#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void){
  fork(); 
  printf("Process ID: %d \n", getpid()); 
  return 0;
}
