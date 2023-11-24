#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <time.h>
#include "arraylist.h"

ArrayList* arraylist_newListWithSize(int init_size){

  ArrayList *list = (ArrayList*) malloc(sizeof(ArrayList));
  list->size = 0;
  list->arraySize = init_size;
  list->data = (void*)malloc(sizeof(void*)*init_size);
  return list;
}

ArrayList* arraylist_newList(){

  ArrayList *list = (ArrayList*) malloc(sizeof(ArrayList));
  list->size = 0;
  list->arraySize = INIT_SIZE;
  list->data = (void*)malloc(sizeof(void*)*INIT_SIZE);
  return list;
}

void arraylist_addPointerValue(ArrayList* list, void* value){
  if(list->size >= list->arraySize){
     list->data = realloc(list->data,sizeof(void*)*(list->size+1));
     list->arraySize = list->size+1;
  }
  list->data[list->size] = value;
  list->size++;
}

void* arraylist_getValue(ArrayList* list, int index){
  return list->data[index];
}

void arraylist_printListString(ArrayList* list){
  for(int i = 0; i < list->size; i ++){
    printf("%d,%s\n",i,((char*)list->data[i]));
  }
}

void arraylist_removeValue(ArrayList* list, int index)
{
  free(list->data[index]);
  memmove(list->data + index, list->data + index + 1, sizeof(void*) * (list->size - index - 1));
  list->size--;
}

void arraylist_destroyArrayList(ArrayList* list){
  for(int i = 0; i < list->size; i ++){
    free(list->data[i]);
  }
  free(list->data);
  free(list);
}

void arraylist_addValue(ArrayList* list, void *value){
  if(list->size >= list->arraySize){
     list->data = realloc(list->data,sizeof(void*)*(list->size*1));
     list->arraySize = list->size*1;
  }
  size_t size = strlen(((char*)value));
  list->data[list->size] = malloc(size);
  memcpy(list->data[list->size],value,size);

  list->size++;
}

void arraylist_clearArrayList(ArrayList* list){
  for(int i = 0; i < list->size; i ++){
    free(list->data[i]);
  }
  list->size = 0;
}

void* arraylist_popValue(ArrayList* list){
  void* value = arraylist_getValue(list,list->size-1);
  size_t s = strlen(((char*)value));
  void* ret = malloc(s);
  memcpy(ret,value,  s);

  arraylist_removeValue(list,list->size-1);
  return ret;
}

/* int main(){
  ArrayList *list = arraylist_newListWithSize(10); // create list

  for(int i = 0; i < 10; i ++){
    arraylist_addValue(list,&i);
  }

  clock_t t;
  t = clock();
  arraylist_removeValueFAST(list,1);
  t = clock() - t;
  double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds

  printf("fun() took %f seconds to execute \n", time_taken);

  //free list
  arraylist_destroyArrayList(list);
  exit(0);
} */
