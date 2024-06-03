#include <stdio.h>
#include "arboldecorrelatividad.h"
#include "malloc.h"
#include <string.h>

void imprimir_arbol(Nodo *raiz) {
    if (raiz == NULL) {
        return;
    }
    imprimir_arbol(raiz->izquierda);
    printf("%s\n", raiz->nombre);
    imprimir_arbol(raiz->derecha);
}

Nodo *agregar_nodo(Nodo *raiz, char nombre[]) {
    Nodo *nuevo_nodo = (Nodo*) malloc(sizeof(Nodo));
    strcpy(nuevo_nodo->nombre, nombre);
    nuevo_nodo->izquierda = NULL;
    nuevo_nodo->derecha = NULL;
    if (raiz == NULL) {
        raiz = nuevo_nodo;
    } else {
        Nodo *actual = raiz;
        Nodo *anterior = NULL;
        while (actual!= NULL) {
            anterior = actual;
            if (strcmp(actual->nombre, nombre) < 0) {
                actual = actual->derecha;
            } else {
                actual = actual->izquierda;
            }
        }
        if (strcmp(anterior->nombre, nombre) < 0) {
            anterior->derecha = nuevo_nodo;
        } else {
            anterior->izquierda = nuevo_nodo;
        }
    }
    return raiz;
}

Nodo *buscar_nodo(Nodo *raiz, char nombre[]) {
    if (raiz == NULL) {
        return NULL;
    }
    if (strcmp(raiz->nombre, nombre) == 0) {
        return raiz;
    }
    Nodo *izquierda = buscar_nodo(raiz->izquierda, nombre);
    if (izquierda!= NULL) {
        return izquierda;
    }
    Nodo *derecha = buscar_nodo(raiz->derecha, nombre);
    return derecha;
}