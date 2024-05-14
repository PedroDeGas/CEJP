#include <stdio.h>
#include <malloc.h>

typedef struct structNodo {
    int valor;
    struct structNodo *proximo;
} Nodo;

Nodo *agregar(Nodo *lista, int valor) {
    Nodo *nuevoNodo = malloc(sizeof(Nodo));
    
    nuevoNodo->valor = valor;
    nuevoNodo->proximo = NULL;
    if (lista == NULL) {
        lista = nuevoNodo;
    } else {
        Nodo *cursor = lista;
        while (cursor->proximo != NULL) {
            cursor = cursor->proximo;
        }
        cursor->proximo = nuevoNodo;
    }
    return lista;
}
//largo de lista
int largo(Nodo *lista) {
    int count = 0;
    Nodo *cursor = lista;
    while (cursor!= NULL) {
        count++;
        cursor = cursor->proximo;
    }
    return count;
}

//obtener un elemnto de la lista
Nodo *obtenerElemento(Nodo *lista, int posicion) {
    Nodo *cursor = lista;
    int i = 0;
    while (cursor!= NULL && i < posicion) {
        cursor = cursor->proximo;
        i++;
    }
    return cursor;
}



//Borrar un elemento de la lista
Nodo *eliminar(Nodo *lista, int posicion) {
    if (posicion == 0) {
        Nodo *nuevoInicio = lista->proximo;
        free(lista);
        return nuevoInicio;
    }

    Nodo *cursor = lista;
    int i = 0;
    while (cursor!= NULL && i < posicion - 1) {
        cursor = cursor->proximo;
        i++;
    }

    if (cursor == NULL || cursor->proximo == NULL) {
        return lista;
    }

    Nodo *temp = cursor->proximo;
    cursor->proximo = temp->proximo;
    free(temp);

    return lista;
}

//imprimir lista
void imprimir(Nodo *lista) {
    Nodo *cursor = lista;
    while (cursor!= NULL) {
        printf("%d ", cursor->valor);
        cursor = cursor->proximo;
    }
    printf("\n");
}

int main(void) {
    Nodo *lista = NULL;

    lista = agregar(lista, 1);
    lista = agregar(lista, 2);
    lista = agregar(lista, 3);
    lista = agregar(lista, 4);
    lista = agregar(lista, 5);
    lista = agregar(lista, 6);

    printf("%d\n", lista->valor);
    printf("%d\n", lista->proximo->valor);
    printf("%d\n", lista->proximo->proximo->valor);
    printf("%d\n", lista->proximo->proximo->proximo->valor);
    printf("%d\n", lista->proximo->proximo->proximo->proximo->valor);
    printf("%d\n", lista->proximo->proximo->proximo->proximo->proximo->valor);

//imprimir 
imprimir(lista);

//eliminar
lista = eliminar(lista, 2);
printf("Se elimino el elemento en la posicion 2\n");
//largo
printf("Largo de la lista: %d\n", largo(lista));
//obtener
printf("Elemento en la posicion 2: %d\n", obtenerElemento(lista, 2)->valor);

return 0;



}
