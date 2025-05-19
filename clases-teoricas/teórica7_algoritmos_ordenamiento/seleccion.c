#include <stdio.h>

#define MAX 7

void ordenar_por_seleccion(int vector[MAX], int tope){
    int auxiliar;
    int pos_minimo;
    for(int i = 0; i < (tope - 1); i++) {
        pos_minimo = i;
        for (int j = i + 1; j < tope; j++) {
            if (vector[pos_minimo] > vector [j]) {
                pos_minimo = j;
            }
        }
        auxiliar = vector [i];
        vector [i] = vector [pos_minimo];
        vector [pos_minimo] = auxiliar;
    }
}

int main() {

    int vector[MAX] = {4, 54, 2, 34, 45, 23, 1};
    int tope = 7;

    ordenar_por_seleccion(vector, tope);

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