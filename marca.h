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

int marca_cargar(eMarca marcas[], int tamMarcas, int id, char descripcion[]);

int marca_mostrarTodas(eMarca marcas[], int tamMarcas);

void marca_mostrarUna(eMarca unaMarca);

#endif // MARCA_H_INCLUDED
