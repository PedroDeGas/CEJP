#ifndef CEJP_ESTUDIANTE_H
#define CEJP_ESTUDIANTE_H
#include "fechas.h"
#include "lista_materiasEnCurso.h"
#include "materias.h"

typedef struct Estudiante {
    char *nombre;
    int dni;
    Fecha *fechaNacimiento;
    listaMateriasEnCurso *listaEnCurso;
} Estudiante;

Estudiante *crearEstudiante(char *nombre, int dni, Fecha *fechaNacimiento);
void modificarNombre(Estudiante *estudiante);
void modificarDNI(Estudiante *estudiante);
void modificarFechaNacimiento(Estudiante *estudiante);
void modificarEstudiante(Estudiante *estudiante);
void anotarseEnMateria(Estudiante *estudiante, Materia *materia);
void setNota(Estudiante *estudiante);

#endif
