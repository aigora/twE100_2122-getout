#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct 
{
    //fila x columna
    int x, y;
} dosDatos;

#include "pantallas.h"
#include "acciones.h"
#include "juego.h"

int main() {
    system("cls");
    pantallaInicio();
    getch(); //loophole no preguntes

    system("cls");
    pantallaSeleccion();
    seleccionSeleccion();
}