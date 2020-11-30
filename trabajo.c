#include "trabajo.h"

/** \brief Inicializa el vector de trabajos
 *
 * \param trabajos[] eTrabajo
 * \param tamTrabajos int
 * \return int
 *
 */
int trabajo_inicializar(eTrabajo trabajos[], int tamTrabajos)
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

/** \brief Busca un espacio libre en el vector de trabajos
 *
 * \param trabajos[] eTrabajo
 * \param tam int
 * \return int
 *
 */
int trabajo_buscarLibre(eTrabajo trabajos[], int tam)
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

/** \brief Da de alta un nuevo trabajo
 *
 * \param trabajos[] eTrabajo
 * \param tamTrabajos int
 * \param idTrabajos int
 * \param autos[] eAuto
 * \param tamAutos int
 * \param marcas[] eMarca
 * \param tamMarcas int
 * \param colores[] eColor
 * \param tamColores int
 * \param servicios[] eServicio
 * \param tamServicios int
 * \param clientes[] eCliente
 * \param tamCl int
 * \return int
 *
 */
int trabajo_alta(eTrabajo trabajos[], int tamTrabajos, int idTrabajos, eAuto autos[], int tamAutos, eMarca marcas[], int tamMarcas, eColor colores[], int tamColores, eServicio servicios[], int tamServicios, eCliente clientes[], int tamCl)
{
    int error=1, auxIDAuto, auxIDServicio, index;
    char confirma='s';
    eTrabajo nuevoTrabajo;

    if(trabajos != NULL && tamTrabajos>0)
    {
        index = trabajo_buscarLibre(trabajos, tamTrabajos);
        if(index== -1)
        {
            printf("Sistema completo\n\n\n");
        }
        else
        {
            system("cls");
            printf("   **** Alta trabajo ****\n\n\n");
            auto_mostrarTodos(autos, tamAutos, marcas, tamMarcas, colores, tamColores, clientes, tamCl);
            auxIDAuto = getInt("Ingrese ID del auto a trabajar: ", "ID Incorrecto, intente de nuevo: ", 3000, 4000);
            for(int i=0; i<tamAutos; i++)
            {
                if(auxIDAuto == autos[i].id && autos[i].isEmpty!=0)
                {
                    printf("Auto encontrado, patente: %s\n", autos[i].patente);
                    system("pause");
                    system("cls");
                    servicio_mostrarTodos(servicios, tamServicios);
                    auxIDServicio = getInt("Ingrese ID del servicio a realizar: ", "ID Incorrecto, intente de nuevo: ", 20000, 29999);
                    for(int j=0; j<tamServicios; j++)
                    {
                        if(servicios[j].id==auxIDServicio)
                        {
                            printf("Servicio encontrado: %s\n", servicios[j].descripcion);
                            nuevoTrabajo.id = idTrabajos;
                            strcpy(nuevoTrabajo.patente, autos[i].patente);
                            nuevoTrabajo.fecha = fecha_solicitar(nuevoTrabajo.fecha);
                            nuevoTrabajo.idServicio = servicios[j].id;
                            printf("%d/%d/%d\n", nuevoTrabajo.fecha.dia, nuevoTrabajo.fecha.mes, nuevoTrabajo.fecha.anio);
                            nuevoTrabajo.isEmpty = 1;
                            trabajo_mostrarUno(nuevoTrabajo, servicios, tamServicios);
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

/** \brief Imprime todos los trabajos
 *
 * \param trabajos[] eTrabajo
 * \param tamTrabajos int
 * \param servicios[] eServicio
 * \param tamServicios int
 * \return int
 *
 */
int trabajo_mostrarTodos(eTrabajo trabajos[], int tamTrabajos, eServicio servicios[], int tamServicios)
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
                trabajo_mostrarUno(trabajos[i], servicios, tamServicios);
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

/** \brief Imprime un trabajo
 *
 * \param unTrabajo eTrabajo
 * \param servicios[] eServicio
 * \param tamServicios int
 * \return void
 *
 */
void trabajo_mostrarUno(eTrabajo unTrabajo, eServicio servicios[], int tamServicios)
{
    char auxServicio[20];
    servicio_cargar(servicios, tamServicios, unTrabajo.idServicio, auxServicio);
    printf("%4d     %8s       %15s       %2d/%2d/%4d\n", unTrabajo.id, unTrabajo.patente, auxServicio, unTrabajo.fecha.dia, unTrabajo.fecha.mes, unTrabajo.fecha.anio);
}
