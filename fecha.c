#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "fecha.h"
#include "input.h"

eFecha solicitarFecha(eFecha unaFecha)
{
    do
    {
        printf("Ingrese fecha valida (dd/mm/aaaa): ");
        fflush(stdin);
        scanf("%d/%d/%d", &unaFecha.dia, &unaFecha.mes, &unaFecha.anio);
    }while((unaFecha.dia<1 && unaFecha.dia>31) || (unaFecha.mes<1 && unaFecha.mes>12) || unaFecha.anio!=2020);
    return unaFecha;
}
