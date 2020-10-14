#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct
{
    int id; //comienza en 20000
    char descripcion[25];
    int precio;
}eServicio;

int cargarServicio(eServicio servicios[], int tamServicios, int id, char descripcion[]);

int mostrarServicios(eServicio servicios[], int tamServicios);

void mostrarServicio(eServicio unServicio);


#endif // SERVICIO_H_INCLUDED
