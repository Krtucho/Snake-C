#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "bfs.h"


int main(int argc, char *argv[])
{
//    int filas, columnas;
//     printf("Introduzca la cantidad de filas: ");
//     scanf("%d", &filas);

//     printf("Introduzca la cantidad de columnas: ");
//     scanf("%d", &columnas);

    // printf("%d \n", global);

    // global = 10;
    // printf("%d \n", global);

    char mapa[2][5] = {
        {'.', '.', '.', '@', '.'},
        {'.', '.', '.', 'x', '.'}};

    // pinta(mapa);

    // Juego(filas,columnas);

    // int width, columnas;

    filas = atoi(argv[1]); // Creo q atoi proviene de stdlib...Creo...
    
    columnas = atoi(argv[2]);

    printf("width: %d, height: %d\n", filas, columnas);

    coordenada p;
    p.row = 0;
    p.col = 0;

    int pasos = 0;

    parte_t * sols = (parte_t*)malloc(sizeof(parte_t));

    sols = bfs(mapa, p, &pasos);
    printf("\n pasos: %d \n", pasos);

    print_list(sols);

    return 0;
}












