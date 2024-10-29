#include <stdio.h> // for print and input
#include <stdlib.h> // for rand and exit
#include <unistd.h> // for fork
#include <stdbool.h> // for booleans
#include <sys/wait.h> // for waitpid
#include <time.h> // for time

int main(int argc, char *argv[]){
  srandom(time(NULL));
  printf("I am unique \n");
  pid_t pid = fork();
  bool parent = pid != 0;
  if((random() % 2 == 0) == parent)sleep(1);
  if(parent)waitpid(pid, NULL, 0);
  printf("I get printed twice--%s\n", parent? "parent": "child");
  return 0;
}
