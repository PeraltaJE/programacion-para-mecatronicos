#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

int main() {
    FILE *archivo = NULL;
    char jugada[20];
    int opcion;

    do {
        printf("Menu:\n");
        printf("1. jugar\n");
        printf("2. tirar\n");
        printf("3. imprimir historial de tiradas\n");
        printf("4. Cerrar la loteria y salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        if (opcion == 1) {
            if (archivo != NULL) {
                fclose(archivo);
                archivo = NULL;
            }
            printf("Opcion no disponible\n");
        } else if (opcion == 2) {
            // Generar tres números aleatorios
            srand((unsigned int)time(NULL));
            int numeros[3];
            for (int i = 0; i < 3; i++) {
                numeros[i] = rand() % 20 + 1;
            }

            // Obtener la fecha y hora actual
            time_t tiempoActual;
            struct tm *infoTiempo;

            time(&tiempoActual);
            infoTiempo = localtime(&tiempoActual);

            // Imprimir la fecha y hora en la consola
            printf("Fecha y hora actual: %04d-%02d-%02d %02d:%02d:%02d\n",
                    infoTiempo->tm_year + 1900, infoTiempo->tm_mon + 1, infoTiempo->tm_mday,
                    infoTiempo->tm_hour, infoTiempo->tm_min, infoTiempo->tm_sec);

            // Imprimir los números en la consola
            printf("Numeros generados: %d, %d, %d\n", numeros[0], numeros[1], numeros[2]);

            // Abrir el archivo en modo de escritura (añadir contenido al final)
            archivo = fopen("numeros_y_fecha.txt", "a");

            // Verificar si el archivo se abrió correctamente
            if (archivo == NULL) {
                fprintf(stderr, "Error al abrir el archivo.\n");
                return 1;
            }

            // Imprimir la fecha, hora y números en el archivo
            fprintf(archivo, "Fecha y hora actual: %04d-%02d-%02d %02d:%02d:%02d\n",
                    infoTiempo->tm_year + 1900, infoTiempo->tm_mon + 1, infoTiempo->tm_mday,
                    infoTiempo->tm_hour, infoTiempo->tm_min, infoTiempo->tm_sec);

            fprintf(archivo, "Numeros generados: %d, %d, %d\n", numeros[0], numeros[1], numeros[2]);

            // Cerrar el archivo
            fclose(archivo);
        } else if (opcion == 3) {
            // Abrir el archivo en modo de lectura
            archivo = fopen("numeros_y_fecha.txt", "r");

            // Verificar si el archivo se abrió correctamente
            if (archivo == NULL) {
                fprintf(stderr, "Error al abrir el archivo.\n");
                return 1;
            }

            // Leer y mostrar el historial de tiradas
            printf("Historial de tiradas:\n");
            int c;
            while ((c = fgetc(archivo)) != EOF) {
                putchar(c);
            }

            // Cerrar el archivo
            fclose(archivo);
        } else if (opcion == 4) {
            // Cerrar la loteria y salir
            printf("Cerrando la loteria y saliendo.\n");
        } else {
            printf("Opcion no válida. Por favor, selecciona una opcion valida.\n");
        }
    } while (opcion != 4);

    return 0;
}
