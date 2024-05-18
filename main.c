#include <stdio.h>
#include "lista_materias.c"
#include "estudiante.c"
#include "materias.c"


int main(){   
    Materia *materia = crearMateria("-", 123);
    NodoMateria *nodoMateria = crearNuevoNodo(materia);
    ListaMaterias *lista = crearNuevaLista();
    lista = agregarNodo(lista, nodoMateria);
    imprimir(lista);
    return 0;
}


