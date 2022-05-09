#include <stdio.h>
#include <conio.h>
#include "juego.h"
#include "acciones.h"
#include "pantallas.h"

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

void juego(FILE *map) 
{
    //[numero de laberinto][fila del laberinto][columna del laberinto]
    char mapas[30][200][200];

    //utilizaremos la i para el numero de laberinto
    //la j para la fila del laberinto y la k para la columna del laberinto
    int i, j, k;
    dosDatos medidas[30];
    
    for (i = 0; i < 30; i++) 
    {
        //obetenemos las dimensines del laberinto y las almacenamos
        //en una estructura
        fscanf(map, "%d %d", &medidas[i].x, &medidas[i].y);
        //obtenemos el laberinto escaneando por filas
        for (j = 0; j < medidas[i].x; j++) 
        {
            fscanf(map, "%s", mapas[i][j]);
            //va escaneando por cada elemento de la matriz
            //buscando "o" para sustituirlos por espacios.
            for (k = 0; k < medidas[i].y; k++) 
            {
                if (mapas[i][j][k] == 'o') 
                {
                    mapas[i][j][k] = ' ';
                }
            }
        }
    }
    dosDatos salida;
    //a arreglar: la n tiene que ser random para elegir el mapa
    int mapa_jugable;
    //Provisional
    mapa_jugable=0;
    //Para que funcione con los demas mapas hay que borrar las X en todos los mapas

    //Funcion para definir cordenadas de jugador
    decidir_posicion(mapas, mapa_jugable);
    salida=analizar_posicion(mapas, medidas, mapa_jugable);
    do
    {
        imprimir_area(mapas, medidas, mapa_jugable);
        mov(mapas, medidas, mapa_jugable);
        system("cls");
    } while (mapas[mapa_jugable][salida.x][salida.y]=='X');
    system("cls");
}

void mov(char c[][200][200], dosDatos medidas[], int mapa_jugable)
{
    int i, j, k=0;
    dosDatos jugador;
    char up, down, left, right;
    char tecla_mov;
    //Busca donde se encuentra el jugador
    jugador=analizar_posicion(c, medidas, mapa_jugable);
    //determina lo que rodea al jugador
    up=c[mapa_jugable][jugador.x-1][jugador.y];
    down=c[mapa_jugable][jugador.x+1][jugador.y];
    right=c[mapa_jugable][jugador.x][jugador.y+1];
    left=c[mapa_jugable][jugador.x][jugador.y-1];
    //elimina la posicion anterior del jugador
    c[mapa_jugable][jugador.x][jugador.y]=' ';
    do
    {
        fflush(stdin);
        tecla_mov=getch();
        switch (tecla_mov)
        {
        case('w'):
            if (up=' '||up=='M')
            {
                jugador.x=jugador.x-1;
                k=1;
            }
            else
            {
                k=0;
            }
            break;
        case ('W'):
            if (up=' '||up=='M')
            {
                jugador.x=jugador.x-1;
                k=1;
            }
            else
            {
                k=0;
            }
            break;
        case ('s'):
            if (down=' '||down=='M')
            {
                jugador.x=jugador.x+1;
                k=1;
            }
            else
            {
                k=0;
            }
            break;
        case ('S'):
            if (down=' '||down=='M')
            {
                jugador.x=jugador.x+1;
                k=1;
            }
            else
            {
                k=0;
            }
            break;
        case ('d'):
            if (right=' '||right=='M')
            {
                jugador.y=jugador.y+1;
                k=1;
            }
            else
            {
                k=0;
            }
            break;
        case ('D'):
            if (right=' '||right=='M')
            {
                jugador.y=jugador.y+1;
                k=1;
            }
            else
            {
                k=0;
            }
            break;
        case ('a'):
            if (left=' '||left=='M')
            {
                jugador.y=jugador.y-1;
                k=1;
            }
            else
            {
                k=0;
            }
            break;
        case ('A'):
            if (left=' '||left=='M')
            {
                jugador.y=jugador.y-1;
                k=1;
            }
            else
            {
                k=0;
            }
            break;
        default:
            break;
        }
    } while (k==0);
    c[mapa_jugable][jugador.x][jugador.y]='X';
}
dosDatos analizar_posicion(char c[][200][200], dosDatos medidas[], int mapa_jugable)
{
    dosDatos posicion_jugador;
    int i, j, k;
    for ( i = 0; i < medidas[mapa_jugable].x; i++)
    {
        for ( j = 0; j < medidas[mapa_jugable].y; j++)
        {
            if (c[mapa_jugable][i][j]=='X')
            {
                posicion_jugador.x=i;
                posicion_jugador.y=j;
            }
        }
    }
    return posicion_jugador;
}
void decidir_posicion(char c[][200][200], int mapa_jugable)
{
    dosDatos jugador;
    int k=0;
    do
    {
        printf("Escribe una posicion de la cual empezar\n");
        printf("Recuerda las dimensiones de los niveles\nFacil:25x25\nMedio:50x50\nDificil:100x100\n");
        scanf("%i %i", &jugador.x, &jugador.y);
        if (c[mapa_jugable][jugador.x][jugador.y]==' ')
        {
            c[mapa_jugable][jugador.x][jugador.y]='X';
            k=1;
        }
        else
        {
            k=0;
            printf("Si no se borra este comando es porque la posicion coincide con una pared, por favor ingrese otra cordenada\n");
            system("pause");
            system("cls");
        }
    } while (k==0);
}
void imprimir_area(char c[][200][200], dosDatos medidas[], int mapa_jugable)
{
    int i, j, k;
    dosDatos jugador, area;
    jugador=analizar_posicion(c, medidas, mapa_jugable);
    if (jugador.y<12){
        area.y=12;
    }
    if (jugador.x<5){
        area.x=5;
    }
    if (jugador.y>medidas[mapa_jugable].y-12){
        area.y=medidas[mapa_jugable].y-12;
    }
    if (jugador.x>medidas[mapa_jugable].x-5){
        area.x=medidas[mapa_jugable].x-5;
    }
    printf("\n\n\n\n\n");
    for ( i = area.x-5; i < area.x+5; i++)
    {
        printf("\t\t\t\t\t\t");
        for ( j = area.y-12; j < area.y+12; j++)
        {
            printf("%c ", c[mapa_jugable][i][j]);
        }
        printf("\n");
    }
}