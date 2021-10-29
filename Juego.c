#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include "linkedlist.h"




parte* CreaSnake(int filas, int columnas)
{
    parte * head=(parte*)malloc(sizeof(parte));
    head->pos.row=filas/2;
    head->pos.col=columnas/2;

    parte * segunda = head->next=(parte*)malloc(sizeof(parte));
    segunda->pos.row=filas/2;
    segunda->pos.col=columnas/2-1;

    parte * tercera = segunda->next=(parte*)malloc(sizeof(parte));
    tercera->pos.row=filas/2;
    tercera->pos.col=columnas/2-2;

    return head;
}

void ColocarSnakeEnWorld(parte * head, char mapa[filas][columnas])
{
    parte * current = head;
    mapa[head->pos.row][head->pos.col]="@";
    current = current->next;
    while (current != NULL)
    {
        mapa[current->pos.row][current->pos.col]="o";
        current = current->next;
    }

}

void PonerComiditas(mapa[filas][columnas])
{
    numero = rand() % filas;

}

bool MoverSnake(parte head,/* movimientos obtenidos en el bfs*/ movimientos, int tamannoAumentar,mapa[filas][columnas])
{
    //Ver si con el movimiento actual se pierde y devolver el bool
    //if(movimientos.count==0){RealizarMovimientoAleatorio();}








}










