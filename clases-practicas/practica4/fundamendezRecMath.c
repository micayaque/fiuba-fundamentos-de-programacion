#include "fundamendezRecMath.h"
#include <stdio.h>

int multiplicacion_rec(int num1, int num2){
    if(num1 == 0 || num2 == 0){
        return 0;
    }
    return num1 + multiplicacion_rec(num1, num2-1);
}


bool es_primo_rec_aux(int numero, int divisor){
    if(divisor == 1){
        return true;
    }
    if(numero%divisor == 0){
        return false;
    }
    return es_primo_rec_aux(numero, divisor -1);
}


bool es_primo_rec(int numero){
    return es_primo_rec_aux(numero, numero-1);
}


int factorial_rec(int numero){
    if(numero == 0) return 1;
    return numero * factorial_rec(numero - 1);
}

void fibonacci_hasta(int a, int b, int n) {
    if (a > n) {
        return; // caso base: si el número actual es mayor que n, terminamos
    }
    
    printf("%d ", a); // sino, imprimimos el número actual
    
    fibonacci_hasta(b, a + b, n); // y llamamos recursivamente a imprimir el resto con b como número actual (a)
}

void imprimir_fibonacci_rec(int numero){
    fibonacci_hasta(0, 1, numero);
}

int valor_maximo_rec(int vector[], int tope){
    if(tope == 1)  return vector[0];
    int max = valor_maximo_rec(vector, tope - 1);
    if(vector[tope - 1] > max){
        return vector[tope - 1];
    }
    return max;
}

int valor_minimo_rec(int vector[], int tope){
    if(tope == 1)  return vector[0];
    int min = valor_minimo_rec(vector, tope - 1);
    if(vector[tope - 1] < min){
        return vector[tope - 1];
    }
    return min;
}