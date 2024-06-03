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
    ListaMaterias *lista_materias = crearNuevaListaMaterias();

    Materia *materia1 = crearMateria("matematica0",1);
    Materia *materia2 = crearMateria("lengua",2);
    Materia *materia3 = crearMateria("fisica",3);
    Materia *materia4 = crearMateria("quimica",4);
    Materia *materia5 = crearMateria("ayp3",5);

    Estudiante *estudiante1 = crearEstudiante("pedro",1234,fecha);
    Estudiante *estudiante2 = crearEstudiante("juan",124,fecha);
    Estudiante *estudiante3 = crearEstudiante("daniel",1034,fecha);
    Estudiante *estudiante4 = crearEstudiante("norber",1235,fecha);

    agregarEstudiante(lista_estudiantes, crearNuevoNodoEstudiante(estudiante1));
    agregarEstudiante(lista_estudiantes, crearNuevoNodoEstudiante(estudiante2));
    agregarEstudiante(lista_estudiantes, crearNuevoNodoEstudiante(estudiante3));
    agregarEstudiante(lista_estudiantes, crearNuevoNodoEstudiante(estudiante4));

    agregarMateria(lista_materias,materia1);
    agregarMateria(lista_materias,materia2);
    agregarMateria(lista_materias,materia3);
    agregarMateria(lista_materias,materia4);
    agregarMateria(lista_materias,materia5);

    agregarCorrelativas(materia1,materia2);
    agregarCorrelativas(materia2,materia3);
    agregarCorrelativas(materia1,materia4);

    anotarseEnMateria(estudiante1,materia1);
    anotarseEnMateria(estudiante2,materia1);
    anotarseEnMateria(estudiante2,materia2);
    anotarseEnMateria(estudiante3,materia1);
    anotarseEnMateria(estudiante3,materia2);


    do {
        printf("\n---- MENU ----\n");
        printf("0. Crear materias\n");
        printf("1. Crear estudiante\n");
        printf("2. Modificar estudiante\n");
        printf("3. Modificar materia\n");
        printf("4. Eliminar estudiante\n");
        printf("5. Eliminar materia\n");
        printf("6. Listar estudiantes\n");
        printf("7. Listar materias\n");
        printf("8. Buscar estudiante\n");
        printf("9. Anotar a materia\n");
        printf("10. Rendir materia\n");
        printf("11. Salir\n");
        printf("Seleccione una opcion: \n");
        scanf("%d", &opcion);

        switch (opcion) {
            case 0: {
                Materia *materia = crearMateria(NULL,-2);
                modificarNombreMateriaGeneral(materia);
                modificarIDMateriaGeneral(materia);
                agregarMateria(lista_materias,materia);
                imprimirDatosMateria(materia);
                break;
            }
            case 1: {
                Estudiante *creado = crearEstudianteMenu();
                NodoEstudiante *nodo = crearNuevoNodoEstudiante(creado);
                if (creado->fechaNacimiento == NULL){
                    break;
                }
                agregarEstudiante(lista_estudiantes,nodo);
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
                imprimirMaterias(lista_materias);
                int id;
                printf("Ingrese el id de la materia a modificar: \n");
                scanf("%d", &id);
                Materia *buscada = buscarMateriaPorId(lista_materias,id);
                if (buscada == NULL){
                    break;
                }
                int opcion;
                do {
                    printf("\nSeleccione lo que desea modificar:\n");
                    printf("1. Nombre\n");
                    printf("2. ID\n");
                    printf("3. Salir al menu principal\n");
                    scanf("%d", &opcion);
                    getchar();
                    switch (opcion) {
                        case 1:
                            modificarNombreMateriaGeneral(buscada);
                            break;
                        case 2:
                            modificarIDMateriaGeneral(buscada);
                            break;
                        case 3:
                            printf("Volviendo al menu principal \n");
                            break;
                    }
                } while (opcion != 3);
                break;
            }
            case 4: {
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
            case 5: {
                imprimirMaterias(lista_materias);
                int id;
                printf("Ingrese el id de la materia a eliminar: \n");
                scanf("%d", &id);
                Materia *buscada = buscarMateriaPorId(lista_materias,id);
                if (buscada == NULL){
                    break;
                }
                eliminarMateriaListaGeneral(lista_materias,lista_estudiantes,buscada);
                imprimirMaterias(lista_materias);
                break;
            }
            case 6: {
                imprimirListaEstudiantes(lista_estudiantes);
                break;
            }
            case 7: {
                imprimirMaterias(lista_materias);
                break;
            }
            case 8: {
                int opcion_busqueda;
                    printf("Ingrese su opcion: \n");
                    printf("1. Buscar por DNI:\n");
                    printf("2. Buscar por nombre:\n");
                    printf("3. Volver al menu principal:\n");
                    scanf("%d",&opcion_busqueda);
                    switch (opcion_busqueda) {
                        case 1:{
                            int dni;
                            printf("Ingrese el numero de DNI del estudiante a buscar: \n");
                            scanf("%d", &dni);
                            imprimirDatosEstudiante(buscarEstudiantePorDNI(lista_estudiantes,dni));
                            break;
                        }
                        case 2:{
                            printf("Ingrese el nombre para el estudiante: ");
                            char nombre[100];

                            scanf("%s", nombre);
                            imprimirDatosEstudiante(buscarEstudiantePorNombre(lista_estudiantes,nombre));
                            break;
                        }
                        case 3:{
                            printf("Volviendo al menu principal: \n");
                            break;
                        }
                    }
                break;
            }
            case 9: {

            }
            case 10: {

            }
            case 11: {
                printf("Saliendo del programa...\n");
            }
        }
    } while (opcion != 11);
    return 0;
}

