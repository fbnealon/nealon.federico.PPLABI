#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "cliente.h"
#include "input.h"


int cargarCliente(eCliente clientes[], int tamClientes, int id, char descripcion[])
{
    int error=1;
    if(clientes != NULL && tamClientes>0 && id>0)
    {
        for(int i=0; i<tamClientes; i++)
        {
            if(clientes[i].id == id)
            {
                strcpy(descripcion, clientes[i].nombre);
                error=0;
            }
        }
    }
    return error;
}
