#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "marca.h"
#include "input.h"


int cargarMarca(eMarca marcas[], int tamMarcas, int id, char descripcion[])
{
    int error=1;
    if(marcas != NULL && tamMarcas>0 && id>0)
    {
        for(int i=0; i<tamMarcas; i++)
        {
            if(marcas[i].id == id)
            {
                strcpy(descripcion, marcas[i].descripcion);
            }
        }
        error=0;
    }
    return error;
}

int mostrarMarcas(eMarca marcas[], int tamMarcas)
{
    int error=1;
    int flag=0;
    if(marcas != NULL && tamMarcas>0)
    {
        printf("ID                     NOMBRE\n\n");
        for(int i=0; i<tamMarcas; i++)
        {
            mostrarMarca(marcas[i]);
            flag=1;
        }
        printf("\n\n");
        if (flag==0)
        {
            printf("    No hay marcas cargadas en la lista\n\n");
        }
        error=0;
    }
    return error;
}

void mostrarMarca(eMarca unaMarca)
{
    printf("%4d     %20s\n", unaMarca.id, unaMarca.descripcion);
}
