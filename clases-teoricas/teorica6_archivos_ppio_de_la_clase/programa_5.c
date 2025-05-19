#include <stdio.h>

const int MIN_NOTA = 1;
const int MAX_NOTA = 10;

int main() {
    int x = 5;
    if (x > MIN_NOTA || x < MAX_NOTA) { 
        printf("Valor de nota válida :):):)\n");
    } else {
        printf("El valor no pertenece a una nota válida\n");
    }
    return 0;
}
