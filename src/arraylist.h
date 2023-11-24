#ifndef ARRAYLIST_FILE
#define ARRAYLIST_FILE
/*
  Alfred Roos 2023
  This is a generic ArrayList implementation.

  Exmaple of use
  int main(){
    ArrayList *list = arraylist_newList(); // create list
    // add some strings
    arraylist_addValue(list,"asd1");
    arraylist_addValue(list,"asd2");
    arraylist_addValue(list,"asd3");

    //print the strings
    arraylist_printListString(list);
    //clear array
    arraylist_clearArrayList(list);

    // get age from command line and add it to the list
    // and then print all ages
    int age;
    printf("Write the ages: ");
    while(scanf("%d",&age)>0){
      printf("Write the ages: ");
      arraylist_addValue(list,&age);
    }
    for(int i = 0; i < list->size; i ++){
      printf("Age %d: %d\n",i, *(int*)arraylist_getValue(list,i));
    }
    //free list
    arraylist_destroyArrayList(list);
    return 0;
  }

*/

#define INIT_SIZE 10

typedef struct arrayList{
  void** data;
  int size;
  int arraySize;
} ArrayList;

/**
   Constructor
   will allocated the struct and set the default size to 10
   and return the poiter to the struct
   * */
ArrayList* arraylist_newList();
/**
   Constructor
   will allocated the struct and set the default size to 10
   and return the poiter to the struct
   * */
ArrayList* arraylist_newListWithSize(int init_size);
/**
   returns the value at index
* */
void* arraylist_getValue(ArrayList* list, int index);
/**
   print all items as strings
*/
void arraylist_printListString(ArrayList* list);
/**
   removes the item at index
   it will free the item and move all index before back
   * */
void arraylist_removeValue(ArrayList* list, int index);
/**
   will free all allocated memory by the list
  * */
void arraylist_destroyArrayList(ArrayList* list);
/**
   Function to add a value to the array. It will allocate memory
   and copy the value from the value adress.
   Input: any adress
 */
void arraylist_addValue(ArrayList* list, void *value);
/**
   This function will not allocate memory and expects that the value
   allready is allocated. REMEMBER THAT THE LIST WILL FREE IT FOR YOU
   * */
void arraylist_addPointerValue(ArrayList* list, void* value);

/**
   Removes all elements
   * */
void arraylist_clearArrayList(ArrayList* list);

/**
   return and removes last newest added to the list
   REMEMBER TO FREE THE RETURNED VALUE WHEN DONE
   */
void * arraylist_popValue(ArrayList* list);

#endif
