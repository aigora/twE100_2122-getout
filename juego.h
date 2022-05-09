//opcion facil
void Facil();

//opcion medio
void Medio();

//opcion dificil
void Dificil();

//el juego en si
void juego(FILE *map);

typedef struct 
{
    int x, y;
}dosDatos;

//funciones en relacion a movimiento
dosDatos analizar_posicion(char c[][200][200], dosDatos medidas[], int mapa_jugable);
void decidir_posicion(char c[][200][200], int mapa_jugable);
void moverse(char c[][200][200], dosDatos medidas[], int mapa_jugable);

//funcion de muestra de mapa
void imprimir_area(char c[][200][200], dosDatos medidas[], int mapa_jugable);