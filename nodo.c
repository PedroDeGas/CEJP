#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <time.h>
#include "materias.c"
#ifndef NODO
#define NODO

typedef struct structNodo {
    int
    struct structNodo *proximo;
} Nodo;

// crear un nuevo nodo
Nodo *crearNuevoNodo(Materia *materia) {
    Nodo *nuevoNodo = malloc(sizeof(NodoMateria));
    nuevoNodo->materia = materia;
    return nuevoNodo;
}

#endif