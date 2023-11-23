#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct arrayList{
  void** data;
  int size;
  int arraySize;
} ArrayList;

ArrayList* newList(){
  int init_size = 10;
  ArrayList *list = (ArrayList*) malloc(sizeof(ArrayList));
  list->size = 0;
  list->arraySize = init_size;
  list->data = (void*)malloc(sizeof(void*)*init_size);
  return list;
}

void addPoinerValue(ArrayList* list, void* value){
  if(list->size >= list->arraySize){
     list->data = realloc(list->data,sizeof(void*)*(list->size*2));
     list->arraySize = list->size*2;
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
  list->data[list->size] = malloc(sizeof(void*));
  memcpy(list->data[list->size],value,sizeof(void*));
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
  void* ret = malloc(sizeof(value));
  memcpy(ret,value,sizeof(value));

  removeValue(list,list->size-1);
  return ret;
}

/* int main(){ */
/*   ArrayList *list = newList(); */
/*   addValue(list,"asd1"); */
/*   addValue(list,"asd2"); */
/*   addValue(list,"asd3"); */

/*   char* poped = (char*)popValue(list); */
/*   printf("poped %s\n",poped); */
/*   free(poped); */
/*   poped = (char*)popValue(list); */
/*   printf("poped %s\n",poped); */
/*   free(poped); */
/*   poped = (char*)popValue(list); */
/*   printf("poped %s\n",poped); */
/*   free(poped); */

/*   destroyArrayList(list); */
/*   return 0; */
/* } */
