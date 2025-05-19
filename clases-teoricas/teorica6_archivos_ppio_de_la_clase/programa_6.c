#include <stdio.h>

int main() {
    int i = 0;

    printf("Antes de entrar al bucle\n");

    while (i != 10) {
        i =+ 2;
    }

    printf("Salí del bucle\n");
    return 0;
}