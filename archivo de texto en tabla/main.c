#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    FILE *archivo = NULL;
    char nombreArchivo[50];
    int opcion;

    do
    {
        printf("Menu:\n");
        printf("1. Crear archivo\n");
        printf("2. Ingresar informacion al archivo\n");
        printf("3. Abrir archivo\n");
        printf("4. Cerrar el archivo y salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        if (opcion == 1)
        {
            if (archivo != NULL)
            {
                fclose(archivo);
                archivo = NULL;
            }
            printf("Introduce el nombre del archivo (max 50 caracteres): ");
            scanf("%s", nombreArchivo);
            archivo = fopen(nombreArchivo, "w");
            if (archivo == NULL)
            {
                printf("No se pudo crear el archivo.\n");
            }
            else
            {
                fputc('\0', archivo);
                fclose(archivo);
                printf("Archivo creado y configurado.\n");
            }
        }
        else if (opcion == 2)
        {
            if (archivo != NULL)
            {
                printf("Introduce la informacion: ");
                char informacion[1000];
                scanf(" %[^\n]", informacion);
                archivo = fopen(nombreArchivo, "w");
                fprintf(archivo, "%s", informacion);
                fclose(archivo);
                printf("Informacion guardada.\n");
            }
            else
            {
                printf("El archivo no esta abierto. Abre un archivo primero.\n");
            }
        }
        else if (opcion == 3)
        {
            if (archivo != NULL)
            {
                fclose(archivo);
                archivo = NULL;
            }
            printf("Introduce el nombre del archivo a abrir: ");
            scanf("%s", nombreArchivo);
            archivo = fopen(nombreArchivo, "r");
            if (archivo == NULL)
            {
                printf("Este archivo no existe.\n");
            }
            else
            {
                char caracter;
                int mayusculas = 0, minusculas = 0;

                while ((caracter = fgetc(archivo)) != EOF)
                {
                    if (isupper(caracter))
                    {
                        mayusculas++;
                    }
                    else if (islower(caracter))
                    {
                        minusculas++;
                    }
                }

                rewind(archivo);

                printf("Contenido del archivo:\n");
                while ((caracter = fgetc(archivo)) != EOF)
                {
                    putchar(caracter);
                }

                printf("\nMayusculas: %d\n", mayusculas);
                printf("Minusculas: %d\n", minusculas);

                fclose(archivo);
            }
        }
        else if (opcion == 4)
        {
            if (archivo != NULL)
            {
                fclose(archivo);
                archivo = NULL;
            }
            printf("Archivo cerrado. Saliendo del programa.\n");
        }
        else
        {
            printf("Opcion no valida. Por favor, selecciona una opcion valida.\n");
        }
    }
    while (opcion != 4);

    return 0;
}

