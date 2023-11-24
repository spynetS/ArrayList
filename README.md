# ArrayList
This is a generic ArrayList implementation in c.

## Exmaple of use
```c
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
```
