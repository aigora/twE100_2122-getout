#pragma once

#include <stdio.h>
#include <stdlib.h>

void verHistorial() {
    char resultado;
    FILE *historial;
    system("cls");
    historial = fopen("historial.txt", "r");

    if (historial == NULL) {
        printf("No se pudo abrir el fichero\n");
        exit(1);
        //end of program
    } else {
        printf("#####################################################################################\n\n\t");
        while (!feof (historial)) {
            resultado = getc(historial);
            printf ("%c", resultado);
            if (resultado=='\n') {
                printf("\n\t");
            }
        }
        printf("\n");
        printf("#####################################################################################\n");
    }

    fclose(historial);
    
    system("pause");
}