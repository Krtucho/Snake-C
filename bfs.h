#include "utils.h"
#include "linked_list.h"

// extern const int dir_x[]; // Direcciones para las x
// extern const int dir_y[];// Direcciones para las y

// extern const int *dir_x[];// Direcciones para las x
// extern const int *dir_y[]; // Direcciones para las y

parte_t * bfs(char mapa [filas][columnas], coordenada c, int * pasos);