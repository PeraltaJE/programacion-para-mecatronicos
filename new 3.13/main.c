#include <stdio.h>

/* Fibonacci.
El programa calcula y escribe los primeros 50 números de Fibonacci.
I, PRI, SEG, SIG: variables de tipo entero. */

int main(void)
{
    int I, PRI = 0, SEG = 1, SIG;
    printf("\t %d \t %d", PRI, SEG); // Imprimir los dos primeros numeros de Fibonacci.
    for (I = 3; I <= 50; I++)// Bucle para calcular y mostrar los siguientes numeros.
    {
        SIG = PRI + SEG; // Calcular el siguiente número de Fibonacci.
        PRI = SEG;// Actualizar el valor de PRI con el valor de SEG.
        SEG = SIG;// Actualizar el valor de SEG con el valor de SIG.
        printf("\t %d", SIG);
    }

    return 0;
}
