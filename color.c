#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "color.h"
#include "input.h"


int cargarColor(eColor colores[], int tamColores, int id, char descripcion[])
{
    int error=1;
    if(colores != NULL && tamColores>0 && id>0)
    {
        for(int i=0; i<tamColores; i++)
        {
            if(colores[i].id == id)
            {
                strcpy(descripcion, colores[i].nombreColor);
            }
        }
        error=0;
    }
    return error;
}

int mostrarColores(eColor colores[], int tamColores)
{
    int error=1;
    int flag=0;
    if(colores != NULL && tamColores>0)
    {
        printf("ID                      COLOR\n\n");
        for(int i=0; i<tamColores; i++)
        {
            mostrarColor(colores[i]);
            flag=1;
        }
        if (flag==0)
        {
            printf("    No hay marcas cargadas en la lista\n\n");
        }
        error=0;
    }
    return error;
}

void mostrarColor(eColor unColor)
{
    printf("%4d     %20s\n", unColor.id, unColor.nombreColor);
}
