#include <stdio.h>
#include <stdlib.h>






void pinta(char mapa [])
{
    for(i=0;i<filas;i++)
    {
        for(j=0;j<columnas;j++)
        {
            printf("%c",mapa[i][j]);
        }
         printf("\n");
    }
}

void mueve()
{

}








int main()
{
   int filas, columnas;
    printf("Introduzca la cantidad de filas: ");
    scanf("%d", &filas);

    printf("Introduzca la cantidad de columnas: ");
    scanf("%d", &columnas);

    Juego(filas,columnas);

    return 0;
}












