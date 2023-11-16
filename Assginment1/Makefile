#Makefile

CC = gcc
OBJS = main.o copy.o
all: exe

exe: $(OBJS)
	$(CC) -o exe $(OBJS)
main.o: main.c copy.h
	$(CC) -c main.c
copy.o: copy.c
	$(CC) -c copy.c

clean:
	rm -f $(OBJS) exe *.o
