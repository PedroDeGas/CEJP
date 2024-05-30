#include <stdio.h>
#include <malloc.h>
#include "nodo_estudiante.h"

NodoEstudiante *crearNuevoNodoEstudiante(Estudiante *estudiante) {
    NodoEstudiante *nuevoNodo = malloc(sizeof(NodoEstudiante));
    nuevoNodo->estudiante = estudiante;
    nuevoNodo->proximo = NULL;
    return nuevoNodo;
}
