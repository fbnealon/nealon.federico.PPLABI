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

#define TAM_A 10
#define TAM_M 5
#define TAM_C 5
#define TAM_S 4
#define TAM_T 1000
#define TAM_CL 4

//ID MARCAS 1000-1999
//ID SERVICIOS 2000-2999
//ID AUTOS 3000-3999
//ID TRABAJOS 4000-4999
//ID COLORES 5000-5999
//ID CLIENTES 6000-6999

int main()
{
    char seguir = 's';
    char confirma;
    int rta;
    int proximoIDAuto=3004;
    int proximoIDTrabajos= 4003;
    eAuto listaAutos[TAM_A] ={{3000, "AS123DS", 1004, 5003, 2000, 1}, {3001, "FD789NL", 1002, 5001, 1985, 1}, {3002, "BC123AD", 1003, 5004, 2010, 1}, {3003, "AN654AS", 1003, 5000, 2020, 1}};
    eMarca listaMarcas[TAM_M] ={{1000, "Renault"}, {1001, "Fiat"}, {1002, "Ford"}, {1003, "Chevrolet"}, {1004, "Peugeot"}};
    eColor listaColores[TAM_C] ={{5000, "Negro"}, {5001, "Blanco"}, {5002, "Gris"}, {5003, "Rojo"}, {5004, "Azul"}};
    eServicio listaServicios[TAM_S] ={{2000, "Lavado", 250}, {2001, "Pulido", 300}, {2002, "Encerado", 400}, {2003, "Completo", 600}};
    eTrabajo listaTrabajos[TAM_T] = {{4000, "AS123DS", 2000, {21,10,2020}, 1}, {4001, "AS123DS", 2003, {27,10,2020}, 1}, {4002, "BC123AD", 2000, {23,10,2020}, 1}};
    eCliente listaClientes[TAM_CL] = { {6000, "Federico", 'm'}, {6001, "Florencia", 'f'}, {6002, "Joaquin", 'm'}, {6003, "Nicolas", 'm'}}

    /*if(!inicializarAutos(listaAutos, TAM_A))
    {
        printf("Inicializacion de autos exitosa!!\n\n");
    }
    else
    {
        printf("Error al inicializar\n\n");

    }
    if(!inicializarTrabajos(listaTrabajos, TAM_T))
    {
        printf("Inicializacion de trabajos exitosa!!\n\n");
    }
    else
    {
        printf("Error al inicializar\n\n");
    }
    system("pause");
    */
    do
    {
        switch(menu())
        {
        case 'a':
            rta=altaAuto(listaAutos, TAM_A, proximoIDAuto, listaMarcas, TAM_M, listaColores, TAM_C);
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
            rta=modificarAuto(listaAutos, TAM_A, listaMarcas, TAM_M, listaColores, TAM_C);
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
            break;
        case 'c':
            if(mostrarAutos(listaAutos, TAM_A, listaMarcas, TAM_M, listaColores, TAM_C)!=2)
            {
                rta = bajaAuto(listaAutos, TAM_A, listaMarcas, TAM_M, listaColores, TAM_C);
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
            break;
        case 'd':
            if(!ordenarAutosXMarcaYPatente(listaAutos, TAM_A, listaMarcas, TAM_M, listaColores, TAM_C))
            {
                printf("              ***LISTA DE AUTOS POR MARCA Y PATENTE***\n\n");
                mostrarAutos(listaAutos, TAM_A, listaMarcas, TAM_M, listaColores, TAM_C);
            }
            else
            {
                printf("Error al ordenar\n\n");
            }
            break;
        case 'e':
            system("cls");
            mostrarMarcas(listaMarcas, TAM_M);
            break;
        case 'f':
            system("cls");
            mostrarColores(listaColores, TAM_C);
            break;
        case 'g':
            system("cls");
            mostrarServicios(listaServicios, TAM_S);
            break;
        case 'h':
            rta = altaTrabajo(listaTrabajos, TAM_T, proximoIDTrabajos, listaAutos, TAM_A,  listaMarcas, TAM_M,  listaColores, TAM_C, listaServicios, TAM_S);
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
            break;
        case 'i':
            system("cls");
            mostrarTrabajos(listaTrabajos, TAM_T, listaServicios, TAM_S);
            break;
        case 'j':
            system("cls");
            informar(listaAutos, TAM_A, listaMarcas, TAM_M, listaColores, TAM_C, listaServicios, TAM_S, listaTrabajos, TAM_T);
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
