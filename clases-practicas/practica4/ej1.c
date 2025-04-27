#include "fundamendezRecMath.h"
#include <stdio.h>




int main(){

    int num1 = 3;
    int num2 = 4;
    int resultado = multiplicacion_rec(num1, num2);
    printf("%i\n", resultado);
    int num_primo = 41;
    if(es_primo_rec(num_primo)){
        printf("Era primo yeiii\n");
    }
    else{
        printf("no es primo :(\n");
    }

    return 0;
}