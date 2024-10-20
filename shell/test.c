#include <stdio.h>
#include <string.h>

int main(void){
  char *str = NULL;
  int l = strlen(str);
  str[l] = 'c';
  str[l + 1] = '\0';
}
