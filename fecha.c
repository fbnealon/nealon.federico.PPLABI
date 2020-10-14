#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "fecha.h"
#include "input.h"

eFecha solicitarFecha(eFecha nuevaFecha)
{
    do
    {
        printf("Ingrese fecha valida (dd/mm/aaaa): ");
        fflush(stdin);
        scanf("%d/%d/%d", &nuevaFecha.dia, &nuevaFecha.mes, &nuevaFecha.anio);
    }while((nuevaFecha.dia<1 && nuevaFecha.dia>31) || (nuevaFecha.mes<1 && nuevaFecha.mes>12) || nuevaFecha.anio!=2020);
    return nuevaFecha;
}
