#include "color.h"


/** \brief Carga en una cadena pasada por parametro el nombre de color que coincide con el id pasado por parametro
 *
 * \param marcas[] eMarca
 * \param tamMarcas int
 * \param id int
 * \param descripcion[] char
 * \return int
 *
 */
int color_cargar(eColor colores[], int tamColores, int id, char descripcion[])
{
    int error=1;
    if(colores != NULL && tamColores>0 && id>0)
    {
        for(int i=0; i<tamColores; i++)
        {
            if(colores[i].id == id)
            {
                strcpy(descripcion, colores[i].nombreColor);
                error=0;
            }
        }
    }
    return error;
}

/** \brief Imprime todos los colores
 *
 * \param colores[] eColor
 * \param tamColores int
 * \return int
 *
 */
int color_mostrarTodos(eColor colores[], int tamColores)
{
    int error=1;
    int flag=0;
    if(colores != NULL && tamColores>0)
    {
        printf("ID                      COLOR\n\n");
        for(int i=0; i<tamColores; i++)
        {
            color_mostrarUno(colores[i]);
            flag=1;
        }
        printf("\n\n");
        if (flag==0)
        {
            printf("    No hay colores cargados en la lista\n\n");
        }
        error=0;
    }
    return error;
}

/** \brief Imprime un color
 *
 * \param unColor eColor
 * \return void
 *
 */
void color_mostrarUno(eColor unColor)
{
    printf("%4d     %20s\n", unColor.id, unColor.nombreColor);
}
