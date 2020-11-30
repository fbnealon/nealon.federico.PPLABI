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
    char patente[9]; //VALIDAR
    int idMarca; //VALIDAR
    int idColor;
    int modelo;
    int idCliente;
    int isEmpty; //1 OCUPADO, 0 LIBRE
}eAuto;

char menu();

int auto_buscarLibre(eAuto autos[], int tam);

int auto_buscar(eAuto autos[], int tamAutos, int id);

int auto_inicializar(eAuto autos[], int tam);

int auto_mostrarTodos(eAuto autos[], int tamAutos, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores, eCliente clientes[], int tamClientes);

void auto_mostrarUno(eAuto unAuto, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores, eCliente clientes[], int tamClientes);

int auto_alta(eAuto autos[], int tam, int idAuto, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores, eCliente clientes[], int tamClientes);

int auto_baja(eAuto autos[], int tamAutos, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores, eCliente clientes[], int tamClientes);

int auto_modificar(eAuto autos[], int tamAutos, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores, eCliente clientes[], int tamClientes);

eAuto auto_modificaciones(eAuto unAuto, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores, eCliente clientes[], int tamClientes);

int auto_ordenarXMarcaYPatente(eAuto autos[], int tamAutos, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores);

int auto_hayCargado(eAuto autos[], int tamAutos);

#endif // AUTO_H_INCLUDED
