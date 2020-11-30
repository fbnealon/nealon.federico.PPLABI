#include "auto.h"

/** \brief Menu principal de ABM
 *
 * \return char
 *
 */
char menu()
{
    char opcion;
    system("cls");

    printf("-----------------ABM AUTOS-----------------\n\n");
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

/** \brief Busca un espacio libre en el vector de autos, retorna -1 si no encuentra
 *
 * \param autos[] eAuto
 * \param tam int
 * \return int
 *
 */
int auto_buscarLibre(eAuto autos[], int tam)
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

/** \brief Busca un auto por id, pasado por parametro
 *
 * \param autos[] eAuto
 * \param tamAutos int
 * \param id int
 * \return int
 *
 */
int auto_buscar(eAuto autos[], int tamAutos, int id)

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

/** \brief inicializa un vector de autos, de tamaño tam
 *
 * \param autos[] eAuto
 * \param tam int
 * \return int
 *
 */
int auto_inicializar(eAuto autos[], int tam)
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

/** \brief Imprime todos los autos de un vector
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
int auto_mostrarTodos(eAuto autos[], int tamAutos, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores, eCliente clientes[], int tamClientes)
{
    int error=1;
    int flag=0;
    if(autos != NULL && tamAutos>0)
    {
        printf(" ID       PATENTE               MARCA               COLOR     MODELO   CLIENTE\n\n");
        for(int i=0; i<tamAutos; i++)
        {
            if(autos[i].isEmpty == 1)
            {
                auto_mostrarUno(autos[i], marcas, tamMarcas, colores, tamColores, clientes, tamClientes);
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

/** \brief Imprime un auto
 *
 * \param unAuto eAuto
 * \param marcas[] eMarca
 * \param tamMarcas int
 * \param colores[] eColor
 * \param tamColores int
 * \param clientes[] eCliente
 * \param tamClientes int
 * \return void
 *
 */
void auto_mostrarUno(eAuto unAuto, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores, eCliente clientes[], int tamClientes)
{
    char marca[20];
    char color[20];
    char cliente[20];
    marca_cargar(marcas, tamMarcas, unAuto.idMarca, marca);
    color_cargar(colores, tamColores, unAuto.idColor, color);
    cliente_cargar(clientes, tamClientes, unAuto.idCliente, cliente);
    printf("%4d     %7s     %15s     %15s     %4d     %s\n", unAuto.id, unAuto.patente, marca, color, unAuto.modelo, cliente);
}

/** \brief Da de alta un auto en el vector, o devuelve un mensaje de error si esta completo
 *
 * \param autos[] eAuto
 * \param tamAutos int
 * \param idAuto int
 * \param marcas[] eMarca
 * \param tamMarcas int
 * \param colores[] eColor
 * \param tamColores int
 * \param clientes[] eCliente
 * \param tamClientes int
 * \return int
 *
 */
int auto_alta(eAuto autos[], int tamAutos, int idAuto, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores, eCliente clientes[], int tamClientes)
{
    int error=1, index;
    eAuto nuevoAuto;
    char auxMarca[20];
    char auxColor[20];
    char auxCliente[20];
    int idMarca;
    int idColor;
    int idCliente;
    char confirma;
    int fEncontro=1;

    if(autos != NULL && tamAutos>0 && idAuto>0)
    {
        system("cls");
        printf("   **** Alta auto ****\n\n\n");
        index = auto_buscarLibre(autos, tamAutos);
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
                getStrings("Ingrese patente (AAA000 o AA0000AA): ", "Demasiado largo, intente de nuevo (AAA000 o AA0000AA): ", 8, nuevoAuto.patente);
            }
            while (strlen(nuevoAuto.patente)<6 || strlen(nuevoAuto.patente)>8);
            do
            {
                system("cls");
                printf("PATENTE: %s\n\n", nuevoAuto.patente);
                marca_mostrarTodas(marcas, tamMarcas);
                idMarca= getInt("Ingrese el ID de la marca: ", "Valor invalido, intente de nuevo: ", 1000, 1999);
                for(int i=0; i<tamMarcas; i++)
                {
                    if(marcas[i].id==idMarca)
                    {
                        nuevoAuto.idMarca= marcas[i].id;
                        fEncontro=0;
                        marca_cargar(marcas, tamMarcas, marcas[i].id, auxMarca);
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
                color_mostrarTodos(colores, tamColores);
                idColor= getInt("Ingrese el ID del color: ", "Valor invalido, intente de nuevo: ", 5000, 5999);
                for(int i=0; i<tamColores; i++)
                {
                    if(colores[i].id==idColor)
                    {
                        nuevoAuto.idColor= colores[i].id;
                        fEncontro=0;
                        color_cargar(colores, tamColores, colores[i].id, auxColor);
                        break;
                    }
                }
            }
            while(fEncontro==1);

            system("cls");
            printf("PATENTE: %s\nMARCA: %s\nCOLOR: %s\n\n", nuevoAuto.patente, auxMarca, auxColor);
            nuevoAuto.modelo = getInt("Ingrese el modelo del auto (de 1900 a 2020): ", "Anio invalido, intente de nuevo: ", 1900, 2020);
            system("cls");

            do
            {
                system("cls");
                printf("PATENTE: %s\nMARCA: %s\nCOLOR: %s\nMODELO: %d\n\n", nuevoAuto.patente, auxMarca, auxColor, nuevoAuto.modelo);
                cliente_mostrarTodos(clientes, tamClientes);
                idCliente= getInt("Ingrese el ID del cliente: ", "Valor invalido, intente de nuevo: ", 6000, 6999);
                for(int i=0; i<tamClientes; i++)
                {
                    if(clientes[i].id==idCliente && clientes[i].isEmpty==1)
                    {
                        nuevoAuto.idCliente= clientes[i].id;
                        fEncontro=0;
                        cliente_cargar(clientes, tamClientes, clientes[i].id, auxCliente);
                        break;
                    }
                }
            }
            while(fEncontro==1);
            system("cls");
            printf("PATENTE: %s\nMARCA: %s\nCOLOR: %s\nMODELO: %d\nCLIENTE: %s\n\n", nuevoAuto.patente, auxMarca, auxColor, nuevoAuto.modelo, auxCliente);
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

/** \brief Da de baja un auto del vector de autos
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
int auto_baja(eAuto autos[], int tamAutos, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores, eCliente clientes[], int tamClientes)
{
    int error=1;
    int index;
    int id;
    char confirma;

    if(autos != NULL && tamAutos>0)
    {
        system("cls");
        printf("   **** Baja de auto ****\n\n\n");
        auto_mostrarTodos(autos, tamAutos, marcas, tamMarcas, colores, tamColores, clientes, tamClientes);
        id = getInt("Ingrese ID del auto a eliminar: ", "ID invalido, intente de nuevo: ", 3000, 4000);

        index= auto_buscar(autos, tamAutos, id);

        if(index == -1)
        {
            printf("No hay ningun auto con ese id\n\n");
        }
        else
        {
            auto_mostrarUno(autos[index], marcas, tamMarcas, colores, tamColores, clientes, tamClientes);
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

/** \brief Entra al menu de modificaciones si logra encontrar el auto con el id ingresado
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
int auto_modificar(eAuto autos[], int tamAutos, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores, eCliente clientes[], int tamClientes)
{
    int error=1, auxIDAuto;
    char confirma;

    if(autos != NULL && tamAutos>0 && marcas != NULL && tamMarcas>0 && colores != NULL && tamColores>0)
    {
        system("cls");
        printf("***            **** Modificar auto ****            ***\n\n\n");
        auto_mostrarTodos(autos, tamAutos, marcas, tamMarcas, colores, tamColores, clientes, tamClientes);
        auxIDAuto= getInt("Ingrese ID de auto a modificar: ", "ID invalido, intente de nuevo: ", 3000, 3999);
        for(int i=0; i<tamAutos; i++)
        {
            if(autos[i].id==auxIDAuto && autos[i].isEmpty!=LIBRE)
            {
                printf("\n");
                auto_mostrarUno(autos[i], marcas, tamMarcas, colores, tamColores, clientes, tamClientes);
                printf("\n");
                confirma = getLetter("Confirma modificacion? ", "Caracter invalido, intente de nuevo: ");
                if(confirma == 's')
                {
                    autos[i] = auto_modificaciones(autos[i], marcas, tamMarcas, colores, tamColores, clientes, tamClientes);
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

/** \brief Menu de modificaciones, permite modificar un auto y guardar o no los cambios
 *
 * \param unAuto eAuto
 * \param marcas[] eMarca
 * \param tamMarcas int
 * \param colores[] eColor
 * \param tamColores int
 * \param clientes[] eCliente
 * \param tamClientes int
 * \return eAuto
 *
 */
eAuto auto_modificaciones(eAuto unAuto, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores, eCliente clientes[], int tamClientes)
{
    eAuto auxAuto= unAuto;
    char opcion;
    char confirma='n';
    int auxIDColor;
    int auxModelo;

    if(marcas != NULL && tamMarcas>0 && colores != NULL && tamColores>0)
    {
        do
        {
            system("cls");
            printf("          ***   Modificaciones de auto   ***\n\n\n");
            auto_mostrarUno(unAuto, marcas, tamMarcas, colores, tamColores, clientes, tamClientes);
            printf("\n");
            printf("a Modificar color\n");
            printf("b Modificar Modelo\n");
            printf("c Salir\n");
            opcion = getLetter("Ingrese opcion: ", "Caracter invalido, intente de nuevo: ");
            switch(opcion)
            {
            case 'a':
                if(!color_mostrarTodos(colores, tamColores))
                {
                    auxIDColor= getInt("Ingrese ID de nuevo color: ", "Color invalido, intente de nuevo: ", 5000, 5999);
                    for(int i=0; i<tamColores; i++)
                    {
                        if(colores[i].id==auxIDColor)
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

/** \brief Ordena los autos por marca y patente
 *
 * \param autos[] eAuto
 * \param tamAutos int
 * \param marcas[] eMarca
 * \param tamMarcas int
 * \param colores[] eColor
 * \param tamColores int
 * \return int
 *
 */
int auto_ordenarXMarcaYPatente(eAuto autos[], int tamAutos, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores)
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
                marca_cargar(marcas, tamMarcas, autos[i].idMarca, descripcionI);
                for(int j=i+1; j<tamAutos; j++)
                {
                    if(autos[j].isEmpty != LIBRE)
                    {
                        marca_cargar(marcas, tamMarcas, autos[j].idMarca, descripcionJ);
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

/** \brief Devuelve 1 si hay algun auto cargado en el vector de autos
 *
 * \param autos[] eAuto
 * \param tamAutos int
 * \return int
 *
 */
int auto_hayCargado(eAuto autos[], int tamAutos)
{
    int ok=0;

    for(int i=0; i<tamAutos; i++)
    {
        if(autos[i].isEmpty!=LIBRE)
        {
            ok=1;
            break;
        }
    }
    return ok;
}
