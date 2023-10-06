#include <stdio.h>
#include <math.h>

/* Serie de ULAM.
El programa, al recibir como dato un entero positivo, obtiene y escribe
la serie de ULAM.
NUM: variable de tipo entero. */

int main(void)
{
    int NUM;
    printf("Ingresa el numero para calcular la serie: ");
    scanf("%d", &NUM);
    if (NUM > 0)
    {
        printf("\nSerie de ULAM\n");
        printf("%d \t", NUM);
        while (NUM != 1)// Bucle que se ejecuta hasta que NUM sea igual a 1.
        {
            if (pow(-1, NUM) > 0)// Comprobar si NUM es par.
                NUM = NUM / 2;// Dividir NUM por 2 si es par.
            else
                NUM = NUM * 3 + 1;// Multiplicar NUM por 3 y sumar 1 si es impar.
            printf("%d \t", NUM);// Imprimir el valor actual de NUM en la serie.
        }
    }
    else
        printf("\n NUM debe ser un entero positivo");


    return 0;
}
