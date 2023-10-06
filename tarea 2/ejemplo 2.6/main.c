#include <stdio.h>

int main(void) {
    float SAL;
    int NIV;

    printf("Ingrese el nivel academico del profesor: ");
    scanf("%d", &NIV);

    printf("Ingrese el salario: ");
    scanf("%f", &SAL);

    switch (NIV) {
        case 1: SAL *= 1.0035; break;
        case 2: SAL *= 1.0041; break;
        case 3: SAL *= 1.0048; break;
        case 4: SAL *= 1.0053; break;
        default:
            printf("Nivel academico no valido.\n");
            return 1; // Salir del programa con un codigo de error
    }

    printf("\nNivel: %d \tNuevo salario: %8.2f\n", NIV, SAL);

    return 0;
}
