hilbert-matrix: hilbert-matrix.o array.h xmalloc.o
	gcc hilbert-matrix.o array.h xmalloc.o -o hilbert-matrix

hilbert-matrix.o: hilbert-matrix.c
	gcc -c -Wall -pedantic -std=c99 -O2 hilbert-matrix.c

xmalloc.o: xmalloc.c xmalloc.h
	gcc -c -Wall -pedantic -std=c99 -O2 xmalloc.c