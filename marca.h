#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
}eMarca;

int cargarMarca(eMarca marcas[], int tamMarcas, int id, char descripcion[]);

int hardcodearMarcas(eMarca marcas[], int tam, int cant);

#endif // MARCA_H_INCLUDED
