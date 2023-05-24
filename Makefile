CC = gcc
CFLAGS = -Wall

all: allocate write read deallocate

allocate: allocate.c
	$(CC) $(CFLAGS) -o allocate allocate.c

write: write.c
	$(CC) $(CFLAGS) -o write write.c

read: read.c
	$(CC) $(CFLAGS) -o read read.c

deallocate: deallocate.c
	$(CC) $(CFLAGS) -o deallocate deallocate.c

clean:
	rm -f allocate write read deallocate
