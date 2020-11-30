#include "cliente.h"


int cliente_cargar(eCliente clientes[], int tamClientes, int id, char descripcion[])
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

int cliente_mostrarTodos(eCliente clientes[], int tamClientes)
{
    int error=1;
    int flag=0;
    if(clientes != NULL && tamClientes>0)
    {
        printf("ID                    CLIENTE\n\n");
        for(int i=0; i<tamClientes; i++)
        {
            cliente_mostrarUno(clientes[i]);
            flag=1;
        }
        printf("\n\n");
        if (flag==0)
        {
            printf("    No hay clientes cargados en la lista\n\n");
        }
        error=0;
    }
    return error;
}

void cliente_mostrarUno(eCliente unCliente)
{
    printf("%4d     %20s\n", unCliente.id, unCliente.nombre);
}
