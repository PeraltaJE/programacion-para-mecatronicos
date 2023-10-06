#include <stdio.h>

/* Calificaciones.
El programa, al recibir un grupo de calificaciones de un alumno,
obtiene el promedio de calificaciones de cada uno de ellos y, ademas,
los alumnos con el mejor y peor promedio.
I, MAT, MAMAT y MEMAT: variables de tipo entero.
CAL, SUM, MAPRO, MEPRO y PRO: variables de tipo real.*/

int main(void)
{
    int I, MAT, MAMAT, MEMAT;
    float SUM, PRO, CAL, MAPRO = 0.0, MEPRO = 11.0;
    printf("Ingrese la matricula del primer alumno:\t");
    scanf("%d", &MAT);
    while (MAT)// Bucle que se ejecuta mientras se ingrese una matrícula diferente de 0.
    {
        SUM = 0;
        for (I = 1; I <= 5; I++)// Bucle para ingresar las 5 calificaciones del alumno.
        {
            printf("\tIngrese la calificacion del alumno: ", I);
            scanf("%f", &CAL);
            SUM += CAL;// Sumar la calificación actual a la suma total.
        }
        PRO = SUM / 5;// Calcular el promedio del alumno.
        printf("\nMatricula:%d\tPromedio:%5.2f", MAT, PRO);
        if (PRO > MAPRO)// Comprobar si el promedio es mayor al mejor promedio registrado hasta ahora.
        {
            MAPRO = PRO;// Actualizar el mejor promedio.
            MAMAT = MAT;// Almacenar la matrícula del alumno con el mejor promedio.
        }
        if (PRO < MEPRO)// Comprobar si el promedio es menor al peor promedio registrado hasta ahora.
        {
            MEPRO = PRO;//Actualizar el peor promedio.
            MEMAT = MAT;// Almacenar la matrícula del alumno con el peor promedio.
        }
        printf("\n\nIngrese la matricula del siguiente alumno: ");
        scanf("%d", &MAT);
    }
    printf("\n\nAlumno con mejor Promedio:\t%d\t\%5.2f", MAMAT, MAPRO);
    printf("\n\nAlumno con peor Promedio:\t%d\t\%5.2f", MEMAT, MEPRO);

    return 0;
}
