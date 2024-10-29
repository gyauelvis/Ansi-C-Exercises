#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/wait.h>


#define MAXARGs 64
#define DELIMS " \t\a\n\r/"

typedef struct{
  char *name;
  char **args;
  int arg_count;
}Command;

char *read_line(void);
int parseline(char *, Command *);
void free_command(Command *);
int execute_command(Command *);
int main(int argc, char **argv){

  bool status = true;
  char *line = NULL;
  Command cmd;

  while(status){
    printf("\nx > ");
    line = read_line();
    if(parseline(line, &cmd)){
      execute_command(&cmd);  
      free_command(&cmd); 
    } 
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

int parseline(char *line, Command *cmd){
  int buff_size = MAXARGs; 
  char *token;
  char **tokens = malloc(buff_size * sizeof(char *));
  int position = 0;
  if(!tokens){
    perror("allocation error");
    exit(0); 
  };

  token = strtok(line, DELIMS);
  while(token != NULL){
    tokens[position++] = token;
    if(position >= buff_size){
      buff_size += MAXARGs;
      tokens = realloc(tokens, buff_size * sizeof(char *));
      if(!tokens){
        perror("allocation error");
        exit(0); 
      };
    }
    token = strtok(NULL, DELIMS);
  }
  tokens[position] = NULL;
  if(position == 0){
    free(tokens); 
    return 0;
  }
  cmd->name = tokens[0];
  cmd->args= tokens;
  cmd->arg_count = position;
  return 1;
}
void free_command(Command *cmd){
  free(cmd->args);
}

int execute_command(Command *cmd){
  pid_t pid;
  if(strcmp(cmd->name, "exit") == 0)
    return 0;
  pid = fork();
  if(pid == -1){
    printf("fork failed");
    exit(1);
  }
  if(pid == 0){
    execvp(cmd->name, cmd->args);
  }

  int status;
  do{
    waitpid(pid, &status, 0);
  }while(!WIFEXITED(status) && !WIFSIGNALED(status));
  
  return 1;
}
