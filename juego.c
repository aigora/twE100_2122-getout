#include <stdio.h>

#include "juego.h"
#include "acciones.h"
#include "pantallas.h"

typedef struct 
{
    //fila x columna
    //la x es el numero de fila
    //la y es el numero de columna
    int x, y;
} dosDatos;

void Facil() {
    //apertura del fichero:
    FILE *map;
    map = fopen("Mapas25x25.txt", "r");
    //nos dice el estado del mapa:
    if (map == NULL) {
        printf("No se ha encontrado el mapa.\n");
        return 1;
    } else {
        printf("Abierto correctamente.\n");
    }

    juego(map);

    fclose(map);

    resultadosLB();
}

void Medio() {
    FILE *map;
    map = fopen("Mapas50x50.txt", "r");
    //nos dice el estado del mapa:
    if (map == NULL) {
        printf("No se ha encontrado el mapa.\n");
        return 1;
    } else {
        printf("Abierto correctamente.\n");
    }

    juego(map);

    fclose(map);

    resultadosLB();
}

void Dificil() {
    FILE *map;
    map = fopen("Mapas100x100.txt", "r");
    //nos dice el estado del mapa:
    if (map == NULL) {
        printf("No se ha encontrado el mapa.\n");
        return 1;
    } else {
        printf("Abierto correctamente.\n");
    }

    juego(map);

    fclose(map);

    resultadosLB();
}

void juego(FILE *map) {
    //[numero de laberinto][fila del laberinto][columna del laberinto]
    char mapas[30][200][200];

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
                //escaneo del punto de inicio
                //no va a ser necesario cuando se ponga el 
                //sistema para que el jugador ponga el punto de inicio
                if (mapas[i][j][k] == 'x') {
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

    //a arreglar: la n tiene que ser random para elegir el mapa
    int n = 0;
    char input;
    //a arreglar: la posicion no tiene que estar determinada por el mapa
    //sino que tiene la tiene que dar el jugador.

    //declaraciones de variables que se utilizan
    dosDatos posicionactual, render;
    posicionactual.x = posicion[n].x;
    posicionactual.y = posicion[n].y;
    int check = 1;
    char izquierda, derecha, arriba, abajo;

    while (check == 1) {
        system("cls");
        //renderizado del mapa
        //si el jugador esta en una esquina se renderiza bien:
        render.x = posicionactual.x;
        render.y = posicionactual.y;
        /* if (posicionactual.y < 12) {
            render.y = 12;
        }
        if (posicionactual.x < 5) {
            render.x = 5;
        }
        if (posicionactual.y > medidas[n].y - 12) {
            render.y = medidas[n].y - 12;
        }
        if (posicionactual.x > medidas[n].x - 5) {
            render.x = medidas[n].x - 5;
        }
 */
        //imprime el mapa en pantalla
        for (i = render.x - 5; i < render.x + 5; i++) {
            for (j = render.y - 12; j < render.y + 12; j++) {
                printf("%c", mapas[n][i][j]);
            }
            printf("\n");
        }
        //coge todo lo que esta alrededor del jugador
        arriba = mapas[n][posicionactual.x - 1][posicionactual.y];
        izquierda = mapas[n][posicionactual.x][posicionactual.y - 1];
        abajo = mapas[n][posicionactual.x + 1][posicionactual.y];
        derecha = mapas[n][posicionactual.x][posicionactual.y + 1];
        //borra la X anterior
        mapas[n][posicionactual.x][posicionactual.y] = ' ';
        
        //movimiento
        input = getch();
        switch (input) {
            case 'w':
                if (arriba == ' ' || arriba == 'M') {
                    posicionactual.x--;
                } else {
                    break;
                }
                break;
            case 'W': 
                if (arriba == ' ' || arriba == 'M') {
                    posicionactual.x--;
                } else {
                    break;
                }
                break;
            case 'a':
                if (izquierda == ' ' || izquierda == 'M') {
                    posicionactual.y--;
                } else {
                    break;
                }
                break;
            case 'A':
                if (izquierda == ' ' || izquierda == 'M') {
                    posicionactual.y--;
                } else {
                    break;
                }
                break;
            case 's':
                if (abajo == ' ' || abajo == 'M') {
                    posicionactual.x++;
                } else {
                    break;
                }
                break;
            case 'S':
                if (abajo == ' ' || abajo == 'M') {
                    posicionactual.x++;
                } else {
                    break;
                }
                break;
            case 'd':
                if (derecha == ' ' || derecha == 'M') {
                    posicionactual.y++;
                } else {
                    break;
                }
                break;
            case 'D':
                if (derecha == ' ' || derecha == 'M') {
                    posicionactual.y++;
                } else {
                    break;
                }
                break;
            
            default:
                break;
        }
        //Pone la X en el mapa de nuevo
        mapas[n][posicionactual.x][posicionactual.y] = 'X';
        //comprueba si el jugador ha llegado a la meta
        if (posicionactual.x == meta[n].x) {
            if (posicionactual.y == meta[n].y) {
                system("cls");
                check = 0;
            }
        }
        if (posicionactual.y == meta[n].y) {
            if (posicionactual.x == meta[n].x) {
                system("cls");
                check = 0;
            }
        }
    }
}