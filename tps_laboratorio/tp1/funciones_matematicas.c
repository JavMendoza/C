#include <stdio.h>
#include <stdlib.h>

/** \brief suma 2 numeros decimales y retorna el resultado
 *
 * \param primer numero decimal
 * \param segundo numero decimal
 * \return la suma de los numeros pasados por parametro
 *
 */
float suma(float numA, float numB)
{
    float resultado;
    resultado = numA + numB;
    return resultado;
}

/** \brief resta 2 numeros decimales y retorna el resultado
 *
 * \param primer numero decimal
 * \param segundo numero decimal
 * \return la resta de los numeros pasados por parametro
 *
 */
float resta(float numA, float numB)
{
    float resultado;
    resultado = numA - numB;
    return resultado;
}

/** \brief multiplica 2 numeros decimales y retorna el resultado
 *
 * \param primer numero decimal
 * \param segundo numero decimal
 * \return la multiplicacion de los numeros pasados por parametro
 *
 */
float multiplicacion(float numA, float numB)
{
    float resultado;
    resultado = numA * numB;
    return resultado;
}

/** \brief divide 2 numeros decimales y retorna el resultado
 *
 * \param primer numero decimal
 * \param segundo numero decimal
 * \return la division de los numeros pasados por parametro
 *
 */
float division(float numA, float numB)
{
    float resultado;
    resultado = numA / numB;
    return resultado;
}

/** \brief recibe un numero y retorna el calculo de su factorial
 *
 * \param numero al cual se averiguara su factorial
 * \return el numero factorial del numero pasado por parametro a la funcion
 *
 */
int factorial(int num)
{
    int numRetorno;

    if (num == 1 || num == 0)
    {
        return num;
    }
    numRetorno = num * factorial(num-1);
    return numRetorno;
}
