#include <stdio.h>
#include <math.h>

int main(void) {
    int OP, T;
    float RES;

    printf("Ingrese la opcion del calculo y el valor entero: ");
    scanf("%d %d", &OP, &T);

    switch (OP) {
        case 1:
            RES = T / 5.0;
            break;
        case 2:
            RES = pow(T, 2);
            break;
        case 3:
            RES = 6 * T / 3;
            break;
        case 4:
            RES = 6 * T / 2;
            break;
        default:
            RES = 1;
            break;
    }

    printf("Resultado: %7.2f\n", RES);

    return 0;
}
