# make-Makros
CC = gcc
CFLAGS = -g -ansi -pedantic -Wall

glogomat.out: main.o textfun.o
	$(CC) $(CFLAGS) main.o textfun.o -o glogomat

main.o: main.c textfun.h
	$(CC) $(CFLAGS) -c main.c

textfun.o: textfun.c textfun.h
	$(CC) $(CFLAGS) -c textfun.c