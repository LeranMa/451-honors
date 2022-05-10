all: umfpack-demo1 umfpack-demo2 umfpack-demo3

umfpack-demo1: umfpack-demo1.o array.h sparse.o xmalloc.o
	gcc umfpack-demo1.o array.h sparse.o xmalloc.o -o umfpack-demo1 -lumfpack

umfpack-demo2: umfpack-demo2.o array.h sparse.o xmalloc.o
	gcc umfpack-demo2.o array.h sparse.o xmalloc.o -o umfpack-demo2 -lumfpack

umfpack-demo3: umfpack-demo3.o array.h sparse.o xmalloc.o
	gcc umfpack-demo3.o array.h sparse.o xmalloc.o -o umfpack-demo3 -lumfpack

umfpack-demo1.o: umfpack-demo1.c
	gcc -c -Wall -pedantic -std=c99 -O2 umfpack-demo1.c

umfpack-demo2.o: umfpack-demo2.c
	gcc -c -Wall -pedantic -std=c99 -O2 umfpack-demo2.c

umfpack-demo3.o: umfpack-demo3.c
	gcc -c -Wall -pedantic -std=c99 -O2 umfpack-demo3.c

sparse.o: sparse.c sparse.h
	gcc -c -Wall -pedantic -std=c99 -O2 sparse.c

xmalloc.o: xmalloc.c xmalloc.h
	gcc -c -Wall -pedantic -std=c99 -O2 xmalloc.c
	