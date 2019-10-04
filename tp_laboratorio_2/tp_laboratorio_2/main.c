#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAME 12
// luego cambiar el tame por 1000

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} eEmpleado;

void inicializarEmpleados(eEmpleado empleados[], int tam);
int hardcodearEmpleados(eEmpleado empleados[], int tam, int cantidad);
int menu();
int menuInformes();

int main()
{
    int idEmpleado = 0;
    char salir = 'n';

    eEmpleado listaEmpleados[TAME];
    inicializarEmpleados(listaEmpleados, TAME);

    idEmpleado = idEmpleado + hardcodearEmpleados(listaEmpleados, TAME, 2);

    do
    {
        switch(menu())
        {
        case 1:
            printf("Eligio alta empleado");
            break;
        case 2:
            printf("Eligio modificar empleado");
            break;
        case 3:
            printf("Eligio baja empleado");
            break;
        case 4:
            printf("Eligio informar empleado");
            break;
        case 5:
            printf("Eligio mostrar empleados");
            break;
        case 6:
            printf("Confirma que desea salir? ");
            fflush(stdin);
            scanf("%c", &salir);
            break;
        default:
            printf("Eligio una opcion invalida\n\n");
        }
        //system("pause");
    }
    while(salir != 's');

    return 0;
}

void inicializarEmpleados(eEmpleado empleados[], int tam)
{
    for (int i=0; i< tam; i++)
    {
        empleados[i].isEmpty = 0;
    }
}

int hardcodearEmpleados(eEmpleado empleados[], int tam, int cantidad)
{
    int cont = 0;
    eEmpleado suplentes[] =
    {
        {1, "Javier", "Mendoza", 40000.30, 1, 0},
        {2, "Juan", "Tretto", 30000.21, 1, 0},
        {3, "Aloy", "Siberia", 3500.39, 1, 0},
        {4, "Julian", "Castellano", 60000.30923, 1, 0},
        {5, "Ignacio", "Macri", 80150.30, 1, 0},
        {6, "Valeria", "Solanas", 93531.30, 1, 0},
        {7, "Florencia", "Esteche", 120000.80, 1, 0},
        {8, "Jose", "Fernandez", 900000.24, 1, 0},
        {9, "Carolina", "Magoya", 100000.863, 1, 0},
        {10, "Gustavo", "Macaya", 24000.451, 1, 0},
    };

    if (cantidad <= 10 && tam >= cantidad)
    {
        for (int i=0; i< cantidad; i++)
        {
            empleados[i] = suplentes[i];
            cont++;
        }
    }
    return cont;
}

int menu()
{
    int opcion;

    //system("cls");
    printf("*************** MENU DE OPCIONES ***************\n\n");
    printf("1 - Alta Empleado\n");
    printf("2 - Modificar Empleado\n");
    printf("3 - Baja Empleado\n");
    printf("4 - Informar\n");
    printf("5 - Mostrar Empleados\n");
    printf("6 - Salir\n");
    printf("Elija la opcion deseada: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

int menuInformes()
{
    int opcion;
    //system("cls");
    printf("*************** INFORMES ***************\n\n");
    printf("1 - Listado de empleados ordenados alfabeticamente por Apellido y Sector\n");
    printf("2 - Total y Promedio de los salarios y cuantos empleados superan el salario promedio\n");
    printf("3 - Salir\n");
    printf("Elija la opcion deseada: ");
    scanf("%d", &opcion);
    return opcion;
}

void mostrarInformes(eEmpleado empleados[], int tam)
{
    char salir = 'n';
    do
    {
        switch(menuInformes())
        {
        case 1:
            printf("Listado de empleados ordenados alfabeticamente por Apellido y Sector");
            break;
        case 2:
            printf("Total y Promedio de los salarios y cuantos empleados superan el salario promedio");
            break;
        case 3:
            printf("Confirma que desea salir? ");
            fflush(stdin);
            scanf("%c", &salir);
            break;
        default:
            printf("Eligio una opcion invalida\n\n");
        }
        //system("pause");
    }
    while(salir != 's');
}
