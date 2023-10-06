#include <stdio.h>

/* Serie.
El programa imprime los términos y obtiene la suma de una determinada serie.
I, SSE y CAM: variable de tipo entero. */

int main(void)
{
    int I = 2, CAM = 1;
    long SSE = 0; // Variable para almacenar la suma de los términos.
    while (I <= 2500)// Bucle que se ejecuta mientras I sea menor o igual a 2500.
    {
        SSE = SSE + I;// Sumar el valor actual de I a la suma total.
        printf("\t %d", I); // Imprimir el término actual de la serie.
        if (CAM)// Comprobar si CAM es verdadero (1).
        {
            I += 5;// Incrementar I en 5 unidades.
            CAM--;// Cambiar el valor de CAM a falso (0).
        }
        else
        {
            I += 3; // Incrementar I en 3 unidades.
            CAM++;// Cambiar el valor de CAM a verdadero (1).
        }
    }
    printf("\nLa suma de la serie es: %ld", SSE);

    return 0;
}
