#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "servicio.h"
#include "input.h"

int cargarServicio(eServicio servicios[], int tamServicios, int id, char descripcion[])
{
    int error=1;
    if(servicios != NULL && tamServicios>0 && id>0)
    {
        for(int i=0; i<tamServicios; i++)
        {
            if(servicios[i].id == id)
            {
                strcpy(descripcion, servicios[i].descripcion);
            }
        }
        error=0;
    }
    return error;
}

int mostrarServicios(eServicio servicios[], int tamServicios)
{
    int error=1;
    int flag=0;
    if(servicios != NULL && tamServicios>0)
    {
        printf("ID                     SERVICIO      PRECIO\n\n");
        for(int i=0; i<tamServicios; i++)
        {
            mostrarServicio(servicios[i]);
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

void mostrarServicio(eServicio unServicio)
{
    printf("%4d     %20s          %d\n", unServicio.id, unServicio.descripcion, unServicio.precio);
}
