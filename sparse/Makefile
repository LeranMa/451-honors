sparse-test: sparse-test.o array.h sparse.o xmalloc.o
	gcc sparse-test.o array.h sparse.o xmalloc.o -o sparse-test

sparse-test.o: sparse-test.c
	gcc -c -Wall -pedantic -std=c99 -O2 sparse-test.c

sparse.o: sparse.c sparse.h
	gcc -c -Wall -pedantic -std=c99 -O2 sparse.c

xmalloc.o: xmalloc.c xmalloc.h
	gcc -c -Wall -pedantic -std=c99 -O2 xmalloc.c