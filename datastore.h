#ifndef DATASTORE_H_INCLUDED
#define DATASTORE_H_INCLUDED

#include "auto.h"
#include "marca.h"
#include "color.h"
#include "servicio.h"
#include "trabajo.h"

eAuto autosH[4] = {{3000, "AS123DS", 1004, 5003, 2000, 1}, {3001, "FD789NL", 1002, 5001, 1985, 1}, {3002, "BC123AD", 1003, 5004, 2010, 1}, {3003, "AN654AS", 1003, 5000, 2020, 1}};

eMarca marcasH[5] = {{1000, "Renault"}, {1001, "Fiat"}, {1002, "Ford"}, {1003, "Chevrolet"}, {1004, "Peugeot"}};

eColor coloresH[5] = {{5000, "Negro"}, {5001, "Blanco"}, {5002, "Gris"}, {5003, "Rojo"}, {5004, "Azul"}};

eServicio serviciosH[4] = {{20000, "Lavado", 250}, {20001, "Pulido", 300}, {20002, "Encerado", 400}, {20003, "Completo", 600}};

eTrabajo trabajosH[3] = {{4000, "AS123DS", 2000, {21,10,2020}, 1}, {4001, "AS123DS", 2003, {27,10,2020}, 1}, {4002, "BC123AD", 2000, {23,10,2020}, 1}};

#endif // DATASTORE_H_INCLUDED
