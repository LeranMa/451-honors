random-pbm: random-pbm.o array.h xmalloc.o
	gcc random-pbm.o array.h xmalloc.o -o random-pbm

random-pbm.o: random-pbm.c
	gcc -c -Wall -pedantic -std=c99 -O2 random-pbm.c

xmalloc.o: xmalloc.c xmalloc.h
	gcc -c -Wall -pedantic -std=c99 -O2 xmalloc.c