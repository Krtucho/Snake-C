#include "Juego.c"


void Juego(int filas, int columnas)
{
    parte * head = creaSnake(filas,columnas);//Se crea la snake con tres piezas enlazadas, solo se necesita la direccion de head
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
    int cantComiditas=0;
    int tamannoAumentar=0;
    int movimientosPorDar=0;
    int Puntuacion=0;
    ColocarSnakeEnWorld(head,mapa);

    while(sePerdio==false)
    {
        if(cantComiditas==0)
        {
            PonerComiditas(mapa);
            /*donde se va a guardar*/movimientos=bfs(mapa,head->pos);//Aqui crear un array o linked list para guardar los movimientos
        }
        sePerdio=MoverSnake(head,movimientos,tamannoAumentar);


    }
