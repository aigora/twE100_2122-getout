//opcion facil
void Facil();

//opcion medio
void Medio();

//opcion dificil
void Dificil();

//opcion personalizado
void Personalizado();

//el juego en si
void juego(FILE *map);

typedef struct 
{
    int x, y;
}dosDatos;

//funciones en relacion a movimiento
dosDatos analizar_posicion_jugador(char mapas[][200][200], dosDatos medidas[], int mapa_jugable);

dosDatos analizar_posicion_salida(char mapas[][200][200], dosDatos medidas[], int mapa_jugable);

void decidir_posicion(char mapas[][200][200],dosDatos medidas[], int mapa_jugable);

void mov(char mapas[][200][200], dosDatos medidas[], int mapa_jugable);
//Dice pistas para saber donde esta la meta cada 15 movimientos
void Pista_meta(char mapas[][200][200], dosDatos medidas[], int mapa_jugable);
//imprimir los mapas personalizaddos para escoger
int imprimir_mapa_entero(char mapas[][200][200], dosDatos medidas[], int numero_mapas);

//funcion de muestra de mapa
void imprimir_area(char mapas[][200][200], dosDatos medidas[], int mapa_jugable);
//impresion del mapa a editar
void imprimir_lab(char mapa[50][50], dosDatos medidas, dosDatos posicion);
//Edicion del laberinto
void editar_lab(char mapa[50][50], dosDatos medidas, dosDatos posicion, char caso);

dosDatos mover_cursor(char mapa[50][50], dosDatos medidas, dosDatos posicion, char caso);

char detectar_salida(char mapa[50][50], dosDatos medidas, dosDatos posicion);
//Guardado de laberinto
char guardar();
//Laberinto creado
void editor();
//
//funcion del juego final
void getout();