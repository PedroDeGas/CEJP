#ifndef SISTEMA_MATERIADESAPROBADA_H
#define SISTEMA_MATERIADESAPROBADA_H

typedef struct Materia {
    char nombre[10];
    int nota;
    struct Materia *proximo;
    struct Estudiante *estudiantes;
    struct Materia *prerequisito; // Materia anterior requerida
} Materia;
} Materia;

#endif
