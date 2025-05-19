#include <stdio.h>
#include <stdbool.h>

#define MAX_ENTEROS 100
const int NO_ENCONTRADO = -1;


/* Pre condiciones: algunos_enteros tiene que estar ordenado ascendentemente
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


int main () {

    int algunos_enteros[MAX_ENTEROS] = {1, 2, 9, 12, 15, 20, 23, 27, 33, 35, 36, 45, 48, 49, 50, 51, 55, 59, 60, 65, 77, 78, 81, 82, 86, 87, 90, 95, 99, 101, 112, 125, 130};
    int cantidad_enteros = 33;

    int valor_buscado = 101;
    int posicion = buscar_valor(algunos_enteros, cantidad_enteros, valor_buscado);
    if (posicion != NO_ENCONTRADO){
        printf(":):) ¡El valor %i se encuentra en la posición %i del vector! :):)\n", valor_buscado, posicion);
    } else {
        printf(":(:( ¡El valor %i NO se encuentra en el vector! :(:(\n", valor_buscado);
    }

    return 0;
}