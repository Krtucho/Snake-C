#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int a = 5;
    int b = a/2-1;
    srand(time(NULL));
    int random = rand() % a;
    // int random = srand (time(a));
    // int random = rand() % a;
    int randomdos = rand() % a;
    printf("%d %d\n", random, randomdos);
    return 0;
}