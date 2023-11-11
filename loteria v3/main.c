#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

int main()
{
    FILE *archivo = NULL;
    char jugada[20];
    int opcion;
    float dineroApostado = 0.0;
    int tipoJuego;

    do
    {
        printf("Menu:\n");
        printf("1. Jugar\n");
        printf("2. Tirar\n");
        printf("3. Imprimir historial de tiradas\n");
        printf("4. Revisar jugada y tirada\n");
        printf("5. Cerrar la loteria y salir\n");
        printf("6. Cerrar la loteria, borrar historial y salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        if (opcion == 1)
        {
            if (archivo != NULL)
            {
                fclose(archivo);
                archivo = NULL;
            }

            printf("¿Cuanto dinero quieres apostar? ");
            scanf("%f", &dineroApostado);

            printf("¿Que tipo de juego quieres realizar?\n");
            printf("1. Jugar un numero\n");
            printf("2. Jugar un pale (dos numeros)\n");
            printf("3. Jugar una tripleta (tres numeros)\n");
            printf("Seleccione una opcion: ");
            scanf("%d", &tipoJuego);

            if (tipoJuego == 1)
            {
                printf("Ingresa el numero que quieres jugar: ");
                int numero;
                scanf("%d", &numero);
                sprintf(jugada, "Numero jugado: %d\n", numero);
            }
            else if (tipoJuego == 2)
            {
                printf("Ingresa el primer numero del pale: ");
                int numero1;
                scanf("%d", &numero1);
                printf("Ingresa el segundo numero del pale: ");
                int numero2;
                scanf("%d", &numero2);
                sprintf(jugada, "Pale jugado: %d, %d\n", numero1, numero2);
            }
            else if (tipoJuego == 3)
            {
                printf("Ingresa el primer numero de la tripleta: ");
                int numero1;
                scanf("%d", &numero1);
                printf("Ingresa el segundo numero de la tripleta: ");
                int numero2;
                scanf("%d", &numero2);
                printf("Ingresa el tercer numero de la tripleta: ");
                int numero3;
                scanf("%d", &numero3);
                sprintf(jugada, "Tripleta jugada: %d, %d, %d\n", numero1, numero2, numero3);
            }
            else
            {
                printf("Opcion no valida.\n");
            }
        }
        else if (opcion == 2)
        {
            srand((unsigned int)time(NULL));
            int numeros[3];
            for (int i = 0; i < 3; i++)
            {
                numeros[i] = rand() % 20 + 1;
            }

            time_t tiempoActual;
            struct tm *infoTiempo;

            time(&tiempoActual);
            infoTiempo = localtime(&tiempoActual);

            printf("Fecha y hora actual: %04d-%02d-%02d %02d:%02d:%02d\n",
                   infoTiempo->tm_year + 1900, infoTiempo->tm_mon + 1, infoTiempo->tm_mday,
                   infoTiempo->tm_hour, infoTiempo->tm_min, infoTiempo->tm_sec);

            printf("Numeros generados: %d, %d, %d\n", numeros[0], numeros[1], numeros[2]);

            archivo = fopen("numeros_y_fecha.txt", "a");

            if (archivo == NULL)
            {
                fprintf(stderr, "Error al abrir el archivo.\n");
                return 1;
            }

            fprintf(archivo, "Fecha y hora actual: %04d-%02d-%02d %02d:%02d:%02d\n",
                    infoTiempo->tm_year + 1900, infoTiempo->tm_mon + 1, infoTiempo->tm_mday,
                    infoTiempo->tm_hour, infoTiempo->tm_min, infoTiempo->tm_sec);

            fprintf(archivo, "Numeros generados: %d, %d, %d\n", numeros[0], numeros[1], numeros[2]);

            fclose(archivo);
        }
        else if (opcion == 3)
        {
            archivo = fopen("numeros_y_fecha.txt", "r");

            if (archivo == NULL)
            {
                fprintf(stderr, "Error al abrir el archivo.\n");
                return 1;
            }

            printf("Historial de tiradas:\n");
            int c;
            int newLineCount = 0;

            while ((c = fgetc(archivo)) != EOF)
            {
                putchar(c);

                if (c == '\n')
                {
                    newLineCount++;
                    if (newLineCount % 2 == 0)
                    {
                        // Imprimir una linea de separacion despues de cada segunda linea (despues de cada tirada)
                        printf("----------------------------------------\n");
                    }
                }
            }

            fclose(archivo);
        }
        else if (opcion == 4)
        {
            // Revisar jugada y tirada y determinar si hay algun numero en comun
            int numerosJugada[3];
            sscanf(jugada, "%*[^0-9]%d%*[^0-9]%d%*[^0-9]%d", &numerosJugada[0], &numerosJugada[1], &numerosJugada[2]);

            int numerosTirada[3];
            archivo = fopen("numeros_y_fecha.txt", "r");

            if (archivo == NULL)
            {
                fprintf(stderr, "Error al abrir el archivo.\n");
                return 1;
            }

            // Leer la ultima tirada del historial
            while (fscanf(archivo, "%*[^0-9]%d%*[^0-9]%d%*[^0-9]%d", &numerosTirada[0], &numerosTirada[1], &numerosTirada[2]) != EOF)
            {
            }

            fclose(archivo);

            // Verificar si hay algun numero en comun segun el tipo de juego
            int numerosEnComun = 0;

            switch (tipoJuego)
            {
            case 1: // Jugar un numero
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        if (numerosJugada[i] == numerosTirada[j])
                        {
                            numerosEnComun++;
                            break;
                        }
                    }
                }
                break;

            case 2: // Jugar un pale
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        if (numerosJugada[i] == numerosTirada[j])
                        {
                            numerosEnComun++;
                            break;
                        }
                    }
                }
                break;

            case 3: // Jugar una tripleta
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        if (numerosJugada[i] == numerosTirada[j])
                        {
                            numerosEnComun++;
                            break;
                        }
                    }
                }
                break;

            default:
                // Opcion no válida
                printf("Opcion de juego no valida.\n");
                break;
            }

            // Determinar el resultado y multiplicar el dinero apostado
            float resultado;
            if (numerosEnComun == 0)
            {
                printf("No has acertado ningun numero. Has perdido.\n");
                resultado = 0.0;
            }
            else
            {
                printf("Has acertado %d numero(s). ¡Felicidades!\n", numerosEnComun);

                // Multiplicar el dinero segun el tipo de juego
                switch (numerosEnComun)
                {
                case 1:
                    resultado = dineroApostado * 2.3;
                    break;
                case 2:
                    resultado = dineroApostado * 2.7;
                    break;
                case 3:
                    resultado = dineroApostado * 3.5;
                    break;
                default:
                    resultado = 0.0;
                    break;
                }
            }

            printf("Tu resultado es: %.2f\n", resultado);
        }
        else if (opcion == 5)
        {
            // Cerrar la loteria y salir sin borrar historial
            printf("Cerrando la loteria y saliendo.\n");
        }
        else if (opcion == 6)
        {
            // Cerrar la loteria, borrar historial y salir
            printf("Cerrando la loteria, borrando historial y saliendo.\n");

            archivo = fopen("numeros_y_fecha.txt", "w");
            if (archivo == NULL)
            {
                fprintf(stderr, "Error al abrir el archivo para eliminar el historial.\n");
                return 1;
            }
            fclose(archivo);
        }
        else
        {
            printf("Opcion no valida. Por favor, selecciona una opcion valida.\n");
        }
    }
    while (opcion != 5 && opcion != 6);

    return 0;
}

