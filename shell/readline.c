#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAXARGs 64
#define DELIMS " \t\a\n\r"
#define LINESIZE 100

typedef struct {
  char * name;
  char **args;
  int argcount;
}Command;


bool convertToModifiebleString(char *line, char modLine[]);
char *readline(void);
void appendChar(char *str, char c);
int parseline(char *line, Command *cmd);

int main(int argc, char *argv){
  bool status = true;
  char *line = NULL;
  Command cmd;

  while(status){
    line = readline();
    if(strcmp(line, "exit") == 1)
      status = false;
    puts(line);
    //  int val = parseline(line, &cmd);
    // printf("%d", val);
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
  char *line = malloc(LINESIZE); 
  printf("x > ");
  while((letter = getchar()) != EOF || letter != '\n'){
   // appendChar(line, letter);
  }
  if(letter == '\n')
    return line;
  exit(1);
}

bool convertToModifiebleString(char *line, char modLine[]){
  int len = strlen(line);
  for(int i = 0; i<len; i++){
    modLine[i] = line[i]; 
  }
  modLine[len] = '\0';
  return true;
}


/* int parseline(char *line, Command *cmd){
  int buffSize = MAXARGs;
  int position = 0;
  char **tokens = malloc(buffSize * sizeof(char *));
  char *token;
  if(!tokens){
    perror("allocation error");
    exit(1);
  }
  // convert char * to char[]
  char modLine[strlen(line)];
  convertToModifiebleString(line, modLine);
  token = strtok(modLine, DELIMS);

  while(token != NULL){
    tokens[position++] = token;
    if(position >= buffSize){
      buffSize += MAXARGs;
      tokens = realloc(tokens, buffSize * sizeof(char *));
      if(!tokens){
        perror("allocation error");
        exit(1);
      }
    }
    token = strtok(NULL, DELIMS); 
  }
  tokens[position] == NULL;
  if(position == 0){
    free(tokens); 
    return 0;
  } 
  cmd->name = tokens[0];
  cmd->args = tokens;
  cmd->argcount = position;
  return 1;
}*/
