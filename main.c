#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
// #include "bfs.h"
//
#include "Juego.h"

// #include<stdbool.h>
// #include "linked_list.h"
//#include "Juego.h"
//#include "utils.h"
#include "usando_timer.h"
#include "bfs.h"

int dire_x[4] = {-1, 0, 1, 0}; // Direcciones para las x
int dire_y[4] = { 0, 1, 0,-1}; // Direcciones para las y

parte_t * CreaSnake(int filas, int columnas)
{
    parte_t * head=(parte_t*)malloc(sizeof(parte_t));
    coordenada p;
    p.row = filas/2;
    p.col = columnas/2;
    head->pos=p;//.row=filas/2;
    // head->pos=p//.col=columnas/2;

    //parte_t * segunda = 
    head->next=(parte_t*)malloc(sizeof(parte_t));
    coordenada p_uno;
    p_uno.row = filas/2;
    p_uno.col = columnas/2;
    head->next->pos=p_uno;//columnas/2-1;//.row=filas/2;
    // segunda->pos.col=columnas/2-1;

    //parte_t * tercera = 
    head->next->next=(parte_t*)malloc(sizeof(parte_t));
    coordenada p_dos;
    p_dos.row = filas/2;
    p_dos.col = columnas/2-2;
    head->next->next->pos = p_dos;//columnas/2-2;//.row=filas/2;
    // tercera->pos.col=columnas/2-2;

    // printf("%d %d \n", head->pos.row, head->pos.col);
    // free(segunda);
    // free(tercera);
    return head;
}

void ColocarSnakeEnElMapa(parte_t * head, char mapa[filas][columnas])
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
    (*cantComiditas)=0;
    while( (*cantComiditas)<5 && cantPosVacias>0)
    {
        int random = rand() % cantPosVacias;
        coordenada temp = posicionesVacias[random];
        mapa[temp.row][temp.col]='x';
        posicionesVacias[random]=posicionesVacias[cantPosVacias-1];
        posicionesVacias[cantPosVacias-1]=temp;
        cantComiditas++;
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


    coordenada nuevo;//=(coordenada*)malloc(sizeof(coordenada));
    nuevo.row=movimientos->pos.row;
    nuevo.col=movimientos->pos.col;

    mapa[head->pos.row][head->pos.col]='o';
    mapa[nuevo.row][nuevo.col]='@';
    push_front_n_return(head, nuevo);
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    ////Se puedde hacer tambien con el metodo a�adir
    //newHead->next=head;
    //head=newHead;////Revisar si funciona la referencia

    if(tamannoAumentar=0)
    {
        coordenada borrada=remove_last(head);
        mapa[borrada.row][borrada.col]='.';

    }


}

parte_t * BuscaMovimiento(char mapa[filas][columnas],parte_t * head)
{
    int i;
    parte_t * movimiento=(parte_t*)malloc(sizeof(parte_t));
    //movimiento->pos.row=filas/2;
    //movimiento->pos.col=columnas/2;

    for(i=0;i<4;i++)
    {
        int posx=head->pos.row+dire_x[i];
        int posy=head->pos.col+dire_y[i];
        if(mapa[posx][posy]=='.')
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
    parte_t * head = CreaSnake(filas,columnas);//Se crea la snake con tres piezas enlazadas, solo se necesita la direccion de head
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

    // bool sePerdio=false;

    int tamannoAumentar=0;
    int pasos=0;
    int Puntuacion=0;

    ColocarSnakeEnElMapa(head,mapa);

    int tamannoDelSnake=3;
    int cantComiditas;
    PonerComiditas(mapa,tamannoDelSnake, &cantComiditas);
    coordenada c; 
    c = head->pos;
    printf("%d %d\n", c.row, c.col);
    int cantComiditas=5;
    parte_t * movimientos=//(parte_t*)malloc(sizeof(parte_t));
    //movimientos = bfs(mapa, c, &pasos);


    while(1)//while(sePerdio==false)
    {
        //if(cantComiditas==0)
        //{
        //   PonerComiditas(mapa,tamannoDelSnake);
        //   parte_t * movimientos=bfs(mapa,head->pos);//Aqui crear un array o linked list para guardar los movimientos
        //}
        int x=movimientos->pos.row;
        int y=movimientos->pos.col;
        //parte_t * movimientos;//=NULL;

        if(x>filas||x>columnas||x<0||y<0)break;//Caso en el que se pierde porque se sale de los limites

        if(mapa[x][y]=='o')//se piedse porque la serpiente choca consigo misma
        {
            //printf("Juego Perdido");
            //MoverSnake(head,movimientos,tamannoAumentar);
            break;
        }

        //sePerdio=MoverSnake(head,movimientos,tamannoAumentar);
        if(mapa[x][y]=='x')//Caso en el que en este turno va a comer
        {
            MoverSnake(head, movimientos, mapa, tamannoAumentar);
            pasos--;
            tamannoAumentar+=3;
            Puntuacion++;
            cantComiditas--;
            //tamannoDelSnake++;
            if(cantComiditas==0)PonerComiditas(mapa,tamannoDelSnake, &cantComiditas);
            movimientos=bfs(mapa,head->pos,&pasos);//Aqui crear un array o linked list para guardar los movimientos

            //////////////////////////////Si el bfs no devuelve nada, hay que elegir un camino opcional aleatorio///////////////////////////////////////////
            //////////////idea de Seguir caminando hacia delante///////
            if(pasos==0)//(movimientos==NULL)
            {
                movimientos=BuscaMovimiento(mapa,head);
                pasos=1;
            }
            break;
        }

        MoverSnake(head,movimientos,mapa,tamannoAumentar);
        pinta(mapa);
        printf("Puntuacion:%d \n",Puntuacion);
        if(tamannoAumentar>0)tamannoAumentar--;

        setTimeout(1000);
    }
    printf("Juego Perdido\n Puntuaci�n Final:%d \n",Puntuacion);

    free(head);
    free(movimientos);

}
















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












