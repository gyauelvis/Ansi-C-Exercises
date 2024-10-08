#include <stdbool.h>

#define MAX 100

typedef struct{
  char arr[MAX];
  int top;
} Stack;

Stack init(){
  Stack s;
  s.top = 0;
  return s;
}

bool is_full(Stack s){
  return s.top == MAX;
}

bool is_empty(Stack s){
  return s.top == 0;
}

bool push(Stack *s, char val){
  if(is_full(*s))return false;
  s->arr[s->top] = val;
  s->top++;
  return true;
}

bool pop(Stack *s){
  if(is_empty(*s))return false;
  s->top--;
  return true;
}

void display(Stack s){
  for(int i = 0; i<s.top; i++){
    printf("%c", s.arr[i]);
  }
}

int top(Stack *s){
  if(s->top <= 0)return s->arr[s->top];
  return 0;
}
