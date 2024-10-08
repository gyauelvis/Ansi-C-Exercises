#include <stdio.h>

#define MAXLINE 1000

int getLine(char s[], int lim);
void printLine(char currentLine[], int len);

int main(void){
  char currentLine[MAXLINE];
  int currentLineLength;

  while((currentLineLength = getLine(currentLine, MAXLINE)) > 0 ){
    printLine(currentLine, currentLineLength);
  }

  return 0;
}

int getLine(char s[], int lim){
  int letter, i = 0;
  while((letter = getchar()) != EOF && i < lim - 1 && letter != '\n'){
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

void printLine(char currentLine[], int len){
  if(len > 80) printf("%s", currentLine);
}
