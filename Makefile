CC=gcc
CFLAGS= -lm -Wall
EXEC=hex

OBJDIR = obj
SRCDIR = src

STRUCT_O = group.o board.o node.o graph.o jouer.o

all: $(EXEC)

group.o: $(SRCDIR)/group.c
	$(CC) -o group.o -c $(SRCDIR)/group.c $(CFLAGS)
	
graph.o: $(SRCDIR)/graph.c
	$(CC) -o graph.o -c $(SRCDIR)/graph.c $(CFLAGS)
	
board.o: $(SRCDIR)/board.c
	$(CC) -o board.o -c $(SRCDIR)/board.c $(CFLAGS)
	
node.o: $(SRCDIR)/node.c
	$(CC) -o node.o -c $(SRCDIR)/node.c $(CFLAGS)
	
jouer.o:$(SRCDIR)/jouer.c
	$(CC) -o jouer.o -c $(SRCDIR)/jouer.c $(CFLAGS)
	

main.o: $(SRCDIR)/main.c
	$(CC) -o main.o -c $(SRCDIR)/main.c $(CFLAGS)
	
$(EXEC): $(STRUCT_O) main.o
	$(CC) $(STRUCT_O) main.o -o $(EXEC) $(CFLAGS)
	mv *.o $(OBJDIR)/


clean:
	rm -rf $(OBJDIR)/*.o $(EXEC) save/*.txt