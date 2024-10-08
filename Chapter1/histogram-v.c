#include <stdio.h>

#define SIZE 10

// had to do this because you can't pass an array by value in C
typedef struct {
  int arr[SIZE];
}ArrayWrapper;

int findGreatest(ArrayWrapper);
void drawHistogram(ArrayWrapper);

main(void){
  int character; 
  ArrayWrapper arrayWrapper;

  for(int i = 0; i < SIZE; i++)arrayWrapper.arr[i] = 0;
  
  while((character = getchar()) != EOF){
    if(character >= '0' && character <= '9')
      ++arrayWrapper.arr[character - '0'];
  }
  printf("\n"); 
  
  drawHistogram(arrayWrapper);
  printf("   =");

  for(int i = 1; i<SIZE; i++)printf("========");
  printf("\n    ");

  for(int i = 0; i<SIZE; i++)printf("%d\t ", i);
}

int findGreatest(ArrayWrapper arrayWrapper){
  int max_index = 0;
  for(int i = 1; i<SIZE; i++)
    if(arrayWrapper.arr[i] > arrayWrapper.arr[max_index])max_index = i;
  return max_index;
}

void drawHistogram(ArrayWrapper arrayWrapper){
  int max_index = findGreatest(arrayWrapper);
  while(arrayWrapper.arr[max_index] > 0){ 
    printf("%2d #", arrayWrapper.arr[max_index]);
    for(int i = 0; i<SIZE; i++){
      if(arrayWrapper.arr[i] > 0 && 
        arrayWrapper.arr[i] == arrayWrapper.arr[max_index]){
        if(i != max_index)
          arrayWrapper.arr[i]--;
        printf(" +\t");
      }else printf("\t");
    }
    arrayWrapper.arr[max_index]--;
    printf("\n");
  }
}
