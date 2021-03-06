#include "marca.h"



/** \brief Carga en una cadena pasada por parametro la descripcion de la marca que coincide con el id pasado por parametro
 *
 * \param marcas[] eMarca
 * \param tamMarcas int
 * \param id int
 * \param descripcion[] char
 * \return int
 *
 */
int marca_cargar(eMarca marcas[], int tamMarcas, int id, char descripcion[])
{
    int error=1;
    if(marcas != NULL && tamMarcas>0 && id>0)
    {
        for(int i=0; i<tamMarcas; i++)
        {
            if(marcas[i].id == id)
            {
                strcpy(descripcion, marcas[i].descripcion);
                error=0;
            }
        }
    }
    return error;
}

/** \brief Imprime todas las marcas
 *
 * \param marcas[] eMarca
 * \param tamMarcas int
 * \return int
 *
 */
int marca_mostrarTodas(eMarca marcas[], int tamMarcas)
{
    int error=1;
    int flag=0;
    if(marcas != NULL && tamMarcas>0)
    {
        printf("ID                     NOMBRE\n\n");
        for(int i=0; i<tamMarcas; i++)
        {
            marca_mostrarUna(marcas[i]);
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

/** \brief Imprime una marca
 *
 * \param unaMarca eMarca
 * \return void
 *
 */
void marca_mostrarUna(eMarca unaMarca)
{
    printf("%4d     %20s\n", unaMarca.id, unaMarca.descripcion);
}
