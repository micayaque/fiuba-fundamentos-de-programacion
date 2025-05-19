#include <stdio.h>
#define MAX 7

void ordenar_por_burbujeo (int vector[MAX], int tope){
    int auxiliar;
    
    for (int i = 0; i < tope; i++) {
        for (int j = 0; j < (tope - i - 1); j++) {
            if(vector[j] > vector[j + 1]) {
                auxiliar = vector [j];
                vector [j] = vector [j + 1];
                vector [j + 1] = auxiliar ;
            }
        }
    }
}

int main() {

    int vector[MAX] = {4, 54, 2, 34, 45, 23, 1};
    int tope = 7;

    ordenar_por_burbujeo(vector, tope);

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