#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "input.h"
#include "auto.h"
#include "marca.h"

#define TAM_A 10
#define TAM_M 5
#define TAM_C 5


int main()
{
    char seguir = 's';
    char confirma;
    int rta;
    int proximoIDAuto=3000;
    eAuto listaAutos[TAM_A] = {{3000, "AS123DS", 1004, 5003, 2000, 1}, {3001, "FD789NL", 1002, 5001, 1985, 1}};
    eMarca listaMarcas[TAM_M] = {{1000, "Renault"}, {1001, "Fiat"}, {1002, "Ford"}, {1003, "Chevrolet"}, {1004, "Peugeot"}};
    eColor listaColores[TAM_C] = {{5000, "Negro"}, {5001, "Blanco"}, {5002, "Gris"}, {5003, "Rojo"}, {5004, "Azul"}};
    /*if(!inicializarAutos(listaAutos, TAM_A))
    {
        printf("Inicializacion exitosa!!\n\n");
    }
    else
    {
        printf("Error al inicializar\n\n");

    }
    system("pause");*/
    do
    {
        switch(menu())
        {
        case 'a':
            if(!altaAuto(listaAutos, TAM_A, proximoIDAuto, listaMarcas, TAM_M, listaColores, TAM_C))
            {
                proximoIDAuto++;
                printf("Alta exitosa!!\n\n");
            }
            else
            {
                printf("No se pudo realizar el alta...\n\n");
            }
            break;
        case 'b':
            if(mostrarAutos(listaAutos, TAM_A, listaMarcas, TAM_M, listaColores, TAM_C)!=2)
            {
                modificarAuto(listaAutos, TAM_A, listaMarcas, TAM_M, listaColores, TAM_C);
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
            system("cls");
            mostrarAutos(listaAutos, TAM_A, listaMarcas, TAM_M, listaColores, TAM_C);
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
            break;
        case 'h':
            break;
        case 'i':
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
