#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

char *readline(void);
void appendChar(char *str, char c);

int main(int argc, char *argv){
  bool status = true;
  char *line = NULL;

  while(status){
    line = readline();
    if(strcmp(line, "exit") == 1)
      status = false;
    puts(line);
    printf("\n");
  }

  free(line);
  return 0;
}

void appendChar(char *str, char c){
  int len;
  if(str == NULL){
    len = 0;
  }else len = strlen(str);
  str[len] = c;
  str[len + 1] = '\0';
}

char *readline(void){
  int letter;
  char *line = NULL;
  printf("x > ");
  while((letter = getchar()) != EOF || letter != '\n'){
    char c = letter; 
    appendChar(line, c);
  }
  if(letter == '\n')
    return line;
  exit(1);
}
