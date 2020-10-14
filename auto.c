#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "auto.h"
#include "marca.h"
#include "color.h"
#include "input.h"
#define LIBRE 0

char menu()
{
    char opcion;
    system("cls");

    printf("---------     *** ABM Autos ***      ---------\n\n");
    printf("a Alta auto\n");
    printf("b Modificar auto\n");
    printf("c Baja auto\n");
    printf("d Listar autos\n");
    printf("e Listar marcas\n");
    printf("f Listar colores\n");
    printf("g Listar servicios\n");
    printf("h Alta trabajo\n");
    printf("i Listar trabajos\n");
    printf("z Salir\n\n");
    opcion = getLetter("Ingrese opcion: ", "Caracter invalido, intente de nuevo: ");

    return opcion;
}

int buscarLibre(eAuto autos[], int tam)
{
    int index=-1;
    for(int i=0; i<tam; i++)
    {
        if(autos[i].isEmpty == LIBRE)
        {
            index=i;
            break;
        }
    }
    return index;
}

int buscarAuto(eAuto autos[], int tamAutos, int id)
{
    int index=-1;
    for(int i=0; i<tamAutos; i++)
    {
        if(autos[i].id == id && autos[i].isEmpty==1)
        {
            index=i;
            break;
        }
    }
    return index;
}

int inicializarAutos(eAuto autos[], int tam)
{
    int error=1;
    if(autos != NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            autos[i].isEmpty= LIBRE;
        }
        error=0;
    }
    return error;
}

int mostrarAutos(eAuto autos[], int tamAutos, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores)
{
    int error=1;
    int flag=0;
    if(autos != NULL && tamAutos>0)
    {
        printf("ID         Patente             Marca             Color        Modelo\n\n");
        for(int i=0; i<tamAutos; i++)
        {
            if(autos[i].isEmpty == 1)
            {
                mostrarAuto(autos[i], marcas, tamMarcas, colores, tamColores);
                flag=1;
            }
        }
        error=0;
        if (flag==0)
        {
            printf("    No hay autos cargados en la lista\n\n");
            error=2;
        }

    }
    return error;
}

void mostrarAuto(eAuto unAuto, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores)
{
    char marca[20];
    char color[20];
    cargarMarca(marcas, tamMarcas, unAuto.idMarca, marca);
    cargarColor(colores, tamColores, unAuto.idColor, color);
    printf("%4d     %7s     %15s     %15s     %4d\n", unAuto.id, unAuto.patente, marca, color, unAuto.modelo);
}

int altaAuto(eAuto autos[], int tam, int idAuto, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores)
{
    int error=1, index;
    eAuto nuevoAuto;
    char auxCad[20];
    int fEncontro=1;

    if(autos != NULL && tam>0 && idAuto>0)
    {
        system("cls");
        printf("   **** Alta auto ****\n\n\n");
        index = buscarLibre(autos, tam);
        if(index == -1)
        {
            printf("Sistema completo\n\n");
        }
        else
        {
            nuevoAuto.id= idAuto;

            nuevoAuto.isEmpty= 1;

            getStrings("Ingrese patente: ", "Demasiado largo, intente de nuevo: ", 10, nuevoAuto.patente);
            strupr(nuevoAuto.patente);

            do
            {
                getStrings("Ingrese marca: ", "Demasiado largo, intente de nuevo: ", 20, auxCad);
                for(int i=0; i<tamMarcas; i++)
                {
                    if(stricmp(auxCad, marcas[i].descripcion)==0)
                    {
                        nuevoAuto.idMarca=  marcas[i].id;
                        fEncontro=0;
                        break;
                    }
                }
            }
            while(fEncontro==1);
            fEncontro=1;
            do
            {
                getStrings("Ingrese color: ", "Demasiado largo, intente de nuevo: ", 20, auxCad);
                for(int i=0; i<tamColores; i++)
                {
                    if(stricmp(auxCad, colores[i].nombreColor)==0)
                    {
                        nuevoAuto.idColor=  colores[i].id;
                        fEncontro=0;
                        break;
                    }
                }
            }
            while(fEncontro==1);

            nuevoAuto.modelo = getInt("Ingrese el modelo del auto: ", "Anio invalido, intente de nuevo: ", 1900, 2020);

            autos[index] = nuevoAuto;

            error=0;
        }
    }
    return error;
}

int bajaAuto(eAuto autos[], int tamAutos, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores)
{
    int error=1;
    int index;
    int id;
    char confirma;

    if(autos != NULL && tamAutos>0)
    {
        system("cls");
        printf("   **** Baja de auto ****\n\n\n");
        mostrarAutos(autos, tamAutos, marcas, tamMarcas, colores, tamColores);
        id = getInt("Ingrese ID del auto a eliminar: ", "ID invalido, intente de nuevo: ", 3000, 4000);

        index= buscarAuto(autos, tamAutos, id);

        if(index == -1)
        {
            printf("No hay ningun auto con ese id\n\n");
        }
        else
        {
            mostrarAuto(autos[index], marcas, tamMarcas, colores, tamColores);
            confirma = getLetter("Confirma baja? ", "Caracter invalido, intente de nuevo: ");
            if(confirma == 's')
            {
                autos[index].isEmpty=LIBRE;
                error=0;
            }
            else
            {
                error=2;
            }
        }
    }
    return error;
}

int modificarAuto(eAuto autos[], int tamAutos, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores)
{
    int error=1;
    char auxCad[20];
    char confirma;

    if(autos != NULL && tamAutos>0)
    {
        system("cls");
        printf("***            **** Modificar auto ****            ***\n\n\n");
        mostrarAutos(autos, tamAutos, marcas, tamMarcas, colores, tamColores);
        getStrings("Ingrese patente de auto a modificar: ", "Patente invalida, intente de nuevo: ", 20, auxCad);
        strupr(auxCad);
        for(int i=0; i<tamAutos; i++)
        {
            if(strcmp(auxCad, autos[i].patente)==0 && autos[i].isEmpty!=LIBRE)
            {
                mostrarAuto(autos[i], marcas, tamMarcas, colores, tamColores);
                confirma = getLetter("Confirma modificacion? ", "Caracter invalido, intente de nuevo: ");
                if(confirma == 's')
                {
                    modificaciones(autos[i], marcas, tamMarcas, colores, tamColores);
                    error=0;
                }
                else
                {
                    error=2;
                }
            }
        }
    }
    return error;
}

int modificaciones(eAuto unAuto, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores)
{
    int error=-1;
    char opcion;
    char confirma='s';
    char auxCad[20];

    if(marcas != NULL && tamMarcas>0 && colores != NULL && tamColores>0)
    {
        system("cls");
        printf("          ***   Modificaciones de auto   ***\n\n\n");
        printf("a Modificar color\n");
        printf("b Modificar Modelo\n");
        printf("c Salir\n");
        opcion = getLetter("Ingrese opcion: ", "Caracter invalido, intente de nuevo: ");
        do
        {
            switch(opcion)
            {
            case 'a':
                getStrings("Ingrese nuevo color: ", "Color invalido, intente de nuevo: ", 20, auxCad);
                for(int i=0; i<tamColores; i++)
                {
                    if(stricmp(auxCad, colores[i].nombreColor)==0)
                    {
                        confirma= getLetter("Confirma cambio de color?: ", "Caracter invalido, intente de nuevo: ");
                        if(confirma=='s')
                        {
                            unAuto.idColor = colores[i].id;
                            printf("Cambio de color confirmado\n\n");
                        }
                        else
                        {
                            printf("Cambio de color cancelado por el usuario\n\n");
                        }
                    }
                    break;
                }
                break;
            case 'b':
                getStrings("Ingrese nuevo color: ", "Color invalido, intente de nuevo: ", 20, auxCad);
                for(int i=0; i<tamMarcas; i++)
                {
                    if(stricmp(auxCad, marcas[i].descripcion)==0)
                    {
                        confirma= getLetter("Confirma cambio de color?: ", "Caracter invalido, intente de nuevo: ");
                        if(confirma=='s')
                        {
                            unAuto.idMarca = marcas[i].id;
                            printf("Cambio de marca confirmado\n\n");
                        }
                        else
                        {
                            printf("Cambio de marca cancelado por el usuario\n\n");
                        }
                    }
                    break;
                }
                break;
            case 'c':
                printf("Saliendo del menu de modificaciones...\n\n\n");
                break;
            default:
                printf("Ha ingresado una opcion invalida\n\n");
                break;
            }
        }while(opcion != 'c');
        error=0;
    }
    return error;
}
