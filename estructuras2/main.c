#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"
#include "sector.h"
#include "informes.h"
#include "almuerzo.h"

#define TAM 10
#define TAMSEC 5
#define TAMAL 50
#define TAMCOM 5


int menu();


//void altaAlmuerzo(int idAlmuerzo, eAlmuerzo almuerzos[], int tamAl, eEmpleado vec[], int tam, eSector sectores[], int tamSec, eComida comidas[], int tamCom);
//void inicializarAlmuerzos(eAlmuerzo almuerzos[], int tamal);
//int buscarLibreAlmuerzo(eAlmuerzo almuerzos[], int tamal);

int main()
{
    char seguir = 's';
    char confirma;
    int proximoId = 1000;
    eEmpleado lista[TAM];
    eSector sectores[TAMSEC] = {{1, "Sistemas"}, {2, "RRHH"},{3, "Ventas"},{4, "Compras"},{5, "Contable"}};
    //eAlmuerzo almuerzos[TAMAL];
    //eComida comidas[TAMCOM] = {{100, "Milanesa", 150}, {102, "Fideos", 120}, {103, "Pizza", 140}, {104, "Ensalada", 200},{105, "Arroz", 135}}

    inicializarEmpleados(lista, TAM);
    //inicializarAlmuerzos(almuerzos, TAMAL);

    harcodearEmpleados(lista, 7);
    proximoId += 7;

    do
    {

        switch(menu())
        {

        case 1:
            if(altaEmpleado(proximoId, lista, TAM, sectores, TAMSEC))
            {

                proximoId ++;

            };
            break;
        case 2:
            modificarEmpleado(lista, TAM, sectores, TAMSEC);
            break;
        case 3:
            bajaEmpleado(lista, TAM, sectores, TAMSEC);
            break;
        case 4:
            printf("Ordenar\n");
            break;
        case 5:
            mostrarEmpleados(lista, TAM, sectores, TAMSEC);
            break;
        case 6:
            informar(lista, TAM, sectores, TAMSEC);
            break;
        case 7:
            printf("Alta almuerzo");
            break;
        case 8:
            printf("Confirma salida?:\n");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma == 's')
            {

                seguir = 'n';

            }
            break;
        }

        system("pause");

    }
    while(seguir == 's');

    return 0;
}

int menu()
{

    int opcion;

    system("cls");
    printf("Menu de Opciones\n\n");
    printf("1- Alta\n");
    printf("2- Modificar\n");
    printf("3- Baja\n");
    printf("4- Ordenar\n");
    printf("5- Listar\n");
    printf("6- Informes\n");
    printf("7- Alta almuerzo\n");
    printf("8- Salir\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;

}




/*void informarSueldosSector(eEmpleado vec[], int tam, eSector sectores[], int tamSec)
{

    int flag = 0;
    system("cls");

    for(int i=0; i < tamSec; i++)
    {
        flag = 0;
        printf("\nSector %s\n\n", sectores[i].descripcion);

        for(int j = 0; j < tam; j++)
        {

            if(vec[j].isEmpty == 0 && sectores[i].id == vec[j].idSector)
            {


                printf("%.2f\n", vec[i].sueldo);
                flag = 1;

            }


        }


    }

}
*/


/*


void inicializarAlmuerzos(eAlmuerzo almuerzos[], int tamal)
{

    for(int i=0; i < tamal; i++)
    {

        almuerzos[i].isEmpty = 1;

    }
}


int buscarLibreAlmuerzo(eAlmuerzo almuerzos[], int tamal)
{

    int indice = -1; //va -1, porque -1 no puede ser un indice de un vector, al inicializar, indice no puede ser un indice valido del vector.

    for(int i=0; i < tamal; i++)
    {

        if(almuerzos[i].isEmpty == 1)
        {

            indice = i;
            break;
        }

    }

    return indice;
}

void altaAlmuerzo(int idAlmuerzo, eAlmuerzo almuerzos[], int tamAl, eEmpleado vec[], int tam, eSector sectores[], int tamSec, eComida comidas[], int tamCom)
{

    int todoOk = 0;
    int indice;

    //int id;
    eAlmuerzo auxAlmuerzo;

    system("cls");

    printf("------Alta Almuerzo------\n\n");

    indice = buscarLibreAlmuerzo(almuerzos, tamal);

    if(indice == -1)
    {

        printf("El sistema se encuentra completo\n\n");
        system("pause");

    }
    else
    {

        printf("Ingrese id: ");
        scanf("%d", &id);

        esta = buscarEmpleado(id, vec, tam);

        if(esta != -1)
        {

            printf("Ya existe ese empleado\n");
            mostrarEmpleado(vec[esta]);
            system("pause");

        }
    else
    {

        auxAlmuerzo.id = proximoId;

        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(auxEmpleado.nombre);

        printf("Ingrese sexo: ");
        fflush(stdin);
        scanf("%c", &auxEmpleado.sexo);

        printf("Ingrese edad: ");
        scanf("%d", &auxEmpleado.edad);

        printf("Ingrese sueldo: ");
        scanf("%f", &auxEmpleado.sueldo);

        printf("Ingrese fechas de ingreso dd/mm/aaaa: ");
        scanf("%d/%d/%d", &auxEmpleado.fechaIngreso.dia, &auxEmpleado.fechaIngreso.mes,&auxEmpleado.fechaIngreso.anio);

        mostrarSectores(sectores, tamSec);

        printf("Ingrese id del sector: ");
        scanf("%d", &auxEmpleado.idSector);

        auxEmpleado.isEmpty = 0;

        vec[indice] = auxEmpleado;
        todoOk = 1;

    }

    //}

    return todoOk;



}
*/
