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
  size_t s = strlen(((char*)value));

  list->data[list->size] = malloc(s);
  memcpy(list->data[list->size],value,s);
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

/* int main(){ */
/*   ArrayList *list = newList(); */
/*   addValue(list,&"0123456789101112"); */

/*   char* poped = (char*)popValue(list); */
/*   printf("poped %s\n",poped); */

/*   int i = -10000; */
/*   addValue(list,&i); */
/*   char c = 'a'; */
/*   addValue(list,&c); */


/*   printf("poped %d\n",*(int*)list->data[0]); */
/*   printf("poped %c\n",*(char*)list->data[1]); */

/*   destroyArrayList(list); */
/*   return 0; */
/* } */
