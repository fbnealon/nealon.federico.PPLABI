#ifndef DATASTORE_H_INCLUDED
#define DATASTORE_H_INCLUDED

#include "marca.h"
#include "color.h"
#include "servicio.h"

eMarca marcasH[5] = {{1000, "Renault"}, {1001, "Fiat"}, {1002, "Ford"}, {1003, "Chevrolet"}, {1004, "Peugeot"}};

eColor coloresH[5] = {{5000, "Negro"}, {5001, "Blanco"}, {5002, "Gris"}, {5003, "Rojo"}, {5004, "Azul"}};

eServicio serviciosH[4] = {{20000, "Lavado", 250}, {20001, "Pulido", 300}, {20002, "Encerado", 400}, {20003, "Completo", 600}};

#endif // DATASTORE_H_INCLUDED
