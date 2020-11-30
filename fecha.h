#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "input.h"

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

eFecha fecha_solicitar(eFecha unaFecha);

#endif // FECHA_H_INCLUDED
