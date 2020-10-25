#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "auto.h"
#include "marca.h"
#include "color.h"
#include "trabajo.h"
#include "fecha.h"
#include "servicio.h"

char menuInformes();

int informar(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC, eServicio servicios[], int tamS, eTrabajo trabajos[], int tamT);

int mostrarAutosDeColor(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC, int idColor);

int mostrarAutosDeMarca(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC, int idMarca);

int mostrarMasAntiguo(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC);

int mostrarXMarca(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC);

int contarXColorYMarca(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC, int idColor, int idMarca);

int marcasMasElegidas(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC);

int mostrarTrabajosXAuto(eTrabajo trabajos[], int tamT, eServicio servicios[], int tamS, char patente[]);

int mostrarImportesXAuto(eTrabajo trabajos[], int tamT, eServicio servicios[], int tamS, char patente[]);

int mostrarAutosXServicio(eTrabajo trabajos[], int tamT, int idServicio);

int mostrarServiciosXFecha(eTrabajo trabajos[], int tamT, eServicio servicios[], int tamS, eFecha fecha);


#endif // INFORMES_H_INCLUDED
