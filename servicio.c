#include "servicio.h"

/** \brief Carga en una cadena pasada por parametro la descripcion del servicio que coincide con el id pasado por parametro
 *
 * \param marcas[] eMarca
 * \param tamMarcas int
 * \param id int
 * \param descripcion[] char
 * \return int
 *
 */
int servicio_cargar(eServicio servicios[], int tamServicios, int id, char descripcion[])
{
    int error=1;
    if(servicios != NULL && tamServicios>0 && id>0)
    {
        for(int i=0; i<tamServicios; i++)
        {
            if(servicios[i].id == id)
            {
                strcpy(descripcion, servicios[i].descripcion);
            }
        }
        error=0;
    }
    return error;
}

/** \brief Imprime todos los servicios
 *
 * \param servicios[] eServicio
 * \param tamServicios int
 * \return int
 *
 */
int servicio_mostrarTodos(eServicio servicios[], int tamServicios)
{
    int error=1;
    int flag=0;
    if(servicios != NULL && tamServicios>0)
    {
        printf("ID                     SERVICIO      PRECIO\n\n");
        for(int i=0; i<tamServicios; i++)
        {
            servicio_mostrarUno(servicios[i]);
            flag=1;
        }
        printf("\n\n");
        if (flag==0)
        {
            printf("    No hay marcas cargadas en la lista\n\n");
        }
        error=0;
    }
    return error;
}

/** \brief Imprime un servicio
 *
 * \param unServicio eServicio
 * \return void
 *
 */
void servicio_mostrarUno(eServicio unServicio)
{
    printf("%4d     %20s          %d\n", unServicio.id, unServicio.descripcion, unServicio.precio);
}
