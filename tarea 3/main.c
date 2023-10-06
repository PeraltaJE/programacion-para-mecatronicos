#include <stdio.h>

int main() {
    char nombre[100]; // Variable para almacenar el nombre del estudiante
    float PRO;        // Variable para almacenar el promedio del estudiante

    // Solicitar al usuario ingresar el nombre del estudiante
    printf("Ingrese el nombre del estudiante: ");
    scanf("%s", nombre);

    // Solicitar al usuario ingresar el promedio del estudiante
    printf("Ingrese el promedio del estudiante %s: ", nombre);
    scanf("%f", &PRO);

    // Verificar si el promedio es mayor o igual a 6
    if (PRO >= 6.0) {
        printf("Aprobado\n");
    } else {
        printf("Reprobado\n");
    }

    return 0;
}
