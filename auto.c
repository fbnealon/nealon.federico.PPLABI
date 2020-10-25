#include "auto.h"

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

int mostrarAutos(eAuto autos[], int tamAutos, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores, eCliente clientes[], int tamCl)
{
    int error=1;
    int flag=0;
    if(autos != NULL && tamAutos>0)
    {
        printf(" ID      Patente               Marca               Color     Modelo   Cliente\n\n");
        for(int i=0; i<tamAutos; i++)
        {
            if(autos[i].isEmpty == 1)
            {
                mostrarAuto(autos[i], marcas, tamMarcas, colores, tamColores, clientes, tamCl);
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

void mostrarAuto(eAuto unAuto, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores, eCliente clientes[], int tamCl)
{
    char marca[20];
    char color[20];
    char cliente[20];
    cargarMarca(marcas, tamMarcas, unAuto.idMarca, marca);
    cargarColor(colores, tamColores, unAuto.idColor, color);
    cargarCliente(clientes, tamCl, unAuto.idCliente, cliente);
    printf("%4d     %7s     %15s     %15s     %4d     %s\n", unAuto.id, unAuto.patente, marca, color, unAuto.modelo, cliente);
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
                getStrings("Ingrese patente (AAA000 o AA000AA): ", "Demasiado largo, intente de nuevo (AAA000 o AA000AA): ", 10, nuevoAuto.patente);
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

int bajaAuto(eAuto autos[], int tamAutos, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores, eCliente clientes[], int tamCl)
{
    int error=1;
    int index;
    int id;
    char confirma;

    if(autos != NULL && tamAutos>0)
    {
        system("cls");
        printf("   **** Baja de auto ****\n\n\n");
        mostrarAutos(autos, tamAutos, marcas, tamMarcas, colores, tamColores, clientes, tamCl);
        id = getInt("Ingrese ID del auto a eliminar: ", "ID invalido, intente de nuevo: ", 3000, 4000);

        index= buscarAuto(autos, tamAutos, id);

        if(index == -1)
        {
            printf("No hay ningun auto con ese id\n\n");
        }
        else
        {
            mostrarAuto(autos[index], marcas, tamMarcas, colores, tamColores, clientes, tamCl);
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

int modificarAuto(eAuto autos[], int tamAutos, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores, eCliente clientes[], int tamCl)
{
    int error=1;
    char auxCad[20];
    char confirma;

    if(autos != NULL && tamAutos>0 && marcas != NULL && tamMarcas>0 && colores != NULL && tamColores>0)
    {
        system("cls");
        printf("***            **** Modificar auto ****            ***\n\n\n");
        mostrarAutos(autos, tamAutos, marcas, tamMarcas, colores, tamColores, clientes, tamCl);
        getStrings("Ingrese patente de auto a modificar: ", "Patente invalida, intente de nuevo: ", 20, auxCad);
        strupr(auxCad);
        for(int i=0; i<tamAutos; i++)
        {
            if(strcmp(auxCad, autos[i].patente)==0 && autos[i].isEmpty!=LIBRE)
            {
                printf("\n");
                mostrarAuto(autos[i], marcas, tamMarcas, colores, tamColores, clientes, tamCl);
                printf("\n");
                confirma = getLetter("Confirma modificacion? ", "Caracter invalido, intente de nuevo: ");
                if(confirma == 's')
                {
                    autos[i] = modificaciones(autos[i], marcas, tamMarcas, colores, tamColores, clientes, tamCl);
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

eAuto modificaciones(eAuto unAuto, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores, eCliente clientes[], int tamCl)
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
            mostrarAuto(unAuto, marcas, tamMarcas, colores, tamColores, clientes, tamCl);
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
        system("cls");
        for(int i=0; i<tamAutos-1; i++)
        {
            if(autos[i].isEmpty != LIBRE)
            {
                cargarMarca(marcas, tamMarcas, autos[i].idMarca, descripcionI);
                for(int j=i+1; j<tamAutos; j++)
                {
                    if(autos[j].isEmpty != LIBRE)
                    {
                        cargarMarca(marcas, tamMarcas, autos[j].idMarca, descripcionJ);
                        if(stricmp(descripcionI, descripcionJ)>0 || (stricmp(descripcionI, descripcionJ)==0 && stricmp(autos[i].patente, autos[j].patente)>0))
                        {
                            auxAuto=autos[i];
                            autos[i]=autos[j];
                            autos[j]=auxAuto;
                        }
                    }
                }
            }
        }
        error=0;
    }
    return error;
}

