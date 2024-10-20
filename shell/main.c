#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char *read_line(void);

int main(int argc, char **argv){

  bool status = true;
  char *line = NULL;
  
  while(status){
    printf("x > ");
    line = read_line();
    puts(line);
    if(strcmp(line, "exit\n") == 0)
      status = false;
  }

  free(line);
  return 0;
}

char *read_line(void){
  char *line = NULL;
  size_t buffsize = 0;

  if(getline(&line, &buffsize, stdin) == -1){
    if(feof(stdin)){
      exit(0);
    }
    perror("read_line");
    exit(1);
  }
  return line;
}
