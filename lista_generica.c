#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <time.h>
#include "materias.c"
#include "nodo.c"
#ifndef LISTAMATERIAS
#define LISTAMATERIAS


typedef struct structListaGenerica {
    Nodo *head;
    Nodo *tail;
    int size;
} ListaGenerica;

ListaGenerica *crearNuevaLista(){
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
void imprimir(ListaGenerica *lista) {
    Nodo *cursor = lista->head;
    while (cursor != NULL) {
        printf("%c", cursor->materia->nombre);
        cursor = cursor->proximo;
    }
    printf("\n");
}

#endif