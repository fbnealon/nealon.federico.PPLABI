#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct
{
    int id;
    char nombreColor[20];
}eColor;

int cargarColor(eColor colores[], int tamColores, int id, char descripcion[]);


#endif // COLOR_H_INCLUDED
