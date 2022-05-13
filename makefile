CC=gcc
CFLAGS=-I.
DEPS = pantallas.h juego.h
OBJ = main.o pantallas.o editor.o juego.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

prueba: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)