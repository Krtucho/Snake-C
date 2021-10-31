#include <stdio.h>
#include <stdlib.h>
// #include<stdbool.h>
// #include "linked_list.h"
#include "Juego.h"
#include "utils.h"
#include "usando_timer.h"
#include "bfs.h"

int dire_x[4] = {-1, 0, 1, 0}; // Direcciones para las x
int dire_y[4] = { 0, 1, 0,-1}; // Direcciones para las y

void clrscr()
{
    system("@cls||clear");
}

parte_t * CreaSnake(int filas, int columnas)
{
    parte_t * head=(parte_t*)malloc(sizeof(parte_t));
    coordenada p;
    p.row = filas/2;
    p.col = columnas/2;
    head->pos=p;
    head->next=(parte_t*)malloc(sizeof(parte_t));
    coordenada p_uno;
    p_uno.row = filas/2;
    p_uno.col = columnas/2-1;
    head->next->pos=p_uno;

    head->next->next=(parte_t*)malloc(sizeof(parte_t));
    coordenada p_dos;
    p_dos.row = filas/2;
    if(columnas/2-2<0)
    {
        p_dos.row=filas/2-1;
        p_dos.col = columnas/2-1;
    }
    else p_dos.col = columnas/2-2;
    head->next->next->pos = p_dos;

    // printf("%d %d \n", head->pos.row, head->pos.col);
    // printf("%d %d \n", head->next->pos.row, head->next->pos.col);
    // printf("%d %d \n", head->next->next->pos.row, head->next->next->pos.col);
    return head;
}

void ColocarSnakeEnElMapa(parte_t * head, char mapa [filas][columnas])
{
    parte_t * current = head;
    mapa[head->pos.row][head->pos.col]='@';
    current = current->next;
    while (current != NULL)
    {
        mapa[current->pos.row][current->pos.col]='o';
        current = current->next;
    }

}

void PonerComiditas(char mapa [filas][columnas],int tamannoDelSnake, int *cantComiditas)
{
    int cantPosVacias=filas*columnas-tamannoDelSnake;
    coordenada posicionesVacias[cantPosVacias];
    int i,j,k=0;
    for(i=0;i<filas;i++)
    {
        for(j=0;j<columnas;j++)
        {
            if(mapa[i][j]=='.')
            {
                posicionesVacias[k].row=i;
                posicionesVacias[k].col=j;
                k++;
            }
        }
    }
    // for(i=0; i<cantPosVacias; i++)
    //     printf("%d %d \n", posicionesVacias[i].row, posicionesVacias[i].col);

    (*cantComiditas)=0;
    // printf("Cant comiditas en metodo poner comida: %d \n", (*cantComiditas));
    while( (*cantComiditas)<5 && cantPosVacias>0)
    {
        srand(time(NULL));
        int random = rand() % cantPosVacias;
        coordenada temp = posicionesVacias[random];
        mapa[temp.row][temp.col]='x';
        posicionesVacias[random]=posicionesVacias[cantPosVacias-1];
        posicionesVacias[cantPosVacias-1]=temp;
        (*cantComiditas)++;
        cantPosVacias--;
        // printf("%d \n", (*cantComiditas));
    }

}

parte_t * MoverSnake(parte_t * head, parte_t * movimientos, char mapa [filas][columnas],int tamannoAumentar)
{
    coordenada nuevo;
    nuevo.row=movimientos->pos.row;
    nuevo.col=movimientos->pos.col;
    mapa[nuevo.row][nuevo.col]='@';

    mapa[head->pos.row][head->pos.col]='o';
    // printf("Pintando mapa en mover snake\n");
    // pinta(mapa);
    
    // printf("Imprimiendo a moverse\n");
    // imprimir_coordenada(nuevo);

    head = push_front_n_return(head, nuevo);

    // printf("Imprimiendo cuerpo");
    // print_list(head);

    // imprimir_coordenada(head->pos);

    if(tamannoAumentar == 0)
    {
        coordenada borrada=remove_last(head);
        // imprimir_coordenada(borrada);
        mapa[borrada.row][borrada.col]='.';

    }

    // printf("Imprimiendo cuerpo");
    // print_list(head);
    // pinta(mapa);

    return head;
}

parte_t * BuscaMovimiento(char mapa[filas][columnas],parte_t * head)
{
    parte_t * movimiento=(parte_t*)malloc(sizeof(parte_t));

    coordenada p;
    p.row= 0;
    p.col = 0;

    for(int i=0;i<4;i++)
    {
        int posx=head->pos.row+dire_x[i];
        int posy=head->pos.col+dire_y[i];
        if(posx>=filas||posy>=columnas||posx<0||posy<0)continue;
        
        if(mapa[posx][posy]=='.')
        {
            p.row = posx;
            p.col = posy;
            movimiento->pos = p;
            
            return movimiento;
        }
    }
    p.row = head->next->pos.row;
    p.col = head->next->pos.col;
    movimiento->pos = p;

    return movimiento;;

}


void Juego(int filas, int columnas)
{
    parte_t * head = CreaSnake(filas,columnas);//Se crea la snake con tres piezas enlazadas, solo se necesita la direccion de head
    
    // printf("%d %d \n", head->pos.row, head->pos.col);
    // printf("%d %d \n", head->next->pos.row, head->next->pos.col);
    // printf("%d %d \n", head->next->next->pos.row, head->next->next->pos.col);
    
    char mapa[filas][columnas];
    int i,j;

    //En el mapa se toman los siguientes char:
    //@ cabeza
    //o cuerpo
    //x comidita
    //.vacio

    for(i=0;i<filas;i++)
    {
        for(j=0;j<columnas;j++)
        {
            mapa[i][j]='.';
        }
    }

    int tamannoAumentar=0;
    int pasos=0;
    int Puntuacion=0;

    ColocarSnakeEnElMapa(head,mapa);
    // pinta(mapa);
    int tamannoDelSnake=3;
    int cantComiditas;
    PonerComiditas(mapa,tamannoDelSnake, &cantComiditas);
    pinta(mapa);
    printf("Puntuacion:%d \n", Puntuacion);
    coordenada c; 
    c = head->pos;
    // printf("%d %d\n", c.row, c.col);
    parte_t * movimientos=(parte_t*)malloc(sizeof(parte_t));
    movimientos = bfs(mapa, c, &pasos);
    // print_list(movimientos);

    while(1)
    {
        setTimeout(500);
        
        int x=movimientos->pos.row;
        int y=movimientos->pos.col;
        

        if(x>filas||x>columnas||x<0||y<0)break;//Caso en el que se pierde porque se sale de los limites

        if(mapa[x][y]=='o')//se piedse porque la serpiente choca consigo misma
        {
            break;
        }
        clrscr();

        if(mapa[x][y]=='x')//Caso en el que en este turno va a comer
        {
            if(tamannoAumentar>0)tamannoDelSnake++;

            head = MoverSnake(head, movimientos, mapa, tamannoAumentar);
            pinta(mapa);
            printf("Puntuacion:%d \n", Puntuacion);
            pasos--;
            tamannoAumentar+=3;
            Puntuacion++;
            cantComiditas--;
            // printf("cantidad de comiditas: %d\n", cantComiditas);
            if(cantComiditas==0)PonerComiditas(mapa,tamannoDelSnake, &cantComiditas);
            movimientos=bfs(mapa,head->pos,&pasos);//Aqui crear un array o linked list para guardar los movimientos

            // printf("pasos: %d\n", pasos);            
            //Si el bfs no devuelve nada, hay que elegir un camino opcional
            if(pasos==0)//(movimientos==NULL)
            {
                // printf("Termino bfs, pasos==0");
                movimientos=BuscaMovimiento(mapa,head);
                pasos=1;
            }

            continue;
        }

        if(tamannoAumentar>0)tamannoDelSnake++;
        // printf("Tamanno del snake: %d \n Tamanno a aumentar: %d\n", tamannoDelSnake, tamannoAumentar);
        head = MoverSnake(head, movimientos, mapa, tamannoAumentar);
        pasos--;
        pinta(mapa);
        printf("Puntuacion:%d \n", Puntuacion);
        if(tamannoAumentar>0)tamannoAumentar--;

        //movimientos=bfs(mapa,head->pos,&pasos);

        if(pasos==0)
        {
            // printf("Termino bfs, pasos==0");
            movimientos=bfs(mapa,head->pos,&pasos);
            // printf("Pasos luego de ultimo bfs: %d", pasos);
            if(pasos==0)
            {

                movimientos=BuscaMovimiento(mapa, head);
                print_list(movimientos);
                pasos=1;

            }
            continue;
        }
        movimientos = movimientos->next;

        
    }
    printf("Juego Perdido\n Puntuacin Final:%d \n",Puntuacion);

    free(head);
    free(movimientos);

}









