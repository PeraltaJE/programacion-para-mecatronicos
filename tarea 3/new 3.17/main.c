#include <stdio.h>

/* Numeros perfectos.
El programa, al recibir como dato un número entero positivo como limite, obtiene
los numeros perfectos que hay entre 1 y ese número,
y además imprime cuantos numeros perfectos hay en el intervalo.
I, J, NUM, SUM, C: variables de tipo entero. */

int main(void)
{
    int I, J, NUM, SUM, C = 0;//variables
    printf("\nIngrese el numero limite: ");
    scanf("%d", &NUM);
    for (I = 1; I <= NUM; I++)// Ciclo para verificar números perfectos en el rango.
    {
        SUM = 0;
        for (J = 1; J <= (I / 2); J++)// Ciclo para encontrar los divisores de I.
            if ((I % J) == 0)// Comprobar si J es divisor de I.
                SUM += J;// Sumar el divisor J a SUM.
        if (SUM == I)// Comprobar si SUM es igual a I, lo que indica un número perfecto.
        {
            printf("\n%d es un numero perfecto", I);
            C++;
        }
    }
    printf("\nEntre 1 y %d hay %d numeros perfectos", NUM, C);

    return 0;
}
