// #include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"


void pinta(char mapa [][columnas])
{
    int i,j;
    for( i=0;i<filas;i++)
    {
        for( j=0;j<columnas;j++)
        {
            printf("%c ",mapa[i][j]);
        }
         printf("\n");
    }
}

// void pinta_pi(coordenada mapa [][columnas])
// {
//     int i,j;
//     for( i=0;i<filas;i++)
//     {
//         for( j=0;j<columnas;j++)
//         {
//             printf("row -> %d, col -> %d \t",mapa[i][j].row, mapa[i][j].col);
//         }
//          printf("\n");
//     }
// }

void pinta_int(int mapa [][columnas])
{
    int i,j;
    for( i=0;i<filas;i++)
    {
        for( j=0;j<columnas;j++)
        {
            printf("%d ",mapa[i][j]);
        }
         printf("\n");
    }
}