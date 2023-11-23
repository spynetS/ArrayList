# ArrayList
This is a generic ArrayList implementation in c.

## Exmaple of use
```c
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
```
