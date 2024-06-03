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
        return;
    }
    materia->id = nuevo_id;

    limpiarBuffer();
}

void modificarNombreMateriaGeneral(Materia *materia){
    printf("Ingrese el nombre para la materia: ");
    char nuevoNombre[100];

    scanf("%s", nuevoNombre);

    materia->nombre = malloc(strlen(nuevoNombre) + 1);
    if (materia->nombre == NULL) {
        printf("Error: sin memoria para almacenar el nuevo nombre.\n");
        return;
    }
    strcpy(materia->nombre, nuevoNombre);

    limpiarBuffer();
}
int obtenerIDMateria(Materia *materia){
    return materia->id;
}
char* obtenerNombreMateria(Materia *materia){
    return materia->nombre;
}
void imprimirDatosMateria(Materia *materia){
    if (materia == NULL) {
        printf("Materia no encontrada.\n");
        return;
    }
    printf("ID: %d | Nombre: %s \n", materia->id, materia->nombre);
}