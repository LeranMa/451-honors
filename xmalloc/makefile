all: xmalloc-demo-1 xmalloc-demo-2

xmalloc-demo-1: xmalloc.o xmalloc-demo-1.o
	gcc xmalloc.o xmalloc-demo-1.o -o xmalloc-demo-1

xmalloc-demo-1.o: xmalloc-demo-1.c
	gcc -c -Wall -pedantic -std=c99 -O2 xmalloc-demo-1.c

xmalloc-demo-2: xmalloc.o xmalloc-demo-2.o
	gcc xmalloc.o xmalloc-demo-2.o -o xmalloc-demo-2

xmalloc-demo-2.o: xmalloc-demo-2.c
	gcc -c -Wall -pedantic -std=c99 -O2 xmalloc-demo-2.c

xmalloc.o: xmalloc.c xmalloc.h
	gcc -c -Wall -pedantic -std=c99 -O2 xmalloc.c
