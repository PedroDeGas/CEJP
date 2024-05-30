#include <stdio.h>
#include <malloc.h>
#include "materias.h"
#include <string.h>

void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

Materia* crearMateria(char *nombre, int id){
    Materia *nuevaMateria = malloc(sizeof(Materia));
    nuevaMateria->nombre = nombre;
    nuevaMateria->id = id;

    printf("Materia %s con id: %d \n",nombre,id);
    return nuevaMateria;
}

void modificarIDMateriaGeneral(Materia *materia){
    if (materia == NULL){
        printf("Error: Materia nula\n");
        return;
    }

    printf("Ingrese el nuevo id para la materia:\n");
    int nuevo_id;
    scanf("%d",&nuevo_id);

    if (nuevo_id < 0 || nuevo_id> 99){
        printf("Error: fuera de rango\n");
    }
    materia->id = nuevo_id;

    printf("Cambio exitoso!\n");
    limpiarBuffer();
}

void modificarNombreMateriaGeneral(Materia *materia){
    if (materia == NULL){
        printf("Error: Materia nula\n");
        return;
    }

    printf("Ingrese el nuevo nombre para la materia: ");
    char nuevoNombre[100];

    fgets(nuevoNombre, sizeof(nuevoNombre), stdin);

    size_t len = strlen(nuevoNombre);
    if (len > 0 && nuevoNombre[len - 1] == '\n') {
        nuevoNombre[len - 1] = '\0';
    }

    materia->nombre = malloc(strlen(nuevoNombre) + 1);
    if (materia->nombre == NULL) {
        printf("Error: Sin memoria para almacenar el nuevo nombre.\n");
        return;
    }
    strcpy(materia->nombre, nuevoNombre);

    printf("Cambio realizado con exito!\n");
    limpiarBuffer();
}