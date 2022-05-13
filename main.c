#include <stdio.h>
#include <stdlib.h>
#include <conio.h> //libreria conio.h utilizada para detectar que tecla se presiona sin necesidad de dar enter despues de cada movimiento

#include "pantallas.h"
#include "juego.h"

int main() 
{
    system("cls");
    pantallaInicio();
    getch(); //loophole no preguntes

    system("color f0"); //probando


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
                //lleva hasta el editor de niveles
                system("cls");
                goto seleccionSeleccion;
                break;

            case '4':
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
                //lleva al modo personalizado
                goto seleccionDificultad;
                break;

            case '5':
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

            case 'S':
                //igual que la minuscula
                goto meta;
                break;

            case 'n':
                goto seleccionSeleccion;
                break;

            case 'N':
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