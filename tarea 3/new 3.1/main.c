#include <stdio.h>

/* Nómina.
El programa, al recibir los salarios de 15 profesores, obtiene el total de la
nómina de la universidad.

I: variable de tipo entero.
SAL y NOM: variables de tipo real. */

int main(void)
{
    int I; //variable para el bucle
    float SAL, NOM; // Sal guarda el salario y NOM la nomina
    NOM = 0; // el total inicial de la nomina es cero
    for (I=1; I<=15; I++) //bucle para ingresar y sumar salarios hasta el salario quince

    {
        printf ("\Ingrese el salario del profesor%d:", I); //solicitamos salarios
        scanf ("%f", &SAL); // leemos salarios ingresados
        NOM = NOM + SAL; //sumamos el salario total con la nomina
    }
    printf("\nEl total de la nomina es: %.2f", NOM); //mostramos resultado final de nomina
    return 0;
}
