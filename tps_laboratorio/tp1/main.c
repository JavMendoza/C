#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funciones_matematicas.h"

int main()
{
    float numeroA;
    float numeroB;
    float resultadoOperacion;
    float resultadoFacA;
    float resultadoFacB;

    int operandoOk;

    char opcion;
    char salir = 'n';

    printf("******* Bienvenido a mi Calculadora *******\n");

    printf("Ingrese primer operando: \n");
    fflush(stdin);
    operandoOk = scanf("%f", &numeroA);
    while(operandoOk == 0)
    {
        printf("Error, el operando debe ser un numero entero o decimal, ingrese primer operando: \n");
        fflush(stdin);
        operandoOk = scanf("%f", &numeroA);
    }

    printf("Ingrese segundo operando: \n");
    fflush(stdin);
    operandoOk = scanf("%f", &numeroB);
    while(operandoOk == 0)
    {
        printf("Error, el operando debe ser un numero entero o decimal, ingrese segundo operando: \n");
        fflush(stdin);
        operandoOk = scanf("%f", &numeroB);
    }

    do
    {
        system("cls");
        printf("************************************\n");
        printf("Numeros elegidos: \n");
        printf("A=%.2f\n", numeroA);
        printf("B=%.2f\n", numeroB);
        printf("******** MENU DE OPCIONES **********\n");
        printf("a - Suma\n");
        printf("b - Resta\n");
        printf("c - Division\n");
        printf("d - Multiplicacion\n");
        printf("e - Factorial\n");
        printf("s - Salir\n");
        printf("*************************************\n");

        printf("Indique la opcion que desee: ");
        fflush(stdin);
        scanf("%c", &opcion);
        opcion = tolower(opcion);
        switch(opcion)
        {
            case 'a':
                resultadoOperacion = suma(numeroA, numeroB);
                printf("El resultado de %.2f + %.2f es: %.2f\n", numeroA, numeroB, resultadoOperacion);
                system("pause");
                break;
            case 'b':
                resultadoOperacion = resta(numeroA, numeroB);
                printf("El resultado de %.2f - %.2f es: %.2f\n", numeroA, numeroB, resultadoOperacion);
                system("pause");
                break;
            case 'c':
                if (numeroB == 0)
                {
                    printf("No es posible dividir por %.2f\n", numeroB);
                } else
                {
                    resultadoOperacion = division(numeroA, numeroB);
                    printf("El resultado de %.2f / %.2f es: %.2f\n", numeroA, numeroB, resultadoOperacion);
                }
                system("pause");
                break;
            case 'd':
                resultadoOperacion = multiplicacion(numeroA, numeroB);
                printf("El resultado de %.2f * %.2f es: %.2f\n", numeroA, numeroB, resultadoOperacion);
                system("pause");
                break;
            case 'e':
                printf("Segun el sistema operativo, no es posible calcular el factorial de numeros decimales\n");
                printf("Por ello se calculara solo la parte entera de los numeros\n");
                resultadoFacA = factorial((int)numeroA);
                resultadoFacB = factorial((int)numeroB);
                printf("El factorial de %d es: %d y El factorial de %d es: %d\n", (int)numeroA, (int)resultadoFacA, (int)numeroB, (int)resultadoFacB);
                system("pause");
                break;
            case 's':
                printf("Confirma que desea salir? s/n\n");
                fflush(stdin);
                scanf("%c", &salir);
                while(salir != 's' && salir != 'n')
                {
                    printf("Error en la respuesta, por favor confirme que desea salir? [s/n]\n");
                    fflush(stdin);
                    scanf("%c", &salir);
                }
                break;
            default:
                printf("La opcion elegida es invalida, por favor elija una opcion del menu\n");
                system("pause");
        }
    }while(salir == 'n');

    return 0;
}
