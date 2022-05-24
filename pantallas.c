#pragma once

#include "pantallas.h"
#include <stdio.h>
#include <conio.h>
#include <time.h>

void pantallaInicio() {
    printf("                         #######\n");
    printf("              #############################\n");
    printf("##########################################################\n\n");
    printf("                            +\n");
    printf("                 ----------------------\n");
    printf("                    +   Get Out!   +\n");
    printf("                 ----------------------\n");
    printf("                            +\n\n");
    printf("##########################################################\n");
    printf("              #############################\n");
    printf("                         #######\n\n");
    printf("Para una mejor experiencia se recomienda\njugar en pantalla completa zoom reducido.\n\n");
    printf("Pulse cualquier tecla para iniciar...\n");
}

void pantallaSeleccion() {
    printf("##########################################################\n\n");
    printf("     1  Jugar\n\n");
    printf("     2  Historial\n\n");
    printf("     3  Editor de niveles\n\n");
    printf("     4  Salir\n\n\n\n");
    printf("##########################################################\n\n");
    printf("Pulse el numero de la opcion...\n");
}

void pantallaDificultad() {
    printf("##########################################################\n\n");
    printf("     1  Facil\n\n");
    printf("     2  Medio\n\n");
    printf("     3  Dificil\n\n");
    printf("     4  Personalizados\n\n");
    printf("     5  Atras\n\n");
    printf("##########################################################\n\n");
    printf("Pulse el numero de la opcion...\n");
}

void pantallaFinal() {
    int n = numero_pasos_guardado();
    printf("\t\t##########################################################\n\n");
    printf("\t\t     Ha realizado %i pasos en la ultima partida\n", n);
    printf("\t\t     Gracias por jugar, pulse cualquier\n");
    printf("\t\t     tecla para salir...\n\n");
    printf("\t\t     Get Out!\n\n");
    printf("\t\t##########################################################\n\n");
    boceto_randon();
    getch();
}

void pantallaMeta() {
    printf("######################################################################\n\n");
    printf("     Enhorabuena!\n");
    printf("     Has conseguido salir del laberinto\n\n");
    printf("     Desea registrar su puntuacion?\n     S - Si\n     N - No\n\n");
    printf("######################################################################\n\n");
}

void pantallaDimensiones() {
    printf("##########################################################\n\n");
    printf("     Introduzca las dimensiones del laberinto\n");
    printf("     que quiere crear:       (Ejemplo: 23 12)\n");
    printf("     Minimo: 4 x 4\n");
    printf("     Maximo: 50 x 50\n\n");
    printf("     Dimensiones introducidas: ");
}

void seccionInstrucciones() {
    printf("    Teclas y acciones:\n\n");
    printf("    T - Colocar pared      E - Colocar espacio\n");
    printf("    R - Colocar meta       G - Guardar\n");
    printf("    Presiona enter para crear paredes enteras, vuelve a presionarlo para crearlas\n\n");
    printf("    X - Salir del editor\n");
}

void PantallaSeleccionPosicion(char dificultad) {
    printf("    Escribe una posicion de la cual empezar:\n");
    printf("    Recuerda las dimensiones de los niveles\n\n    Dimensiones maximas del modo: ");
    switch (dificultad) {
        case 'f': 
            printf("25 x 25");
            break;
        case 'm':
            printf("50 x 50");
            break;
        case 'd':
            printf("100 x 100");
            break;
        
        default:
            printf("Ha habido un error");
            break;
    }
    printf("\n\n    Ejemplo: 1 1 (Enter)\n");
}

void PantallaSeleccionPosicionEditor(){
    printf("    Escribe una posicion de la cual empezar\n");
    printf("    Dimensiones del mapa escogido: ");
}

void instruccionesMovimiento() {
    printf("\n\n                                %c             W  \n", 30);
    printf("    Muevase con las teclas:   %c %c %c   (%c)   A S D  \n\n", 17, 31, 16, 162);
}

int numero_pasos_guardado() {   
    int num_pasos=0, i;
    FILE *pf;
    pf = fopen("ultima_partida.txt", "r");
    //Comprobacion por si hay error al abrir archivo.
    if (pf == NULL){
        printf("Error al abrir el fichero.\n");
        return -1;
    }
    else{
        fscanf(pf, "%i", &num_pasos);
        fclose (pf);
        return num_pasos;
    }
}

void boceto_randon() {
    int n_aleatorio;
    char simbolo;

    srand(time(NULL));
    //Numero aleatorio entre 1 y 100
    n_aleatorio = (rand() % 3 + 1);

    FILE *pf;
    switch (n_aleatorio) {
    case 1:
        pf = fopen("bocetos\\boceto_1.txt", "r");
            while (fscanf(pf, "%c", &simbolo) != EOF) {
                printf("%c",simbolo);
            }
        break;
    case 2:
        pf = fopen("bocetos\\boceto_2.txt", "r");
            while (fscanf(pf, "%c", &simbolo) != EOF) {
                printf("%c",simbolo);
            }
        break;
    case 3:
        pf = fopen("bocetos\\boceto_3.txt", "r");
            while (fscanf(pf, "%c", &simbolo) != EOF) {
                printf("%c",simbolo);
            }
        break;
    default:
        printf(" Gracias por jugar nuestro juego.");
        break;
    }
    fclose(pf);
} 