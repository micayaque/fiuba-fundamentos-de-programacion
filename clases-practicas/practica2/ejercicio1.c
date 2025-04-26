#include <stdio.h>

#define PRECIO_BASE 300
#define HORARIO_MIN 9
#define HORARIO_MAX 12

void preguntar_hora(int *hora){
    printf("Ingrese la hora para la cual necesita las respuestas del exámen: ");
    scanf("%d", hora);

    while (*hora < HORARIO_MIN || *hora > HORARIO_MAX){
        printf("Hora inválida. Ingrese un horario de %d-%d: ", HORARIO_MIN, HORARIO_MAX);
        scanf("%d", hora);
    }
}

int precio_total(int hora){
    return PRECIO_BASE + (400 / hora);
}

int main(){
    int hora;
    preguntar_hora(&hora);
    int total = precio_total(hora);
    printf("El precio total del servicio es: %d\n", total);

    return 0;
}