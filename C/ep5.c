#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
  printf("Before\n");
  pid_t pid = fork();
  printf("After\n");
  if(pid == 0)
    printf("I am the child process\n");
  else if(pid){
    printf("Parent here\n");
    int status;
    do{
      waitpid(pid, &status, 0);
    }while(!WIFEXITED(status));
    printf("Child exited with status %d. \n", WEXITEDSTATUS(status));
  }
  return 0;
}
