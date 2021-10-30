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
parte_t * push_front_n_return(parte_t * head, coordenada pos){
    parte_t * new_node;
    new_node =  (parte_t *) malloc(sizeof(parte_t));

    new_node->pos = pos;
    new_node->next = head;
    return new_node;

}
void print_list(parte_t * head) {
    parte_t * current = head;
    printf("Imprimiendo lista con respectivos pasos...\n");
    while (current != NULL) {
        printf("%d %d\n", current->pos.row, current->pos.col);
        current = current->next;
    }
}

coordenada pos remove_last(parte_t * head) {
    coordenada retval = 0;
    /* if there is only one item in the list, remove it */
    if (head->next == NULL) {
        retval = head->pos;
        free(head);
        return retval;
    }

    /* get to the second to last node in the list */
    parte_t * current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    /* now current points to the second to last item of the list, so let's remove current->next */
    retval = current->next->pos;
    free(current->next);
    current->next = NULL;
    return retval;

}