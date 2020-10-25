#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "input.h"

typedef struct
{
    int id;
    char nombre[20];
    char sexo;
    int isEmpty;
}eCliente;

int cargarCliente(eCliente clientes[], int tamClientes, int id, char descripcion[]);

#endif // CLIENTE_H_INCLUDED
