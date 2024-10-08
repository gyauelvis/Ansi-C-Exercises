#include <stdio.h>
#include "stack.h"

int main(){
  Stack s1;
  bool ele;
  s1 = init();
  ele = push(&s1,'1');
  ele?printf("true"):printf("false");
  push(&s1, '2');
  display(s1);
  pop(&s1);
  display(s1);
}
