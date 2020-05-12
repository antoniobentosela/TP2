#include "sector.h"

#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;

} eFechaIngreso;

typedef struct
{
    int id;
    char nombre[20];
    char sexo;
    int edad;
    float sueldo;
    int isEmpty;
    eFechaIngreso fechaIngreso;
    int idSector;

} eEmpleado;

#endif // EMPLEADO_H_INCLUDED

void inicializarEmpleados(eEmpleado vec[], int tam);
void mostrarEmpleados(eEmpleado vec[], int tam, eSector sectores[], int tamSec);
void mostrarEmpleado(eEmpleado x, eSector sectores[], int tamSec);
void ordenarEmpleados(eEmpleado x[], int tam, eSector sectores[], int tamSec);
int altaEmpleado(int proximoId, eEmpleado vec[], int tam, eSector sectores[], int tamSec);
void bajaEmpleado(eEmpleado vec[], int tam, eSector sectores[], int tamSec);
void modificarEmpleado(eEmpleado vec[], int tam, eSector sectores[], int tamSec);
int buscarEmpleado(int id, eEmpleado vec[], int tam);
int buscarLibre(eEmpleado vec[], int tam);
void harcodearEmpleados(eEmpleado vec[], int cant);
int cargarDescripcionSector(char descripcion[], int id, eSector sectore[], int tam);

