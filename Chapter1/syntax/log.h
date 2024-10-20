#define LOGMAX 100

typedef struct {
  int logArray[2][100];
  int top;
}Log;

Log logInit(){
  Log s;
  s.top = -1;
  return s;
}

bool logIsFull(Log s){
  return s.top == LOGMAX;
}

bool logisEmpty(LOGMAX s){
  return s.top == -1;
}

bool logPush(Log *s, int val, int val1){
  if(is_full(*s))return false;
  s->logArray[0][s->top + 1] = val;
  s->logArray[1][s->top + 1] = val1;
  s->top++;
  return true;
}

bool logPop(Log *s){
  if(is_empty(*s))return false;
  s->top--;
  return true;
}

void logDisplay(Log s){
  for(int i = 0; i<s.top; i++)
    printf("row = %d col = %d", s.arr[0][i], s.arr[1][i]);
}

int logTop(Log *s){
  if(s->top >= 0)return s->arr[s->top]; 
  return EOF;
}
