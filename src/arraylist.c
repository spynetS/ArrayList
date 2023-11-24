#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <time.h>
#include "arraylist.h"

ArrayList* newListWithSize(int init_size){

  ArrayList *list = (ArrayList*) malloc(sizeof(ArrayList));
  list->size = 0;
  list->arraySize = init_size;
  list->data = (void*)malloc(sizeof(void*)*init_size);
  return list;
}

ArrayList* newList(){

  ArrayList *list = (ArrayList*) malloc(sizeof(ArrayList));
  list->size = 0;
  list->arraySize = INIT_SIZE;
  list->data = (void*)malloc(sizeof(void*)*INIT_SIZE);
  return list;
}

void addPointerValue(ArrayList* list, void* value){
  if(list->size >= list->arraySize){
     list->data = realloc(list->data,sizeof(void*)*(list->size+1));
     list->arraySize = list->size+1;
  }
  list->data[list->size] = value;
  list->size++;
}

void* getValue(ArrayList* list, int index){
  return list->data[index];
}

void printListString(ArrayList* list){
  for(int i = 0; i < list->size; i ++){
    printf("%d,%s\n",i,((char*)list->data[i]));
  }
}

void removeValue(ArrayList* list, int index)
{
  free(list->data[index]);
  memmove(list->data + index, list->data + index + 1, sizeof(void*) * (list->size - index - 1));
  list->size--;
}

void destroyArrayList(ArrayList* list){
  for(int i = 0; i < list->size; i ++){
    free(list->data[i]);
  }
  free(list->data);
  free(list);
}

void addValue(ArrayList* list, void *value){
  if(list->size >= list->arraySize){
     list->data = realloc(list->data,sizeof(void*)*(list->size*1));
     list->arraySize = list->size*1;
  }
  size_t size = strlen(((char*)value));
  list->data[list->size] = malloc(size);
  memcpy(list->data[list->size],value,size);

  list->size++;
}

void clearArrayList(ArrayList* list){
  for(int i = 0; i < list->size; i ++){
    free(list->data[i]);
  }
  list->size = 0;
}

void* popValue(ArrayList* list){
  void* value = getValue(list,list->size-1);
  size_t s = strlen(((char*)value));
  void* ret = malloc(s);
  memcpy(ret,value,  s);

  removeValue(list,list->size-1);
  return ret;
}

/* int main(){
  ArrayList *list = newListWithSize(10); // create list

  for(int i = 0; i < 10; i ++){
    addValue(list,&i);
  }

  clock_t t;
  t = clock();
  removeValueFAST(list,1);
  t = clock() - t;
  double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds

  printf("fun() took %f seconds to execute \n", time_taken);

  //free list
  destroyArrayList(list);
  exit(0);
} */
