#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"

#define TAME 1000

/** \brief  Shows the Main Menu options
 * \return option int which is the option number selected
 */
int menu();

/** \brief  Shows the Reports Menu options
 * \return option int which is the option number selected
 */
int reportsMenu();

/** \brief  Handle the response of the ReportsMenu option that was selected
 * \param list Employee array of eEmployee type
 * \param len int Array length
 */
void showReports(eEmployee employees[], int len);

int main()
{
    int idEmployee = 1;
    char quit = 'n';

    eEmployee employees[TAME];
    initEmployees(employees, TAME);

    //idEmployee = idEmployee + hardcodeEmployees(employees, TAME, 4);

    do
    {
        switch(menu())
        {
        case 1:
            if(addEmployee(employees, TAME, idEmployee))
            {
                idEmployee++;
            }
            break;
        case 2:
            if(employeesIsEmpty(employees, TAME) != -1)
            {
                updateEmployee(employees, TAME);
            }
            else
            {
                printf("Sorry but currently we don't have any employees in the system.\n");
            }
            break;
        case 3:
            if(employeesIsEmpty(employees, TAME) != -1)
            {
                removeEmployee(employees, TAME);
            }
            else
            {
                printf("Sorry but currently we don't have any employees in the system.\n");
            }
            break;
        case 4:
            if(employeesIsEmpty(employees, TAME) != -1)
            {
                showReports(employees, TAME);
            }
            else
            {
                printf("Sorry but currently we don't have any employees in the system.\n");
            }
            break;
        case 5:
            if(employeesIsEmpty(employees, TAME) != -1)
            {
                printEmployees(employees, TAME);
            }
            else
            {
                printf("Sorry but currently we don't have any employees in the system.\n");
            }
            break;
        case 6:
            printf("Confirm that you like to quit? ");
            fflush(stdin);
            scanf("%c", &quit);
            break;
        default:
            printf("Invalid Option!!\n\n");
        }
        system("pause");
    }
    while(quit != 'y');

    return 0;
}

int menu()
{
    int option;

    system("cls");
    printf("*************** MENU OPTIONS ***************\n\n");
    printf("1 - New Employee\n");
    printf("2 - Update Employee\n");
    printf("3 - Remove Employee\n");
    printf("4 - Reports\n");
    printf("5 - Show List of Employees\n");
    printf("6 - Quit\n");
    printf("Choose your option: ");
    scanf("%d", &option);

    return option;
}

int reportsMenu()
{
    int option;
    system("cls");
    printf("*************** REPORTS ***************\n\n");
    printf("1 - List of Employees ordered by last name and Business Sector\n");
    printf("2 - Total Salaries, Average Salaries and how many employees earn more than the average salary\n");
    printf("3 - Quit\n");
    printf("Choose your option: ");
    scanf("%d", &option);
    return option;
}

void showReports(eEmployee employees[], int len)
{
    char quit = 'n';
    do
    {
        switch(reportsMenu())
        {
        case 1:
            sortEmployees(employees, len, 1);
            break;
        case 2:
            reportSalaries(employees, len);
            break;
        case 3:
            printf("Confirm that you like to quit? ");
            fflush(stdin);
            scanf("%c", &quit);
            break;
        default:
            printf("Invalid Option!!\n\n");
        }
        system("pause");
    }
    while(quit != 'y');
}

