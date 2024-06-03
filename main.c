#include "materias.h"
#include "estudiante.h"
#include "lista_materiasEnCurso.h"
#include "lista_materias.h"
#include <stdio.h>
#include "lista_estudiantes.h"
#include "malloc.h"
#include "string.h"

Estudiante *crearEstudianteMenu(){

    Estudiante *creado = crearEstudiante(NULL,-1,NULL);
    asignarNombre(creado);

    asignarDNI(creado);
    asignarFechaDeNacimiento(creado);

    return creado;
}

int main() {
    int opcion;
    Fecha *fecha = crearFecha(12,12,1999);
    ListaEstudiante *lista_estudiantes = crearListaEstudiantes();

    do {
        printf("\n---- MENU ----\n");
        printf("1. Crear estudiante\n");
        printf("2. Modificar estudiante\n");
        printf("3. Eliminar estudiante\n");
        printf("4. Mostrar estudiantes disponibles\n");
        printf("5. Buscar estudiante: \n");
        printf("6. Seleccionar estudiante\n");
        printf("7. Salir\n");
        printf("Seleccione una opcion: \n");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: { //Cuando se guarda el estudiante, el nombre se imprime mal (algun problema de punteros?)
                Estudiante *creado = crearEstudianteMenu();
                if (creado->fechaNacimiento == NULL){
                    break;
                }
                agregarEstudiante(lista_estudiantes,creado);
                break;
            }
            case 2: {
                imprimirListaEstudiantes(lista_estudiantes);
                if (lista_estudiantes->head == NULL){
                    break;
                }
                int dni;
                printf("Seleccione el DNI del estudiante a modificar: \n");
                scanf("%d", &dni);
                Estudiante *buscado = buscarEstudiantePorDNI(lista_estudiantes,dni);
                if(buscado == NULL){
                    break;
                }
                modificarEstudiante(buscado);
                break;
            }
            case 3: {
                imprimirListaEstudiantes(lista_estudiantes);
                if (lista_estudiantes->head == NULL){
                    break;
                }

                printf("Ingrese el dni del estudiante que desea eliminar: \n");
                int dni;
                scanf("%d", &dni);

                Estudiante *estudiante = buscarEstudiantePorDNI(lista_estudiantes,dni);

                if (estudiante == NULL){
                    break;
                }

                eliminarEstudiante(lista_estudiantes,dni);
                break;
            }
            case 4: {
                int opcion_busqueda;
                do {
                    printf("Ingrese su opcion: \n");
                    printf("1. Buscar por DNI:\n");
                    printf("2. Buscar por nombre:\n");
                    printf("3. Volver al menu principal:\n");
                    switch (opcion_busqueda) {
                        case 1:{
                            int dni;
                            printf("Ingrese el numero de DNI del estudiante a buscar: \n");
                            scanf("%d", &dni);
                            Estudiante *buscado = buscarEstudiantePorDNI(lista_estudiantes,dni);
                            break;
                        }
                        case 2:{
                            break;
                        }
                        case 3:{
                            printf("Volviendo al menu principal: \n");
                            break;
                        }
                    }
                } while (opcion_busqueda != 3);
            }
            case 5: {

            }
            case 6: {

            }
            case 7: {
                printf("Saliendo del programa...");
                break;
            }
        }
    } while (opcion != 7);
    return 0;
}

