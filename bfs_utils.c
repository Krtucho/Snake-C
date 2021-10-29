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

typedef struct parte
{
     struct parte * next;
    coordenada pos;
}parte_t;

int dir_x[4] = {-1, 0, 1, 0};
int dir_y[4] = { 0, 1, 0,-1};

int filas = 2, columnas = 5;

coordenada pos_siguiente(int x, int y, int direccion){
    coordenada pos;

    pos.row = x + dir_x[direccion];
    pos.col = y + dir_y[direccion];
    return pos;
}

bool pos_valida(int mapa_copy[][columnas],int rows,int cols, coordenada pos){
    if (!(pos.row >= 0 && pos.row < rows && pos.col >= 0 && pos.col < cols))
        return false;
    int valor = mapa_copy[pos.row][pos.col];
    // printf("%d \n", valor);
    if (valor== 0 || valor == -2)
        return true;
    return false;
}

void pinta(char mapa [][columnas])
{
    // int filas = 2, columnas = 5;
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

void pinta_pi(coordenada mapa [][columnas])
{
    // int filas = 2, columnas = 5;
    int i,j;
    for( i=0;i<filas;i++)
    {
        for( j=0;j<columnas;j++)
        {
            printf("row -> %d, col -> %d \t",mapa[i][j].row, mapa[i][j].col);
        }
         printf("\n");
    }
}

void pinta_int(int mapa [][columnas]){
    // int filas = 2, columnas = 5;
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

// typedef struct
// {
//      struct node * next;
//     coordenada pos;
// }parte;

void push(parte_t * head, coordenada pos) {
    parte_t * current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    /* now we can add a new variable */
    current->next = (parte_t *) malloc(sizeof(parte_t));
    current->next->pos = pos;
    current->next->next = NULL;
}
void push_front(parte_t ** head, coordenada pos) {
    parte_t * new_node;
    new_node = (parte_t *) malloc(sizeof(parte_t));

    new_node->pos = pos;
    new_node->next = *head;
    *head = new_node;
}
void print_list(parte_t * head) {
    parte_t * current = head;
    printf("Imprimiendo lista con respectivos pasos...\n");
    while (current != NULL) {
        printf("%d %d\n", current->pos.row, current->pos.col);
        current = current->next;
    }
}
// void push_front(parte * tail, parte * insertar, coordenada pos){
//     insertar->next = tail;

// }

// int filas = 2, columnas = 5;

// Via devolviendo LinkedList
parte_t * bfs(char mapa [filas][columnas], coordenada c, int * pasos){
    int mapa_copy[2][5];
    coordenada pi[2][5];


    int i,j;
    for( i=0;i<2;i++){
        for( j=0;j<5;j++){
            if(mapa[i][j] == 'x'){ // Comidita = x = -2
                mapa_copy[i][j] = -2;
            }
            else if(mapa[i][j] == '.'){ // Vacia = . = 0
                mapa_copy[i][j] = 0;
            }
            else
            {
                mapa_copy[i][j] = -1; // Obstaculos y cuerpo = -1
            }
            // coordenada p;
            // p.row = c.col;
            // p.col = c.col;

            pi[i][j] = c;
        }
    }
    mapa_copy[c.row][c.col] = 1;
    pinta_int(mapa_copy);
    // pinta_int(mapa_copy);


    bool cambio = true;
    while (cambio)
    {
        cambio = false;
        // printf("%d %d", filas, columnas);

        int i;
        for ( i = 0; i < filas; i++)
        {
            int j;
            for ( j = 0; j < columnas; j++)
            {
                // if(mapacopy[i][j] ==  '.'|| mapacopy[i][j] == '@' || mapacopy[i][j] == 'o')
                //     continue;
                // printf("%d %d", i, j);
                // printf("%d ", mapa_copy[i][j]);
                int l = mapa_copy[i][j];
                // printf("%d %d %d ",i, j,  l);

                // if(l > 1){
                //     return result;
                // }
                if(l <= 0)// Casilla vacia, con obstaculos o con comidita, estamos buscando aquellas casillas a las que se haya llegado desde otra o la 1ra desde la q comenzamos // || mapacopy[i][j] == -1)
                    continue;

                int k;
                for( k = 0; k < 4; k++){
                    coordenada pos;
                    pos = pos_siguiente( i, j, k); // Obteniendo posicion al sumar x + numero que sea en la direccion
                    // printf("pos: x:%d y:%d \n", pos.row, pos.col);
                    // printf(" \n %d %d " );
                    // printf("x: %d y:%d", pos.row, pos.col);
                    bool se_puede = pos_valida(mapa_copy, filas, columnas, pos);
                    if(se_puede){ // Comprobando que la posicion se encuentre entre los limites del mapa y que la misma este vacia
                        if(mapa_copy[pos.row][pos.col] == -2){
                            int temp_x = pos.row;
                            int temp_y = pos.col;
                            (*pasos) = mapa_copy[i][j];
                            int tamanno = mapa_copy[i][j];
                            // static coordenada result[filas*columnas];
                            int paso_actual = mapa_copy[i][j] - 1;
                            // sols = (coordenada *) malloc(pasos * sizeof(coordenada));

                            parte_t * result = (parte_t*)malloc(sizeof(parte_t));
                            result->pos.row=temp_x;
                            result->pos.col=temp_y;
                            // parte * ult = (parte*)malloc(sizeof(parte));
                            // ult->pos.row=temp_x
                            // ult->pos.col=temp_y;
                            // parte * penult = (parte*)malloc(sizeof(parte));
                            // penult->pos.row=temp_x
                            // penult->pos.col=temp_y;

                            // result -> next = ult;

                            // printf("llego");
                            coordenada actual_pos;
                            actual_pos.row = i;
                            actual_pos.col = j;
                            pi[pos.row][pos.col] = actual_pos;
                            while(temp_x != c.row || temp_y != c.col){
                                coordenada temp_pos = pi[temp_x][temp_y];
                                push(result, temp_pos);
                                // sols[0] = temp_pos;
                                // result[paso_actual] = temp_pos;
                                // printf("%d %d", temp_x, temp_y);
                                temp_x = temp_pos.row;
                                temp_y = temp_pos.col;
                                paso_actual--;

                            }
                            return result;

                        }
                        // printf("paso");
                        mapa_copy[pos.row][pos.col] = mapa_copy[i][j] + 1;
                        // pinta_int(mapa_copy);
                        cambio = true;
                        coordenada actual_pos;
                        actual_pos.row = i;
                        actual_pos.col = j;
                        pi[pos.row][pos.col] = actual_pos;
                    }

                    // free(p);
                }

            }
        }


    }

    // pinta_int(mapa_copy);
    // pinta(mapa);
    // pinta_pi(pi);

    return NULL;
}

// Via Devolviendo array
// coordenada * bfs(char mapa [filas][columnas], coordenada c, int * pasos){
//     int mapa_copy[2][5];
//     coordenada pi[2][5];


//     for(int i=0;i<2;i++){
//         for(int j=0;j<5;j++){
//             if(mapa[i][j] == 'x'){ // Comidita = x = -2
//                 mapa_copy[i][j] = -2;
//             }
//             else if(mapa[i][j] == '.'){ // Vacia = . = 0
//                 mapa_copy[i][j] = 0;
//             }
//             else
//             {
//                 mapa_copy[i][j] = -1; // Obstaculos y cuerpo = -1
//             }
//             // coordenada p;
//             // p.row = c.col;
//             // p.col = c.col;

//             pi[i][j] = c;
//         }
//     }
//     mapa_copy[c.row][c.col] = 1;
//     pinta_int(mapa_copy);
//     // pinta_int(mapa_copy);


//     bool cambio = true;
//     while (cambio)
//     {
//         cambio = false;
//         // printf("%d %d", filas, columnas);

//         for (int i = 0; i < filas; i++)
//         {
//             for (int j = 0; j < columnas; j++)
//             {
//                 // if(mapacopy[i][j] ==  '.'|| mapacopy[i][j] == '@' || mapacopy[i][j] == 'o')
//                 //     continue;
//                 // printf("%d %d", i, j);
//                 // printf("%d ", mapa_copy[i][j]);
//                 int l = mapa_copy[i][j];
//                 // printf("%d %d %d ",i, j,  l);

//                 // if(l > 1){
//                 //     return result;
//                 // }
//                 if(l <= 0)// Casilla vacia, con obstaculos o con comidita, estamos buscando aquellas casillas a las que se haya llegado desde otra o la 1ra desde la q comenzamos // || mapacopy[i][j] == -1)
//                     continue;

//                 for(int k = 0; k < 4; k++){
//                     coordenada pos;
//                     pos = pos_siguiente( i, j, k); // Obteniendo posicion al sumar x + numero que sea en la direccion
//                     // printf("pos: x:%d y:%d \n", pos.row, pos.col);
//                     // printf(" \n %d %d " );
//                     // printf("x: %d y:%d", pos.row, pos.col);
//                     bool se_puede = pos_valida(mapa_copy, filas, columnas, pos);
//                     if(se_puede){ // Comprobando que la posicion se encuentre entre los limites del mapa y que la misma este vacia
//                         if(mapa_copy[pos.row][pos.col] == -2){
//                             int temp_x = pos.row;
//                             int temp_y = pos.col;
//                             (*pasos) = mapa_copy[i][j];
//                             int tamanno = mapa_copy[i][j];
//                             static coordenada result[filas*columnas];
//                             int paso_actual = mapa_copy[i][j] - 1;
//                             // sols = (coordenada *) malloc(pasos * sizeof(coordenada));

//                             // printf("llego");
//                             while(temp_x != c.row && temp_y != c.col){
//                                 coordenada temp_pos = pi[temp_x][temp_y];
//                                 // sols[0] = temp_pos;
//                                 result[paso_actual] = temp_pos;
//                                 // printf("%d %d", temp_x, temp_y);
//                                 temp_x = temp_pos.row;
//                                 temp_y = temp_pos.col;
//                                 paso_actual--;

//                                 return result;
//                             }
//                         }
//                         // printf("paso");
//                         mapa_copy[pos.row][pos.col] = mapa_copy[i][j] + 1;
//                         pinta_int(mapa_copy);
//                         cambio = true;
//                         coordenada actual_pos;
//                         actual_pos.row = i;
//                         actual_pos.col = j;
//                         pi[pos.row][pos.col] = actual_pos;
//                     }

//                     // free(p);
//                 }

//             }
//         }


//     }

//     pinta_int(mapa_copy);
//     // pinta(mapa);
//     // pinta_pi(pi);

//     return NULL;
// }



int main()
{
    char mapa[2][5] = {
        {'.', '.', '.', '@', '.'},
        {'.', '.', '.', 'x', '.'}};

    coordenada p;
    p.row = 0;
    p.col = 0;

    int pasos = 0;
    // coordenada * sols;
    // int * sols;
    parte_t * sols = (parte_t*)malloc(sizeof(parte_t));

    sols = bfs(mapa, p, &pasos);
    printf("\n pasos: %d \n", pasos);


    print_list(sols);
    // for(int i = 0; i < 1; i++)
    //     printf("%d %d \n", sols[i].row, sols[i].col);
    // pinta(mapa);

    return 0;
}
