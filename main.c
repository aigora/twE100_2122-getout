#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "pantallas.h"
#include "juego.h"

int main() 
{
    system("cls");
    pantallaInicio();
    getch(); //loophole no preguntes

    int input;
    char character;
    //infinite_loop:

        seleccionSeleccion:
        system("cls");
        pantallaSeleccion();
        input = getch();
        switch (input) {
            case '1':
                //pantalla de jugar
                system("cls");
                goto seleccionDificultad;
                break;

            case '2':
                //llevaria a la pantalla de ver el historial
                system("cls");
                goto seleccionSeleccion;                
                break;

            case '3':
                //Sales del programa
                system("cls");
                pantallaFinal();
                system("cls");
                exit(0);
                break;
            

            default:
                //continua el bucle
                goto seleccionSeleccion;             
                break;
        }

        seleccionDificultad:
        system("cls");
        pantallaDificultad();
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
                goto seleccionSeleccion;
                break;

            default:
                //continua esta parte del bucle
                goto seleccionDificultad;
                break;
        }

        meta:
        system("cls");
        pantallaMeta();
        character = getch();
        switch (character) {
            case 's':
                //aqui iria para guardar la puntuacion
                goto meta;
                break;
            case 'n':
                goto seleccionSeleccion;
                break;

            default:
                system("cls");
                goto meta;
                break;
        }

    //goto infinite_loop;

    return 0;
}