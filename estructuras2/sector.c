#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sector.h"

void mostrarSectores(eSector sectores[], int tam)
{

    //system("cls");
    printf("-----Listado Sectores-----\n\n");
    printf(" ID      Descripcion\n\n");

    for(int i=0; i < tam; i++)
    {

        printf("%d   %10s\n",sectores[i].id, sectores[i].descripcion);


    }
    printf("\n");
}
