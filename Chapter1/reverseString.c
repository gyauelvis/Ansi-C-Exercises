#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

void reverseString(char [], int);
int getLine(char [], int);
int main(void){
  int currentLen;
  char line[MAXLINE];
  while((currentLen = getLine(line, MAXLINE)) > 0){
    reverseString(line,strlen(line)); 
    printf("%s", line);
  }
  return 0;
}

int getLine(char s[], int lim){
  int letter, i =0;
  for( i; i< lim - 1 && (letter = getchar()) != EOF && letter != '\n'; i++)
    s[i] = letter;
  if(letter == '\n'){
    s[i] = letter;
    i++;
  }
  s[i] = '\0';
  return i;
}

void reverseString(char s[], int len){
  if(len <= 0) return;
  int left = 0, right = len - 1;
  while(left < right){
    char temp = s[left];
    s[left] = s[right];
    s[right] = temp;
    left++; right--;
  }
}
