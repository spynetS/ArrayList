#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
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

void removeValue(ArrayList* list, int index){
  // [1,2,3,4,5,6,7,|8|,9]
  // [1,2,3,4,5,6,7,9,0]
  // free the index to remove
  if(index>=0){
    free(list->data[index]);
  }
  for(int i = index; i < list->size-1; i ++){
    // after index we move all infront back a step
    list->data[i] = list->data[i+1];
  }
  list->size--;
}

void removeValueFAST(ArrayList* list, int index)
{
  memcpy(list->data + index, list->data + index + 1, sizeof(void*) * (list->size - index));
  free(list->data[list->size - 1]);
  //puts("here4");
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
     list->data = realloc(list->data,sizeof(void*)*(list->size*2));
     list->arraySize = list->size*2;
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

int main(){
  ArrayList *list = newListWithSize(100000000); // create list

  for(int i = 0; i < 100000000; i ++){
    addValue(list,"a");
  }

  clock_t t;
  t = clock();
  removeValueFAST(list,1);
  t = clock() - t;
  double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds

  printf("fun() took %f seconds to execute \n", time_taken);

  //free list
  destroyArrayList(list);
  return 0;
}
