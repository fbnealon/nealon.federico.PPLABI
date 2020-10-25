#include "informes.h"

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
    printf("g Informar trabajos realizados a un auto\n");
    printf("h Informar importes cobrados a un auto\n");
    printf("i Informar autos y fechas en las que se realizo un servicio\n");
    printf("j Informar servicios realizados en una fecha\n");

    printf("z Salir\n\n");
    opcion = tolower(getLetter("Ingrese opcion: ", "Caracter invalido, intente de nuevo: "));

    return opcion;
}

int informar(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC, eServicio servicios[], int tamS, eTrabajo trabajos[], int tamT, eCliente clientes[], int tamCl)
{
    system("cls");
    int idColor;
    int idMarca;
    int idServicio;
    eFecha fecha;
    //int idAuto;
    //int idTrabajo;
    char seguir='s';
    char confirma;
    char patente[20];
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
            mostrarAutosDeColor(autos, tamA, marcas, tamM, colores, tamC, idColor, clientes, tamCl);
            break;
        case 'b':
            system("cls");
            mostrarMarcas(marcas, tamM);
            idMarca=getInt("Ingrese ID de marca a listar: ", "Valor invalido, intente de nuevo: ", 1000, 2000);
            system("cls");
            printf("      *** Informe de autos de una marca ***\n\n");
            mostrarAutosDeMarca(autos, tamA, marcas, tamM, colores, tamC, idMarca, clientes, tamCl);
            break;
        case 'c':
            system("cls");
            printf("      *** Informe de autos mas antiguos ***\n\n");
            mostrarMasAntiguo(autos, tamA, marcas, tamM, colores, tamC, clientes, tamCl);
            break;
        case 'd':
            system("cls");
            printf("      *** Informe de autos por marca ***\n\n");
            mostrarXMarca(autos, tamA, marcas, tamM, colores, tamC, clientes, tamCl);
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
            system("cls");
            marcasMasElegidas(autos, tamA, marcas, tamM, colores, tamC);
            break;
        case 'g':
            system("cls");
            mostrarAutos(autos, tamA, marcas, tamM, colores, tamC, clientes, tamCl);
            getStrings("Ingrese patente del auto: ", "Demasiado largo, intente de nuevo: ", 10, patente);
            system("cls");
            printf("      *** Informe de servicios por patente de auto ***\n\n");
            if(mostrarTrabajosXAuto(trabajos, tamT, servicios, tamS, patente))
            {
                printf("No hay servicios asignados al auto de patente %s\n\n", strupr(patente));
            }
            break;
        case 'h':
            system("cls");
            mostrarAutos(autos, tamA, marcas, tamM, colores, tamC, clientes, tamCl);
            getStrings("Ingrese patente del auto: ", "Demasiado largo, intente de nuevo: ", 10, patente);
            system("cls");
            printf("      *** Informe de importes auto ***\n\n");
            if(mostrarImportesXAuto(trabajos, tamT, servicios, tamS, patente))
            {
                printf("No hay servicios asignados al auto seleccionado\n\n");
            }
            break;
        case 'i':
            system("cls");
            mostrarServicios(servicios, tamS);
            idServicio=getInt("Ingrese ID del servicio: ", "Intente de nuevo: ", 2000, 3000);
            system("cls");
            printf("      *** Informe de autos y fecha de servicio ***\n\n");
            if(mostrarAutosXServicio(trabajos, tamT, idServicio))
            {
                printf("No hay servicios realizados del tipo elegido\n\n");
            }
            break;
        case 'j':
            system("cls");
            mostrarTrabajos(trabajos, tamT, servicios, tamS);
            fecha=solicitarFecha(fecha);
            system("cls");
            printf("      *** Informe de servicios por fecha ***\n\n");
            if(mostrarServiciosXFecha(trabajos, tamT, servicios, tamS, fecha))
            {
                printf("No hay servicios realizados en la fecha seleccionada\n\n");
            }
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

int mostrarAutosDeColor(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC, int idColor, eCliente clientes[], int tamCl)
{
    int error=1;
    int flag=0;
    if(autos != NULL && tamA>0 && marcas != NULL && tamM>0 && colores != NULL && tamC>0)
    {
        printf(" ID      Patente               Marca               Color     Modelo   Cliente\n\n");
        for(int i=0; i<tamA; i++)
        {
            if(autos[i].isEmpty != LIBRE && autos[i].idColor==idColor)
            {
                mostrarAuto(autos[i], marcas, tamM, colores, tamC, clientes, tamCl);
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

int mostrarAutosDeMarca(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC, int idMarca, eCliente clientes[], int tamCl)
{
    int error=1;
    int flag=0;
    if(autos != NULL && tamA>0 && marcas != NULL && tamM>0 && colores != NULL && tamC>0)
    {
        printf(" ID      Patente               Marca               Color     Modelo   Cliente\n\n");
        for(int i=0; i<tamA; i++)
        {
            if(autos[i].isEmpty != LIBRE && autos[i].idMarca==idMarca)
            {
                mostrarAuto(autos[i], marcas, tamM, colores, tamC, clientes, tamCl);
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

int mostrarMasAntiguo(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC, eCliente clientes[], int tamCl)
{
    int error=1;
    int esPrimera=1;
    eAuto masAntiguo;
    if(autos != NULL && tamA>0 && marcas != NULL && tamM>0 && colores != NULL && tamC>0)
    {
        printf(" ID      Patente               Marca               Color     Modelo   Cliente\n\n");
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
            if(autos[i].isEmpty != LIBRE && autos[i].modelo == masAntiguo.modelo && autos[i].id!=masAntiguo.id)
            {
                mostrarAuto(masAntiguo, marcas, tamM, colores, tamC, clientes, tamCl);
                masAntiguo=autos[i];
            }
        }
        mostrarAuto(masAntiguo, marcas, tamM, colores, tamC, clientes, tamCl);
        printf("\n\n");
        error=0;
    }
    return error;
}

int mostrarXMarca(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC, eCliente clientes[], int tamCl)
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
                    mostrarAutosDeMarca(autos, tamA, marcas, tamM, colores, tamC, marcas[i].id, clientes, tamCl);
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

int marcasMasElegidas(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC)
{
    int error=1;
    int cantidad=0;
    int mayor=0;
    char marca[20];
    if(autos != NULL && tamA>0 && marcas != NULL && tamM>0 && colores != NULL && tamC>0)
    {
        for(int i=0; i<tamA;i++)
        {
            if(autos[i].isEmpty != LIBRE)
            {
                for(int j=0; j<tamA; j++)
                {
                    if(autos[j].isEmpty != LIBRE && autos[j].idMarca==autos[i].idMarca)
                    {
                        cantidad++;
                    }
                }
                if(mayor<cantidad)
                {
                    cargarMarca(marcas, tamM, autos[i].idMarca, marca);
                    mayor=cantidad;
                }
            }
            cantidad=0;
        }
        printf("La marca mas elegida es %s\n\n", marca);
        error=0;
    }
    return error;
}

int mostrarTrabajosXAuto(eTrabajo trabajos[], int tamT, eServicio servicios[], int tamS, char patente[])
{
    int error=1;
    if(trabajos != NULL && tamT>0 && servicios != NULL && tamS>0)
    {
        for(int i=0; i<tamT; i++)
        {
            if(stricmp(patente, trabajos[i].patente)==0 && trabajos[i].isEmpty!=0)
            {
                mostrarTrabajo(trabajos[i], servicios, tamS);
                error=0;
            }
        }
    }
    return error;
}

int mostrarImportesXAuto(eTrabajo trabajos[], int tamT, eServicio servicios[], int tamS, char patente[])
{
    int error=1;
    int total=0;
    if(trabajos != NULL && tamT>0 && servicios != NULL && tamS>0)
    {
        for(int i=0; i<tamT; i++)
        {
            if(stricmp(patente, trabajos[i].patente)==0 && trabajos[i].isEmpty!=0)
            {
                for(int j=0; j<tamS; j++)
                {
                    if(trabajos[i].idServicio==servicios[j].id)
                    {
                        total=+servicios[j].precio;
                    }
                }
            }
        }
        if(total>0)
        {
            printf("El total de importes aplicados al auto de patente %s es de %d\n\n", strupr(patente), total);
            error=0;
        }
    }
    return error;
}

int mostrarAutosXServicio(eTrabajo trabajos[], int tamT, int idServicio)
{
    int error=1;
    if(trabajos != NULL && tamT>0)
    {
        printf("PATENTE            FECHA\n\n");
        for(int i=0; i<tamT; i++)
        {
            if(idServicio==trabajos[i].idServicio && trabajos[i].isEmpty!=LIBRE)
            {
                printf("%s           %d/%d/%d\n", trabajos[i].patente, trabajos[i].fecha.dia, trabajos[i].fecha.mes, trabajos[i].fecha.anio);
                error=0;
            }
        }
    }
    return error;
}

int mostrarServiciosXFecha(eTrabajo trabajos[], int tamT, eServicio servicios[], int tamS, eFecha fecha)
{
    int error=1;
    char servicio[20];
    if(trabajos != NULL && tamT>0)
    {
        printf("SERVICIO            FECHA\n\n");
        for(int i=0; i<tamT; i++)
        {
            if(fecha.dia==trabajos[i].fecha.dia && fecha.mes==trabajos[i].fecha.mes && fecha.anio==trabajos[i].fecha.anio && trabajos[i].isEmpty!=LIBRE)
            {
                cargarServicio(servicios, tamS, trabajos[i].idServicio, servicio);
                printf("%s           %d/%d/%d\n", servicio, trabajos[i].fecha.dia, trabajos[i].fecha.mes, trabajos[i].fecha.anio);
                error=0;
            }
        }
    }
    return error;
}
