#ifndef CEJP_NODO_ESTUDIANTE_H
#define CEJP_NODO_ESTUDIANTE_H
#include "estudiante.h"

typedef struct structNodoEstudiante {
    Estudiante *estudiante;
    struct structNodoEstudiante *proximo;
} NodoEstudiante;

NodoEstudiante *crearNuevoNodoEstudiante(Estudiante *estudiante);
#endif