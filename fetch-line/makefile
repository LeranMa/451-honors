fetch-line-demo: fetch-line.o fetch-line-demo.o
	gcc fetch-line.o fetch-line-demo.o -o fetch-line-demo

fetch-line-demo.o: fetch-line-demo.c
	gcc -c -Wall -pedantic -std=c89 -O2 fetch-line-demo.c

fetch-line.o: fetch-line.c fetch-line.h
	gcc -c -Wall -pedantic -std=c89 -O2 fetch-line.c
