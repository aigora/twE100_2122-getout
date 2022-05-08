CC=gcc
CFLAGS=-I.
DEPS = pantallas.h acciones.h juego.h
OBJ = main.o pantallas.o acciones.o juego.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

prueba: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)