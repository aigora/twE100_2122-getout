//estructura de datos
typedef struct 
{
    int x, y;
}dosDatos;
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