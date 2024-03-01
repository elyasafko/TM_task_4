#flags
CC = gcc
CFLAGS = -Wall


.PHONY: all clean

all: digitcompress

digitcompress: encodemain.o compress.o
	$(CC) $(CFLAGS) -o digitcompress encodemain.o compress.o

encodemain.o: encodemain.c
	$(CC) $(CFLAGS) -c encodemain.c

compress.o: compress.c compress.h
	$(CC) $(CFLAGS) -c compress.c

clean:
	@rm -f digitcompress *.o