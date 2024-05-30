#include <string.h>
#include <malloc.h>
#include "nodo_materiaestudiante.h"
#include "materias.h"

NodoMateriaEstudiante *crearNuevoNodoMateriaEstudiante(Materia *materia, int nota) {
    NodoMateriaEstudiante *nuevoNodo = malloc(sizeof(NodoMateriaEstudiante));
    if (nuevoNodo != NULL) {
        nuevoNodo->materia = materia;
        nuevoNodo->nota = nota;
        nuevoNodo->proximo = NULL;
    }
    return nuevoNodo;
}