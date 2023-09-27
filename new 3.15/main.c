#include <stdio.h>
#include <math.h>

/* Cálculo de P.
El programa obtiene el valor de P aplicando una serie determinada.
I, B, C: variables de tipo entero.
RES: variable de tipo real de doble precisión. */

int main(void)
{
    int I = 1, B = 0, C;
    double RES;//variable para almacenar el resultado
    RES = 4.0 / I;// Inicialización del resultado como 4.0 dividido por I.
    C = 1;
    while ((fabs (3.1415 - RES)) > 0.0005)// Bucle que se ejecuta hasta que se alcance la precisión requerida.
    {
        I += 2 ;// Incrementar I en 2 unidades.
        if (B)// Comprobar si B es verdadero .
        {
            RES += (double) (4.0 / I);// Sumar al resultado el término correspondiente.
            B = 0;// Cambiar el valor de B a falso.
        }
        else
        {
            RES -= (double) (4.0 / I);// Restar al resultado el término correspondiente.
            B = 1;//cambiar el valor de B a verdadero.
        }
        C++;//incrementar e contador.
    }
    printf("\nNumero de terminos:%d", C);

    return 0;
}
