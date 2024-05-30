#include <stdio.h>
#include <malloc.h>
#include "lista_estudiantes.h"
#include <time.h>
#include "lista_materias.h"

ListaEstudiante *crearListaEstudiantes(){
    ListaEstudiante *lista = malloc(sizeof(ListaEstudiante));
    lista->head = NULL;
    lista->tail = NULL;
    return lista;
}

void agregarEstudiante(ListaEstudiante *lista,Estudiante *estudiante) {
    NodoEstudiante *nuevoNodo = malloc(sizeof(NodoEstudiante));
    if (nuevoNodo == NULL) {
        printf("Error: Sin memoria para almacenar el nuevo estudiante\n");
        return;
    }

    nuevoNodo->estudiante = estudiante;
    nuevoNodo->proximo = NULL;

    if (lista->head == NULL) {
        lista->head = nuevoNodo;
        lista->tail = nuevoNodo;
    } else {
        lista->tail->proximo = nuevoNodo;
        lista->tail = nuevoNodo;
    }

    printf("Estudiante %d agregado\n", estudiante->dni);
}
void eliminarEstudiante(ListaEstudiante *lista, int dni) {
    if (lista == NULL || lista->head == NULL) {
        printf("Lista vacia.\n");
        return;
    }

    if (lista->head->estudiante->dni == dni) {
        NodoEstudiante *temp = lista->head;
        lista->head = lista->head->proximo;
        free(temp);
        printf("Estudiante con DNI %d eliminado de la lista.\n", dni);
        return;
    }
    NodoEstudiante *anterior = lista->head;
    NodoEstudiante *actual = anterior->proximo;
    while (actual != NULL) {
        if (actual->estudiante->dni == dni) {
            anterior->proximo = actual->proximo;
            if (actual == lista->tail) {
                lista->tail = anterior;
            }
            free(actual);
            printf("Estudiante con DNI %d eliminado de la lista.\n", dni);
            return;
        }
        anterior = actual;
        actual = actual->proximo;
    }

    printf("Estudiante con DNI %d no encontrado en la lista.\n", dni);
}
void imprimirListaEstudiantes(ListaEstudiante *lista) {
    if (lista == NULL || lista->head == NULL) {
        printf("La lista esta vacia.\n");
        return;
    }
    NodoEstudiante *actual = lista->head;
    printf("Lista de estudiantes:\n");
    while (actual != NULL) {
        printf("Nombre: %s - DNI: %d - Fecha de nacimiento: %d/%d/%d\n", actual->estudiante->nombre, actual->estudiante->dni, actual->estudiante->fechaNacimiento->dia,actual->estudiante->fechaNacimiento->mes,actual->estudiante->fechaNacimiento->anio);
        actual = actual->proximo;
    }
}
Estudiante *buscarEstudiantePorDNI(ListaEstudiante *lista, int dni) {
    if (lista == NULL) {
        printf("La lista esta vacia.\n");
        return NULL;
    }

    NodoEstudiante *actual = lista->head;
    while (actual != NULL) {
        if (actual->estudiante->dni == dni) {
            return actual->estudiante;
        }
        actual = actual->proximo;
    }

    printf("Estudiante con ID %d no encontrado.\n", dni);
    return NULL;
}

Estudiante *buscarEstudiantePorNombre(ListaEstudiante *lista, char *nombre) {
    if (lista == NULL) {
        printf("La lista esta vacia.\n");
        return NULL;
    }
    NodoEstudiante *actual = lista->head;
    while (actual != NULL) {
        if (actual->estudiante->nombre == nombre) {
            return actual->estudiante;
        }
        actual = actual->proximo;
    }

    printf("Estudiante %s no encontrado.\n", nombre);
    return NULL;
}
ListaEstudiante *buscarEstudiantesPorRangoEdad(ListaEstudiante *lista, Fecha *fecha_inicio, Fecha *fecha_fin) {
    if (lista == NULL) {
        printf("La lista de estudiantes es nula.\n");
        return NULL;
    }

    ListaEstudiante *estudiantes_en_rango = crearListaEstudiantes();
    if (estudiantes_en_rango == NULL) {
        printf("Error: sin memoria para buscar a los estudiantes.\n");
        return NULL;
    }

    NodoEstudiante *cursor = lista->head;
    while (cursor != NULL) {
        if (compararFechas(*cursor->estudiante->fechaNacimiento, *fecha_inicio) >= 0 &&
            compararFechas(*cursor->estudiante->fechaNacimiento, *fecha_fin) <= 0) {

            Estudiante *nuevo_estudiante = malloc(sizeof(Estudiante));
            nuevo_estudiante->nombre = cursor->estudiante->nombre;
            nuevo_estudiante->dni = cursor->estudiante->dni;
            nuevo_estudiante->fechaNacimiento = cursor->estudiante->fechaNacimiento;
            agregarEstudiante(estudiantes_en_rango, nuevo_estudiante);
        }

        cursor = cursor->proximo;
    }
    return estudiantes_en_rango;
}
void modificarListaEstudiante(ListaEstudiante *lista) {
    if (lista == NULL) {
        printf("La lista de estudiantes esta vacia.\n");
        return;
    }

    printf("Estudiantes disponibles:\n");
    imprimirListaEstudiantes(lista);

    int dniEstudiante;
    printf("Ingrese el DNI del estudiante que desea modificar: ");
    scanf("%d", &dniEstudiante);

    NodoEstudiante *actual = lista->head;
    while (actual != NULL) {
        if (actual->estudiante->dni == dniEstudiante) {
            printf("Estudiante encontrado:\n");
            printf("Nombre: %s, DNI: %d\n", actual->estudiante->nombre, actual->estudiante->dni);

            int opcion;
            do {
                printf("Seleccione que desea modificar:\n");
                printf("1. Nombre\n");
                printf("2. DNI\n");
                printf("3. Fecha de Nacimiento\n");
                printf("4. Materias en Curso\n");
                printf("5. Salir\n");
                printf("Opcion: ");
                scanf("%d", &opcion);

                while (getchar() != '\n');
                switch (opcion) {
                    case 1:
                        modificarNombre(actual->estudiante);
                        break;
                    case 2:
                        modificarDNI(actual->estudiante);
                        break;
                    case 3:
                        modificarFechaNacimiento(actual->estudiante);
                        break;
                    case 4:
                        printf("Lista de las materias que se pueden modificar (nota:)\n");
                        imprimirListaMateriasEnCurso(actual->estudiante->listaEnCurso);
                        printf("Ingrese el ID de la materia a modificar: \n");
                        int idMateria;
                        scanf(&idMateria);
                        int nota;
                        printf("Ingrese la nueva nota de la materia: ");
                        scanf("%d", &nota);
                        modificarNota(actual->estudiante->listaEnCurso, idMateria,nota);
                        break;
                    case 5:
                        printf("Saliendo del menú de modificaciones.\n");
                        break;
                    default:
                        printf("Opción invalida. Por favor, seleccione una opcion valida.\n");
                        break;
                }
            } while (opcion != 5);

            return;
        }
        actual = actual->proximo;
    }

    printf("Estudiante con DNI %d no encontrado en la lista.\n", dniEstudiante);
}
