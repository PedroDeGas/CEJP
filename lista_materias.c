#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <time.h>
#include "materias.c"
#include "nodo_materia.c"
#ifndef LISTAMATERIAS
#define LISTAMATERIAS


typedef struct structLista {
    NodoMateria *head;
    NodoMateria *tail;
    int size;
} ListaMaterias;

ListaMaterias *crearNuevaListaMaterias(){
    ListaMaterias *lista = malloc(sizeof(ListaMaterias));
    lista->head = NULL;
    lista->tail = NULL;
    return lista;
}

void *agregarMateria(ListaMaterias *lista, NodoMateria *nodo) {

    NodoMateria *c = lista->head;
    while (c->proximo != NULL){
        c = c->proximo;
    }
    c->proximo = nodo;
}

//imprimir lista
void imprimirMaterias(ListaMaterias *lista) {
    NodoMateria *cursor = lista->head;
    while (cursor != NULL) {
        printf("%c", cursor->materia->nombre);
        cursor = cursor->proximo;
    }
    printf("\n");
}

#endif