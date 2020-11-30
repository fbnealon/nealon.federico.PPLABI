#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "input.h"

typedef struct
{
    int id; //comienza en 20000
    char descripcion[25];
    int precio;
}eServicio;

int servicio_cargar(eServicio servicios[], int tamServicios, int id, char descripcion[]);

int servicio_mostrarTodos(eServicio servicios[], int tamServicios);

void servicio_mostrarUno(eServicio unServicio);


#endif // SERVICIO_H_INCLUDED
