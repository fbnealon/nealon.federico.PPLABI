#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct
{
    int id;
    char nombre[20];
    char sexo;
}eCliente;

int cargarCliente(eCliente clientes[], int tamClientes, int id, char descripcion[]);

#endif // CLIENTE_H_INCLUDED
