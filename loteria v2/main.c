#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

int main()
{
    FILE *archivo = NULL;//puntero al archivo
    char jugada[20];//almacena la jugada del usuario
    int opcion;//opcion del menu

    do
    {
        //mostrar menu
        printf("Menu:\n");
        printf("1. Jugar\n");
        printf("2. Tirar\n");
        printf("3. Imprimir historial de tiradas\n");
        printf("4. Cerrar la loteria y salir\n");
        printf("5. Cerrar la loteria, borrar historial y salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        if (opcion == 1)
        {
            if (archivo != NULL)
            {
                fclose(archivo);
                archivo = NULL;
            }
            //pregunta que tipo de juego el usuario desea realizar
            printf("¿Que tipo de juego quieres realizar?\n");
            printf("1. Jugar un numero\n");
            printf("2. Jugar un pale (dos numeros)\n");
            printf("3. Jugar una tripleta (tres numeros)\n");
            printf("Seleccione una opcion: ");
            int tipoJuego;
            scanf("%d", &tipoJuego);
             //procesa la eleccion
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
        else if (opcion == 2) //revisar v1
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
         else if (opcion == 3)// abrir historial
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
        else if (opcion == 4)//cerrar loteria sin borrar historial
        {
            printf("Cerrando la loteria y saliendo.\n");
        }
        else if (opcion == 5)//cerrar loteria borrando historial
        {
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
    while (opcion != 4 && opcion != 5);

    return 0;
}
