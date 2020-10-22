#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "input.h"

typedef struct
{
    int id;
    char descripcion[20];
}eMarca;

int cargarMarca(eMarca marcas[], int tamMarcas, int id, char descripcion[]);

int mostrarMarcas(eMarca marcas[], int tamMarcas);

void mostrarMarca(eMarca unaMarca);

#endif // MARCA_H_INCLUDED
