#pragma once

#include "pantallas.h"
#include <stdio.h>
#include <conio.h>

void pantallaInicio() {
    printf("		#######\n");
    printf("        #######################\n");
    printf("#######################################\n");
    printf("		   +\n");
    printf("	 ----------------------\n");
    printf("            +   Get Out!   +\n");
    printf("	 ----------------------\n");
    printf("		   +\n");
    printf("#######################################\n");
    printf("        #######################\n");
    printf("		#######\n");
    printf("\n");
    printf("Pulse cualquier tecla para iniciar...\n");
}

void pantallaSeleccion() {
    printf("###########################################\n\n");
    printf("     1  Jugar\n\n");
    printf("     2  Historial\n\n");
    printf("     3  Editor de niveles\n\n");
    printf("     4  Salir\n\n\n\n");
    printf("###########################################\n\n");
    printf("Pulse el numero de la opcion...\n");
}

void pantallaDificultad() {
    printf("###########################################\n\n");
    printf("     1  Facil\n\n");
    printf("     2  Medio\n\n");
    printf("     3  Dificil\n\n");
    printf("     4  Personalizados\n\n");
    printf("     5  Atras\n\n");
    printf("###########################################\n\n");
    printf("Pulse el numero de la opcion...\n");
}

void pantallaFinal() {
    printf("###########################################\n\n");
    printf("     Gracias por jugar, pulse cualquier\n");
    printf("     tecla para salir...\n\n");
    printf("     Get Out!\n\n");
    printf("###########################################\n\n");
    getch();
}

void pantallaMeta() {
    printf("###########################################\n\n");
    printf("     Enhorabuena!\n");
    printf("     Has conseguido salir del laberinto\n");
    printf("     Desea registrar su puntuacion?\n     Si (s)     No (n)\n\n");
    printf("###########################################\n\n");
}

void PantallaSeleccionPosicion(){
    printf("Escribe una posicion de la cual empezar\n");
    printf("Recuerda las dimensiones de los niveles\nFacil:25x25\nMedio:50x50\nDificil:100x100\n");
}