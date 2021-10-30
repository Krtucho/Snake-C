#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include "linked_list.h"
#include "Juego.h"
#include "utils.h"
#include "usando_timer.c"

parte_t* CreaSnake(int filas, int columnas)
{
    parte_t * head=(parte_t*)malloc(sizeof(parte_t));
    head->pos.row=filas/2;
    head->pos.col=columnas/2;

    parte_t * segunda = head->next=(parte_t*)malloc(sizeof(parte_t));
    segunda->pos.row=filas/2;
    segunda->pos.col=columnas/2-1;

    parte_t * tercera = segunda->next=(parte_t*)malloc(sizeof(parte_t));
    tercera->pos.row=filas/2;
    tercera->pos.col=columnas/2-2;

    return head;
}

void ColocarSnakeEnElMapa(parte_t * head, char mapa[filas][columnas])
{
    parte_t * current = head;
    mapa[head->pos.row][head->pos.col]="@";
    current = current->next;
    while (current != NULL)
    {
        mapa[current->pos.row][current->pos.col]="o";
        current = current->next;
    }

}

void PonerComiditas(char mapa [filas][columnas],int tamannoDelSnake)
{
    int cantPosVacias=filas*columnas-tamannoDelSnake;
    //coordenada posicionesVacias [cantPosVacias];
    coordenada * posicionesVacias=malloc(cantPosVacias * sizeof *posicionesVacias);
    int i,j,k;
    for(i=0;i<filas;i++)
    {
        for(j=0;j<columnas;j++)
        {
            if(mapa[i][j]=='.')
            {
                //posicionesVacias[k]=(coordenada*)malloc(sizeof(coordenada));//posicionesVacias[k]=coordenada ci;//
                posicionesVacias[k].row=i;//ci.row=i;//
                posicionesVacias[k].col=j;//ci.col=j;//
                k++;
            }
        }
    }
    int count=0;
    while( count<5 && cantPosVacias>0)
    {
        int random = rand() % cantPosVacias;
        coordenada temp = posicionesVacias[random];
        mapa[temp.row][temp.col]='x';
        posicionesVacias[random]=posicionesVacias[cantPosVacias-1];
        posicionesVacias[cantPosVacias-1]=temp;
        count++;
        cantPosVacias--;
    }


}

void MoverSnake(parte_t * head, parte_t * movimientos, char mapa [filas][columnas],int tamannoAumentar)
{
    //Ver si con el movimiento actual se pierde y devolver el bool
    //if(movimientos.count==0){RealizarMovimientoAleatorio();
    //if(mapa[movimientos.pos.row][movimientos.pos.col]=="x")

    //parte_t * newHead=(parte_t*)malloc(sizeof(parte_t));
    //newHead->pos.row=movimientos->pos.row;
    //newHead->pos.col=movimientos->pos.col;


    coordenada * nuevo=(coordenada*)malloc(sizeof(coordenada));
    nuevo.row=movimientos->pos.row;
    nuevo.col=movimientos->pos.col;


    push_front_n_return(head, nuevo);
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    ////Se puedde hacer tambien con el metodo añadir
    newHead->next=head;
    head=newHead;////Revisar si funciona la referencia

    if(tamannoAumentar=0)
    {
        remove_last(head);
    }







}

parte_t* BuscaMovimiento(char mapa[filas][columnas],parte_t head)
{
    int i;
    parte_t * movimiento=(parte_t*)malloc(sizeof(parte_t));
    //movimiento->pos.row=filas/2;
    //movimiento->pos.col=columnas/2;

    for(i=0;i<4;i++)
    {
        int posx=head->pos.row+dir_x[i];
        int posy=head->pos.col+dir_x[i];
        if[mapa[posx][posy]=='.')
        {
            movimiento->pos.row=posx;
            movimiento->pos.col=posy;
            return movimiento;
        }
    }
    if(head->pos.row==head->next->pos.row)
    {
        movimiento->pos.row;
        movimiento->pos.col=2*head->pos.col-head->next->pos.col;//posy2;
        return movimiento;
    }
    if(head->pos.col==head->next->pos.col)
    {
        movimiento->pos.row=2*head->pos.row-head->next->pos.row;//
        movimiento->pos.col;//=posy2;
        return movimiento;
    }

}


void Juego(int filas, int columnas)
{
    parte_t * head = creaSnake(filas,columnas);//Se crea la snake con tres piezas enlazadas, solo se necesita la direccion de head
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

    bool sePerdio=false;

    int tamannoAumentar=0;
    int movimientosPorDar=0;
    int Puntuacion=0;

    ColocarSnakeEnElMapa(head,mapa);

    int tamannoDelSnake=3;
    PonerComiditas(mapa,tamannoDelSnake);
    int cantComiditas=5;
    parte_t *movimientos=bfs(mapa,head->pos);


    while(1)//while(sePerdio==false)
    {
        //if(cantComiditas==0)
        //{
        //   PonerComiditas(mapa,tamannoDelSnake);
        //   parte_t * movimientos=bfs(mapa,head->pos);//Aqui crear un array o linked list para guardar los movimientos
        //}
        int x=movimientos.pos.row;
        int y=movimientos.pos.col;
        //parte_t * movimientos;//=NULL;

        if(x>filas||x>columnas||x<0||y<0)break;//Caso en el que se pierde porque se sale de los limites

        if(mapa[x][y]=="o")//se piedse porque la serpiente choca consigo misma
        {
            //printf("Juego Perdido");
            //MoverSnake(head,movimientos,tamannoAumentar);
            break;
        }

        //sePerdio=MoverSnake(head,movimientos,tamannoAumentar);
        if(mapa[x][y]=="x")//Caso en el que en este turno va a comer
        {
            MoverSnake(head,movimientos,tamannoAumentar);
            movimientosPorDar--;
            tamannoAumentar+=3;
            Puntuacion++;
            cantComiditas--;
            //tamannoDelSnake++;
            if(cantComiditas==0)PonerComiditas(mapa,tamannoDelSnake);
            movimientos=bfs(mapa,head->pos,&movimientosPorDar);//Aqui crear un array o linked list para guardar los movimientos

            //////////////////////////////Si el bfs no devuelve nada, hay que elegir un camino opcional aleatorio///////////////////////////////////////////
            //////////////idea de Seguir caminando hacia delante///////
            if(movimientosPorDar==0)//(movimientos==NULL)
            {
                movimientos=BuscaMovimiento(mapa,head);
                movimientosPorDar=1;
            }
        }


        pinta(mapa);
        printf("Puntuación:%d \n",Puntuacion)
        if(tamannoAumentar>0)tamannoAumentar--;

        setTimeout(1000);
    }
    printf("Juego Perdido\n Puntuación Final:%d \n",Puntuacion);



}










