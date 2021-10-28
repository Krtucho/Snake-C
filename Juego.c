
typedef struct node
{
    int row;
    int col;
}coordenada;


typedef struct
{
     struct node * next;
    coordenada pos;
}parte;


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

void MoverSnake()
{

}
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
    //Se procede a poner la pequenna snake en el mapa

    parte * current = &head;





}

