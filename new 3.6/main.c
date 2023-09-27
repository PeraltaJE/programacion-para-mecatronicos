#include <stdio.h>

/* Nomina de profesores.
El programa, al recibir como datos los salarios de los profesores de una
universidad, obtiene la nomina y el promedio de los salarios.
I: variable de tipo entero.
SAL, NOM y PRO: variables de tipo real. */

int main(void)
{
    int I = 0;//acumulador
    float SAL, PRO, NOM = 0;//variables de programa, salario y nomina
    printf("Ingrese el salario del profesor:\t");
    /* Observa que al menos se necesita ingresar el salario de un profesor para que
    no ocurra un error de ejecucion del programa. */
    scanf("%f", &SAL);
    do
{
     NOM = NOM + SAL;//nomina es igual a nomina + salario
     I = I + 1;//incrementa el aculumador en cada repeticion
     printf("Ingrese el salario del profesor -0 para terminar- :\t");
     scanf("%f", &SAL);
}
    while (SAL);
     PRO = NOM / I;// el promedio es la nomina entre el acumulador
     printf("\nNomina: %.2f \t Promedio de salarios: %.2f", NOM, PRO);

    return 0;
}
