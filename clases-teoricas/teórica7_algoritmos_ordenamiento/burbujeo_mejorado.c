#include <stdio.h>
#include <stdbool.h>

#define MAX 7

void ordenar_por_burbujeo_mejorado (int vector[MAX], int tope){
    int j = 0, i, aux;
    bool esta_ordenado = false;

    while((j < tope) && (!esta_ordenado)){
        esta_ordenado = true ;
        for (i = 0; i < tope - 1; i++) {
            if(vector[i] > vector[i+1]) {
                aux = vector[i];
                vector[i] = vector[i + 1];
                vector[i + 1] = aux ;
                esta_ordenado = false ;
            }
        }
        j++;
    }
}


int main() {

    int vector[MAX] = {10, 1, 2, 4, 5, 7, 9};
    int tope = 7;

    ordenar_por_burbujeo_mejorado(vector, tope);

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