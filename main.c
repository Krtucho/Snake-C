#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
// #include "bfs.h"
//
// #include "Juego.h"

// #include<stdbool.h>
// #include "linked_list.h"
#include "Juego.h"
//#include "utils.h"
// #include "usando_timer.h"
// #include "bfs.h"


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

    // char mapa[2][5] = {
    //     {'.', '.', '.', '@', '.'},
    //     {'.', '.', '.', 'x', '.'}};

    // pinta(mapa);

    // Juego(filas,columnas);

    // int width, columnas;

    filas = atoi(argv[1]); // Creo q atoi proviene de stdlib...Creo...
    
    columnas = atoi(argv[2]);

    Juego(filas, columnas);

    // printf("width: %d, height: %d\n", filas, columnas);

    // coordenada p;
    // p.row = 0;
    // p.col = 0;

    // int pasos = 0;

    // parte_t * sols = (parte_t*)malloc(sizeof(parte_t));

    // sols = bfs(mapa, p, &pasos);
    // printf("\n pasos: %d \n", pasos);

    // print_list(sols);

    // parte_t * sols_rev;// = reverse(sols);
    // parte_t * sols_two = (parte_t*)malloc(sizeof(parte_t));
    // sols_two ->pos = p;
    // coordenada p_two;
    // p_two.row = 1;
    // p_two.col = 2;
    // sols_two = push_front_n_return(sols_two, p_two);
    // coordenada p_three;
    // p_three.row = 1;
    // p_three.col = 3;
    // sols_two = push_front_n_return(sols_two, p_three);
    // printf("1: %d %d \n2: %d %d\n3: %d %d\n", 
    // sols_two->pos.row, 
    // sols_two->pos.col, 
    // sols_two->next->pos.row, 
    // sols_two->next->pos.col,
    // sols_two->next->next->pos.row,
    // sols_two->next->next->pos.col);
    // *sols_two ->pos = p;
    // push_front(sols_two, p);
    // int fila = sols_two->next->pos.row;
    // printf("%d", fila);
    // printf("%d %d\n ", *sols_two->pos.row, *sols_two->pos.col);
    // print_list(sols_rev);
    // print_list(sols_two);


    return 0;
}












