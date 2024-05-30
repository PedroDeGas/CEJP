#include "materias.h"
#include "estudiante.h"
#include "lista_materiasEnCurso.h"
#include "lista_materias.h"
#include <stdio.h>
#include "lista_estudiantes.h"

int main(){
    //Creacion Materias
    Materia *materia1 = crearMateria("Lengua", 123);
    Materia *materia2 = crearMateria("Biologia", 124);
    Materia *materia3 = crearMateria("Fisica", 125);

    //Creacion Fechas
    Fecha *fecha1 = crearFecha(29,5,1990);
    Fecha *fecha2 = crearFecha(13,11,1992);
    Fecha *fecha3 = crearFecha(1,10,2000);
    Fecha *inicio_busqueda = crearFecha(1,1,1900);
    Fecha *fin_busqueda = crearFecha(12,12,1994);
    Fecha *actual = obtenerFechaActual();

    //Calcular Edades
    Fecha* edad1 = calcularEdad(fecha1);
    Fecha* edad2 = calcularEdad(fecha2);
    Fecha* edad3 = calcularEdad(fecha3);
    printf("Edad: %d d - %d m - %d a \n", edad1->dia,edad1->mes,edad1->anio);

    //Creacion Estudiantes
    Estudiante *estudiante1 = crearEstudiante("Juan",42046296,fecha1);
    Estudiante *estudiante2 = crearEstudiante("Pedro",22240495,fecha2);
    Estudiante *estudiante3 = crearEstudiante("Ramon",1192375,fecha3);

    //Anotarse en materias
    anotarseEnMateria(estudiante1,materia1);
    anotarseEnMateria(estudiante2,materia3);
    anotarseEnMateria(estudiante3,materia2);

    //Listar Materias
    ListaMaterias *listaMaterias = crearNuevaListaMaterias();
    agregarMateria(listaMaterias,materia1);
    agregarMateria(listaMaterias,materia2);
    agregarMateria(listaMaterias,materia3);
    eliminarMateria(listaMaterias, 123);

    //ListaEstudiantes
    ListaEstudiante *listaEstudiante = crearListaEstudiantes();
    agregarEstudiante(listaEstudiante, estudiante1);
    agregarEstudiante(listaEstudiante, estudiante2);
    agregarEstudiante(listaEstudiante, estudiante3);
    eliminarEstudiante(listaEstudiante, 42046296);
    ListaEstudiante *encontrados = buscarEstudiantesPorRangoEdad(listaEstudiante, inicio_busqueda, fin_busqueda);
    //modificarListaEstudiante(listaEstudiante);

    //Metodos Materias
    //modificarIDMateriaGeneral(materia2);
    //modificarNombreMateriaGeneral(materia2);

    //SetNota - Estudiante
    imprimirListaMateriasEnCurso(estudiante1->listaEnCurso);

}


