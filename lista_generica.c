#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <time.h>
#include "materias.c"
#include "nodo.c"
#ifndef LISTAGENERICA
#define LISTAGENERICA


typedef struct structListaGenerica {
    Nodo *head;
    Nodo *tail;
    int size;
} ListaGenerica;


ListaGenerica *crearNuevaListaGenerica(){
    ListaGenerica *lista = malloc(sizeof(ListaGenerica));
    lista->head = NULL;
    lista->tail = NULL;
    return lista;
}

void *agregarNodo(ListaGenerica *lista, Nodo *nodo) {

    Nodo *c = lista->head;
    while (c->proximo != NULL){
        c = c->proximo;
    };
    c->proximo = nodo;
    return lista;
}

//imprimir lista
void imprimirListaGenerica(ListaGenerica *lista) {
    Nodo *cursor = lista->head;
    while (cursor != NULL) {
        printf("ID Materia: %d\nNota Materia: %d", cursor->materias[0][0],cursor->materias[0][1]);
        cursor = cursor->proximo;
    }
    printf("\n");
}

#endif