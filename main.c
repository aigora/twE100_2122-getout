#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "pantallas.h"
#include "acciones.h"

int main() {
    system("cls");
    pantallaInicio();
    getch(); //loophole no preguntes

    system("cls");
    pantallaSeleccion();
    seleccionSeleccion();
}