#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <time.h>
#include "materias.c"
#ifndef NODOMATERIA
#define NODOMATERIA

typedef struct structNodoMateria {
    Materia *materia;
    int nota;
    struct structNodoMateria *proximo;
} NodoMateria;

// crear un nuevo nodo
NodoMateria *crearNuevoNodoMateria(Materia *materia) {
    NodoMateria *nuevoNodo = malloc(sizeof(NodoMateria));
    nuevoNodo->materia = materia;
    nuevoNodo->nota = NULL;
    nuevoNodo->proximo = NULL;
    return nuevoNodo;
}

#endif