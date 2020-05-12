#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED



#endif // INFORMES_H_INCLUDED

void informar(eEmpleado vec[], int tam, eSector sectores[], int tamSec);
int menuInformes();
void informarAlumnosXAnio(eEmpleado vec[], int tam, eSector sectores[], int tamSec);
void informarAlumnosVarones(eEmpleado vec[], int tam, eSector sectores[], int tamSec);
void informarTotalSueldos(eEmpleado vec[], int tam);
void informarEmpleadosSector(eEmpleado vec[], int tam, eSector sectores[], int tamSec);
void informarEmpleadosXSector(eEmpleado vec[], int tam, eSector sectores[], int tamSec);
void informarSueldosSector(eEmpleado vec[], int tam, eSector sectores[], int tamSec);
void informarMayorSueldoSector(eEmpleado vec[], int tam, eSector sectores[], int tamSec);
void informarMayorSueldoEmpleadoSector(eEmpleado vec[], int tam, eSector sectores[], int tamSec);
void aumentarSueldosSectorPorcentaje(eEmpleado vec[], int tam, eSector sectores[], int tamSec);

float obtenerTotalSueldosSector(int idSector, eEmpleado vec[], int tam, eSector sectores[], int tamSec);
void sectorQueMasCobra(eEmpleado vec[], int tam, eSector sectores[], int tamSec);
