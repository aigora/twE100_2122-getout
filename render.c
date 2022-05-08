#include <stdio.h>

typedef struct 
{
    //fila x columna
    int x, y;
} dosDatos;

dosDatos movimiento(dosDatos *posicion, int n);

int main() {
    //[numero de laberinto][fila del laberinto][columna del laberinto]
    char mapas[30][200][200];

    FILE *map;
    map = fopen("laberinto_25x25/facil.txt", "r");
    //nos dice el estado del mapa:
    if (map == NULL) {
        printf("No se ha encontrado el mapa.\n");
        return 1;
    } else {
        printf("Abierto correctamente.\n");
    }

    //utilizaremos la i para el numero de laberinto
    //la j para la fila del laberinto y la k para la columna del laberinto
    int i, j, k;
    dosDatos medidas[30], posicion[30], meta[30];
    
    for (i = 0; i < 30; i++) {
        //obetenemos las dimensines del laberinto y las almacenamos
        //en una estructura
        fscanf(map, "%d %d", &medidas[i].x, &medidas[i].y);
        //obtenemos el laberinto escaneando por filas
        for (j = 0; j < medidas[i].x; j++) {
            fscanf(map, "%s", mapas[i][j]);
            //va escaneando por cada elemento de la matriz
            //buscando "o" para sustituirlos por espacios.
            for (k = 0; k < medidas[i].y; k++) {
                if (mapas[i][j][k] == 'o') {
                    mapas[i][j][k] = ' ';
                }
                if (mapas[i][j][k] == '#') {
                    mapas[i][j][k] = 219;
                }
                //escaneo del punto de inicio
                if (mapas[i][j][k] == 'X') {
                    posicion[i].x = j;
                    posicion[i].y = k;
                }
                //escaneo de la meta
                if (mapas[i][j][k] == 'M') {
                    meta[i].x = j;
                    meta[i].y = k;
                }
            }
        }
    }

    for (i = 0; i < 30; i++) {
        printf("%d %d\n", medidas[i].x, medidas[i].y);
    }
    printf("\n");
    for (i = 0; i < 30; i++) {
        printf("%d %d\n", posicion[i].x, posicion[i].y);
    }
    
    int n = 4;

    dosDatos render, posicionActual;
    posicionActual.x = posicion[n].x;
    posicionActual.y = posicion[n].y;

    render.x = posicionActual.x;
    render.y = posicionActual.y;
    printf("%d %d\n", render.x, render.y);
    if (posicionActual.x < 12) {
        render.x = 12;
    }
    if (posicionActual.y < 5) {
        render.y = 5;
    }
    if (posicionActual.x > medidas[n].x - 12) {
        render.x = medidas[n].x - 12;
    }
    if (posicionActual.y > medidas[n].y - 5) {
        render.y = medidas[n].y - 5;
    }
    printf("%d %d\n", render.x, render.y);

    for (i = render.x - 5; i < render.x + 5; i++) {
        for (j = render.y - 12; j < render.y + 12; j++) {
            printf("%c", mapas[n][i][j]);
        }
        printf("\n");
    }
    
    printf("%d %d\n", posicionActual.x, posicionActual.y);
    movimiento(&posicionActual, n);
    printf("%d %d\n", posicionActual.x, posicionActual.y);
    printf("%d %d\n", meta[n].x, meta[n].y);
    

    fclose(map);
}

dosDatos movimiento(dosDatos *posicion, int n) {
    posicion -> x = 20;
    posicion -> y = 20;
}