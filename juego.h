//opcion facil
void Facil(int *exito);

//opcion medio
void Medio(int *exito);

//opcion dificil
void Dificil(int *exito);

//opcion personalizado
void Personalizado(int *exito);

//el juego en si
int juego(FILE *map, char dificultad);

typedef struct 
{
    int x, y;
}dosDatos;

//funciones en relacion a movimiento
dosDatos analizar_posicion_jugador(char mapas[][200][200], dosDatos medidas[], int mapa_jugable);

dosDatos analizar_posicion_salida(char mapas[][200][200], dosDatos medidas[], int mapa_jugable);

void decidir_posicion(char mapas[][200][200],dosDatos medidas[], int mapa_jugable, char dificultad);

void mov(char mapas[][200][200], dosDatos medidas[], int mapa_jugable, char *pista, int *quit);
//Dice pistas para saber donde esta la meta en cada movimiento
void Pista_meta(char mapas[][200][200], dosDatos medidas[], int mapa_jugable);
//imprimir los mapas personalizaddos para escoger
int imprimir_mapa_entero(char mapas[][200][200], dosDatos medidas[], int numero_mapas);

//funcion de muestra de mapa
void imprimir_area(char mapas[][200][200], dosDatos medidas[], int mapa_jugable);
//impresion del mapa a editar
void imprimir_lab(char mapa[50][50], dosDatos medidas, dosDatos posicion, char paredes[50][50]);
//Edicion del laberinto
dosDatos editar_lab(char mapa[50][50], dosDatos medidas, dosDatos posicion, char caso);

dosDatos mover_cursor(char mapa[50][50], dosDatos medidas, dosDatos posicion, char caso);

char detectar_salida(char mapa[50][50], dosDatos medidas, dosDatos posicion);

//Guardado de laberinto
char guardar();

//Confirmacion salida del laberinto
char salida();

//Laberinto creado
void editor();

//Abre fichero y almacena pasos utilizados en un archivo txt.
void guardar_numero_pasos(int num_pasos);