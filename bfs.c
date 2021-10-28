#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>// Booleanos
#include "Juego.h"

// typedef struct node
// {
//     int row;
//     int col;
// }coordenada;


void pinta(char mapa [][5])
{
    int filas = 2, columnas = 5;
    for(int i=0;i<filas;i++)
    {
        for(int j=0;j<columnas;j++)
        {
            printf("%c",mapa[i][j]);
        }
         printf("\n");
    }
}

void pintapi(coordenada mapa [][5])
{
    int filas = 2, columnas = 5;
    for(int i=0;i<filas;i++)
    {
        for(int j=0;j<columnas;j++)
        {
            printf("row -> %d, col -> %d \t",mapa[i][j].row, mapa[i][j].col);
        }
         printf("\n");
    }
}

int filas = 2, columnas = 5;
int bfs(char mapa [filas][columnas], coordenada c){
    char mapacopy[2][5];
    coordenada pi[2][5];
    for(int i=0;i<2;i++){
        for(int j=0;j<5;j++){
            mapacopy[i][j]=mapa[i][j];
            coordenada p;
            p.row = c.col;
            p.col = c.col;

            pi[i][j] = p;
        }
    }
    mapacopy[0][0] = 'Z';

    bool wasChanged = true;
    while (wasChanged)
    {
        wasChanged = false;

        for (int i = c.row; i < filas; i++)
        {
            for (int j = c.col; j < columnas; j++)
            {

            }
        }
    }

    pinta(mapacopy);
    pinta(mapa);
    pintapi(pi);
}



int main()
{
    char mapa[2][5] = {
        {'A', 'E', 'I', 'O', 'U'},
        {'a', 'e', 'i', 'o', 'u'}};

    coordenada p;
    p.row = 1;
    p.col = 0;
    bfs(mapa, p);

    pinta(mapa);

    return 0;
}