#include <stdio.h>
#include <malloc.h>
#include "lista_materias.h"
#include <string.h>

ListaMaterias *crearNuevaListaMaterias() {
    ListaMaterias *lista = malloc(sizeof(ListaMaterias));
    if (lista == NULL) {
        printf("Error al asignar memoria para la lista.\n");
        return NULL;
    }
    lista->head = NULL;
    lista->tail = NULL;
    return lista;
}

void agregarMateria(ListaMaterias *lista, Materia *materia) {
    if (lista == NULL || materia == NULL) {
        printf("Error: La lista o la materia no pueden ser nulos.\n");
        return;
    }

    NodoMateria *nuevoNodo = malloc(sizeof(NodoMateria));
    if (nuevoNodo == NULL) {
        printf("Error al asignar memoria para el nodo.\n");
        return;
    }

    nuevoNodo->materia = materia;
    nuevoNodo->proximo = NULL;

    if (lista->head == NULL) {
        lista->head = nuevoNodo;
        lista->tail = nuevoNodo;
    } else {
        lista->tail->proximo = nuevoNodo;
        lista->tail = nuevoNodo;
    }
}

void imprimirMaterias(ListaMaterias *lista) {
    if (lista == NULL) {
        printf("La lista no puede ser nula.\n");
        return;
    }
    printf("Materias disponibles:\n");
    NodoMateria *cursor = lista->head;
    while (cursor != NULL) {
        printf("ID: %d, Nombre: %s\n", cursor->materia->id, cursor->materia->nombre);
        cursor = cursor->proximo;
    }
    printf("\n");
}

void eliminarMateria(ListaMaterias *lista, int id) {
    if (lista == NULL) {
        printf("La lista no puede ser nula.\n");
        return;
    }
    NodoMateria *cursor = lista->head;
    NodoMateria *anterior = NULL;

    while (cursor != NULL) {
        if (cursor->materia->id == id) {
            if (anterior == NULL) {
                lista->head = cursor->proximo;
            } else {
                anterior->proximo = cursor->proximo;
            }
            if (cursor->proximo == NULL) {
                lista->tail = anterior;
            }
            free(cursor->materia);
            free(cursor);
            printf("Materia con ID %d eliminada.\n", id);
            return;
        }
        anterior = cursor;
        cursor = cursor->proximo;
    }
    printf("No se encontro materia con ID %d.\n", id);
}
Materia *buscarMateriaPorNombre(ListaMaterias *lista, char *nombre) {
    if (lista == NULL || nombre == NULL) {
        printf("La lista o el nombre no pueden ser nulos.\n");
        return NULL;
    }
    NodoMateria *cursor = lista->head;
    while (cursor != NULL) {
        if (strcmp(cursor->materia->nombre, nombre) == 0) {
            return cursor->materia;
        }
        cursor = cursor->proximo;
    }
    printf("No se encontro materia con nombre %s.\n", nombre);
    return NULL;
}

Materia *buscarMateriaPorId(ListaMaterias *lista, int id) {
    if (lista == NULL) {
        printf("La lista no puede ser nula.\n");
        return NULL;
    }
    NodoMateria *cursor = lista->head;
    while (cursor != NULL) {
        if (cursor->materia->id == id) {
            return cursor->materia;
        }
        cursor = cursor->proximo;
    }
    printf("No se encontro materia con ID %d.\n", id);
    return NULL;
}
void modificarNombreMateria(ListaMaterias *lista) {
    if (lista == NULL) {
        printf("La lista no puede ser nula.\n");
        return;
    }

    int id;
    printf("Ingrese el ID de la materia que desea modificar: \n");
    scanf("%d", &id);

    Materia *materia = buscarMateriaPorId(lista, id);
    if (materia == NULL) {
        printf("Materia con ID %d no encontrada.\n", id);
        return;
    }

    printf("Materia encontrada: %s\n", materia->nombre);

    char nuevoNombre[30];
    printf("Ingrese el nuevo nombre para la materia:");
    scanf("%s", nuevoNombre);

    materia->nombre = malloc(strlen(nuevoNombre) + 1);
    if (materia->nombre == NULL) {
        printf("Error: sin memoria para almacenar el nuevo nombre.\n");
        return;
    }
    strcpy(materia->nombre, nuevoNombre);

    printf("Nuevo nombre de la materia: %s\n", materia->nombre);
}