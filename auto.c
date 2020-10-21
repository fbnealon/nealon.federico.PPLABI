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
    printf("j Informes\n");
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
        printf(" ID      Patente               Marca               Color     Modelo\n\n");
        for(int i=0; i<tamAutos; i++)
        {
            if(autos[i].isEmpty == 1)
            {
                mostrarAuto(autos[i], marcas, tamMarcas, colores, tamColores);
                flag=1;
            }
        }
        printf("\n\n");
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
    char auxMarca[20];
    char auxColor[20];
    char confirma;
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

            do
            {
                getStrings("Ingrese patente: ", "Demasiado largo, intente de nuevo: ", 10, nuevoAuto.patente);
            }
            while (strlen(nuevoAuto.patente)<6 || strlen(nuevoAuto.patente)>7);
            strupr(nuevoAuto.patente);

            do
            {
                system("cls");
                printf("PATENTE: %s\n\n", nuevoAuto.patente);
                mostrarMarcas(marcas, tamMarcas);
                getStrings("Ingrese marca: ", "Demasiado largo, intente de nuevo: ", 20, auxCad);
                for(int i=0; i<tamMarcas; i++)
                {
                    if(stricmp(auxCad, marcas[i].descripcion)==0)
                    {
                        nuevoAuto.idMarca=  marcas[i].id;
                        fEncontro=0;
                        cargarMarca(marcas, tamMarcas, marcas[i].id, auxMarca);
                        break;
                    }
                }
            }
            while(fEncontro==1);
            fEncontro=1;
            do
            {
                system("cls");
                printf("PATENTE: %s\nMARCA: %s\n\n", nuevoAuto.patente, auxMarca);
                mostrarColores(colores, tamColores);
                getStrings("Ingrese color: ", "Demasiado largo, intente de nuevo: ", 20, auxCad);
                for(int i=0; i<tamColores; i++)
                {
                    if(stricmp(auxCad, colores[i].nombreColor)==0)
                    {
                        nuevoAuto.idColor=  colores[i].id;
                        fEncontro=0;
                        cargarColor(colores, tamColores, colores[i].id, auxColor);
                        break;
                    }
                }
            }
            while(fEncontro==1);

            system("cls");
            printf("PATENTE: %s\nMARCA: %s\nCOLOR: %s\n\n", nuevoAuto.patente, auxMarca, auxColor);
            nuevoAuto.modelo = getInt("Ingrese el modelo del auto (de 1900 a 2020): ", "Anio invalido, intente de nuevo: ", 1900, 2020);
            system("cls");
            printf("PATENTE: %s\nMARCA: %s\nCOLOR: %s\nMODELO: %d\n\n", nuevoAuto.patente, auxMarca, auxColor, nuevoAuto.modelo);
            confirma=getLetter("Confirma alta?: ", "Caracter invalido, intente de nuevo: ");
            if(confirma=='s')
            {
                autos[index] = nuevoAuto;
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

    if(autos != NULL && tamAutos>0 && marcas != NULL && tamMarcas>0 && colores != NULL && tamColores>0)
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
                printf("\n");
                mostrarAuto(autos[i], marcas, tamMarcas, colores, tamColores);
                printf("\n");
                confirma = getLetter("Confirma modificacion? ", "Caracter invalido, intente de nuevo: ");
                if(confirma == 's')
                {
                    autos[i] = modificaciones(autos[i], marcas, tamMarcas, colores, tamColores);
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

eAuto modificaciones(eAuto unAuto, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores)
{
    eAuto auxAuto= unAuto;
    char opcion;
    char confirma='n';
    char auxCad[20];
    int auxModelo;

    if(marcas != NULL && tamMarcas>0 && colores != NULL && tamColores>0)
    {
        do
        {
            system("cls");
            printf("          ***   Modificaciones de auto   ***\n\n\n");
            mostrarAuto(unAuto, marcas, tamMarcas, colores, tamColores);
            printf("\n");
            printf("a Modificar color\n");
            printf("b Modificar Modelo\n");
            printf("c Salir\n");
            opcion = getLetter("Ingrese opcion: ", "Caracter invalido, intente de nuevo: ");
            switch(opcion)
            {
            case 'a':
                if(!mostrarColores(colores, tamColores))
                {
                    getStrings("Ingrese nuevo color: ", "Color invalido, intente de nuevo: ", 20, auxCad);
                    for(int i=0; i<tamColores; i++)
                    {
                        if(stricmp(auxCad, colores[i].nombreColor)==0)
                        {
                            printf("Color nuevo: %s\n", colores[i].nombreColor);
                            confirma= getLetter("Confirma cambio de color?: ", "Caracter invalido, intente de nuevo: ");
                            if(confirma=='s')
                            {
                                auxAuto.idColor=colores[i].id;
                                printf("Cambio de color confirmado\n\n");
                                break;
                            }
                            else
                            {
                                printf("Cambio de color cancelado por el usuario\n\n");
                            }
                        }
                    }
                    system("pause");

                }
                break;
            case 'b':
                auxModelo= getInt("Ingrese nuevo modelo (1950 a 2020): ", "Modelo invalido, intente de nuevo: ", 1950, 2020);
                confirma= getLetter("Confirma cambio de modelo?: ", "Caracter invalido, intente de nuevo: ");
                if(confirma=='s')
                {
                    auxAuto.modelo=auxModelo;
                    printf("Cambio de modelo confirmado\n\n");
                }
                else
                {
                    printf("Cambio de modelo cancelado por el usuario\n\n");
                }
                system("pause");
                break;
            case 'c':
                printf("Saliendo del menu de modificaciones...\n\n\n");
                break;
            default:
                printf("Ha ingresado una opcion invalida\n\n");
                break;
            }
            unAuto=auxAuto;
        }
        while(opcion != 'c');
    }
    return unAuto;
}

int ordenarAutosXMarcaYPatente(eAuto autos[], int tamAutos, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores)
{
    int error=1;
    char descripcionI[20], descripcionJ[20];
    eAuto auxAuto;
    if(autos != NULL && tamAutos>0 && marcas != NULL && tamMarcas>0 && colores != NULL && tamColores>0)
    {
        for(int i=0; i<tamAutos-1; i++)
        {
            cargarMarca(marcas, tamMarcas, autos[i].idMarca, descripcionI);
            for(int j=i+1; j<tamAutos; j++)
            {
                cargarMarca(marcas, tamMarcas, autos[j].idMarca, descripcionJ);
                if(strcmp(descripcionI, descripcionJ)>0 || (strcmp(descripcionI, descripcionJ)==0 && stricmp(autos[i].patente, autos[j].patente)>0))
                {
                    auxAuto=autos[i];
                    autos[i]=autos[j];
                    autos[j]=auxAuto;
                }
            }
        }
        error=0;
    }
    return error;
}

char menuInformes()
{
    char opcion;
    system("cls");

    printf("---------     *** Informes ***      ---------\n\n");
    printf("a Informar autos de un color\n");
    printf("b Informar autos de una marca\n");
    printf("c Informar auto mas antiguo\n");
    printf("d Informar autos por marca\n");
    printf("e Informar cantidad de autos de un color y marca\n");
    printf("f Informar marca mas elegida\n");
    printf("z Salir\n\n");
    opcion = tolower(getLetter("Ingrese opcion: ", "Caracter invalido, intente de nuevo: "));

    return opcion;
}

int informar(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC)
{
    system("cls");
    int idColor;
    int idMarca;
    char seguir= 's';
    char confirma;
    do
    {
        switch(menuInformes())
        {
        case 'a':
            system("cls");
            mostrarColores(colores, tamC);
            idColor=getInt("Ingrese ID de color a listar: ", "Valor invalido, intente de nuevo: ", 5000, 6000);
            system("cls");
            printf("      *** Informe de autos de un color ***\n\n");
            mostrarAutosDeColor(autos, tamA, marcas, tamM, colores, tamC, idColor);
            break;
        case 'b':
            system("cls");
            mostrarMarcas(marcas, tamM);
            idMarca=getInt("Ingrese ID de marca a listar: ", "Valor invalido, intente de nuevo: ", 1000, 2000);
            system("cls");
            printf("      *** Informe de autos de una marca ***\n\n");
            mostrarAutosDeMarca(autos, tamA, marcas, tamM, colores, tamC, idMarca);
            break;
        case 'c':
            system("cls");
            printf("      *** Informe de autos mas antiguos ***\n\n");
            mostrarMasAntiguo(autos, tamA, marcas, tamM, colores, tamC);
            break;
        case 'd':
            system("cls");
            printf("      *** Informe de autos por marca ***\n\n");
            mostrarXMarca(autos, tamA, marcas, tamM, colores, tamC);
            break;
        case 'e':
            system("cls");
            mostrarColores(colores, tamC);
            idColor=getInt("Ingrese ID de color: ", "Valor invalido, intente de nuevo: ", 5000, 6000);
            system("cls");
            mostrarMarcas(marcas, tamM);
            idMarca=getInt("Ingrese ID de marca: ", "Valor invalido, intente de nuevo: ", 1000, 2000);
            system("cls");
            printf("      *** Informe de cantidad de autos de color y marca ***\n\n");
            contarXColorYMarca(autos, tamA, marcas, tamM, colores, tamC, idColor, idMarca);
            break;
        case 'f':
            //MARCAS MAS ELEGIDAS
            break;
        case 'g':
            //TRABAJOS POR AUTO
            break;
        case 'h':
            //IMPORTES POR AUTO
            break;
        case 'i':
            //AUTOS POR SERVICIO
            break;
        case 'j':
            //SERVICIOS POR FECHA
            break;
        case 'z':
            confirma = getLetter("Confirma salida a menu principal?: ", "Caracter invalido, intente de nuevo: ");
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
    while(seguir== 's');
    return 0;
}

int mostrarAutosDeColor(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC, int idColor)
{
    int error=1;
    int flag=0;
    if(autos != NULL && tamA>0 && marcas != NULL && tamM>0 && colores != NULL && tamC>0)
    {
        printf(" ID      Patente               Marca               Color     Modelo\n\n");
        for(int i=0; i<tamA; i++)
        {
            if(autos[i].isEmpty != LIBRE && autos[i].idColor==idColor)
            {
                mostrarAuto(autos[i], marcas, tamM, colores, tamC);
                flag=1;
            }
        }
        printf("\n\n");
        if (flag==0)
        {
            printf("    No hay autos cargados del color ingresado!!\n\n");
        }
        error=0;
    }
    return error;
}

int mostrarAutosDeMarca(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC, int idMarca)
{
    int error=1;
    int flag=0;
    if(autos != NULL && tamA>0 && marcas != NULL && tamM>0 && colores != NULL && tamC>0)
    {
        printf(" ID      Patente               Marca               Color     Modelo\n\n");
        for(int i=0; i<tamA; i++)
        {
            if(autos[i].isEmpty != LIBRE && autos[i].idMarca==idMarca)
            {
                mostrarAuto(autos[i], marcas, tamM, colores, tamC);
                flag=1;
                error=0;
            }
        }
        printf("\n\n");
        if (flag==0)
        {
            printf("    No hay autos cargados de la marca ingresada!!\n\n");
            error=2;
        }
        error=0;
    }
    return error;
}

int mostrarMasAntiguo(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC)
{
    int error=1;
    int esPrimera=1;
    eAuto masAntiguo;
    if(autos != NULL && tamA>0 && marcas != NULL && tamM>0 && colores != NULL && tamC>0)
    {
        printf(" ID      Patente               Marca               Color     Modelo\n\n");
        for(int i=0; i<tamA; i++)
        {
            if(esPrimera && autos[i].isEmpty != LIBRE)
            {
                masAntiguo = autos[i];
                esPrimera=0;
            }
            if(autos[i].isEmpty != LIBRE && autos[i].modelo<masAntiguo.modelo)
            {
                masAntiguo=autos[i];
            }
            if(autos[i].modelo == masAntiguo.modelo && autos[i].id!=masAntiguo.id)
            {
                mostrarAuto(masAntiguo, marcas, tamM, colores, tamC);
                masAntiguo=autos[i];
            }
        }
        mostrarAuto(masAntiguo, marcas, tamM, colores, tamC);
        printf("\n\n");
        error=0;
    }
    return error;
}

int mostrarXMarca(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC)
{
    int error=1;
    int mostro=0;
    if(autos != NULL && tamA>0 && marcas != NULL && tamM>0 && colores != NULL && tamC>0)
    {
        for(int i=0; i<tamM; i++)
        {
            printf("MARCA: %s\n", marcas[i].descripcion);
            for(int j=0; j<tamA; j++)
            {
                if(autos[j].isEmpty != LIBRE && autos[j].idMarca== marcas[i].id && mostro==0)
                {
                    mostrarAutosDeMarca(autos, tamA, marcas, tamM, colores, tamC, marcas[i].id);
                    mostro=1;
                }
            }
            if(mostro==0)
            {
                printf("No hay autos ingresados con la marca %s\n\n", marcas[i].descripcion);
            }
            mostro=0;
        }
        error=0;
    }
    return error;
}

int contarXColorYMarca(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC, int idColor, int idMarca)
{
    int error=1;
    int cantidad=0;
    char color[20];
    char marca[20];
    if(autos != NULL && tamA>0 && marcas != NULL && tamM>0 && colores != NULL && tamC>0)
    {
        if(!cargarColor(colores, tamC, idColor, color) && !cargarMarca(marcas, tamM, idMarca, marca))
        {
            for(int i=0; i<tamA; i++)
            {
                if(autos[i].idColor==idColor && autos[i].idMarca==idMarca)
                {
                    cantidad++;
                }
            }
            if(cantidad==0)
            {
                printf("No hay autos de color %s y marca %s\n", color, marca);
            }
            else
            {
                printf("La cantidad de autos de color %s y marca %s es %d\n\n", color, marca, cantidad);
            }
            error=0;
        }
        else
        {
            printf("Ha ingresado algun ID invalido\n\n");
        }

    }
    return error;
}
