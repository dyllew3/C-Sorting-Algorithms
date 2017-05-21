all: test clean
test: testsort.c sorting.o
	gcc -o test testsort.c sorting.o
sorting.o: sorting.c sorting.h
	gcc -c sorting.c
clean :
	rm sorting.o
