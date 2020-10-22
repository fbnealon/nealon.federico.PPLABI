#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "input.h"

typedef struct
{
    int id;
    char nombreColor[20];
}eColor;

int cargarColor(eColor colores[], int tamColores, int id, char descripcion[]);

int mostrarColores(eColor colores[], int tamColores);

void mostrarColor(eColor unColor);

#endif // COLOR_H_INCLUDED
