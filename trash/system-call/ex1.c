#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[]){
  printf("PID EX1: %d\n", getpid());
  char *args[] = {"Hello", "World", NULL};
  execv("./ex2", args);
  printf("Back to EX1");
  return 0;
}
