#include <stdio.h>

#define MAXLINE 10000

int getLine(char s[], int maxLine);
void copyLine(char from[], char to[]);

int main(void){
  char longestLine[MAXLINE];
  char currentLine[MAXLINE];
  int maxLength = 0, currentLength;

  while((currentLength = getLine(currentLine, MAXLINE)) > 0){
    if(currentLength > maxLength){
      maxLength = currentLength;
      copyLine(currentLine, longestLine);
    }
  }
  if(maxLength > 0)printf("%s", longestLine);
  return 0;
}

int getLine(char s[], int maxLine){
  int letter, i = 0;
  while((letter = getchar()) != EOF && letter != '\n' && i < maxLine - 1){
    s[i] = letter;
    i++;
  }
  if(letter == '\n'){
    s[i] = letter;
    i++;
  }
  s[i] = '\0';
  return i;
}

void copyLine(char from[], char to[]){
  int i = 0;
  while((to[i] = from[i]) != '\0') ++i;
}
