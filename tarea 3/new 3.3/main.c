#include <stdio.h>

/* Suma pagos.
El programa, al recibir como datos un conjunto de pagos realizados en el último
mes, obtiene la suma de los mismos.
PAG y SPA: variables de tipo real. */

int main(void)
{
    float PAG, SPA; //PAG guarda los pagos y SPA es la aculumacion de los pagos
    SPA = 0; //acumulador comienza en cero
    printf("\nIngrese el primer pago:\t");
    scanf("%f", &PAG);
    while (PAG)
/* Observa que la condición es verdadera mientras el pago es diferente de cero. */
    {
     SPA = SPA + PAG;
     printf("Ingrese el siguiente pago:\t ");
     scanf("%f", &PAG);
/* Observa que la proposición que modifica la condición es una lectura. */

    }
    printf("\nEl total de pagos del mes es: %.2f", SPA);
    return 0;
}
