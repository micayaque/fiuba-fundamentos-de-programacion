#ifndef FUNDAMENDEZRECMATH_H
#define FUNDAMENDEZRECMATH_H

#include <stdbool.h>


/*
*Pre: -
*Post: Devuelve el resultado de la multiplicación entre num1 y num2
*/
int multiplicacion_rec(int num1, int num2);


/*
*Pre: Numero debe ser mayor que 0
*Post: Devuelve True si numero es primo y False en caso contrario
*/
bool es_primo_rec(int numero);


/*
*Pre: Numero debe ser mayor o igual a 0
*Post: Devuelve el factorial del numero ingresado
*/
int factorial_rec(int numero);


/*
*Pre: Numero debe ser mayor o igual a 0
*Post: Imprime la sucesion de numeros menores o iguales al numero recibido
*/
void imprimir_fibonacci_rec(int numero);


/*
*Pre: tope tiene que ser mayor a 0
*Post: Devuelve el mayor valor encontrado en el vector
*/
int valor_maximo_rec(int vector[], int tope);


/*
*Pre: tope tiene que ser mayor a 0
*Post: Devuelve el menor valor encontrado en el vector
*/
int valor_minimo_rec(int vector[], int tope);


#endif //FUNDAMENDEZRECMATH_H