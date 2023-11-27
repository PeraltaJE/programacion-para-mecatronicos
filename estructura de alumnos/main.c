#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct alumno
{
    int matricula;
    char nombre[20];
    char carrera[20];
    float promedio;
    char direccion[50];
};

struct alumno *Maloc(int cantidad)
{
    return (struct alumno *)malloc(cantidad * sizeof(struct alumno));
}

int main(void)
{
    int cantidad_alumnos = 0;
    struct alumno *alumnos = NULL;

    // Asignar memoria para un número máximo de alumnos
    alumnos = Maloc(100);

    if (alumnos == NULL)
    {
        fprintf(stderr, "Error: No se pudo asignar memoria.\n");
        return 1; // Código de error
    }

    char respuesta; // Variable para almacenar la respuesta del usuario

    // Bucle para ingresar datos de los alumnos
    do
    {
        // Inicializar los datos del alumno actual
        printf("\nDatos del alumno %d\n", cantidad_alumnos + 1);
        printf("Matricula: ");
        scanf("%d", &alumnos[cantidad_alumnos].matricula);
        printf("Nombre: ");
        scanf("%s", alumnos[cantidad_alumnos].nombre);
        printf("Carrera: ");
        scanf("%s", alumnos[cantidad_alumnos].carrera);
        printf("Promedio: ");
        scanf("%f", &alumnos[cantidad_alumnos].promedio);
        printf("Direccion: ");
        scanf("%s", alumnos[cantidad_alumnos].direccion);

        // Incrementar la cantidad de alumnos
        cantidad_alumnos++;

        // Preguntar si se desea ingresar otro alumno
        printf("\n¿Deseas ingresar otro alumno? (y/n): ");
        scanf(" %c", &respuesta);

    }
    while (respuesta == 'y');   // Continuar mientras la respuesta sea 'y'

    // Imprimir los datos de los alumnos
    for (int i = 0; i < cantidad_alumnos; i++)
    {
        printf("\nDatos del alumno %d\n", i + 1);
        printf("Matricula: %d\n", alumnos[i].matricula);
        printf("Nombre: %s\n", alumnos[i].nombre);
        printf("Carrera: %s\n", alumnos[i].carrera);
        printf("Promedio: %.2f\n", alumnos[i].promedio);
        printf("Direccion: %s\n", alumnos[i].direccion);
    }

    // Liberar la memoria asignada dinamicamente
    free(alumnos);

    return 0;
}
