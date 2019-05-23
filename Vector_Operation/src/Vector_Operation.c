/*
 ============================================================================
 Name        : Calc_with_vectors.c
 Author      : Andrew Vorotyntsev
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>




float factorial(float n) //Задаем функцию факториал
{
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}


int algebra() //Задаем операции с вещественными числами
{
    float a , b ;
    int i ;
    printf("Write fist number"); //Вводим числа
    scanf ("%f",&a) ;
    printf("Write second number");
    scanf ("%f",&b) ;
    printf("Choose operation \n 0-plus 1-minus 2-times 3-Divided by 4-power 5- factorial"); //Выбор операции
    scanf ("%i",&i) ;
    switch (i)
        {
            case 0:
                printf(" Answer=%f", a+b);
                break;
            case 1:
                printf(" Answer=%f", a-b);
                break ;
            case 2:
                printf(" Answer=%f", a*b);
                break ;
            case 3:
                printf(" Answer=%f", a/b);
               break;
            case 4:
                printf(" Answer=%f", pow (a, b));
                break;
            case 5:
                printf(" Answer=%f", factorial(a));
                break;
        }
    return EXIT_SUCCESS;
}


int vectors() // Задаем векторные операции
{
    int  i ,n  ;
    printf("Write size of vectors");
    scanf("%i", &i ); // Вводим длинну векторов
    float *A , *B ,e ,d;
    A = calloc(i,sizeof(float));
    B = calloc(i,sizeof(float));
    printf("Write first vector");
    for (int k=0;k<i;k++)          //Вводим вектора
        scanf("%f", &A[k]);
    printf("Write second vector");
    for (int l=0;l<i;l++)
        scanf("%f", &B[l]);
    printf("Choose operation  0-plus 1-minus 2-scalar"); //Выбираем операцию для векторов
    scanf ("%i",&n) ;
    switch (n)
        {
            case 0:
                for (int p=0;p<i;p++)
                    printf("_%f" , A[p]+B[p]);
                break;
            case 1:
                for (int r=0;r<i;r++)
                    printf("_%f" , A[r]-B[r]);
                break ;
            case 2:
                e=0;
                for (int s=0;s<i;s++)
                {
                    d=A[s]*B[s];
                    e=e+d;
                }
                printf("_%f", e);
                break;
        }
    free(A);
    free(B);
    return EXIT_SUCCESS;
}


int main(void)
{
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
    int z , v;
    do {printf("Choose type: 0-numbers , 1-vectors"); // Выбираем операцию
    scanf("%i", &z);
    if (z==0)
        algebra(); //Выполняется операция с вещественными числами
    else
        vectors(); //Выполняется операция с векторами
    printf("Do you wish to restart program? (1-yes , 0-no)"); //Запрос на повтор
    scanf ("%i",&v) ;
    }while(v==1);
    if(v==0)
    printf("Program is closed\n");
}
