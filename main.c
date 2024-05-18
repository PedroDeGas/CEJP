#include <stdio.h>
#include "lista_generica.c"
#include "lista_estudiantes.c"
#include "lista_materias.c"
#include "estudiante.c"
#include "materias.c"
// #include "date.c"



int main(){   
    Materia *materia = crearMateria('matematica', 123);
    NodoMateria *nodoMateria = crearNuevoNodoMateria(materia);
    ListaMaterias *listaMaterias = crearNuevaListaMaterias();

    listaMaterias = crearNuevaListaMaterias(listaMaterias, nodoMateria);
    printf("\na");


    // Estudiante *est1 = crearEstudiante('juan',1234567,'01/02/2003');
    // printf("\nb");

    // NodoEstudiante *nest1 = crearNuevoNodoEstudiante(est1);
    // printf("\nc");

     
    ListaEstudiante *listaEstudiantes = crearNuevaListaEstudiantes();
    printf("\nd");

    listaEstudiantes = agregarEstudiante(listaEstudiantes, crearNuevoNodoEstudiante(crearEstudiante('juan',123465,'01/02/2003')));
    listaEstudiantes = agregarEstudiante(listaEstudiantes, crearNuevoNodoEstudiante(crearEstudiante('asdd',4534566,'01/02/2003')));
    listaEstudiantes = agregarEstudiante(listaEstudiantes, crearNuevoNodoEstudiante(crearEstudiante('nuaj',5643234,'01/02/2003')));
    listaEstudiantes = agregarEstudiante(listaEstudiantes, crearNuevoNodoEstudiante(crearEstudiante('ujan',8903458905,'01/02/2003')));
    printf("\nmain");

    Nodo *nodo = crearNuevoNodoGenerico(123, 0);
    ListaGenerica *listaGen = crearNuevaListaGenerica();
    imprimirEstudiantes(listaEstudiantes);
    return 0;
}


