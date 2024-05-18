#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <time.h>
#include "materias.c"
#ifndef NODOMATERIA
#define NODOMATERIA

typedef struct structNodo {
    Materia *materia;
    struct structNodo *proximo;
} NodoMateria;

// crear un nuevo nodo
NodoMateria *crearNuevoNodo(Materia *materia) {
    NodoMateria *nuevoNodo = malloc(sizeof(NodoMateria));
    nuevoNodo->materia = materia;
    return nuevoNodo;
}

#endif