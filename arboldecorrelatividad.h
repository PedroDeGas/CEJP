typedef struct Nodo {
    char nombre[50];
    struct Nodo *izquierda;
    struct Nodo *derecha;
} Nodo;

void imprimir_arbol(Nodo *raiz);
Nodo *agregar_nodo(Nodo *raiz, char nombre[]);
Nodo *buscar_nodo(Nodo *raiz, char nombre[]);