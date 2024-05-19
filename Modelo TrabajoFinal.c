#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura de datos para los estudiantes
typedef struct Estudiante {
    char nombre[10];
    int edad;
    struct Estudiante *proximo;
    struct Materia *materias;
} Estudiante;

// Estructura de datos para las materias
typedef struct Materia {
    char nombre[10];
    int nota;
    struct Materia *proximo;
    struct Estudiante *estudiantes;
} Materia;

// Funciones para los estudiantes
void alta_estudiante(Estudiante **estudiantes, char nombre[], int edad) {
    Estudiante *new_estudiante = (Estudiante*) malloc(sizeof(Estudiante));
    strcpy(new_estudiante->nombre, nombre);
    new_estudiante->edad = edad;
    new_estudiante->proximo = *estudiantes;
    *estudiantes = new_estudiante;
}

void modificar_estudiante(Estudiante *estudiantes, char nombre[], int edad) {
    Estudiante *actual= estudiantes;
    while (actual!= NULL) {
        if (strcmp(actual->nombre, nombre) == 0) {
          actual->edad = edad;
            break;
        }
       actual = actual->proximo;
    }
}

void eliminar_estudiante(Estudiante **estudiantes, char nombre[]) {
    Estudiante *actual = *estudiantes;
    Estudiante *previous = NULL;
    while (actual!= NULL) {
        if (strcmp(actual->nombre, nombre) == 0) {
            if (previous == NULL) {
                *estudiantes = actual->proximo;
            } else {
                previous->proximo = actual->proximo;
            }
            free(actual);
            break;
        }
        previous =actual;
        actual= actual->proximo;
    }
}

void listar_estudiantes(Estudiante *estudiantes) {
    Estudiante *actual = estudiantes;
    while (actual!= NULL) {
        printf("Nombre: %s, Edad: %d\n", actual->nombre,actual->edad);
        actual = actual->proximo;
    }
}

void buscar_estudiante_nombre(Estudiante *estudiantes, char nombre[]) {
    Estudiante *actual= estudiantes;
    while (actual!= NULL) {
        if (strcmp(actual->nombre, nombre) == 0) {
            printf("Estudiante encontrado: %s, Edad: %d\n",actual->nombre,actual->edad);
            break;
        }
       actual= actual->proximo;
    }
}

void buscar_estudiante_edad(Estudiante *estudiantes, int edad_min, int edad_max) {
    Estudiante *actual = estudiantes;
    while (actual!= NULL) {
        if (actual->edad >= edad_min && actual->edad <= edad_max) {
            printf("Estudiante encontrado: %s, Edad: %d\n", actual->nombre, actual->edad);
        }
      actual= actual->proximo;
    }
}

// Funciones para las materias
void alta_materia(Materia **materias, char nombre[], int nota) {
    Materia *new_materia = (Materia*) malloc(sizeof(Materia));
    strcpy(new_materia->nombre, nombre);
    new_materia->nota = nota;
    new_materia->proximo = *materias;
    *materias = new_materia;
}

void modificar_materia(Materia *materias, char nombre[], int nota) {
    Materia *actual = materias;
    while (actual!= NULL) {
        if (strcmp(actual->nombre, nombre) == 0) {
            actual->nota = nota;
            break;
        }
       actual= actual->proximo;
    }
}

void eliminar_materia(Materia **materias, char nombre[]) {
    Materia *actual = *materias;
    Materia *previous = NULL;
    while (actual!= NULL) {
        if (strcmp(actual->nombre, nombre) == 0) {
            if (previous == NULL) {
                *materias = actual->proximo;
            } else {
                previous->proximo= actual->proximo;
            }
            free(actual);
            break;
        }
        previous = actual;
        actual= actual->proximo;
    }
}

void listar_materias(Materia *materias) {
    Materia *actual = materias;
    while (actual!= NULL) {
        printf("Nombre: %s, Nota: %d\n", actual->nombre, actual->nota);
        actual= actual->proximo;
    }
}


void anotar_estudiante_materia(Estudiante *estudiante, Materia *materia) {
    materia->estudiantes = estudiante;
    estudiante->materias = materia;
}

void rendir_materia(Estudiante *estudiante, char nombre[], int nota) {
    Materia *actual = estudiante->materias;
    while (actual!= NULL) {
        if (strcmp(actual->nombre, nombre) == 0) {
            actual->nota = nota;
            break;
        }
        actual= actual->proximo;
    }
}

// materias rendidas
void mostrar_materias_rendidas(Materia *materias) {
    Materia *actual= materias;
    while (actual!= NULL) {
        if (actual->nota > 0) {
            printf("Nombre: %s, Nota: %d\n", actual->nombre, actual->nota);
        }
        actual = actual->proximo;
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
    anotar_estudiante_materia(estudiantes->proximo, materias->proximo);
    

    // Rendir materias
    printf("Lista de materias rendidas:\n");
    rendir_materia(estudiantes, "Matemáticas", 8);
    rendir_materia(estudiantes->proximo, "Biologia", 7);
    rendir_materia(estudiantes, "Algebra", 10);
    rendir_materia(estudiantes->proximo, "Física", 9);


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
