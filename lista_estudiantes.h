#ifndef CEJP_LISTA_ESTUDIANTES_H
#define CEJP_LISTA_ESTUDIANTES_H
#include "nodo_estudiante.h"
typedef struct structListaEstudiantes {
    NodoEstudiante *head;
    NodoEstudiante *tail;
    int size;
} ListaEstudiante;

ListaEstudiante *crearListaEstudiantes();
void agregarEstudiante(ListaEstudiante *lista, Estudiante *estudiante);
void eliminarEstudiante(ListaEstudiante *lista, int dni);
void modificarListaEstudiante(ListaEstudiante *lista);
void imprimirListaEstudiantes(ListaEstudiante *lista);
Estudiante *buscarEstudiantePorDNI(ListaEstudiante *lista, int dni);
Estudiante *buscarEstudiantePorNombre(ListaEstudiante *lista, char *nombre);
ListaEstudiante *buscarEstudiantesPorRangoEdad(ListaEstudiante *lista,Fecha *fecha_inicio, Fecha *fecha_fin);

#endif
