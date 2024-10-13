CC = gcc
CFLAGS = -Wall
OBJ = main.o filecopy.o parse_args.o

all: copyfile

copyfile: $(OBJ)
	$(CC) $(CFLAGS) -o copyfile $(OBJ)

main.o: main.c filecopy.h
	$(CC) $(CFLAGS) -c main.c

filecopy.o: filecopy.c filecopy.h
	$(CC) $(CFLAGS) -c filecopy.c

parse_args.o: parse_args.c
	$(CC) $(CFLAGS) -c parse_args.c

clean:
	rm -f *.o copyfile
