#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
}eMarca;

int cargarMarca(eMarca marcas[], int tamMarcas, int id, char descripcion[]);

int mostrarMarcas(eMarca marcas[], int tamMarcas);

void mostrarMarca(eMarca unaMarca);

#endif // MARCA_H_INCLUDED
