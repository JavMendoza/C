#include "ArrayEmployees.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initEmployees(eEmployee listE[], int len)
{
    for (int i=0; i< len; i++)
    {
        listE[i].isEmpty = 1;
    }
}

int employeesIsEmpty(eEmployee listE[], int len)
{
    int index = -1;
    for (int i=0; i< len; i++)
    {
        if(listE[i].isEmpty == 0) {
            index = i;
            break;
        }
    }
    return index;
}

int hardcodeEmployees(eEmployee listE[], int len, int qty)
{
    int counter = 0;
    eEmployee substitutes[] =
    {
        {1, "Javier", "Mendoza", 4000.30, 10, 0},
        {2, "Juan", "Tretto", 3000.21, 8, 0},
        {3, "Aloy", "Biseria", 3500.39, 10, 0},
        {4, "Julian", "Castellano", 600.30923, 4, 0},
        {5, "Ignacio", "Dacri", 8150.30, 4, 0},
        {6, "Valeria", "Golanas", 9531.30, 4, 0},
        {7, "Florencia", "Esteche", 1200.80, 8, 0},
        {8, "Jose", "Fernandez", 9000.24, 8, 0},
        {9, "Carolina", "Hagoya", 1000.863, 10, 0},
        {10, "Gustavo", "Jacaya", 200.451, 8, 0},
    };

    if (qty <= 10 && len >= qty)
    {
        for (int i=0; i< qty; i++)
        {
            listE[i] = substitutes[i];
            counter++;
        }
    }
    return counter;
}

int searchFreeSpot(eEmployee listE[], int len)
{
    int index = -1;

    for(int i=0; i < len; i++)
    {
        if( listE[i].isEmpty == 1 )
        {
            index = i;
            break;
        }
    }
    return index;
}

int addEmployee(eEmployee listE[], int len, int idEmployee)
{
    int ok = 0;
    int index;
    char name[51];
    char lastname[51];
    float salary;
    int sector;

    system("cls");

    printf("*****New Employee*****\n\n");

    index = searchFreeSpot(listE, len);

    if( index == -1)
    {
        printf("\nSystem Completed\n\n");
    }
    else
    {
        printf("Name: ");
        fflush(stdin);
        gets(name);

        printf("Last name: ");
        fflush(stdin);
        gets(lastname);

        printf("Salary: ");
        scanf("%f", &salary);

        printf("Sector: ");
        scanf("%d", &sector);

        listE[index] = newEmployee(idEmployee, name, lastname, salary, sector);
        ok = 1;
        printf("Employee Added Successfully!!\n\n");
    }

    return ok;
}

eEmployee newEmployee(int idEmployee,char name[],char lastname[], float salary, int sector)
{

    eEmployee em;
    em.id = idEmployee;
    strcpy( em.name, name);
    strcpy( em.lastName, lastname);
    em.salary = salary;
    em.sector = sector;
    em.isEmpty = 0;

    return em;
}

int findEmployeeById(int idEmployee, eEmployee listE[], int len)
{
    int index = -1;

    for(int i=0; i < len; i++)
    {
        if( listE[i].id == idEmployee && listE[i].isEmpty == 0)
        {
            index = i;
            break;
        }
    }
    return index;
}

int removeEmployee(eEmployee listE[], int len)
{
    int ok = 0;
    int idEmployee;
    int index;
    char confirm;

    system("cls");
    printf("***** Remove Employee *****\n\n");
    printEmployees(listE, len);
    printf("Write the id number of the Employee: ");
    scanf("%d", &idEmployee);

    index = findEmployeeById(idEmployee, listE, len);

    if( index == -1)
    {
        printf("The employee does not exist!\n\n");

    }
    else
    {
        printEmployee(listE[index]);

        printf("\nConfirm that you want to delete this Employee?");
        fflush(stdin);
        scanf("%c", &confirm);

        if( confirm == 'y')
        {
            listE[index].isEmpty = 1;
            ok = 1;
            printf("Employee Deleted Successfully!!!");
        }
        else
        {
            printf("The delete process has been cancelled");
        }
    }

    return ok;
}

int updateEmployee(eEmployee listE[], int len)
{

    int ok = 0;
    int idEmployee;
    int index;
    int option;

    char name[51];
    char lastName[51];

    system("cls");
    printf("***** Update Employee *****\n\n");
    printEmployees(listE, len);
    printf("Enter Id of Employee: ");
    scanf("%d", &idEmployee);

    index = findEmployeeById(idEmployee, listE, len);

    if( index == -1)
    {
        printf("The Employee does not exist, the ID number is wrong\n\n");

    }
    else
    {

        printEmployee(listE[index]);

        printf("1- Update Name\n");
        printf("2- Update Last Name\n");
        printf("3- Update Salary\n");
        printf("4- Update Sector\n");
        printf("5- Quit\n\n");
        printf("Choose your Option: ");
        scanf("%d", &option);

        switch(option)
        {
        case 1:
            printf("Choose your new name: ");
            fflush(stdin);
            scanf("%s", name);
            strcpy(listE[index].name, name);
            break;

        case 2:
            printf("Choose your new last name: ");
            fflush(stdin);
            scanf("%s", lastName);
            strcpy(listE[index].lastName, lastName);
            break;

        case 3:
            printf("Choose your new salary: ");
            scanf("%f", &listE[index].salary);
            break;

        case 4:
            printf("Choose your new sector: ");
            scanf("%d", &listE[index].sector);
            break;

        case 5:
            printf("The update was cancelled\n");
            break;

        }
    }
    return ok;
}

void printEmployee(eEmployee x)
{
    printf("  %1d  %10s   %10s      %10.2f      %d\n",
           x.id,
           x.name,
           x.lastName,
           x.salary,
           x.sector);
}

void printEmployees(eEmployee listE[], int len)
{

    int flag = 0;
    system("cls");

    printf(" id      Name      Last Name         Salary    Sector\n\n");

    for(int i=0; i < len; i++)
    {
        if( listE[i].isEmpty == 0)
        {
            printEmployee(listE[i]);
            flag = 1;
        }
    }

    if( flag == 0)
    {
        printf("\nThere is no Employees to show\n");
    }

    printf("\n\n");
}

void sortEmployees(eEmployee listE[], int len, int order)
{
    eEmployee auxEmployee;
    eEmployee listAuxE[len];
    int swap = 0;

    for (int i=0; i< len; i++)
    {
        listAuxE[i] = listE[i];
    }

    for(int i= 0; i < len-1 ; i++)
    {
        for(int j= i+1; j <len; j++)
        {

            if (listAuxE[i].sector > listAuxE[j].sector && order){
                swap = 1;
            } else if (listAuxE[i].sector < listAuxE[j].sector && !order){
                swap = 1;
            } else if(listAuxE[i].sector == listAuxE[j].sector && stricmp(listAuxE[i].lastName, listAuxE[j].lastName) > 0 && order)
            {
                swap = 1;
            } else if(listAuxE[i].sector == listAuxE[j].sector && stricmp(listAuxE[i].lastName, listAuxE[j].lastName) == -1 && !order) {
                swap = 1;
            }

            if (swap) {
                auxEmployee = listAuxE[i];
                listAuxE[i] = listAuxE[j];
                listAuxE[j] = auxEmployee;
            }

            swap = 0;
        }
    }


    printEmployees(listAuxE, len);
    printf("Employees Sorted!\n\n");
}

void reportSalaries(eEmployee listE[], int len){
    float totalSalary = 0;
    int totalRealEmployees = 0;
    float avgSalary;
    int employeeSalaryMoreAvg = 0;

    for(int i=0; i<len; i++){
        if(listE[i].isEmpty == 0){
            totalSalary += listE[i].salary;
            totalRealEmployees++;
        }
    }

    avgSalary = (float) totalSalary / totalRealEmployees;
    printf("Total Salary of all Employees: %.2f\n", totalSalary);
    printf("Average Salary of all Employees: %.2f\n", avgSalary);

    for(int i=0; i<len; i++){
        if(listE[i].isEmpty == 0 && listE[i].salary > avgSalary){
            employeeSalaryMoreAvg++;
        }
    }
    printf("Employees that earn more than the Average salary: %d\n", employeeSalaryMoreAvg);

}

