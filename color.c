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
