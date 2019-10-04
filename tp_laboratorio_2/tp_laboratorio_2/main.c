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

int buscarLibre(eEmpleado vec[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( vec[i].isEmpty == 1 )
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int altaEmpleado(eEmpleado vec[], int tam, int leg)
{
    int todoOk = 0;
    int indice;
    char nombre[20];
    char sexo;
    int edad;
    int n1;
    int n2;
    int idCarrera;
    eFecha fecha;

    //system("cls");

    printf("*****Alta Empleado*****\n\n");

    indice = buscarLibre(vec, tam);

    if( indice == -1)
    {
        printf("\nSistema completo\n\n");
    }
    else
    {
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(nombre);

        printf("Ingrese edad: ");
        scanf("%d", &edad);

        printf("Ingrese sexo: ");
        fflush(stdin);
        scanf("%c", &sexo);

        printf("Ingrese nota 1: ");
        scanf("%d", &n1);

        printf("Ingrese nota 2: ");
        scanf("%d", &n2);

        printf("Ingrese fecha ingreso: ");
        scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);

        mostrarCarreras(carreras, tamC);
        printf("Ingrese id carrera: ");
        scanf("%d", &idCarrera);

        vec[indice] = newAlumno(leg, nombre, edad, sexo, n1, n2, fecha, idCarrera);
        todoOk = 1;
        printf("Alta exitosa!!\n\n");
    }

    return todoOk;
}

eAlumno newAlumno(
    int leg,
    char nombre[],
    int edad,
    char sexo,
    int nota1,
    int nota2,
    eFecha fecha,
    int idCarrera
)
{

    eAlumno al;
    al.legajo = leg;
    strcpy( al.nombre, nombre);
    al.sexo = sexo;
    al.edad = edad;
    al.nota1 = nota1;
    al.nota2 = nota2;
    al.promedio = (float) (nota1 + nota2 )/2;
    al.fechaIngreso = fecha;
    al.idCarrera = idCarrera;
    al.isEmpty = 0;

    return al;
}

int bajaAlumno(eAlumno vec[], int tam, eCarrera carreras[], int tamC)
{
    int todoOk = 0;
    int legajo;
    int indice;
    char confirma;
    system("cls");
    printf("***** Baja Alumno *****\n\n");
    printf("Ingrese legajo: ");
    scanf("%d", &legajo);

    indice = buscarAlumno(legajo, vec, tam);

    if( indice == -1)
    {
        printf("No existe un alumno con ese legajo\n\n");

    }
    else
    {
        mostrarAlumno(vec[indice], carreras, tamC);

        printf("\nConfirma baja?");
        fflush(stdin);
        scanf("%c", &confirma);

        if( confirma == 's')
        {
            vec[indice].isEmpty = 1;
            todoOk = 1;
            printf("Baja exitosa!!!");
        }
        else
        {
            printf("Se ha cancelado la operacion");
        }
    }

    return todoOk;
}

int ModificarAlumno(eAlumno vec[], int tam, eCarrera carreras[], int tamC)
{

    int todoOk = 0;
    int legajo;
    int indice;
    system("cls");
    printf("***** Modificar Alumno *****\n\n");
    printf("Ingrese legajo: ");
    scanf("%d", &legajo);
    int opcion;

    indice = buscarAlumno(legajo, vec, tam);

    if( indice == -1)
    {
        printf("No existe un alumno con ese legajo\n\n");

    }
    else
    {

        mostrarAlumno(vec[indice], carreras, tamC);

        printf("1- Modificar nota1\n");
        printf("2- Modificar nota2\n");
        printf("3- Salir\n\n");
        printf("Ingrese opcion: ");
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1:
            printf("Ingrese nueva nota: ");
            scanf("%d", &vec[indice].nota1);
            vec[indice].promedio = (float) (vec[indice].nota1  + vec[indice].nota2)/2;
            break;

        case 2:
            printf("Ingrese nueva nota: ");
            scanf("%d", &vec[indice].nota2);
            vec[indice].promedio = (float) (vec[indice].nota1  + vec[indice].nota2)/2;
            break;
        case 3:
            printf("Se ha cancelado la mofdificacion ");
            break;

        }
    }
    return todoOk;
}
