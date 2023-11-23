/*
  Alfred Roos 2023
  This is a generic ArrayList implementation.

  Exmaple of use
  int main(){
    ArrayList *list = newList(); // create list
    // add some strings
    addValue(list,"asd1");
    addValue(list,"asd2");
    addValue(list,"asd3");

    //print the strings
    printListString(list);
    //clear array
    clearArrayList(list);

    // get age from command line and add it to the list
    // and then print all ages
    int age;
    printf("Write the ages: ");
    while(scanf("%d",&age)>0){
      printf("Write the ages: ");
      addValue(list,&age);
    }
    for(int i = 0; i < list->size; i ++){
      printf("Age %d: %d\n",i, *(int*)getValue(list,i));
    }
    //free list
    destroyArrayList(list);
    return 0;
  }

*/



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
ArrayList* newList();
/**
   returns the value at index
* */
void* getValue(ArrayList* list, int index);
/**
   print all items as strings
*/
void printListString(ArrayList* list);
/**
   removes the item at index
   it will free the item and move all index before back
   * */
void removeValue(ArrayList* list, int index);
/**
   will free all allocated memory by the list
  * */
void destroyArrayList(ArrayList* list);
/**
   Function to add a value to the array. It will allocate memory
   and copy the value from the value adress.
   Input: any adress
 */
void addValue(ArrayList* list, void *value);
/**
   This function will not allocate memory and expects that the value
   allready is allocated. REMEMBER THAT THE LIST WILL FREE IT FOR YOU
   * */
void addPoinerValue(ArrayList* list, void* value);
