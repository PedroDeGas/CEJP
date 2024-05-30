#include <stdio.h>
#include <malloc.h>
#include "lista_materiasEnCurso.h"

listaMateriasEnCurso *crearNuevaListaMateriasEnCurso() {
    listaMateriasEnCurso *lista = malloc(sizeof(listaMateriasEnCurso));
    if (lista != NULL) {
        lista->head = NULL;
        lista->tail = NULL;
        lista->size = 0;
    }
    return lista;
}

void agregarMateriaEnCurso(listaMateriasEnCurso *lista, Materia *materia) {
    NodoMateriaEstudiante *nuevoNodo = malloc(sizeof(NodoMateriaEstudiante));
    if (nuevoNodo == NULL) {
        printf("Error: sin memoria para agregar materia.\n");
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
    lista->size++;
}

void imprimirListaMateriasEnCurso(listaMateriasEnCurso *lista) {
    NodoMateriaEstudiante *cursor = lista->head;
    while (cursor != NULL) {
        printf("Materia: %s - ID: %d - Nota: %d\n", cursor->materia->nombre,cursor->materia->id, cursor->nota);
        cursor = cursor->proximo;
    }
    printf("\n");
}

void modificarNota(listaMateriasEnCurso *lista, int idMateria, int nota) {
    NodoMateriaEstudiante *cursor = lista->head;
    while (cursor != NULL) {
        if (cursor->materia->id == idMateria) {
            cursor->nota = nota;
            return;
        }
        cursor = cursor->proximo;
    }
    printf("Materia con ID %d no encontrada.\n", idMateria);
}
