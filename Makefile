ODIR = src
CC = gcc
CFLAGS = -I$(ODIR)

SRC = $(ODIR)/main.c $(ODIR)/utils.c
OBJ = $(ODIR)/main.o $(ODIR)/utils.o
TARGET = leafs

#default target
$(TARGET): $(OBJ)
	$(CC) -o $@ $^

#rule to compile .o
$(ODIR)/%.o: $(ODIR)/%.c $(ODIR)/headers.h
	$(CC) -c -o $@ $< $(CFLAGS)



.PHONY: clean

clean:
	rm -f $(OBJ) $(TARGET)
