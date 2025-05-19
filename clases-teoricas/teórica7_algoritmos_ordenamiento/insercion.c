#include <stdio.h>
#include <stdbool.h>

#define MAX 7

void ordenar_por_insercion(int vector[MAX] , int tope ){
    int j, auxiliar ;
    for (int i = 1; i < tope ; i++) {
        j = i;
        auxiliar = vector[i];
        
        while((j > 0) && (auxiliar < vector[j - 1])){
            vector[j] = vector[j - 1];
            j--;
        }
        vector[j] = auxiliar;
    }
}


int main() {
    int vector[MAX] = {4, 54, 2, 34, 45, 23, 1};
    int tope = 7;

    ordenar_por_insercion(vector , tope);

    for(int i = 0; i < tope; i++) {
        if(i == 0) {
            printf("[");
        }
        
        printf(" %i", vector[i]);

        if(i == (tope - 1)) {
            printf( " ]\n");
        }
    }

    return 0;
}
