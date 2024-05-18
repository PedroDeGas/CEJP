#include <stdio.h>
#include <string.h>
#include <malloc.h>

#ifndef MATERIAS
#define MATERIAS

typedef struct MateriaStruct {
    char nombre;
    int id;
    // int correlativas[];
} Materia;

// crear una nueva materia indicando nombre e id de materia
Materia* crearMateria(char nombre, int id){
    Materia *nuevaMateria = malloc(sizeof(Materia));
    nuevaMateria->nombre = nombre;
    nuevaMateria->id = id;

    printf("Materia creada con id: %d",id);
    return nuevaMateria;
}

#endif