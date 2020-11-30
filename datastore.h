#ifndef DATASTORE_H_INCLUDED
#define DATASTORE_H_INCLUDED

#include "auto.h"
#include "marca.h"
#include "color.h"
#include "servicio.h"
#include "trabajo.h"
#include "cliente.h"

eAuto autosH[4] = {{3000, "AS1234DS", 1004, 5003, 2000, 6000, 1}, {3001, "FD7890NL", 1002, 5001, 1985, 6001, 1}, {3002, "BC1234AD", 1003, 5004, 2010, 6002, 1}, {3003, "AN6543AS", 1003, 5000, 2020, 6003, 1}};

eMarca marcasH[5] = {{1000, "Renault"}, {1001, "Fiat"}, {1002, "Ford"}, {1003, "Chevrolet"}, {1004, "Peugeot"}};

eColor coloresH[5] = {{5000, "Negro"}, {5001, "Blanco"}, {5002, "Gris"}, {5003, "Rojo"}, {5004, "Azul"}};

eServicio serviciosH[4] = {{20000, "Lavado", 250}, {20001, "Pulido", 300}, {20002, "Encerado", 400}, {20003, "Completo", 600}};

eTrabajo trabajosH[3] = {{4000, "AS1234DS", 20000, {21,10,2020}, 1}, {4001, "AS1234DS", 20003, {27,10,2020}, 1}, {4002, "BC1234AD", 20000, {23,10,2020}, 1}};

eCliente clientesH[4] = {{6000, "Federico", 'm', 1}, {6001, "Florencia", 'f', 1}, {6002, "Joaquin", 'm', 1}, {6003, "Nicolas", 'm', 1}};

#endif // DATASTORE_H_INCLUDED
