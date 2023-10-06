#include <stdio.h>

/* Suma pagos.
El programa obtiene la suma de los pagos realizados el último mes.
PAG y SPA: variables de tipo real.*/

int main(void)
{
    float PAG, SPA = 0;//acumulador SPA igualado a 0
    printf ("Ingrese el primer pago:\t");
    scanf("%f", &PAG);
/* Observa que al utilizar la estructura do-while al menos se necesita un pago.*/
    do
    {
        SPA = SPA + PAG;// se suman los pagos al acumulador
        printf("Ingrese el siguinte pago -0 para terminar-\t ");
        scanf("%f", &PAG);
    }
    while (PAG);
    printf("\nEl total de pagos de este mes es: %.2f", SPA);
    return 0;
}
