CC=gcc
CFLAGS=-I.
DEPS = getout.h pantallas.h historial.h juego.h
OBJ = main.o getout.o pantallas.o editor.o historial.o juego.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

prueba: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)