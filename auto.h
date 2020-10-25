#ifndef AUTO_H_INCLUDED
#define AUTO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "marca.h"
#include "color.h"
#include "input.h"
#include "cliente.h"

#define LIBRE 0


typedef struct
{
    int id;
    char patente[7]; //VALIDAR
    int idMarca; //VALIDAR
    int idColor;
    int modelo;
    int idCliente;
    int isEmpty; //1 OCUPADO, 0 LIBRE
}eAuto;

char menu();

int buscarLibre(eAuto autos[], int tam);

int buscarAuto(eAuto autos[], int tamAutos, int id);

int inicializarAutos(eAuto autos[], int tam);

int mostrarAutos(eAuto autos[], int tamAutos, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores, eCliente clientes[], int tamCl);

void mostrarAuto(eAuto unAuto, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores, eCliente clientes[], int tamCl);

int altaAuto(eAuto autos[], int tam, int idAuto, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores);

int bajaAuto(eAuto autos[], int tamAutos, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores, eCliente clientes[], int tamCl);

int modificarAuto(eAuto autos[], int tamAutos, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores, eCliente clientes[], int tamCl);

eAuto modificaciones(eAuto unAuto, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores, eCliente clientes[], int tamCl);

int ordenarAutosXMarcaYPatente(eAuto autos[], int tamAutos, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores);

#endif // AUTO_H_INCLUDED
