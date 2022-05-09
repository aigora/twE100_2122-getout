#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "acciones.h"
#include "pantallas.h"
#include "juego.h"

void seleccionSeleccion() {
    int input, check = 1;

    while (check == 1) {
        input = getch();
        switch (input) {
            case '1':
                //pantalla de jugar
                system("cls");
                pantallaDificultad();
                break;
            case '2':
                //llevaria a la pantalla de ver el historial
                printf("Cooming soon!\n");                
                break;
            case '3':
                //sales de programa, no hay que poner nada
                system("cls");
                pantallaFinal();
                system("cls");
                exit(0);
                break;
            
            default:
                //continua el bucle
                printf("Pulsa uno de los numeros anda...\n");                
                break;
        }
    }
}

void seleccionDificultad() {
    int input, check = 1;

    while (check == 1) {
        input = getch();
        switch (input) {
            case '1': 
                //lleva al modo facil
                Facil();
                break;
            case '2': 
                //lleva al modo medio
                Medio();
                break;
            case '3': 
                //lleva al modo dificil
                Dificil();
                break;
            case '4':
                //lleva a la pantalla de seleccion
                system("cls");
                pantallaSeleccion();
                break;

            default:
                printf("Dale a uno de los numeros de la pantalla...\n");
                break;
        }
    }
}

void resultadosLB() {
    pantallaMeta();
    //falta todo lo de las leaderboards aqui.
    char input;
    int check = 1;
    while (check == 1) {
        input = getch();
        switch (input) {
            case 's':
                //aqui iria para guardar la puntuacion
                printf("Comming soon!\n");
                break;
            case 'n':
                system("cls");
                check = 0;
                break;

            default:
                printf("Pulse una de las opciones...\n");
                break;
        }
    }

    pantallaSeleccion();
}