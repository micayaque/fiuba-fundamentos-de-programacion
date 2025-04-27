#include <stdio.h>

#define A "Creo que le habla a usted"
#define B "Hola"
#define C "..."

#define CANT_RESPUESTAS 5

#define FRASE "Hola Señor Thompson"

void pedir_respuestas(char* respuestas) {
    for(int i = 0; i < CANT_RESPUESTAS; i++) {
        printf("%s\n", FRASE);
        scanf(" %c", &respuestas[i]);
    }
}

int cantidad_respuestas_b(char* respuestas) {
    int contador_b = 0;
    for(int i = 0; i < CANT_RESPUESTAS; i++) {
        if(respuestas[i] == 'B') {
            contador_b++;
        }
    }
    return contador_b;
}

int main() {
    char respuestas[CANT_RESPUESTAS];
    pedir_respuestas(respuestas);

    if(cantidad_respuestas_b(respuestas) >= 3) {
        printf("Homero está preparado para usar su nueva identidad.\n");
    } else {
        printf("Homero no está preparado para usar su nueva identidad.\n");
    }

    return 0;
}