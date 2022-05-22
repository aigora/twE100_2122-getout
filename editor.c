#pragma once
#include <stdio.h>
#include <conio.h>

#include "juego.h"
#include "pantallas.h"

void editor()
{
    FILE *map;
    int i, j, detectar, k=0;
    char save, editar, pared, mapa[50][50], inservible[50][50];
    dosDatos p, medidas;
    p.x=1;
    p.y=1;
    for ( i = 0; i < 50; i++)
    {
        for ( j = 0; j < 50; j++)
        {
            inservible[i][j]=0;
        }
    }
    do {
        pantallaDimensiones();
        scanf("%i %i", &medidas.x, &medidas.y);
        if ((medidas.x>=4&&medidas.x<=50)) {
            if (medidas.y>=4&&medidas.y<=50) {
                k = 1;
            }
        } else {
            printf("No ha introducido unas coordenadas dentro del rango\nVuelva a intentarlo.");
            k = 0;
        }
        system("pause");
        system("cls");
    } while (k == 0);

    for ( i = 0; i < medidas.x; i++)
    {
        for ( j = 0; j < medidas.y; j++)
        {
            mapa[i][j]='x';
        }      
    }
    for ( i = 0; i < medidas.x; i++)
    {
        mapa[i][0]='#';
        mapa[i][medidas.y-1]='#';
    }
    for ( j = 0; j < medidas.y; j++)
    {
        mapa[0][j]='#';
        mapa[medidas.x-1][j]='#';
    }

    do
    {
        imprimir_lab(mapa,medidas, p, inservible);
        fflush(stdin);
        pared=getch();

        if (pared==80||pared==77||pared==75||pared==72||pared=='w'||pared=='a'||pared=='s'||pared=='d'||pared=='W'||pared=='A'||pared=='S'||pared=='D') {
            p=mover_cursor(mapa,medidas, p, pared);
        }

        if (pared=='e'||pared=='r'||pared=='t'||pared=='E'||pared=='R'||pared=='T'||pared==13) {
            p=editar_lab(mapa, medidas, p, pared);
        }
        if (pared=='G'||pared=='g') {
            detectar=detectar_salida(mapa, medidas, p);
            if (detectar==1)
            {
                save=guardar();
            }
            else
            {
                imprimir_lab(mapa, medidas, p, inservible);
                printf("\nNo has a%cadido una salida\n", 164);
                system("pause");
            }
        }
        if (pared == 'x' || pared == 'X') {
            char decision;
            decision = salida();
            if (decision == 's') {
                break;
            }
            if (decision == 'n') {
                //do nothing
            }
        }

    } while (save!='G');

    if (save=='G')
    {
        for ( i = 0; i < medidas.x; i++)
        {
            for ( j = 0; j < medidas.y; j++)
            {
                if (mapa[i][j]=='x')
                {
                    mapa[i][j]='o';
                }
            }
        }
        map=fopen("Niveles_editor.txt", "a");
        fprintf(map, "%i %i\n", medidas.x, medidas.y);
        for ( i = 0; i < medidas.x; i++)
        {
            for ( j = 0; j < medidas.y; j++)
            {
                fprintf(map, "%c", mapa[i][j]);
            }
            fprintf(map, "\n");
        }
        fclose(map);
    }
    
}

void imprimir_lab(char mapa[50][50], dosDatos medidas, dosDatos posicion, char paredes[50][50])
{
    int i, j;
    system("cls");
    for ( i = 0; i < medidas.x; i++)
    {
        printf("\t\t\t\t\t");
        for ( j = 0; j < medidas.y; j++)
        {
            if (i==posicion.x&&j==posicion.y)
            {
                if (mapa[i][j]=='#')
                {
                    printf("\x1b[33m");
                    printf("%c%c", 219, 219);
                    printf("\x1b[0m");
                }
                else
                {
                    if (mapa[i][j]=='x')
                    {
                        printf("\x1b[33m");
                        printf("%c%c", 219, 219);
                        printf("\x1b[0m");
                    }
                    else{
                        printf("\x1b[33m");
                        printf("%c ", mapa[i][j]);
                        printf("\x1b[0m");
                    }
                }
            }
            else
            {
                if (mapa[i][j]=='#')
                {
                    printf("%c%c", 219, 219);
                }
                else
                {
                    if (paredes[i][j]=='x')
                    {
                        printf("\x1b[31m");
                        printf("%c%c", 219, 219);
                        printf("\x1b[0m");
                    }
                    else{
                        if (mapa[i][j]=='x')
                        {
                            printf("\x1b[30m");
                            printf("%c%c", 219, 219);
                            printf("\x1b[0m");
                        }
                        else{
                            printf("%c ", mapa[i][j]);
                        }
                    }
                }
            }
        }
        printf("\n");
    }
    seccionInstrucciones();
}

dosDatos editar_lab(char mapa[50][50], dosDatos medidas, dosDatos posicion, char caso)
{
    int permiso;
    int i, j, bucle=1, save=0;
    char nueva_entrada='x', guardar;
    dosDatos aux, posf;
    char paredes[50][50];
    aux.x=posicion.x;
    aux.y=posicion.y;
    for ( i = 0; i < medidas.x; i++)
    {
        for ( j = 0; j < medidas.y; j++)
        {
            paredes[i][j]='a';
        }
    }
    if (caso=='T'||caso=='t')
    {
        mapa[posicion.x][posicion.y]='#';
        return posicion;
    }
    if (caso==13)
    {
        do
        {
            paredes[aux.x][aux.y]='x';
            nueva_entrada=getch();
            if (nueva_entrada==80||nueva_entrada==77||nueva_entrada==75||nueva_entrada==72||nueva_entrada=='w'||nueva_entrada=='a'||nueva_entrada=='s'||nueva_entrada=='d'||nueva_entrada=='W'||nueva_entrada=='A'||nueva_entrada=='S'||nueva_entrada=='D')
            {
                posicion=mover_cursor(mapa, medidas, posicion, nueva_entrada);
                paredes[posicion.x][posicion.y]='x';
                imprimir_lab(mapa, medidas, posicion, paredes);
                posf.x=posicion.x;
                posf.y=posicion.y;
            }
            if (nueva_entrada==13)
            {
                printf("    Guardar cambios:\n    Si(s)\n    No(n)");
                guardar=getch();
                if (guardar=='s'||guardar=='S')
                {
                    for ( i = 0; i < medidas.x; i++)
                    {
                        for ( j = 0; j < medidas.y; j++)
                        {
                            if (paredes[i][j]=='x')
                            {
                                mapa[i][j]='#';
                            }
                        }
                    }
                    bucle=0;
                }
                if (guardar=='n'||guardar=='N')
                {
                    bucle=0;
                }
                else{

                }
            }
        } while (bucle==1);
        return posf;   
    }
    if (caso=='e'||caso=='E')
    {
        if ((posicion.x==0)||(posicion.x==medidas.x-1)||(posicion.y==0)||(posicion.y==medidas.y-1))
        {
            printf("No se pueden editar las paredes predeterminadas\n");
            system("pause");
            return posicion;
        }
        else
        {
            mapa[posicion.x][posicion.y]= 'x';
            return posicion;
        }
    }
    if (caso=='r'||caso=='R')
    {
        if ((posicion.x==0)||(posicion.x==medidas.x-1)||(posicion.y==0)||(posicion.y==medidas.y-1))
        {
            printf("No se pueden editar las paredes predeterminadas\n");
            system("pause");
            return posicion;
        }
        else{
            permiso=detectar_salida(mapa, medidas, posicion);
            if (permiso==1)
            {
                printf("Ya existe una salida\n");
                system("pause");
                mapa[posicion.x][posicion.y]= 'x';
                return posicion;
            }
            if (permiso==0)
            {
                mapa[posicion.x][posicion.y]='M';
                return posicion;
            }   
        }
    }
}

dosDatos mover_cursor(char mapa[50][50], dosDatos medidas, dosDatos posicion, char caso)
{
    int k=1;
    do{
        switch (caso)
        {
            case (72):
                if ((posicion.x>=0)&&(posicion.x<=medidas.x-1))
                {
                    if (posicion.x==0)
                    {
                        posicion.x=1;
                    }
                    else
                    {
                        posicion.x=posicion.x-1;    
                    }
                    k=0;
                }
                else
                {
                    k=1;
                }
                break;
            case ('W'):
                if ((posicion.x>=0)&&(posicion.x<=medidas.x-1))
                {
                    if (posicion.x==0)
                    {
                        posicion.x=1;
                    }
                    else
                    {
                        posicion.x=posicion.x-1;    
                    }
                    k=0;
                }
                else
                {
                    k=1;
                }
                break; 
            case ('w'):
                if ((posicion.x>=0)&&(posicion.x<=medidas.x-1))
                {
                    if (posicion.x==0)
                    {
                        posicion.x=1;
                    }
                    else
                    {
                        posicion.x=posicion.x-1;    
                    }
                    k=0;
                }
                else
                {
                    k=1;
                }
                break; 
            case (80):
                if ((posicion.x>=0)&&(posicion.x<=medidas.x-1))
                {
                    if (posicion.x==medidas.x-1)
                    {
                        posicion.x=medidas.x-2;
                    }
                    else
                    {
                        posicion.x=posicion.x+1;
                    }
                    k=0;    
                }
                else
                {
                    k=1;
                }
                break;
            case ('S'):
                if ((posicion.x>=0)&&(posicion.x<=medidas.x-1))
                {
                    if (posicion.x==medidas.x-1)
                    {
                        posicion.x=medidas.x-2;
                    }
                    else
                    {
                        posicion.x=posicion.x+1;
                    }
                    k=0;    
                }
                else
                {
                    k=1;
                }
                break; 
            case ('s'):
                if ((posicion.x>=0)&&(posicion.x<=medidas.x-1))
                {
                    if (posicion.x==medidas.x-1)
                    {
                        posicion.x=medidas.x-2;
                    }
                    else
                    {
                        posicion.x=posicion.x+1;
                    }
                    k=0;    
                }
                else
                {
                    k=1;
                }
                break; 
            case (77):
                if ((posicion.y>=0)&&(posicion.y<=medidas.y-1))
                {
                    if (posicion.y==medidas.y-1)
                    {
                        posicion.y=medidas.y-2;
                    }
                    else
                    {
                        posicion.y=posicion.y+1;
                    }
                    k=0;    
                }
                else
                {
                    k=1;
                }
                break;
            case ('D'):
                if ((posicion.y>=0)&&(posicion.y<=medidas.y-1))
                {
                    if (posicion.y==medidas.y-1)
                    {
                        posicion.y=medidas.y-2;
                    }
                    else
                    {
                        posicion.y=posicion.y+1;
                    }
                    k=0;    
                }
                else
                {
                    k=1;
                }
                break; 
            case ('d'):
                if ((posicion.y>=0)&&(posicion.y<=medidas.y-1))
                {
                    if (posicion.y==medidas.y-1)
                    {
                        posicion.y=medidas.y-2;
                    }
                    else
                    {
                        posicion.y=posicion.y+1;
                    }
                    k=0;    
                }
                else
                {
                    k=1;
                }
                break; 
            case (75):
                if ((posicion.y>=0)&&(posicion.y<=medidas.y-1))
                {
                    if (posicion.y==0)
                    {
                        posicion.y=1;
                    }
                    else
                    {
                        posicion.y=posicion.y-1;
                    }
                    k=0;    
                }
                else
                {
                    k=1;
                }
                break;
            case ('A'):
                if ((posicion.y>=0)&&(posicion.y<=medidas.y-1))
                {
                    if (posicion.y==0)
                    {
                        posicion.y=1;
                    }
                    else
                    {
                        posicion.y=posicion.y-1;
                    }
                    k=0;    
                }
                else
                {
                    k=1;
                }
                break; 
            case ('a'):
                if ((posicion.y>=0)&&(posicion.y<=medidas.y-1))
                {
                    if (posicion.y==0)
                    {
                        posicion.y=1;
                    }
                    else
                    {
                        posicion.y=posicion.y-1;
                    }
                    k=0;    
                }
                else
                {
                    k=1;
                }
                break; 
            default:
                break;
            }
        }while(k==1);
    return posicion;
}

char detectar_salida(char mapa[50][50], dosDatos medidas, dosDatos posicion)
{
    int i, j;
    for ( i = 0; i < medidas.x; i++)
    {
        for ( j = 0; j < medidas.y; j++)
        {
            if (mapa[i][j]=='M')
            {
                return 1;
            }
        }
    }
    return 0;
}

char guardar()
{
    char aux;
    int loop = 1;
    printf("\n    Quieres guardar?\n    S - Si\n    N - No");

    do {
        aux=getch();

        if (aux == 's' || aux == 'S') {
            return 'G';
        }
        if (aux == 'n' || aux == 'N') {
            return 'q';
        }  
    } while (loop == 1);
    
}

char salida() {
    char input;
    int loop = 1;
    printf("\n    Seguro que quieres salir?\n    S - Si\n    N - No");
    
    while (loop == 1) {
        input = getch();
        
        if (input == 's' || input == 'S') {
            return 's';
        }
        if (input == 'n' || input == 'N') {
            return 'n';
        }
    }
}