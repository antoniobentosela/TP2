#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hardcodeo.h"
#include "empleado.h"

void inicializarEmpleados(eEmpleado vec[], int tam)
{

    for(int i=0; i < tam; i++)
    {

        vec[i].isEmpty = 1;

    }
}

void mostrarEmpleado(eEmpleado x, eSector sectores[], int tamSec)
{

    char nombreSector[20];
    cargarDescripcionSector(nombreSector, x.idSector, sectores, tamSec);

    printf("%d   %10s     %c     %d    %.2f     %02d/%02d/%4d  %10s\n", x.id, x.nombre, x.sexo, x.edad, x.sueldo, x.fechaIngreso.dia, x.fechaIngreso.mes, x.fechaIngreso.anio, nombreSector);


}

void mostrarEmpleados(eEmpleado vec[], int tam, eSector sectores[], int tamSec)
{

    int flag = 0;

    //system("cls");
    printf("-----Listado de Empleados-----\n\n");
    printf(" ID         Nombre  Sexo   Edad    Sueldo    Fecha de Ingreso  Sector\n\n");

    for(int i=0; i < tam; i++)
    {

        if(vec[i].isEmpty == 0)
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

int buscarLibre(eEmpleado vec[], int tam)
{

    int indice = -1; //va -1, porque -1 no puede ser un indice de un vector, al inicializar, indice no puede ser un indice valido del vector.

    for(int i=0; i < tam; i++)
    {

        if(vec[i].isEmpty == 1)
        {

            indice = i;
            break;
        }

    }

    return indice;
}

int buscarEmpleado(int id, eEmpleado vec[], int tam)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {

        if(vec[i].isEmpty == 0 && vec[i].id == id)
        {

            indice = i;
            break;
        }

    }

    return indice;
}

int altaEmpleado(int proximoId, eEmpleado vec[], int tam, eSector sectores[], int tamSec)
{

    int todoOk = 0;
    int indice;

    //int id;
    eEmpleado auxEmpleado;

    system("cls");

    printf("------Alta Empleado------\n\n");

    indice = buscarLibre(vec, tam);

    if(indice == -1)
    {

        printf("El sistema se encuentra completo\n\n");
        system("pause");

    }
    /*else
    {

        printf("Ingrese id: ");
        scanf("%d", &id);

        esta = buscarEmpleado(id, vec, tam);

        if(esta != -1)
        {

            printf("Ya existe ese empleado\n");
            mostrarEmpleado(vec[esta]);
            system("pause");

        }*/
    else
    {

        auxEmpleado.id = proximoId;

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

void bajaEmpleado(eEmpleado vec[], int tam, eSector sectores[], int tamSec)
{

    int indice;
    int id;
    char confirma;

    system("cls");

    printf("------Baja Empleado------\n\n");

    printf("Ingrese id: ");
    scanf("%d", &id);

    indice = buscarEmpleado(id, vec, tam);

    if(indice == -1)
    {
        printf("No existe ese id\n\n");
        system("pause");


    }
    else
    {

        mostrarEmpleado(vec[indice], sectores, tamSec);

        printf("Confirma la eliminacion? ");
        fflush(stdin);
        scanf("%c", &confirma);

        if(confirma == 's')
        {

            vec[indice].isEmpty = 1;
            printf("Se ha realizado la baja\n\n");

        }
        else
        {

            printf("Se cancelo la eliminacion\n\n");

        }
    }
}

void modificarEmpleado(eEmpleado vec[], int tam, eSector sectores[], int tamSec)
{

    int indice;
    int id;
    int edad;
    char sexo;
    float sueldo;
    int opcion;

    system("cls");

    printf("------Modificar Empleado------\n\n");

    printf("Ingrese id: ");
    scanf("%d", &id);

    indice = buscarEmpleado(id, vec, tam);

    if(indice == -1)
    {
        printf("No existe ese id\n\n");
        system("pause");


    }
    else
    {

        mostrarEmpleado(vec[indice], sectores, tamSec);

        printf("1.Edad\n");
        printf("2.Sexo\n");
        printf("3.Sueldo\n");

        printf("Que dato quiere modificar? ");
        scanf("%d", &opcion);

        if(opcion == 1)
        {

            printf("Ingrese edad: ");
            scanf("%d", &edad);
            vec[indice].edad = edad;
            printf("Se ha realizado la modiicacion\n\n");

        }
        if(opcion == 2)
        {

            printf("Ingrese sexo: ");
            scanf("%c", &sexo);
            vec[indice].sexo = sexo;
            printf("Se ha realizado la modificacion\n\n");


        }
        if(opcion == 3)
        {

            printf("Ingrese sueldp: ");
            scanf("%f", &sueldo);
            vec[indice].sueldo = sueldo;
            printf("Se ha realizado la modificacion\n\n");


        }
        else
        {

            printf("no es una opcion valida");


        }
    }
}

void ordenarEmpleados(eEmpleado x[], int tam, eSector sectores[], int tamSec)
{

    eEmpleado aux;

    for(int i = 0; i < tam - 1; i++)
    {

        for(int j = i + 1; j < tam; j++)
        {

            if(x[i].sexo > x[i].sexo)
            {

                aux = x[j];
                x[j] = x[i];
                x[i] = aux;

            }

            else if(x[i].sexo == x[i].sexo && strcmp(x[i].nombre, x[j].nombre) > 0)
            {

                aux = x[j];
                x[j] = x[i];
                x[i] = aux;

            }

        }

    }

}

void harcodearEmpleados(eEmpleado vec[], int cant)
{

    for(int i=0; i < cant; i++)
    {

        vec[i].id = ids[i];
        strcpy(vec[i].nombre, nombres[i]);
        vec[i].sexo = sexos[i];
        vec[i].edad = edades[i];
        vec[i].sueldo = sueldos[i];
        vec[i].fechaIngreso.dia = dias[i];
        vec[i].fechaIngreso.mes = meses[i];
        vec[i].fechaIngreso.anio = anios[i];
        vec[i].idSector = idsSector[i];
        vec[i].isEmpty = 0;

    }
}

int cargarDescripcionSector(char descripcion[], int id, eSector sectores[], int tam)
{

    int todoOk = 0;

    for(int i=0; i < tam; i++)
    {

        if(sectores[i].id == id)
        {

            strcpy(descripcion, sectores[i].descripcion);
            todoOk = 1;
        }

    }

    return todoOk;
}

