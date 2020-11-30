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

typedef struct
{
    int idMarca;
    int cantidad;
}eMasElegidas;

char menuInformes();

int informar(eAuto autos[], int tamAutos, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores, eServicio servicios[], int tamServicios, eTrabajo trabajos[], int tamT, eCliente clientes[], int tamColoresl, eMasElegidas masElegidas[]);

int informe_autosDeColor(eAuto autos[], int tamAutos, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores, int idColor, eCliente clientes[], int tamClientes);

int informe_autosDeMarca(eAuto autos[], int tamAutos, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores, int idMarca, eCliente clientes[], int tamClientes);

int informe_autoMasAntiguo(eAuto autos[], int tamAutos, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores, eCliente clientes[], int tamClientes);

int informe_autosXMarca(eAuto autos[], int tamAutos, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores, eCliente clientes[], int tamClientes);

int informe_cantidadXColorYMarca(eAuto autos[], int tamAutos, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores, int idColor, int idMarca);

int informe_inicializarMasElegidas(eMasElegidas masElegidas[], eMarca marcas[], int tamMarcasarcas);

int informe_cargarMasElegidas(eMasElegidas masElegidas[], eMarca marcas[], int tamMarcasarcas, eAuto autos[], int tamAutos);

int informe_marcasMasElegidas(eMasElegidas masElegidas[], eMarca marcas[], int tamMarcasarcas, eAuto autos[], int tamAutos);

int informe_trabajosXAuto(eTrabajo trabajos[], int tamT, eServicio servicios[], int tamServicios, char patente[]);

int informe_importesXAuto(eTrabajo trabajos[], int tamT, eServicio servicios[], int tamServicios, char patente[]);

int informe_autosXServicio(eTrabajo trabajos[], int tamTrabajos, int idServicio, eAuto autos[], int tamAutos, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores, eCliente clientes[], int tamClientes, eServicio servicios[], int tamServicios);

int informe_serviciosXFecha(eTrabajo trabajos[], int tamT, eServicio servicios[], int tamServicios, eFecha fecha);


#endif // INFORMES_H_INCLUDED
