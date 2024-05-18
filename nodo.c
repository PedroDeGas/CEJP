#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <time.h>
#include "materias.c"
#ifndef NODO
#define NODO

typedef struct structNodo {
    int materias[0][1];
    struct structNodo *proximo;
} Nodo;

// crear un nuevo nodo
Nodo *crearNuevoNodoGenerico(int idMateria, int nota) {
    Nodo *nuevoNodo = malloc(sizeof(Nodo));
    nuevoNodo->materias[0][0] = idMateria;
    nuevoNodo->materias[0][1] = nota;
    return nuevoNodo;
}

#endif