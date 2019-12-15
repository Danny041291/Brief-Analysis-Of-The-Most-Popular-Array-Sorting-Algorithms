# compile main
main : clean_all main.o
	gcc -ansi -Wall -O main.o -o main

# compile main.o
main.o :
	gcc -ansi -Wall -O -c main.c -o main.o

# clean object files
clean :
	rm -f main.o

# clean binary and object files
clean_all :
	rm -f main main.o
