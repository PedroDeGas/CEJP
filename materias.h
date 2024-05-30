#ifndef CEJP_MATERIA_H
#define CEJP_MATERIA_H
typedef struct MateriaStruct {
    char *nombre;
    int id;
} Materia;

void limpiarBuffer();
Materia* crearMateria(char *nombre, int id);
void modificarIDMateriaGeneral(Materia *materia);
void modificarNombreMateriaGeneral(Materia *materia);
#endif