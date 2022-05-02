#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "inicio.h"

int main() {
    system("cls");
    pantallaInicio();

    getch(); //loophole no preguntes
    system("cls");
    pantallaSeleccion();
    
    char input;
    int check = 1;

    while (check == 1) {
        input = getch();
        switch (input) {
            case '1':
                //llevaria a la pantalla de jugar
                printf("Cooming soon!\n");
                break;
            case '2':
                //llevaria a la pantalla de ver el historial
                printf("Cooming soon!\n");                
                break;
            case '3':
                //sales de programa, no hay que poner nada
                check = 0;
                system("cls");
                break;
            
            default:
                //continua el bucle
                printf("Pulsa uno de los numeros anda...\n");                
                break;
        }
    }
    
}