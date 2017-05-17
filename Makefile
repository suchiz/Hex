CC=gcc
CFLAGS= -Wall -lm
EXEC=hex

all: $(EXEC)


graph.o: graph.c
	$(CC) -o graph.o -c graph.c  $(CFLAGS)

$(EXEC): graph.o
	$(CC) graph.o -o $(EXEC) $(CFLAGS)


clean:
	rm -rf *.o $(EXEC)