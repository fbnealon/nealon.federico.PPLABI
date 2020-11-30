#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "input.h"
#include "auto.h"
#include "marca.h"
#include "servicio.h"
#include "fecha.h"
#include "trabajo.h"
#include "informes.h"
#include "cliente.h"
#include "datastore.h"

#define TAM_A 10
#define TAM_M 5
#define TAM_C 5
#define TAM_S 4
#define TAM_T 1000
#define TAM_CL 4

//ID MARCAS 1000-1999
//ID SERVICIOS 20000-2999
//ID AUTOS 3000-3999
//ID TRABAJOS 4000-4999
//ID COLORES 5000-5999
//ID CLIENTES 6000-6999

void cargarVectores(eAuto autos[], int tamAutos, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores, eServicio servicios[], int tamServicios, eTrabajo trabajos[], int tamTrabajos, eCliente clientes[], int tamClientes);

int main()
{
    char seguir = 's';
    char confirma;
    int rta;
    int proximoIDAuto=3004;
    int proximoIDTrabajos= 4003;
    eAuto listaAutos[TAM_A];// ={{3000, "AS123DS", 1004, 5003, 2000, 6000, 1}, {3001, "FD789NL", 1002, 5001, 1985, 6001, 1}, {3002, "BC123AD", 1003, 5004, 2010, 6002, 1}, {3003, "AN654AS", 1003, 5000, 2020, 6003, 1}};
    eMarca listaMarcas[TAM_M];// ={{1000, "Renault"}, {1001, "Fiat"}, {1002, "Ford"}, {1003, "Chevrolet"}, {1004, "Peugeot"}};
    eColor listaColores[TAM_C];// ={{5000, "Negro"}, {5001, "Blanco"}, {5002, "Gris"}, {5003, "Rojo"}, {5004, "Azul"}};
    eServicio listaServicios[TAM_S];// ={{20000, "Lavado", 250}, {20001, "Pulido", 300}, {20002, "Encerado", 400}, {20003, "Completo", 600}};
    eTrabajo listaTrabajos[TAM_T];// = {{4000, "AS123DS", 20000, {21,10,2020}, 1}, {4001, "AS123DS", 20003, {27,10,2020}, 1}, {4002, "BC123AD", 20000, {23,10,2020}, 1}};
    eCliente listaClientes[TAM_CL];// = { {6000, "Federico", 'm', 1}, {6001, "Florencia", 'f', 1}, {6002, "Joaquin", 'm', 1}, {6003, "Nicolas", 'm', 1}};
    eMasElegidas masElegidas[TAM_M];

    if(!auto_inicializar(listaAutos, TAM_A))
    {
        printf("Inicializacion de autos exitosa!!\n\n");
    }
    else
    {
        printf("Error al inicializar\n\n");

    }
    if(!trabajo_inicializar(listaTrabajos, TAM_T))
    {
        printf("Inicializacion de trabajos exitosa!!\n\n");
    }
    else
    {
        printf("Error al inicializar\n\n");
    }
    system("pause");

    cargarVectores(listaAutos, 4, listaMarcas, 5, listaColores, 5, listaServicios, 4, listaTrabajos, 3, listaClientes, 4);
    do
    {
        switch(menu())
        {
        case 'a':
            rta=auto_alta(listaAutos, TAM_A, proximoIDAuto, listaMarcas, TAM_M, listaColores, TAM_C, listaClientes, TAM_CL);
            if(rta==0)
            {
                proximoIDAuto++;
                printf("Alta exitosa!!\n\n");
            }
            else if(rta==1)
            {
                printf("No se pudo realizar el alta...\n\n");
            }
            else
            {
                printf("Alta cancelada por el usuario\n");
            }
            break;
        case 'b':
            if(auto_hayCargado(listaAutos, TAM_A))
            {
                rta=auto_modificar(listaAutos, TAM_A, listaMarcas, TAM_M, listaColores, TAM_C, listaClientes, TAM_CL);
                if(rta == 0)
                    {
                        printf("Modificacion realizada con exito\n\n");
                    }
                    else if (rta==2)
                    {
                        printf("Modificacion cancelada por el usuario\n\n");
                    }
                    else
                    {
                        printf("Problemas con la modificacion\n\n");
                    }
            }
            else
            {
                printf("No hay autos cargados!\n\n");
            }
            break;
        case 'c':
            if(auto_hayCargado(listaAutos, TAM_A))
            {
                rta = auto_baja(listaAutos, TAM_A, listaMarcas, TAM_M, listaColores, TAM_C, listaClientes, TAM_CL);
                if(rta == 0)
                {
                    printf("Baja realizada con exito\n\n");
                }
                else if (rta==2)
                {
                    printf("Baja cancelada por el usuario\n\n");
                }
                else
                {
                    printf("Problemas con la baja\n\n");
                }
            }
            else
            {
                printf("No hay autos cargados!\n\n");
            }
            break;
        case 'd':
            if(auto_hayCargado(listaAutos, TAM_A))
            {
                if(!auto_ordenarXMarcaYPatente(listaAutos, TAM_A, listaMarcas, TAM_M, listaColores, TAM_C))
                {
                    printf("-----------------LISTA DE AUTOS POR MARCA Y PATENTE-----------------\n\n");
                    auto_mostrarTodos(listaAutos, TAM_A, listaMarcas, TAM_M, listaColores, TAM_C, listaClientes, TAM_CL);
                }
                else
                {
                    printf("Error al ordenar\n\n");
                }
            }
            else
            {
                printf("No hay autos cargados!\n\n");
            }
            break;
        case 'e':
            system("cls");
            marca_mostrarTodas(listaMarcas, TAM_M);
            break;
        case 'f':
            system("cls");
            color_mostrarTodos(listaColores, TAM_C);
            break;
        case 'g':
            system("cls");
            servicio_mostrarTodos(listaServicios, TAM_S);
            break;
        case 'h':
            if(auto_hayCargado(listaAutos, TAM_A))
            {
                rta = trabajo_alta(listaTrabajos, TAM_T, proximoIDTrabajos, listaAutos, TAM_A,  listaMarcas, TAM_M,  listaColores, TAM_C, listaServicios, TAM_S, listaClientes, TAM_CL);
                if(rta==0)
                {
                    printf("Alta exitosa!!\n\n");
                    proximoIDTrabajos++;
                }
                else if(rta==2)
                {
                    printf("Alta cancelada por el usuario\n\n");
                }
                else
                {
                    printf("Problemas al intentar cargar un nuevo trabajo\n\n");
                }
            }
            else
            {
                printf("No hay autos cargados!\n\n");
            }
            break;
        case 'i':
            system("cls");
            trabajo_mostrarTodos(listaTrabajos, TAM_T, listaServicios, TAM_S);
            break;
        case 'j':
            system("cls");
            informe_cargarMasElegidas(masElegidas, listaMarcas, TAM_M, listaAutos, TAM_A);
            informar(listaAutos, TAM_A, listaMarcas, TAM_M, listaColores, TAM_C, listaServicios, TAM_S, listaTrabajos, TAM_T, listaClientes, TAM_CL, masElegidas);
            break;
        case 'z':
            confirma = getLetter("Confirma salida?: ", "Caracter invalido, intente de nuevo: ");
            confirma = tolower(confirma);
            if(confirma == 's')
            {
                seguir = 'n';
            }
            break;
        default:
            printf("Opcion invalida!!!\n");
            break;
        }
        system("pause");
    }
    while( seguir == 's');
    return 0;
}

void cargarVectores(eAuto autos[], int tamAutos, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores, eServicio servicios[], int tamServicios, eTrabajo trabajos[], int tamTrabajos, eCliente clientes[], int tamClientes)
{
    int i;
    for(i=0; i<tamAutos; i++)
    {
        autos[i]=autosH[i];
    }
    for(i=0; i<tamMarcas; i++)
    {
        marcas[i]=marcasH[i];
    }
    for(i=0; i<tamColores; i++)
    {
        colores[i]=coloresH[i];
    }
    for(i=0; i<tamServicios; i++)
    {
        servicios[i]=serviciosH[i];
    }
    for(i=0; i<tamTrabajos; i++)
    {
        trabajos[i]=trabajosH[i];
    }
    for(i=0; i<tamClientes; i++)
    {
        clientes[i]=clientesH[i];
    }
}
