#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <time.h>
#include "materias.c"
#include "nodo_estudiante.c"
#ifndef LISTAESTUDIANTES
#define LISTAESTUDIANTES


typedef struct structListaEstudiantes {
    NodoEstudiante *head;
    NodoEstudiante *tail;
    int size;
} ListaEstudiante;

ListaEstudiante *crearNuevaListaEstudiantes(){
    ListaEstudiante *lista = malloc(sizeof(ListaEstudiante));
    lista->head = NULL;
    lista->tail = NULL;
    return lista;
}

void *agregarEstudiante(ListaEstudiante *lista, NodoEstudiante *nodo) {
    printf("\nEntro a agregar estudiante -%d-",nodo->estudiante->dni);
    if (lista->head == NULL){
        printf("\nEntro al if");
        lista->head = nodo;
        lista->tail = nodo;
    }else {
        printf("\nEntro al else");
        NodoEstudiante *aux = lista->tail;
        aux->proximo = nodo;
        lista->tail = nodo;
    }
    printf("\nEstudiante -%d- agregado", nodo->estudiante->dni);
}




//imprimir lista de estudiantes
void imprimirEstudiantes(ListaEstudiante *lista) {
    printf("\nestoy en lista de estudiantes");
    NodoEstudiante *c = lista->head;
    while (c != NULL) {
        printf("%d", c->estudiante->dni);
        c = c->proximo;
    }
    printf("\n");
}

#endif