#include <stdio.h>

/* Factorial.
El programa calcula el factorial de un numero entero.
FAC, I, NUM: variables de tipo entero. */

int main(void)
{
    int I, NUM;
    long FAC;// Variable para almacenar el resultado del factorial.
    printf("\nIngrese el numero: ");
    scanf("%d", &NUM);
    if (NUM >= 0)// Comprobar si el número no es negativo.
    {
        FAC = 1;
        for (I=1; I <= NUM; I++)
            FAC *= I;// multiplicar el factorial por el valor actual de I.
        printf("\nEl factorial de %d es: %ld", NUM, FAC);
    }
    else
        printf("\nError en el dato ingresado");

    return 0;
}
