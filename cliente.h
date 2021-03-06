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

int cliente_cargar(eCliente clientes[], int tamClientes, int id, char descripcion[]);

int cliente_mostrarTodos(eCliente clientes[], int tamClientes);

void cliente_mostrarUno(eCliente unCliente);



#endif // CLIENTE_H_INCLUDED
