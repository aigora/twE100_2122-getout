#include "acciones.h"
#include "pantallas.h"

void seleccionSeleccion() {
    int input, check = 1;

    while (check == 1) {
        input = getch();
        switch (input) {
            case '1':
                //pantalla de jugar
                system("cls");
                check = 0;
                pantallaDificultad();
                break;
            case '2':
                //llevaria a la pantalla de ver el historial
                printf("Cooming soon!\n");                
                break;
            case '3':
                //sales de programa, no hay que poner nada
                check = 0;
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
                //llevaria al modo facil
                printf("Comming soon!\n");
                break;
            case '2': 
                //llevaria al modo medio
                printf("Comming soon!\n");
                break;
            case '3': 
                //llevaria al modo dificil
                printf("Comming soon!\n");
                break;
            case '4':
                //lleva a la pantalla de seleccion
                system("cls");
                check = 0;
                pantallaSeleccion();
                break;

            default:
                printf("Dale a uno de los numeros de la pantalla...\n");
                break;
        }
    }
}