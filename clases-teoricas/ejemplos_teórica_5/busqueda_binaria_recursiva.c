#include <stdio.h>
#include <stdbool.h>

#define MAX_ENTEROS 100
const int NO_ENCONTRADO = -1;

/* Pre condiciones: el vector tiene que estar ordenado ascendentemente
                    tope mayor o igual a cero y menor a MAX_ENTEROS
 * Post condiciones: devuelve el índice en el vector del elemento buscado, caso contrario devuelve -1.
 */
int buscar_valor(int algunos_enteros[MAX_ENTEROS], int tope, int numero_buscado) {
    int inicio = 0;
    int fin = tope - 1;
    int centro;
    bool encontrado = false;

    while(inicio <= fin && !encontrado) {
        centro = (inicio + fin) / 2;

        if(algunos_enteros[centro] == numero_buscado) {
            encontrado = true;
        } else if(algunos_enteros[centro] < numero_buscado) {
            inicio = centro + 1;
        } else {
            fin = centro - 1;
        }
    }

    if(encontrado) {
        return centro;
    } else {
        return NO_ENCONTRADO;
    }
}





/* Pre condiciones: el vector tiene que estar ordenado ascendentemente
                    la primera vez que lo llamo inicio tiene que ser 0
                    la primera vez que lo llamo fin tiene que ser tope-1
 * Post condiciones: devuelve el índice en el vector del elemento buscado, caso contrario devuelve -1.
 */
int buscar_valor_recursivo(int algunos_enteros[MAX_ENTEROS], int inicio, int fin, int numero_buscado) {
    int centro = (inicio+fin)/2;

    if (inicio == fin && algunos_enteros[centro] != numero_buscado){
         return NO_ENCONTRADO;
    }

    if(algunos_enteros[centro] == numero_buscado){
        return centro;
    } else if (algunos_enteros[centro] > numero_buscado) {
        return buscar_valor_recursivo(algunos_enteros, inicio, centro-1, numero_buscado);
    } else {
        // Caso algunos_enteros[centro] < numero_buscado
        return buscar_valor_recursivo(algunos_enteros, centro+1, fin, numero_buscado);
    }
}

/* Pre condiciones: el vector tiene que estar ordenado ascendentemente
                    tope mayor o igual a cero y menor a MAX_ENTEROS
 * Post condiciones: devuelve el índice en el vector del elemento buscado, caso contrario devuelve -1.
 */
int buscar_valor_wrapper(int algunos_enteros[MAX_ENTEROS], int tope, int numero_buscado){
    return buscar_valor_recursivo(algunos_enteros, 0, tope-1, numero_buscado);
}



int main () {

    int algunos_enteros[MAX_ENTEROS] = {1, 2, 9, 12, 15, 20, 23, 27, 33, 35, 36, 45, 48, 49, 50, 51, 55, 59, 60, 65, 77, 78, 81, 82, 86, 87, 90, 95, 99, 101, 112, 125, 130};
    int cantidad_enteros = 33;

    int valor_buscado = 125;
    int posicion = buscar_valor_recursivo(algunos_enteros, 0, cantidad_enteros-1, valor_buscado);
    printf("¡El valor %i se encuentra en la posición %i del vector!\n", valor_buscado, posicion);

    return 0;
}
