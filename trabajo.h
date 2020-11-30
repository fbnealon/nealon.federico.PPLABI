#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "fecha.h"
#include "auto.h"
#include "servicio.h"
#include "input.h"


typedef struct
{
    int id; //autoincremental
    char patente[9]; //debe existir VALIDAR
    int idServicio; //debe existir VALIDAR
    eFecha fecha;  //VALIDAR
    int isEmpty;
}eTrabajo;

int trabajo_inicializar(eTrabajo trabajos[], int tamTrabajos);

int trabajo_buscarLibre(eTrabajo trabajos[], int tam);

int trabajo_alta(eTrabajo trabajos[], int tamTrabajos, int idTrabajos, eAuto autos[], int tamAutos, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores, eServicio servicios[], int tamServicios, eCliente clientes[], int tamCl);

int trabajo_mostrarTodos(eTrabajo trabajos[], int tamTrabajos, eServicio servicios[], int tamServicios);

void trabajo_mostrarUno(eTrabajo unTrabajo, eServicio servicios[], int tamServicios);

#endif // TRABAJO_H_INCLUDED
