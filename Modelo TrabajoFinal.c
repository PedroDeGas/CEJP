#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura de datos para los estudiantes
typedef struct Estudiante {
    char nombre[10];
    int edad;
    struct Estudiante *siguiente;
    struct Materia *materias;
} Estudiante;

// Estructura de datos para las materias
typedef struct Materia {
    char nombre[10];
    int nota;
    struct Materia *siguiente;
    struct Estudiante *estudiantes;
} Materia;

// Funciones para los estudiantes
void alta_estudiante(Estudiante **estudiantes, char nombre[], int edad) {
    Estudiante *new_estudiante = (Estudiante*) malloc(sizeof(Estudiante));
    strcpy(new_estudiante->nombre, nombre);
    new_estudiante->edad = edad;
    new_estudiante->siguiente = *estudiantes;
    *estudiantes = new_estudiante;
}

void modificar_estudiante(Estudiante *estudiantes, char nombre[], int edad) {
    Estudiante *current = estudiantes;
    while (current!= NULL) {
        if (strcmp(current->nombre, nombre) == 0) {
            current->edad = edad;
            break;
        }
        current = current->siguiente;
    }
}

void eliminar_estudiante(Estudiante **estudiantes, char nombre[]) {
    Estudiante *current = *estudiantes;
    Estudiante *previous = NULL;
    while (current!= NULL) {
        if (strcmp(current->nombre, nombre) == 0) {
            if (previous == NULL) {
                *estudiantes = current->siguiente;
            } else {
                previous->siguiente = current->siguiente;
            }
            free(current);
            break;
        }
        previous = current;
        current = current->siguiente;
    }
}

void listar_estudiantes(Estudiante *estudiantes) {
    Estudiante *current = estudiantes;
    while (current!= NULL) {
        printf("Nombre: %s, Edad: %d\n", current->nombre, current->edad);
        current = current->siguiente;
    }
}

void buscar_estudiante_nombre(Estudiante *estudiantes, char nombre[]) {
    Estudiante *current = estudiantes;
    while (current!= NULL) {
        if (strcmp(current->nombre, nombre) == 0) {
            printf("Estudiante encontrado: %s, Edad: %d\n", current->nombre, current->edad);
            break;
        }
        current = current->siguiente;
    }
}

void buscar_estudiante_edad(Estudiante *estudiantes, int edad_min, int edad_max) {
    Estudiante *current = estudiantes;
    while (current!= NULL) {
        if (current->edad >= edad_min && current->edad <= edad_max) {
            printf("Estudiante encontrado: %s, Edad: %d\n", current->nombre, current->edad);
        }
        current = current->siguiente;
    }
}

// Funciones para las materias
void alta_materia(Materia **materias, char nombre[], int nota) {
    Materia *new_materia = (Materia*) malloc(sizeof(Materia));
    strcpy(new_materia->nombre, nombre);
    new_materia->nota = nota;
    new_materia->siguiente = *materias;
    *materias = new_materia;
}

void modificar_materia(Materia *materias, char nombre[], int nota) {
    Materia *current = materias;
    while (current!= NULL) {
        if (strcmp(current->nombre, nombre) == 0) {
            current->nota = nota;
            break;
        }
        current = current->siguiente;
    }
}

void eliminar_materia(Materia **materias, char nombre[]) {
    Materia *current = *materias;
    Materia *previous = NULL;
    while (current!= NULL) {
        if (strcmp(current->nombre, nombre) == 0) {
            if (previous == NULL) {
                *materias = current->siguiente;
            } else {
                previous->siguiente = current->siguiente;
            }
            free(current);
            break;
        }
        previous = current;
        current = current->siguiente;
    }
}

void listar_materias(Materia *materias) {
    Materia *current = materias;
    while (current!= NULL) {
        printf("Nombre: %s, Nota: %d\n", current->nombre, current->nota);
        current = current->siguiente;
    }
}


void anotar_estudiante_materia(Estudiante *estudiante, Materia *materia) {
    materia->estudiantes = estudiante;
    estudiante->materias = materia;
}

void rendir_materia(Estudiante *estudiante, char nombre[], int nota) {
    Materia *current = estudiante->materias;
    while (current!= NULL) {
        if (strcmp(current->nombre, nombre) == 0) {
            current->nota = nota;
            break;
        }
        current = current->siguiente;
    }
}

int main() {
    // Crear listas vacías
    Estudiante *estudiantes = NULL;
    Materia *materias = NULL;

    // Dar de alta estudiantes
    alta_estudiante(&estudiantes, "Juan", 20);
    alta_estudiante(&estudiantes, "Maria", 22);
     alta_estudiante(&estudiantes, "Marcelo", 21);
    alta_estudiante(&estudiantes, "Carla", 22);
     alta_estudiante(&estudiantes, "Lucas", 23);
    alta_estudiante(&estudiantes, "Milagros", 20);

    // Dar de alta materias
    alta_materia(&materias, "Matemáticas", 0);
    alta_materia(&materias, "Física", 0);
    alta_materia(&materias, "Biologia", 0);
    alta_materia(&materias, "Algebra", 0);
    alta_materia(&materias, "Programación", 0);
    alta_materia(&materias, "Quimica", 0);
   
    // Anotar estudiantes en materias
   printf("Los estudiantes se anotan a las materias:\n");
    anotar_estudiante_materia(estudiantes, materias);
    anotar_estudiante_materia(estudiantes->siguiente, materias->siguiente);
    

    // Rendir materias
    printf("Lista de materias rendidas:\n");
    rendir_materia(estudiantes, "Matemáticas", 8);
    rendir_materia(estudiantes->siguiente, "Biologia", 7);
    rendir_materia(estudiantes, "Algebra", 10);
    rendir_materia(estudiantes->siguiente, "Física", 9);


    // Listar estudiantes
    printf("Lista de estudiantes:\n");
    listar_estudiantes(estudiantes);

    // Listar materias
    printf("Lista de materias:\n");
    listar_materias(materias);

    // Buscar estudiante por nombre
    printf("Buscando estudiante 'Juan':\n");
    buscar_estudiante_nombre(estudiantes, "Juan");

    // Buscar estudiantes por rango de edad
    printf("Buscando estudiantes entre 20 y 25 años:\n");
    buscar_estudiante_edad(estudiantes, 20, 25);

    // Modificar estudiante
    printf("Modificando edad de estudiante 'Juan' a 21:\n");
    modificar_estudiante(estudiantes, "Juan", 21);

    // Eliminar estudiante
    printf("Eliminando estudiante 'Juan':\n");
    eliminar_estudiante(&estudiantes, "Juan");

    // Listar estudiantes
    printf("Lista de estudiantes después de eliminar a 'Juan':\n");
    listar_estudiantes(estudiantes);

    return 0;
}
