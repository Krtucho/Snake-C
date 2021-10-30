

typedef struct
{
    int row;
    int col;
}coordenada;

typedef struct parte
{
     struct parte * next;
    coordenada pos;
}parte_t;

void push(parte_t * head, coordenada pos);
void push_front(parte_t ** head, coordenada pos);
parte_t * push_front_n_return(parte_t * head, coordenada pos);
void print_list(parte_t * head);
coordenada pos remove_last(parte_t * head);