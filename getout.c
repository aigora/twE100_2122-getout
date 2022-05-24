#pragma once

#include <stdio.h>
#include <stdlib.h>

void getout()
{
    system("cls");
    pantallaInicio();
    getch(); //loophole no preguntes
    FILE *historial;
    int input, exito = 1, num_paso = 0;
    int *movimientos = &num_paso;
    char character, resultado;
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
                goto resultadosLB;
                system("pause");
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
        resultadosLB:
        {
        system("cls");
        historial=fopen("historial.txt", "r");
        if (historial==NULL)
        {
            printf("No se pudo abrir el fichero\n");
            return -1;
        }
        else
        {
            printf("#####################################################################################\n\n\t");
            while (!feof (historial)) {
            resultado = getc(historial);
            printf ("%c", resultado);
            if (resultado=='\n')
            {
                printf("\n\t");
            }
            }
            printf("\n");
            printf("#####################################################################################\n");
        }
        fclose(historial);
        system("pause");
        goto seleccionSeleccion;
        }
        seleccionDificultad:
        system("cls");
        pantallaDificultad();
        input = getch();
        switch (input) {
            case '1': 
                //lleva al modo facil
                Facil(&exito, movimientos);
                break;

            case '2': 
                //lleva al modo medio
                Medio(&exito, movimientos);
                break;
            
            case '3': 
                //lleva al modo dificil
                Dificil(&exito, movimientos);
                break;

            case '4':
                //lleva al modo personalizado
                Personalizado(&exito, movimientos);
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
                    guardar_numero_pasos(movimientos);
                    goto seleccionSeleccion;
                    break;

                case 'S':
                    //igual que la minuscula
                    guardar_numero_pasos(movimientos);
                    goto seleccionSeleccion;
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