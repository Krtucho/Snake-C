#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "linked_list.h"

void push(parte_t * head, coordenada pos) { // Annade un nodo al final de la linkedlist
    parte_t * current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    /* now we can add a new variable */
    current->next = (parte_t *) malloc(sizeof(parte_t));
    current->next->pos = pos;
    current->next->next = NULL;
}
void push_front(parte_t ** head, coordenada pos) { // Annade nodo al inicio de la linked list (este metdo no se utiliza en esta archivo)
    parte_t * new_node;
    new_node = (parte_t *) malloc(sizeof(parte_t));

    new_node->pos = pos;
    new_node->next = *head;
    *head = new_node;
}
void print_list(parte_t * head) {
    parte_t * current = head;
    printf("Imprimiendo lista con respectivos pasos...\n");
    while (current != NULL) {
        printf("%d %d\n", current->pos.row, current->pos.col);
        current = current->next;
    }
}