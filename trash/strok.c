#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DELIM " \t\r\a\n"

int main(void){
  char *line = "elvis";
  char a = line[0];
  printf("%c", a);
  return 0;
}
