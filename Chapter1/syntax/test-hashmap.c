#include <stdio.h>
#include "hashmap.h"
#include <stdbool.h>
int main(void){
  Map dict;
  dict = init();
  char ele = '{', key = '}';
  bool isInsert = insert(&dict, ele, key);
  char aa = find(dict, ele);
  printf("%c", aa);
}
