#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "fecha.h"
#include "auto.h"
#include "servicio.h"
#include "trabajo.h"
#include "input.h"

int inicializarTrabajos(eTrabajo trabajos[], int tamTrabajos)
{
    int error=1;
    if(trabajos != NULL && tamTrabajos>0)
    {
        for(int i=0; i<tamTrabajos; i++)
        {
            trabajos[i].isEmpty= 0;
        }
        error=0;
    }
    return error;
}

int buscarLibreTrabajo(eTrabajo trabajos[], int tam)
{
    int index=-1;
    for(int i=0; i<tam; i++)
    {
        if(trabajos[i].isEmpty == 0)
        {
            index=i;
            break;
        }
    }
    return index;
}

int altaTrabajo(eTrabajo trabajos[], int tamTrabajos, int idTrabajos, eAuto autos[], int tamAutos, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores, eServicio servicios[], int tamServicios)
{
    int error=1, auxID, index;
    char confirma='s';
    eTrabajo nuevoTrabajo;
    char auxCad[20];

    if(trabajos != NULL && tamTrabajos>0)
    {
        index = buscarLibreTrabajo(trabajos, tamTrabajos);
        if(index== -1)
        {
            printf("Sistema completo\n\n\n");
        }
        else
        {
            system("cls");
            printf("   **** Alta trabajo ****\n\n\n");
            mostrarAutos(autos, tamAutos, marcas, tamMarcas, colores, tamColores);
            auxID = getInt("Ingrese ID del auto a trabajar: ", "ID Incorrecto, intente de nuevo: ", 3000, 4000);
            for(int i=0; i<tamAutos; i++)
            {
                if(auxID == autos[i].id && autos[i].isEmpty!=0)
                {
                    printf("Auto encontrado, patente: %s\n", autos[i].patente);
                    system("pause");
                    system("cls");
                    mostrarServicios(servicios, tamServicios);
                    getStrings("Ingrese servicio a realizarle: ", "Incorrecto, intente de nuevo: ", 20, auxCad);
                    for(int j=0; j<tamServicios; j++)
                    {
                        if(stricmp(auxCad, servicios[j].descripcion)==0)
                        {
                            printf("Servicio encontrado: %s\n", servicios[j].descripcion);
                            nuevoTrabajo.id = idTrabajos;
                            strcpy(nuevoTrabajo.patente, autos[i].patente);
                            nuevoTrabajo.fecha = solicitarFecha(nuevoTrabajo.fecha);
                            nuevoTrabajo.idServicio = servicios[j].id;
                            printf("%d/%d/%d\n", nuevoTrabajo.fecha.dia, nuevoTrabajo.fecha.mes, nuevoTrabajo.fecha.anio);
                            nuevoTrabajo.isEmpty = 1;
                            mostrarTrabajo(nuevoTrabajo, servicios, tamServicios);
                            confirma = getLetter("Confirma alta de trabajo?: ", "Caracter invalido, intente de nuevo: ");
                            if(confirma == 's')
                            {
                                trabajos[index] = nuevoTrabajo;
                                error=0;
                            }
                            else
                            {
                                error=2;
                            }
                        }
                    }
                }
            }
        }
    }
    return error;
}

int mostrarTrabajos(eTrabajo trabajos[], int tamTrabajos, eServicio servicios[], int tamServicios)
{
    int error=1;
    int flag=0;
    if(trabajos != NULL && tamTrabajos>0)
    {
        printf("ID        PATENTE               SERVICIO       FECHA\n\n");
        for(int i=0; i<tamTrabajos; i++)
        {
            if(trabajos[i].isEmpty != 0)
            {
                mostrarTrabajo(trabajos[i], servicios, tamServicios);
                flag=1;
            }
        }
        printf("\n\n");
        if (flag==0)
        {
            printf("    No hay trabajos cargados en la lista\n\n");
        }
        error=0;
    }
    return error;
}

void mostrarTrabajo(eTrabajo unTrabajo, eServicio servicios[], int tamServicios)
{
    char auxServicio[20];
    cargarServicio(servicios, tamServicios, unTrabajo.idServicio, auxServicio);
    printf("%4d     %8s       %15s       %2d/%2d/%4d\n", unTrabajo.id, unTrabajo.patente, auxServicio, unTrabajo.fecha.dia, unTrabajo.fecha.mes, unTrabajo.fecha.anio);
}
