gcc -shared -fPIC -o ./build/libarraylist.so ./src/arraylist.c
cp ./src/arraylist.h ./build

gcc -o ./build/arraylist.o -c ./src/arraylist.c
ar rcs ./build/libarraylist.a ./build/libarraylist.so
