CC=gcc
CFLAGS=-I.
DEPS = pantallas.h acciones.h
OBJ = main.o pantallas.o acciones.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

prueba: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)