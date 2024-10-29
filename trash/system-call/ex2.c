#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


int main(int argc, char *argv[]){
  printf("PID EX2 %d\n", getpid());
  return 0;
}
