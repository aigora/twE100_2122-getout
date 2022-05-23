#pragma once

#include <stdio.h>
#include <stdlib.h>

void getout()
{
    system("cls");
    pantallaInicio();
    getch(); //loophole no preguntes

    int input, exito = 1;
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
                editor();
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
                Facil(&exito);
                break;

            case '2': 
                //lleva al modo medio
                Medio(&exito);
                break;
            
            case '3': 
                //lleva al modo dificil
                Dificil(&exito);
                break;

            case '4':
                //lleva al modo personalizado
                Personalizado(&exito);
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
        if (exito == 0) {
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
        } else {
            goto seleccionSeleccion;
        }
    //goto infinite_loop;
}