#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>// Booleanos
#include "utils.h"
#include "linked_list.h"
// #include "Juego.h"


// typedef struct parte
// {
//      struct parte * next;
//     coordenada pos;
// }parte_t;

int dir_x[4] = {-1, 0, 1, 0}; // Direcciones para las x
int dir_y[4] = { 0, 1, 0,-1}; // Direcciones para las y

// int filas = 2, columnas = 5;

coordenada pos_siguiente(int x, int y, int direccion){ // Dada una posicion (x,y) y una direccion, develve la posicion adelantando 1 paso hacia esa direccion
    coordenada pos;

    pos.row = x + dir_x[direccion];
    pos.col = y + dir_y[direccion];
    return pos;
}

bool pos_valida(int mapa_copy[][columnas],int rows,int cols, coordenada pos){ // Devuelve si la posicion se encuentra entre los limites de la matriz y si no es una parte de la serpiente, obstaculo o comidita
    if (!(pos.row >= 0 && pos.row < rows && pos.col >= 0 && pos.col < cols))
        return false;
    int valor = mapa_copy[pos.row][pos.col];

    if (valor== 0 || valor == -2)
        return true;
    return false;
}

// void pinta(char mapa [][columnas])
// {
//     int i,j;
//     for( i=0;i<filas;i++)
//     {
//         for( j=0;j<columnas;j++)
//         {
//             printf("%c ",mapa[i][j]);
//         }
//          printf("\n");
//     }
// }

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

// void pinta_int(int mapa [][columnas])
// {
//     int i,j;
//     for( i=0;i<filas;i++)
//     {
//         for( j=0;j<columnas;j++)
//         {
//             printf("%d ",mapa[i][j]);
//         }
//          printf("\n");
//     }
// }


// void push(parte_t * head, coordenada pos) { // Annade un nodo al final de la linkedlist
//     parte_t * current = head;
//     while (current->next != NULL) {
//         current = current->next;
//     }

//     /* now we can add a new variable */
//     current->next = (parte_t *) malloc(sizeof(parte_t));
//     current->next->pos = pos;
//     current->next->next = NULL;
// }
// void push_front(parte_t ** head, coordenada pos) { // Annade nodo al inicio de la linked list (este metdo no se utiliza en esta archivo)
//     parte_t * new_node;
//     new_node = (parte_t *) malloc(sizeof(parte_t));

//     new_node->pos = pos;
//     new_node->next = *head;
//     *head = new_node;
// }
// void print_list(parte_t * head) {
//     parte_t * current = head;
//     printf("Imprimiendo lista con respectivos pasos...\n");
//     while (current != NULL) {
//         printf("%d %d\n", current->pos.row, current->pos.col);
//         current = current->next;
//     }
// }

// Via devolviendo LinkedList
parte_t * bfs(char mapa [filas][columnas], coordenada c, int * pasos){
    int mapa_copy[2][5]; // Matriz con valores numericos q representan las posiciones de la matriz de char (0 vacio, -1 obstaculos y cuerpo, -2 comida, 1posicion  a comenzar a ejecutar bfs)
    coordenada pi[2][5]; // Matriz con coordenadas de casilla desde la cual se accede a la casilla actual.


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

            pi[i][j] = c;
        }
    }

    mapa_copy[c.row][c.col] = 1; // Casilla desde la que se comienza a ejecutar bfs


    bool cambio = true; // Mientras se hagan cambios(Se encontro casilla vacia) continua con la ejecucion
    while (cambio)
    {
        cambio = false;

        int i,j,k;
        for ( i = 0; i < filas; i++)
        {
            for ( j = 0; j < columnas; j++)
            {
                int l = mapa_copy[i][j];
                if(l <= 0)// Casilla vacia, con obstaculos o con comidita, estamos buscando aquellas casillas a las que se haya llegado desde otra o la 1ra desde la q comenzamos
                    continue;

                for( k = 0; k < 4; k++){ // k = 4 xq son las direcciones Norte, Sur, Este, Oeste
                    coordenada pos;
                    pos = pos_siguiente( i, j, k); // Obteniendo posicion al sumar x + numero que sea en la direccion

                    bool se_puede = pos_valida(mapa_copy, filas, columnas, pos); // Verificando q la casilla es valida
                    if(se_puede){ // Comprobando que la posicion se encuentre entre los limites del mapa y que la misma este vacia
                        if(mapa_copy[pos.row][pos.col] == -2){ // Si se llego a una casilla en la que hay comida, busca el camino tomado para llegar hasta la misma y retorna
                            int temp_x = pos.row;
                            int temp_y = pos.col;

                            (*pasos) = mapa_copy[i][j]; // Cantidad de pasos necesarios para llegar a la comida mas cercana

                            parte_t * result = (parte_t*)malloc(sizeof(parte_t)); // Camino a retornar
                            result->pos.row=temp_x;
                            result->pos.col=temp_y;

                            coordenada actual_pos; // Actualizando posicion principal desde la cual comenzaremos a dar marcha atras

                            actual_pos.row = i;
                            actual_pos.col = j;
                            pi[pos.row][pos.col] = actual_pos;

                            while(temp_x != c.row || temp_y != c.col){ // Continua la ejecucion mientras no se haya llegado al comienzo del camino
                                coordenada temp_pos = pi[temp_x][temp_y]; // Busca la posicion desde la que se llego a la casilla actual
                                push(result, temp_pos); // Annade posicion actual al camino
                                // sols[0] = temp_pos;
                                // result[paso_actual] = temp_pos;
                                // printf("%d %d", temp_x, temp_y);
                                temp_x = temp_pos.row; // Actualizando valores de la casilla actual (nos movemos a la casilla mediante la cual se llega a la q estamos actualmente)
                                temp_y = temp_pos.col;

                            }
                            return result;

                        }
                        mapa_copy[pos.row][pos.col] = mapa_copy[i][j] + 1; // Si todo esta en talla y se puede acceder a esta casilla, modifica la posicion actual
                        cambio = true;
                        coordenada actual_pos;
                        actual_pos.row = i;
                        actual_pos.col = j;
                        pi[pos.row][pos.col] = actual_pos;
                    }

                }

            }
        }


    }

    // pinta_int(mapa_copy);
    // pinta(mapa);
    // pinta_pi(pi);

    return NULL;
}

// int main()
// {
//     char mapa[2][5] = {
//         {'.', '.', '.', '@', '.'},
//         {'.', '.', '.', 'x', '.'}};

//     coordenada p;
//     p.row = 0;
//     p.col = 0;

//     int pasos = 0;

//     parte_t * sols = (parte_t*)malloc(sizeof(parte_t));

//     sols = bfs(mapa, p, &pasos);
//     printf("\n pasos: %d \n", pasos);


//     print_list(sols);

//     return 0;
// }
