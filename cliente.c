#include "cliente.h"


int cargarCliente(eCliente clientes[], int tamClientes, int id, char descripcion[])
{
    int error=1;
    if(clientes != NULL && tamClientes>0 && id>0)
    {
        for(int i=0; i<tamClientes; i++)
        {
            if(clientes[i].id == id && clientes[i].isEmpty != 0)
            {
                strcpy(descripcion, clientes[i].nombre);
                error=0;
            }
        }
    }
    return error;
}
