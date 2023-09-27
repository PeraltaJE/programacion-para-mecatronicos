#include <stdio.h>

/* Suma positivos.
El programa, al recibir como datos N números enteros, obtiene la suma de los
enteros positivos.
I, N, NUM, SUM: variables de tipo entero. */

int main(void)
{

    int I, N, NUM, SUM; //variables de control y acumulador
    SUM = 0; //acumulador igual a 0
    printf("Ingrese el numero de datos:\t");
    scanf("%d", &N); //cantidad de datos
    for (I=1; I<=N; I++) //bucle para sumar numeros positivos hasta que llegue a la cantidad de datos
{



    printf("\nIngrese el dato numero %d:\t", I);
    scanf("%d", &NUM);//leemos datos ingresados por el usuario
    if (NUM > 0)
        SUM = SUM + NUM; //sumamos los numeros positivos
}
    printf("\nLa suma de los numeros positivos es: %d", SUM);

    return 0;
}
