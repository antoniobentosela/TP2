#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"
#include "sector.h"
#include "informes.h"


void informar(eEmpleado vec[], int tam, eSector sectores[], int tamSec)
{

    char seguir = 's';
    char confirma;

    do
    {
        switch(menuInformes())
        {

        case 'a':
            informarAlumnosXAnio(vec, tam, sectores, tamSec);
            break;
        case 'b':
            informarAlumnosVarones(vec, tam, sectores, tamSec);
            break;
        case 'c':
            informarTotalSueldos(vec, tam);
            break;
        case 'd':
            informarEmpleadosSector(vec, tam, sectores, tamSec);
            break;
        case 'e':
            informarEmpleadosXSector(vec, tam, sectores, tamSec);
            break;
        case 'f':
            informarMayorSueldoSector(vec, tam, sectores, tamSec);
            break;
        case 'g':
            informarMayorSueldoEmpleadoSector(vec, tam, sectores, tamSec);
            break;
        case 'h':
            //informarSueldosSector(vec, tam, sectores, tamSec);
            break;
        case 'i':
            aumentarSueldosSectorPorcentaje(vec, tam, sectores, tamSec);
            break;
        case 'j':
            sectorQueMasCobra(vec, tam, sectores, tamSec);
            break;
        case 'k':

            break;
        case 'l':
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

}

int menuInformes()
{

    char opcion;

    system("cls");
    printf("Menu de Opciones\n\n");
    printf("a- Informar Empleados por Anio\n");
    printf("b- Informar Empleados Varones\n");
    printf("c- Informar total sueldos\n");
    printf("d- Informar Empleados de un Sector\n");
    printf("e- Informar Empleados por Sector\n");
    printf("f- Informar Mayor Sueldo de un Sector\n");
    printf("g- Informar Mayor Sueldo de cada Sector\n");
    printf("h- Informar Sueldos Sector\n");
    printf("i- Informe Aumentar sueldos\n");
    printf("j- Sector que mas cobra\n");
    printf("k- Informar k\n");
    printf("l- Salir\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%c", &opcion);

    return opcion;

}

void informarAlumnosXAnio(eEmpleado vec[], int tam, eSector sectores[], int tamSec)
{

    int flag = 0;
    int anio;

    system("cls");
    printf("-----Listado de Empleados por Anio-----\n\n");

    printf("Ingrese Anio: ");
    scanf("%d", &anio);

    printf(" ID         Nombre  Sexo   Edad    Sueldo    Fecha de Ingreso   Sector\n\n");

    for(int i=0; i < tam; i++)
    {

        if(vec[i].isEmpty == 0 && vec[i].fechaIngreso.anio == anio)
        {

            mostrarEmpleado(vec[i], sectores, tamSec);
            flag = 1;

        }
    }

    if(flag == 0)
    {

        printf("No hay empleados que listar\n");

    }
}

void informarAlumnosVarones(eEmpleado vec[], int tam, eSector sectores[], int tamSec)
{

    int flag = 0;

    system("cls");
    printf("-----Listado de Empleados Varones-----\n\n");

    printf(" ID         Nombre  Sexo   Edad    Sueldo    Fecha de Ingreso  Sector\n\n");

    for(int i=0; i < tam; i++)
    {

        if(vec[i].isEmpty == 0 && vec[i].sexo == 'm')
        {

            mostrarEmpleado(vec[i], sectores, tamSec);
            flag = 1;

        }
    }

    if(flag == 0)
    {

        printf("No hay empleados que listar\n");

    }


}

void informarTotalSueldos(eEmpleado vec[], int tam)
{

    float total = 0;

    for(int i=0; i < tam; i++)
    {

        if(vec[i].isEmpty == 0)
        {

            total += vec[i].sueldo;

        }

    }

    printf("Total a pagar: %.2f\n\n", total);

}

void informarEmpleadosSector(eEmpleado vec[], int tam, eSector sectores[], int tamSec)
{

    int flag = 0;
    int idSector;

    system("cls");
    printf("-----Listado de Empleados por Sector-----\n\n");

    mostrarSectores(sectores, tamSec);

    printf("Ingrese id sector: ");
    scanf("%d", &idSector);

    printf(" ID         Nombre  Sexo   Edad    Sueldo    Fecha de Ingreso   Sector\n\n");

    for(int i=0; i < tam; i++)
    {

        if(vec[i].isEmpty == 0 && vec[i].idSector == idSector)
        {

            mostrarEmpleado(vec[i], sectores, tamSec);
            flag = 1;

        }
    }

    if(flag == 0)
    {

        printf("No hay empleados en este sector\n");

    }

}

void informarEmpleadosXSector(eEmpleado vec[], int tam, eSector sectores[], int tamSec)
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
                mostrarEmpleado(vec[j], sectores, tamSec);
                flag = 1;
            }

        }
        if(flag == 0)
        {

            printf("No hay empleados en este sector\n");

        }

    }
}

void informarMayorSueldoSector(eEmpleado vec[], int tam, eSector sectores[], int tamSec)
{


    int flag = 0;
    int idSector;
    float mayorSueldo;
    char nombreSector[20];

    system("cls");
    printf("-----Sueldo mayor de un  Sector-----\n\n");

    mostrarSectores(sectores, tamSec);

    printf("Ingrese id sector: ");
    scanf("%d", &idSector);


    for(int i=0; i < tam; i++)
    {

        if(vec[i].isEmpty == 0 && vec[i].idSector == idSector)
        {

            if(vec[i].sueldo > mayorSueldo || flag == 0)
            {

                mayorSueldo = vec[i].sueldo;
                flag = 1;
            }
        }
    }

    cargarDescripcionSector(nombreSector, idSector, sectores, tamSec);

    printf("El mayor Sueldo del sector %s es $%.2f\n", nombreSector, mayorSueldo);

}

void informarMayorSueldoEmpleadoSector(eEmpleado vec[], int tam, eSector sectores[], int tamSec)
{

    int flag = 0;
    float mayorSueldo = 0;

    system("cls");

    for(int i=0; i < tamSec; i++)
    {
        flag = 0;
        mayorSueldo = 0;

        printf("\nSector %s\n\n", sectores[i].descripcion);

        for(int j = 0; j < tam; j++)
        {

            if(vec[j].isEmpty == 0 && sectores[i].id == vec[j].idSector)
            {
                if(vec[j].sueldo > mayorSueldo || flag == 0)
                {

                    mayorSueldo = vec[i].sueldo;
                    flag = 1;

                }
            }

        }

        printf("El mayor sueldo es %.2f", mayorSueldo);

    }

}

void aumentarSueldosSectorPorcentaje(eEmpleado vec[], int tam, eSector sectores[], int tamSec)
{

    int flag = 0;
    int idSector;
    int porcentaje;
    float aumento;

    system("cls");
    printf("-----Sueldo mayor de un  Sector-----\n\n");

    mostrarSectores(sectores, tamSec);

    printf("Ingrese id sector: ");
    scanf("%d", &idSector);

    printf("Ingrese porcentaje: ");
    scanf("%d", &porcentaje);

    for(int i=0; i < tam; i++)
    {

        if(vec[i].isEmpty == 0 && vec[i].idSector == idSector)
        {

            aumento = vec[i].sueldo * porcentaje / 100;
            vec[i].sueldo = vec[i].sueldo + aumento;
            flag = 1;


        }
    }


    if(flag == 1)
    {

        printf("Se han modificado los sueldos con exito");

    }
    else
    {

        printf("No hay empleados a quienes aumentar");

    }
}

float obtenerTotalSueldosSector(int idSector, eEmpleado vec[], int tam, eSector sectores[], int tamSec)
{

    float totalSueldos = 0;

    for(int i = 0; i < tam; i++)
    {

        if(vec[i].isEmpty == 0 && vec[i].idSector == idSector)
        {

            totalSueldos += vec[i].sueldo;

        }

    }

    return totalSueldos;

}

void sectorQueMasCobra(eEmpleado vec[], int tam, eSector sectores[], int tamSec)
{

    float totalSueldos[tamSec];
    float mayorTotal = 0;
    int flag = 0;

    system("cls");

    printf("Sector que mas Cobra\n\n");

    for(int s=0; s < tamSec; s++)
    {
        totalSueldos[s] = obtenerTotalSueldosSector(sectores[s].id, vec, tam, sectores, tamSec);

    }


    for(int s = 0; s < tamSec; s++)
    {

        if(totalSueldos[s] > mayorTotal || flag == 0)
        {

            mayorTotal = totalSueldos[s];
            flag = 1;


        }
    }

    printf("\nEl total de sueldos mayor es $%.2f\n", mayorTotal);
    printf("Sector:");

    for(int s = 0; s < tamSec; s++)
    {

        if(totalSueldos[s] == mayorTotal)
        {

            printf("%s\n",sectores[s].descripcion);

        }
    }
}
