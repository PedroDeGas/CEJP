#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <time.h>
#include "estudiante.c"
#ifndef NODOESTUDIANTES
#define NODOESTUDIANTES

typedef struct structNodoEstudiante {
    Estudiante *estudiante;
    struct structNodoEstudiante *proximo;
} NodoEstudiante;

// crear un nuevo nodo
NodoEstudiante *crearNuevoNodoEstudiante(Estudiante *estudiante) {
    NodoEstudiante *nuevoNodo = malloc(sizeof(NodoEstudiante));
    nuevoNodo->estudiante = estudiante;
    nuevoNodo->proximo = NULL;
    return nuevoNodo;
}

#endif