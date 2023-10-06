#include <stdio.h>

/* Conflicto de variables con el mismo nombre.
nota: cuando uso :: me da error asique deicidi poner otro nombre*/

void f1(void); // Prototipo de funcion.
int Q = 5; // Variable global.
void main (void)
{
    int I;
    for (I = 1; I <= 3; I++)
        f1();
}
void f1(void)
// La funcion utiliza tanto la variable local I como la variable global I.
{
    int K = 2; // Variable local.
    K += K;
    printf("\n\nEl valor de la variable local es: %d", K);
    Q = Q + K; // Uso de ambas variables.
    printf("\nEl valor de la variable global es: %d", Q);
}
