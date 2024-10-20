#include <stdbool.h>

typedef struct{
  char map[2][4];
  int length;
}Map;

// constructor emulator for MAP
Map mapInit(){
  Map dict;
  for(int i = 0; i < 2; i++){
    for(int k = 0; k < sizeof(dict.map[i])/ sizeof(dict.map[i][i]); k++){
      dict.map[i][k] = '0'; 
    }
  }
  dict.length = 4; 
  return dict;
}

//hash key
int hash(Map dict, char elem){
  int key = elem;
  return key % dict.length; 
};

// checks if location is empty and inserts it
bool isLocationEmpty(Map *dict, char key, char value, int loc){
  if(dict->map[0][loc] == '0'){
    dict->map[0][loc] = key;
    dict->map[1][loc] = value;
    return true;
  }
  return false;
}

//function to insert a key value pair into map
bool insert(Map *dict,char key, char value){
  int loc = hash(*dict, key);
  if(isLocationEmpty(dict, key, value, loc)) return true; 
  for(int i = loc + 1; i<(sizeof(dict->map[0])/sizeof(dict->map[0][0])); i++){
    if(isLocationEmpty(dict, key, value, i)) return true; 
  }
  for(int i = 0; i<(sizeof(dict->map[0])/sizeof(dict->map[0][0])); i++){
    if(isLocationEmpty(dict, key, value, i)) return true;   
  }
  return false;
}

//find value using key
char find(Map dict, char key){
  int loc = hash(dict, key);
  if(dict.map[0][loc] == key)return dict.map[1][loc];
  for(int i = loc + 1; i<(sizeof(dict.map[0])/sizeof(dict.map[0][0])); i++){
    if(dict.map[0][loc] == key)return dict.map[1][loc];
  }
  for(int i = 0; i<(sizeof(dict.map[0])/sizeof(dict.map[0][0])); i++){
    if(dict.map[0][loc] == key)return dict.map[1][loc];
  }
  return '0';
}
