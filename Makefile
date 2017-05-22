CC=gcc
CFLAGS= -lm -Wall
EXEC=hex

OBJDIR = obj
SRCDIR = src
FILESDIR = test
BINDIR = bin

STRUCT_O = group.o board.o node.o graph.o jouer.o save.o stack.o menu.o

all: $(EXEC)

group.o: $(SRCDIR)/group.c
	$(CC) -o group.o -c $(SRCDIR)/group.c $(CFLAGS)
	
graph.o: $(SRCDIR)/graph.c
	$(CC) -o graph.o -c $(SRCDIR)/graph.c $(CFLAGS)
	
board.o: $(SRCDIR)/board.c
	$(CC) -o board.o -c $(SRCDIR)/board.c $(CFLAGS)
	
node.o: $(SRCDIR)/node.c
	$(CC) -o node.o -c $(SRCDIR)/node.c $(CFLAGS)
	
stack.o: $(SRCDIR)/stack.c
	$(CC) -o stack.o -c $(SRCDIR)/stack.c $(CFLAGS)


jouer.o: $(SRCDIR)/jouer.c
	$(CC) -o jouer.o -c $(SRCDIR)/jouer.c $(CFLAGS)
	
save.o: $(SRCDIR)/save.c
	$(CC) -o save.o -c $(SRCDIR)/save.c $(CFLAGS)
	
menu.o: $(SRCDIR)/menu.c
	$(CC) -o menu.o -c $(SRCDIR)/menu.c $(CFLAGS)
		

main.o: $(SRCDIR)/main.c
	$(CC) -o main.o -c $(SRCDIR)/main.c $(CFLAGS)

test_board.o: $(FILESDIR)/test_board.c
	$(CC) -o test_board.o -c $(FILESDIR)/test_board.c $(CFLAGS)

test_graph.o: $(FILESDIR)/test_graph.c
	$(CC) -o test_graph.o -c $(FILESDIR)/test_graph.c $(CFLAGS)

test_jouer.o: $(FILESDIR)/test_jouer.c
	$(CC) -o test_jouer.o -c $(FILESDIR)/test_jouer.c $(CFLAGS)

test_node.o: $(FILESDIR)/test_node.c
	$(CC) -o test_node.o -c $(FILESDIR)/test_node.c $(CFLAGS)

test_group.o: $(FILESDIR)/test_group.c
	$(CC) -o test_group.o -c $(FILESDIR)/test_group.c $(CFLAGS)

test_save.o: $(FILESDIR)/test_save.c
	$(CC) -o test_save.o -c $(FILESDIR)/test_save.c $(CFLAGS)

test_stack.o: $(FILESDIR)/test_stack.c
	$(CC) -o test_stack.o -c $(FILESDIR)/test_stack.c $(CFLAGS)

	
$(EXEC): $(STRUCT_O) main.o
	$(CC) -o $(BINDIR)/$(EXEC) $(STRUCT_O) main.o $(CFLAGS)
	mv *.o $(OBJDIR)/

test_board: $(STRUCT_O) test_board.o
	$(CC) -o $(BINDIR)/test_board test_board.o $(STRUCT_O) $(CFLAGS)
	mv *.o $(OBJDIR)/

test_graph: $(STRUCT_O) test_graph.o
	$(CC) -o $(BINDIR)/test_graph test_graph.o $(STRUCT_O) $(CFLAGS)
	mv *.o $(OBJDIR)/
	
test_jouer: $(STRUCT_O) test_jouer.o
	$(CC) -o $(BINDIR)/test_jouer test_jouer.o $(STRUCT_O) $(CFLAGS)
	mv *.o $(OBJDIR)/

test_node: $(STRUCT_O) test_node.o
	$(CC) -o $(BINDIR)/test_node test_node.o $(STRUCT_O) $(CFLAGS)
	mv *.o $(OBJDIR)/

test_group: $(STRUCT_O) test_group.o
	$(CC) -o $(BINDIR)/test_group test_group.o $(STRUCT_O) $(CFLAGS)
	mv *.o $(OBJDIR)/
	
test_save: $(STRUCT_O) test_save.o
	$(CC) -o $(BINDIR)/test_save test_save.o $(STRUCT_O) $(CFLAGS)
	mv *.o $(OBJDIR)/
	
test_stack: $(STRUCT_O) test_stack.o
	$(CC) -o $(BINDIR)/test_stack test_stack.o $(STRUCT_O) $(CFLAGS)
	mv *.o $(OBJDIR)/




clean:
	rm -rf $(OBJDIR)/*.o $(EXEC)