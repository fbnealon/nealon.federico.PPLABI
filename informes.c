#include "informes.h"

/** \brief Menu de informes
 *
 * \return char
 *
 */
char menuInformes()
{
    char opcion;
    system("cls");

    printf("---------     *** Informes ***      ---------\n\n");
    printf("a Informar autos del color a seleccionar\n");
    printf("b Informar autos de marca a seleccionar\n");
    printf("c Informar autos mas antiguos\n");
    printf("d Informar autos separados por marca\n");
    printf("e Informar cantidad de autos de un color y marca a seleccionar\n");
    printf("f Informar marcas mas elegidas\n");
    printf("g Informar trabajos realizados a un auto a seleccionar\n");
    printf("h Informar importes cobrados a un auto a seleccionar\n");
    printf("i Informar autos y fechas en las que se realizo un servicio a seleccionar\n");
    printf("j Informar servicios realizados en una fecha\n");

    printf("z Salir\n\n");
    opcion = tolower(getLetter("Ingrese opcion: ", "Caracter invalido, intente de nuevo: "));

    return opcion;
}

/** \brief Seleccion de opcion de menu de informes
 *
 * \param autos[] eAuto
 * \param tamAutos int
 * \param marcas[] eMarca
 * \param tamMarcas int
 * \param colores[] eColor
 * \param tamColores int
 * \param servicios[] eServicio
 * \param tamServicios int
 * \param trabajos[] eTrabajo
 * \param tamTrabajos int
 * \param clientes[] eCliente
 * \param tamClientes int
 * \param masElegidas[] eMasElegidas
 * \return int
 *
 */
int informar(eAuto autos[], int tamAutos, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores, eServicio servicios[], int tamServicios, eTrabajo trabajos[], int tamTrabajos, eCliente clientes[], int tamClientes, eMasElegidas masElegidas[])
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
            color_mostrarTodos(colores, tamColores);
            idColor=getInt("Ingrese ID de color a listar: ", "Valor invalido, intente de nuevo: ", 5000, 6000);
            system("cls");
            printf("      *** Informe de autos de un color ***\n\n");
            informe_autosDeColor(autos, tamAutos, marcas, tamMarcas, colores, tamColores, idColor, clientes, tamClientes);
            break;
        case 'b':
            system("cls");
            marca_mostrarTodas(marcas, tamMarcas);
            idMarca=getInt("Ingrese ID de marca a listar: ", "Valor invalido, intente de nuevo: ", 1000, 2000);
            system("cls");
            printf("      *** Informe de autos de una marca ***\n\n");
            informe_autosDeMarca(autos, tamAutos, marcas, tamMarcas, colores, tamColores, idMarca, clientes, tamClientes);
            break;
        case 'c':
            system("cls");
            printf("      *** Informe de autos mas antiguos ***\n\n");
            informe_autoMasAntiguo(autos, tamAutos, marcas, tamMarcas, colores, tamColores, clientes, tamClientes);
            break;
        case 'd':
            system("cls");
            printf("      *** Informe de autos por marca ***\n\n");
            informe_autosXMarca(autos, tamAutos, marcas, tamMarcas, colores, tamColores, clientes, tamClientes);
            break;
        case 'e':
            system("cls");
            color_mostrarTodos(colores, tamColores);
            idColor=getInt("Ingrese ID de color: ", "Valor invalido, intente de nuevo: ", 5000, 6000);
            system("cls");
            marca_mostrarTodas(marcas, tamMarcas);
            idMarca=getInt("Ingrese ID de marca: ", "Valor invalido, intente de nuevo: ", 1000, 2000);
            system("cls");
            printf("      *** Informe de cantidad de autos de color y marca ***\n\n");
            informe_cantidadXColorYMarca(autos, tamAutos, marcas, tamMarcas, colores, tamColores, idColor, idMarca);
            break;
        case 'f':
            system("cls");
            informe_marcasMasElegidas(masElegidas, marcas, tamMarcas, autos, tamAutos);
            break;
        case 'g':
            system("cls");
            auto_mostrarTodos(autos, tamAutos, marcas, tamMarcas, colores, tamColores, clientes, tamClientes);
            getStrings("Ingrese patente del auto: ", "Demasiado largo, intente de nuevo: ", 10, patente);
            system("cls");
            printf("      *** Informe de servicios por patente de auto ***\n\n");
            if(informe_trabajosXAuto(trabajos, tamTrabajos, servicios, tamServicios, patente))
            {
                printf("No hay servicios asignados al auto de patente %s\n\n", strupr(patente));
            }
            break;
        case 'h':
            system("cls");
            auto_mostrarTodos(autos, tamAutos, marcas, tamMarcas, colores, tamColores, clientes, tamClientes);
            getStrings("Ingrese patente del auto: ", "Demasiado largo, intente de nuevo: ", 10, patente);
            system("cls");
            printf("      *** Informe de importes auto ***\n\n");
            if(informe_importesXAuto(trabajos, tamTrabajos, servicios, tamServicios, patente))
            {
                printf("No hay servicios asignados al auto seleccionado\n\n");
            }
            break;
        case 'i':
            system("cls");
            servicio_mostrarTodos(servicios, tamServicios);
            idServicio=getInt("Ingrese ID del servicio: ", "Intente de nuevo: ", 20000, 29999);
            system("cls");
            printf("      *** Informe de autos y fecha de servicio ***\n\n");
            if(informe_autosXServicio(trabajos, tamTrabajos, idServicio, autos, tamAutos, marcas, tamMarcas, colores, tamColores, clientes, tamClientes, servicios, tamServicios))
            {
                printf("No hay servicios realizados del tipo elegido\n\n");
            }
            break;
        case 'j':
            system("cls");
            trabajo_mostrarTodos(trabajos, tamTrabajos, servicios, tamServicios);
            fecha=fecha_solicitar(fecha);
            system("cls");
            printf("      *** Informe de servicios por fecha ***\n\n");
            if(informe_serviciosXFecha(trabajos, tamTrabajos, servicios, tamServicios, fecha))
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

/** \brief Informa los autos del color pasado por parametro
 *
 * \param autos[] eAuto
 * \param tamAutos int
 * \param marcas[] eMarca
 * \param tamMarcas int
 * \param colores[] eColor
 * \param tamColores int
 * \param idColor int
 * \param clientes[] eCliente
 * \param tamClientes int
 * \return int
 *
 */
int informe_autosDeColor(eAuto autos[], int tamAutos, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores, int idColor, eCliente clientes[], int tamClientes)
{
    int error=1;
    int flag=0;
    if(autos != NULL && tamAutos>0 && marcas != NULL && tamMarcas>0 && colores != NULL && tamColores>0)
    {
        printf(" ID      Patente               Marca               Color     Modelo   Cliente\n\n");
        for(int i=0; i<tamAutos; i++)
        {
            if(autos[i].isEmpty != LIBRE && autos[i].idColor==idColor)
            {
                auto_mostrarUno(autos[i], marcas, tamMarcas, colores, tamColores, clientes, tamClientes);
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

/** \brief Informa los autos de la marca pasada por parametro
 *
 * \param autos[] eAuto
 * \param tamAutos int
 * \param marcas[] eMarca
 * \param tamMarcas int
 * \param colores[] eColor
 * \param tamColores int
 * \param idMarca int
 * \param clientes[] eCliente
 * \param tamClientes int
 * \return int
 *
 */
int informe_autosDeMarca(eAuto autos[], int tamAutos, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores, int idMarca, eCliente clientes[], int tamClientes)
{
    int error=1;
    int flag=0;
    if(autos != NULL && tamAutos>0 && marcas != NULL && tamMarcas>0 && colores != NULL && tamColores>0)
    {
        printf(" ID      Patente               Marca               Color     Modelo   Cliente\n\n");
        for(int i=0; i<tamAutos; i++)
        {
            if(autos[i].isEmpty != LIBRE && autos[i].idMarca==idMarca)
            {
                auto_mostrarUno(autos[i], marcas, tamMarcas, colores, tamColores, clientes, tamClientes);
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

/** \brief Informa el o los autos mas antiguos que se encuentran cargados
 *
 * \param autos[] eAuto
 * \param tamAutos int
 * \param marcas[] eMarca
 * \param tamMarcas int
 * \param colores[] eColor
 * \param tamColores int
 * \param clientes[] eCliente
 * \param tamClientes int
 * \return int
 *
 */
int informe_autoMasAntiguo(eAuto autos[], int tamAutos, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores, eCliente clientes[], int tamClientes)
{
    int error=1;
    int esPrimera=1;
    eAuto masAntiguo;
    if(autos != NULL && tamAutos>0 && marcas != NULL && tamMarcas>0 && colores != NULL && tamColores>0)
    {
        printf(" ID       PATENTE               MARCA               COLOR     MODELO     CLIENTE\n\n");
        for(int i=0; i<tamAutos; i++)
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
                auto_mostrarUno(masAntiguo, marcas, tamMarcas, colores, tamColores, clientes, tamClientes);
                masAntiguo=autos[i];
            }
        }
        auto_mostrarUno(masAntiguo, marcas, tamMarcas, colores, tamColores, clientes, tamClientes);
        printf("\n\n");
        error=0;
    }
    return error;
}

/** \brief Informa los autos separados por marca
 *
 * \param autos[] eAuto
 * \param tamAutos int
 * \param marcas[] eMarca
 * \param tamMarcas int
 * \param colores[] eColor
 * \param tamColores int
 * \param clientes[] eCliente
 * \param tamClientes int
 * \return int
 *
 */
int informe_autosXMarca(eAuto autos[], int tamAutos, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores, eCliente clientes[], int tamClientes)
{
    int error=1;
    int mostro=0;
    if(autos != NULL && tamAutos>0 && marcas != NULL && tamMarcas>0 && colores != NULL && tamColores>0)
    {
        for(int i=0; i<tamMarcas; i++)
        {
            printf("MARCA: %s\n", marcas[i].descripcion);
            for(int j=0; j<tamAutos; j++)
            {
                if(autos[j].isEmpty != LIBRE && autos[j].idMarca== marcas[i].id && mostro==0)
                {
                    informe_autosDeMarca(autos, tamAutos, marcas, tamMarcas, colores, tamColores, marcas[i].id, clientes, tamClientes);
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

/** \brief Informa la cantidad de autos de una marca y color cuyos ids son pasados por parametro
 *
 * \param autos[] eAuto
 * \param tamAutos int
 * \param marcas[] eMarca
 * \param tamMarcas int
 * \param colores[] eColor
 * \param tamColores int
 * \param idColor int
 * \param idMarca int
 * \return int
 *
 */
int informe_cantidadXColorYMarca(eAuto autos[], int tamAutos, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores, int idColor, int idMarca)
{
    int error=1;
    int cantidad=0;
    char color[20];
    char marca[20];
    if(autos != NULL && tamAutos>0 && marcas != NULL && tamMarcas>0 && colores != NULL && tamColores>0)
    {
        if(!color_cargar(colores, tamColores, idColor, color) && !marca_cargar(marcas, tamMarcas, idMarca, marca))
        {
            for(int i=0; i<tamAutos; i++)
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

/** \brief Inicializa el vector de masElegidas
 *
 * \param masElegidas[] eMasElegidas
 * \param marcas[] eMarca
 * \param tamMarcasarcas int
 * \return int
 *
 */
int informe_inicializarMasElegidas(eMasElegidas masElegidas[], eMarca marcas[], int tamMarcasarcas)
{
    int error=1;
    if(masElegidas!=NULL && marcas!=NULL && tamMarcasarcas>0)
    {
        for(int i=0; i<tamMarcasarcas; i++)
        {
            masElegidas[i].idMarca=marcas[i].id;
            masElegidas[i].cantidad=0;
        }
        error=0;
    }
    return error;
}

/** \brief Inicializa el vector de masElegidas y carga las cantidades
 *
 * \param masElegidas[] eMasElegidas
 * \param marcas[] eMarca
 * \param tamMarcasarcas int
 * \param autos[] eAuto
 * \param tamAutosutos int
 * \return int
 *
 */
int informe_cargarMasElegidas(eMasElegidas masElegidas[], eMarca marcas[], int tamMarcasarcas, eAuto autos[], int tamAutosutos)
{
    int error=1;
    if(masElegidas!=NULL && autos!=NULL && marcas!=NULL && tamAutosutos>0 && tamMarcasarcas>0)
    {
        if(!informe_inicializarMasElegidas(masElegidas, marcas, tamMarcasarcas))
        {
            for(int i=0; i<tamAutosutos; i++)
            {
                if(autos[i].isEmpty!=LIBRE)
                {
                    for(int j=0; j<tamMarcasarcas; j++)
                    {
                        if(autos[i].idMarca==masElegidas[j].idMarca)
                        {
                            masElegidas[j].cantidad++;
                        }
                    }
                }
            }
        }
        error=0;
    }
    return error;
}


/** \brief Informa las marcas de autos mas elegidas
 *
 * \param masElegidas[] eMasElegidas
 * \param marcas[] eMarca
 * \param tamMarcasarcas int
 * \param autos[] eAuto
 * \param tamAutosutos int
 * \return int
 *
 */
int informe_marcasMasElegidas(eMasElegidas masElegidas[], eMarca marcas[], int tamMarcasarcas, eAuto autos[], int tamAutosutos)
{
    int error=1, auxMayor=0;
    if(masElegidas!=NULL && marcas!=NULL && autos!=NULL && tamMarcasarcas>0 && tamAutosutos>0)
    {
        printf("Las marcas mas elegidas son: \n\n");
        for(int i=0; i<tamMarcasarcas; i++)
        {
            if(auxMayor<masElegidas[i].cantidad)
            {
                auxMayor=masElegidas[i].cantidad;
            }
        }
        for(int j=0; j<tamMarcasarcas; j++)
        {
            if(auxMayor==masElegidas[j].cantidad)
            {
                for(int k=0; k<tamMarcasarcas; k++)
                {
                    if(masElegidas[j].idMarca==marcas[k].id)
                    {
                        marca_mostrarUna(marcas[k]);
                    }
                }
            }
        }
        printf("\n\n");
        error=0;
    }
    return error;
}

/** \brief Informa los trabajos realizados al auto cuya patente se pasa por parametro
 *
 * \param trabajos[] eTrabajo
 * \param tamTrabajos int
 * \param servicios[] eServicio
 * \param tamServicios int
 * \param patente[] char
 * \return int
 *
 */
int informe_trabajosXAuto(eTrabajo trabajos[], int tamTrabajos, eServicio servicios[], int tamServicios, char patente[])
{
    int error=1;
    if(trabajos != NULL && tamTrabajos>0 && servicios != NULL && tamServicios>0)
    {
        for(int i=0; i<tamTrabajos; i++)
        {
            if(stricmp(patente, trabajos[i].patente)==0 && trabajos[i].isEmpty!=0)
            {
                trabajo_mostrarUno(trabajos[i], servicios, tamServicios);
                error=0;
            }
        }
    }
    return error;
}

/** \brief Informa el total de cargos por auto cuya patente se pasa por parametro
 *
 * \param trabajos[] eTrabajo
 * \param tamTrabajos int
 * \param servicios[] eServicio
 * \param tamServicios int
 * \param patente[] char
 * \return int
 *
 */
int informe_importesXAuto(eTrabajo trabajos[], int tamTrabajos, eServicio servicios[], int tamServicios, char patente[])
{
    int error=1;
    int total=0;
    if(trabajos != NULL && tamTrabajos>0 && servicios != NULL && tamServicios>0)
    {
        for(int i=0; i<tamTrabajos; i++)
        {
            if(stricmp(patente, trabajos[i].patente)==0 && trabajos[i].isEmpty!=0)
            {
                for(int j=0; j<tamServicios; j++)
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

/** \brief Informa los autos y las fechas en los que se realizo el servicio ingresado por parametro
 *
 * \param trabajos[] eTrabajo
 * \param tamTrabajos int
 * \param idServicio int
 * \param autos[] eAuto
 * \param tamAutos int
 * \param marcas[] eMarca
 * \param tamMarcas int
 * \param colores[] eColor
 * \param tamColores int
 * \param clientes[] eCliente
 * \param tamClientes int
 * \param servicios[] eServicio
 * \param tamServicios int
 * \return int
 *
 */
int informe_autosXServicio(eTrabajo trabajos[], int tamTrabajos, int idServicio, eAuto autos[], int tamAutos, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores, eCliente clientes[], int tamClientes, eServicio servicios[], int tamServicios)
{
    int error=1;
    char auxMarca[20];
    char auxColor[20];
    char auxCliente[20];
    char auxServicio[20];
    if(trabajos!=NULL && autos!=NULL && marcas!=NULL && colores!=NULL && clientes!=NULL && servicios!=NULL && tamTrabajos>0 && tamAutos>0 && tamMarcas>0 && tamColores>0 && tamClientes>0 && tamServicios>0)
    {
        for(int i=0; i<tamTrabajos; i++)
        {
            if(idServicio==trabajos[i].idServicio && trabajos[i].isEmpty!=LIBRE)
            {
                for(int j=0; j<tamAutos; j++)
                {
                    if(stricmp(trabajos[i].patente, autos[j].patente)==0)
                    {
                        marca_cargar(marcas, tamMarcas, autos[j].idMarca, auxMarca);
                        color_cargar(colores, tamColores, autos[j].idColor, auxColor);
                        cliente_cargar(clientes, tamClientes, autos[j].idCliente, auxCliente);
                        servicio_cargar(servicios, tamServicios, trabajos[i].idServicio, auxServicio);
                        printf("SERVICIO: %s\nPATENTE: %s\nMARCA: %s COLOR: %s MODELO: %d\nCLIENTE: %s\nFECHA: %d/%d/%d\n\n", auxServicio, autos[j].patente, auxMarca, auxColor, autos[j].modelo, auxCliente, trabajos[i].fecha.dia, trabajos[i].fecha.mes, trabajos[i].fecha.anio);
                    }
                }
                error=0;
            }
        }
    }
    return error;
}

/** \brief Informa los servicios realizados en la fecha pasada por parametro
 *
 * \param trabajos[] eTrabajo
 * \param tamTrabajos int
 * \param servicios[] eServicio
 * \param tamServicios int
 * \param fecha eFecha
 * \return int
 *
 */
int informe_serviciosXFecha(eTrabajo trabajos[], int tamTrabajos, eServicio servicios[], int tamServicios, eFecha fecha)
{
    int error=1;
    char servicio[20];
    if(trabajos != NULL && tamTrabajos>0)
    {
        printf("SERVICIO            FECHA\n\n");
        for(int i=0; i<tamTrabajos; i++)
        {
            if(fecha.dia==trabajos[i].fecha.dia && fecha.mes==trabajos[i].fecha.mes && fecha.anio==trabajos[i].fecha.anio && trabajos[i].isEmpty!=LIBRE)
            {
                servicio_cargar(servicios, tamServicios, trabajos[i].idServicio, servicio);
                printf("%s           %d/%d/%d\n", servicio, trabajos[i].fecha.dia, trabajos[i].fecha.mes, trabajos[i].fecha.anio);
                error=0;
            }
        }
    }
    return error;
}
