#pragma once
#include <time.h>
#include <stdio.h>
#include <conio.h>

#include "juego.h"
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
}

void Personalizado() {
    FILE *map;
    map = fopen("Niveles_editor.txt", "r");
    //nos dice el estado del mapa:
    if (map == NULL) {
        printf("No se ha encontrado el mapa.\n");
        return 1;
    } else {
        printf("Abierto correctamente.\n");
    }

    juego(map);

    fclose(map);
}

void juego(FILE *map) 
{
    //[numero de laberinto][fila del laberinto][columna del laberinto]
    char mapas[30][200][200];

    //utilizaremos la i para el numero de laberinto
    //la j para la fila del laberinto y la k para la columna del laberinto
    int i, j, k, n_laberintos=0, mapa_jugable;
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
    if ((medidas[0].x==1)&&(medidas[0].y==11))
    {
        for ( i = 0; i < 30; i++)
        {
            if ((medidas[i].x>0)&&(medidas[i].y>0))
            {
                n_laberintos=n_laberintos+1;
            }
        }
        imprimir_mapa_entero(mapas, medidas, n_laberintos);
        scanf("%i", &mapa_jugable);
    }
    else
    {
        for ( i = 0; i < 30; i++)
        {
            if ((medidas[i].x>0)&&(medidas[i].y>0))
            {
                n_laberintos=n_laberintos+1;
            }
        }
        srand(time(NULL));
        mapa_jugable = rand() % n_laberintos+1;
        mapa_jugable = mapa_jugable-1;
    }
    dosDatos exit;
    system("cls");
    //Funcion para definir cordenadas de jugador
    decidir_posicion(mapas, medidas, mapa_jugable);
    exit=analizar_posicion_salida(mapas, medidas, mapa_jugable);
    imprimir_area(mapas, medidas, mapa_jugable);
    do
    {
        mov(mapas, medidas, mapa_jugable);
        imprimir_area(mapas, medidas, mapa_jugable);
    } while (mapas[mapa_jugable][exit.x][exit.y] == 'M');
    system("cls");
}

void mov(char mapas[][200][200], dosDatos medidas[], int mapa_jugable)
{
    int k=0;
    dosDatos jugador;
    char up, down, left, right;
    char input;
    //Busca donde se encuentra el jugador
    jugador=analizar_posicion_jugador(mapas, medidas, mapa_jugable);
    //determina lo que rodea al jugador
    up=mapas[mapa_jugable][jugador.x-1][jugador.y];
    down=mapas[mapa_jugable][jugador.x+1][jugador.y];
    right=mapas[mapa_jugable][jugador.x][jugador.y+1];
    left=mapas[mapa_jugable][jugador.x][jugador.y-1];
    //elimina la posicion anterior del jugador
    mapas[mapa_jugable][jugador.x][jugador.y]=' ';
    do
    {
        fflush(stdin);
        input=getch();
        switch (input)
        {
        case('w'):
            if (up==' '||up=='M')
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
            if (up==' '||up=='M')
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
            if (down==' '||down=='M')
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
            if (down==' '||down=='M')
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
            if (right==' '||right=='M')
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
            if (right==' '||right=='M')
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
            if (left==' '||left=='M')
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
            if (left==' '||left=='M')
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
    mapas[mapa_jugable][jugador.x][jugador.y]='x';
}

dosDatos analizar_posicion_jugador(char mapas[][200][200], dosDatos medidas[], int mapa_jugable)
{
    dosDatos posicion;
    int i, j;
    for ( i = 0; i < medidas[mapa_jugable].x; i++)
    {
        for ( j = 0; j < medidas[mapa_jugable].y; j++)
        {
            if (mapas[mapa_jugable][i][j]=='x')
            {
                posicion.x=i;
                posicion.y=j;
            }
        }
    }
    return posicion;
}

void decidir_posicion(char mapas[][200][200],dosDatos medidas[], int mapa_jugable)
{
    dosDatos jugador;
    int k=0;
    do
    {
        if ((medidas[0].x==1)&&(medidas[0].y==11))
        {
            PantallaSeleccionPosicionEditor();
            printf("%ix%i\n", medidas[mapa_jugable].x, medidas[mapa_jugable].y);
            scanf("%i %i", &jugador.x, &jugador.y);
            if (mapas[mapa_jugable][jugador.x][jugador.y]==' '&&mapas[mapa_jugable][jugador.x][jugador.y]!='M')
            {
                mapas[mapa_jugable][jugador.x][jugador.y]='x';
                k=1;
            }
            else
            {
                k=0;
                printf("Si no se borra este comando es porque la posicion coincide con una pared, por favor ingrese otra cordenada\n");
                system("pause");
                system("cls");
            }
        }
        else
        {
            PantallaSeleccionPosicion();
            scanf("%i %i", &jugador.x, &jugador.y);
            if (mapas[mapa_jugable][jugador.x][jugador.y]==' '&&mapas[mapa_jugable][jugador.x][jugador.y]!='M')
            {
                mapas[mapa_jugable][jugador.x][jugador.y]='x';
                k=1;
            }
            else
            {
                k=0;
                printf("Si no se borra este comando es porque la posicion coincide con una pared, por favor ingrese otra cordenada\n");
                system("pause");
                system("cls");
            }
        }
    } while (k==0);
}

void imprimir_area(char mapas[][200][200], dosDatos medidas[], int mapa_jugable)
{
    int i, j;
    dosDatos jugador, area1, area2;
    system("cls");
    jugador=analizar_posicion_jugador(mapas, medidas, mapa_jugable);
    area1.x=jugador.x;
    area1.y=jugador.y;
    area2.x=jugador.x;
    area2.y=jugador.y;
    if (jugador.y<7){
        area1.y=7;
    }
    if (jugador.x<7){
        area1.x=7;
    }
    if (jugador.y>medidas[mapa_jugable].y-7){
        area2.y=medidas[mapa_jugable].y-7;
    }
    if (jugador.x>medidas[mapa_jugable].x-7){
        area2.x=medidas[mapa_jugable].x-7;
    } 
    //imprime el mapa entero:
    /* printf("\n\n\n");
    for ( i = 0; i < medidas[mapa_jugable].x; i++)
    {
        printf("\t\t\t\t");
        for ( j = 0; j < medidas[mapa_jugable].y; j++)
        {
            printf("%c ", mapas[mapa_jugable][i][j]);
        }
        printf("\n");
    } */
    //imprime un area entorno al jugador:
    /* printf("\n\n\n");
    for ( i = (area1.x-7); i <= (area2.x+7); i++)
    {
        printf("\t\t\t\t");
        for ( j = (area1.y-7); j <= (area2.y+7); j++)
        {
            printf("%c ", mapas[mapa_jugable][i][j]);
        }
        printf("\n");
    } */
    //imprime area entorno al jugador con el caracter 219
    printf("\n\n\n");
    for ( i = (area1.x-7); i <= (area2.x+7); i++)
    {
        printf("\t\t\t\t");
        for ( j = (area1.y-7); j <= (area2.y+7); j++)
        {
            if (mapas[mapa_jugable][i][j]=='#')
            {
                printf("%c%c", 219, 219);
            }
            else
            {
                printf("%c ", mapas[mapa_jugable][i][j]);
            }
        }
        printf("\n");
    }
}

dosDatos analizar_posicion_salida(char mapas[][200][200], dosDatos medidas[], int mapa_jugable)
{
    dosDatos posicion;
    int i, j;
    for ( i = 0; i < medidas[mapa_jugable].x; i++)
    {
        for ( j = 0; j < medidas[mapa_jugable].y; j++)
        {
            if (mapas[mapa_jugable][i][j]=='M')
            {
                posicion.x=i;
                posicion.y=j;
            }
        }
    }
    return posicion;
}
void imprimir_mapa_entero(char mapas[][200][200], dosDatos medidas[], int numero_mapas)
{
    int i, j, k;
    system("cls");
    printf("Escoge mapa:\n");
    for ( k = 1; k < numero_mapas; k++)
    {
        printf("Mapa %i\n",  k);
        printf("%i %i\n", medidas[k].x, medidas[k].y);
        for ( i = 0; i < medidas[k].x; i++)
        {
            for ( j = 0; j < medidas[k].y; j++)
            {
                if (mapas[k][i][j]=='#')
                {
                    printf("%c", 219);
                }
                else
                {
                    printf("%c", mapas[k][i][j]);
                }
            }
            printf("\n");
        }
    }
    printf("\n");
}