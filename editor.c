#pragma once
#include <stdio.h>
#include <conio.h>

#include "juego.h"

void editor()
{
    FILE *map;
    int i, j, detectar, k=0;
    char save, editar, pared, mapa[50][50];
    dosDatos p, medidas;
    p.x=1;
    p.y=1;
    do
    {
        printf("Determine la dimension del laberinto(minimo 4x4, maximo 50x50)\n");
        scanf("%i %i", &medidas.x, &medidas.y);
        if ((medidas.x>=4&&medidas.x<=50))
        {
            if (medidas.y>=4&&medidas.y<=50)
            {
                k=1;
            }
        }
        else
        {
            printf("Escribe un laberinto con las caracteristicas indicadas\n");
            k=0;
        }
        system("pause");
        system("cls");
    } while (k==0);
    printf("Cuando termines presiona G(solo usa mayusculas con la G)\n");
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
    system("pause");
    system("cls");
    do
    {
        imprimir_lab(mapa,medidas, p);
        printf("mueve cursor(w,a,s,d)\n");
        printf("presiona segun lo que quieras colocar:\npared(p)\nespacio(o)\nsalida(m)\nGuardar(G)\nSalir del editor(x)\n");
        fflush(stdin);
        pared=getch();
        if (pared=='w'||pared=='d'||pared=='a'||pared=='s')
        {
            p=mover_cursor(mapa,medidas, p, pared);
        }
        if (pared=='p'||pared=='o'||pared=='m')
        {
            editar_lab(mapa, medidas, p, pared);
        }
        /* if (pared=='o')
        {
            editar_lab(c, a, b, p, pared);
        }
        if (pared=='m')
        {
            editar_lab(c, a, b, p, pared);
        } */
        if (pared=='G'||pared=='g')
        {
            detectar=detectar_salida(mapa, medidas, p);
            if (detectar==1)
            {
                save=guardar();
            }
            else
            {
                imprimir_lab(mapa, medidas, p);
                printf("\nNo has a%cadido una salida\n", 164);
                system("pause");
            }
        }
        if (pared=='x')
        {
            break;
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
void imprimir_lab(char mapa[50][50], dosDatos medidas, dosDatos posicion)
{
    int i, j;
    system("cls");
    printf("\n\n\n\n\n");
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
        printf("\n");
    }
}
void editar_lab(char mapa[50][50], dosDatos medidas, dosDatos posicion, char caso)
{
    int permiso;
    if (caso=='p')
    {
        mapa[posicion.x][posicion.y]='#';
    }
    if (caso=='o')
    {
        if ((posicion.x==0)||(posicion.x==medidas.x-1)||(posicion.y==0)||(posicion.y==medidas.y-1))
        {
            printf("No se pueden editar las paredes predeterminadas\n");
            system("pause");
        }
        else
        {
            mapa[posicion.x][posicion.y]= 'x';
        }
    }
    if (caso=='m')
    {
        if ((posicion.x==0)||(posicion.x==medidas.x-1)||(posicion.y==0)||(posicion.y==medidas.y-1))
        {
            printf("No se pueden editar las paredes predeterminadas\n");
            system("pause");
        }
        else{
            permiso=detectar_salida(mapa, medidas, posicion);
            if (permiso==1)
            {
                printf("Ya existe una salida\n");
                system("pause");
                mapa[posicion.x][posicion.y]= 'x';
            }
            if (permiso==0)
            {
                mapa[posicion.x][posicion.y]='M';
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
    printf("\nQuieres guardar?\nsi(y)\tno(n)");
    aux=getch();
    if (aux=='y')
    {
        return 'G';
    }
    else
    {
        return 'a';
    }
}