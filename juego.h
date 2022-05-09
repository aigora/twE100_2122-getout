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
dosDatos analizar_posicion_jugador(char mapas[][200][200], dosDatos medidas[], int mapa_jugable);
dosDatos analizar_posicion_salida(char mapas[][200][200], dosDatos medidas[], int mapa_jugable);
void decidir_posicion(char mapas[][200][200], int mapa_jugable);
void mov(char mapas[][200][200], dosDatos medidas[], int mapa_jugable);

//funcion de muestra de mapa
void imprimir_area(char mapas[][200][200], dosDatos medidas[], int mapa_jugable);