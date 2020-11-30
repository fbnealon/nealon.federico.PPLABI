#include "fecha.h"

/** \brief Solicita al usuario el ingreso de una fecha valida
 *
 * \param unaFecha eFecha
 * \return eFecha
 *
 */
eFecha fecha_solicitar(eFecha unaFecha)
{
    do
    {
        printf("Ingrese fecha valida (dd/mm/aaaa, no puede ser antes de 2020 ni posterior al 2022): ");
        fflush(stdin);
        scanf("%d/%d/%d", &unaFecha.dia, &unaFecha.mes, &unaFecha.anio);
    }while((unaFecha.dia<1 || unaFecha.dia>31) || (unaFecha.mes<1 || unaFecha.mes>12) || (unaFecha.anio<2020 || unaFecha.anio>2022));
    return unaFecha;
}
