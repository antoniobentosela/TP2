#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define LEN 2


typedef struct
{
    int id;
    char name[51];
    //char lastName[51];
    float salary;
    int sector;
    int isEmpty;

} Employee;

void printEmployee(Employee x);
void printfEmployees(Employee vec[], int len);
void initEmployees(Employee employees[], int len);
int addEmployee(Employee employees[], int len);
Employee newAlumno(int id, char name[], int sector, float salary);
int findEmptyPlace(Employee employees[], int len);
int findEmployeeById(int id, Employee employees[], int len);
int removeEmployee(Employee employees[], int len);
int modifyEmployee(Employee employees[], int len);
int menu();

int main()
{


    Employee list[LEN];
    char salir = 'n';

    initEmployees(list, LEN);

    Employee x = { 1234, "Juan", 21000, 20};
    list[0] = x;

    do
    {
        switch(menu())
        {
        case 1:
            addEmployee(list, LEN);
            break;
        case 2:
            removeEmployee(list, LEN);
            break;
        case 3:
            modifyEmployee(list, LEN);
            break;
        case 4:
            printfEmployees(list, LEN);

            break;
        case 5:

            break;
        case 6:
            printf("Confirm Exit?");
            fflush(stdin);
            salir = getch();
            // aca va el alta alumno
            break;
        default:
            printf("Invalid Option\n");
        }
        system("pause");
    }
    while(salir == 'n');

    return 0;
}

void initEmployees(Employee employees[], int len)
{

    for(int i=0; i < len; i++)
    {
        employees[i].isEmpty = 1;
    }
}

int addEmployee (Employee employees[], int len)
{

    int todoOk = 0;
    int indice;
    int esta;
    int id;
    char name[51];
    //char lastName[51];
    float salary;
    int sector;



    system("cls");
    printf("**** Add Employee ****\n\n");

    indice = findEmptyPlace(employees, len);

    if( indice == -1)
    {
        printf("Sistem Complete. Can not add more employees\n");
        system("pause");
    }
    else
    {
        printf("\nWrite id: ");
        scanf("%d", &id );

        esta = findEmployeeById(id, employees, len);

        if( esta != -1)
        {
            printf("\nId already exist\n");
            printEmployee(employees[esta]);
            system("pause");
        }
        else
        {
            printf("Write name: ");
            fflush(stdin);
            gets( name );

            printf("Write sector:");
            scanf("%d", &sector);

            printf("Write salary:");
            scanf("%f", &salary);

            employees[indice] = newAlumno(id, name, sector, salary);
            todoOk = 1;
        }
    }
    return todoOk;
}

Employee newAlumno(int id, char name[], int sector, float salary)
{
    Employee nuevoAlumno;
    nuevoAlumno.id = id;
    strcpy(nuevoAlumno.name, name);
    nuevoAlumno.sector = sector;
    nuevoAlumno.salary = salary;


    nuevoAlumno.isEmpty = 0;

    return nuevoAlumno;
}

void printEmployee(Employee x)
{
    printf("%d      %s        %d          %.2f\n",
           x.id,
           x.name,
           x.sector,
           x.salary);

}

int removeEmployee(Employee employees[], int len)
{

    int todoOk = 0;
    int indice;
    int id;
    char confirma;

    system("cls");
    printf("**** Remove Employee ****\n\n");

    printf("Write id: ");
    scanf("%d", &id);

    indice = findEmployeeById(id, employees, len);

    if( indice == -1 )
    {
        printf("\nInvalid id\n");
        system("pause");
    }
    else
    {
        printEmployee(employees[indice]);
        printf("\nConfirm elimination?: ");
        fflush(stdin);
        confirma = getche();
        if( confirma == 's')
        {
            employees[indice].isEmpty = 1;
            printf("\n\nthe elimination had success\n");
            todoOk = 1;
        }
        else
        {
            printf("\n\nThe remove been cancelled\n");
        }
        system("pause");
    }
    return todoOk;
}

void printfEmployees(Employee vec[], int len)
{
    int flag = 0;
    system("cls");
    printf("**** List Employees ****\n\n");

    printf(" id       Name      Sector        Salary\n");
    for(int i=0; i < len; i++)
    {
        if( vec[i].isEmpty == 0)
        {
            printEmployee(vec[i]);
            flag = 1;
        }
    }

    if( flag == 0)
    {
        system("cls");
        printf("\n---No Employees to show---");
    }

    printf("\n\n");
}

int findEmptyPlace(Employee employees[], int len)
{

    int indice = -1;

    for(int i=0; i < len; i++)
    {
        if( employees[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int findEmployeeById(int id, Employee employees[], int len)
{

    int indice = -1;

    for(int i=0; i < len; i++)
    {
        if( employees[i].isEmpty == 0 && employees[i].id == id)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int menu()
{

    int opcion;
    system("cls");
    printf("Option Menu\n\n");
    printf("1- Add Employee\n");
    printf("2- Remove Employee\n");
    printf("3- Modify Employee\n");
    printf("4- List Alumnos\n");
    printf("5- Ordenar Alumno\n");
    printf("6- Exit\n\n");
    printf("Write option: ");
    scanf("%d", &opcion);

    return opcion;
}

int modifyEmployee(Employee employees[], int len)
{

    int todoOk = 0;
    int indice;
    int id;
    int opcion;
    int sector;
    float salary;


    system("cls");
    printf("**** Modify Employee ****\n\n");

    printf("Write id: ");
    scanf("%d", &id);

    indice = findEmployeeById(id, employees, len);

    if( indice == -1 )
    {
        printf("\nNo tenemos registrado ese legajo\n");
        system("pause");
    }
    else
    {
        printEmployee(employees[indice]);

        printf("Modificar\n\n");
        printf("Sector 1\n");
        printf("Salary 2\n");

        printf("Ingrese opcion:");
        scanf("%d", &opcion);

        if( opcion == 1)
        {
            printf("Write sector: ");
            scanf("%d", &sector);
            employees[indice].sector = sector;
            printf("Sector actualizated");
            todoOk = 1;
        }
        else if( opcion == 2)
        {
            printf("Write salary: ");
            scanf("%f", &salary);
            employees[indice].salary = salary;
            printf("Salary actualizated");
            todoOk = 1;

        }
        else
        {
            printf("No es una opcion valida\n");
        }

        system("pause");
    }
    return todoOk;
}
