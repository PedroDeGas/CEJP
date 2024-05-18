#include <stdio.h>
#include <string.h>
#include <malloc.h>

#ifndef MATERIAS
#define MATERIAS

typedef struct MateriaStruct {
    char nombre;
    int id;
} Materia;


Materia* crearMateria(char nombre, int id){
    Materia *nuevaMateria = malloc(sizeof(Materia));
    nuevaMateria->nombre = nombre;
    nuevaMateria->id = id;

    printf("%d",id);
    return nuevaMateria;
}

#endif