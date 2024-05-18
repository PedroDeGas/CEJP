#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <time.h>

#ifndef ESTUDIANTES
#define ESTUDIANTES

typedef struct Estudiante {
    char nombre;
    int dni;
    char fechaNacimiento;
    // Nodo materias;
} Estudiante;

// validar que no este agregado ya el estudiante

Estudiante *crearEstudiante(char nombre, int dni, char fechaNacimiento){

    Estudiante *nuevoEstudiante = malloc(sizeof(Estudiante));

    nuevoEstudiante->nombre = nombre;
    nuevoEstudiante->dni = dni;
    nuevoEstudiante->fechaNacimiento = fechaNacimiento;

    return nuevoEstudiante;
}

#endif