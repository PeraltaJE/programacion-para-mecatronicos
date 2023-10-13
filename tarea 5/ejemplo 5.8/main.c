#include <stdio.h>

const int TAM = 100;

int main(void)
{
    int P[TAM]; // Arreglo para almacenar los n�meros primos
    P[0] = 2; // El primer n�mero primo es 2
    int contador = 1; // Contador de n�meros primos encontrados
    int candidato = 3; // Empezamos con el siguiente n�mero impar

    while (contador < TAM)
    {
        int es_primo = 1; // Suponemos que es primo hasta que se demuestre lo contrario
        for (int i = 0; i < contador; i++)
        {
            if (candidato % P[i] == 0)
            {
                es_primo = 0; // No es primo
                break;
            }
        }

        if (es_primo)
        {
            P[contador] = candidato;
            contador++;
        }

        candidato += 2; // Pasamos al siguiente n�mero impar
    }

    // Ahora P[] contiene los primeros 100 n�meros primos
    for (int i = 0; i < TAM; i++)
    {
        printf("Primos[%d]: %d\n", i, P[i]);
    }

    return 0;
}
