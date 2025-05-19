#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NOMBRE 500
#define MAX_PREMIO 100

typedef struct premio {
    char titulo[MAX_NOMBRE]; // "Deletreo", "Ciencias", "Nerd del año", etc
    int fecha; //formato AAAA
} premio_t;

void inicializar_premios(premio_t premios[MAX_PREMIO], int* tope){
    premios[0].fecha = 2025;
    strcpy(premios[0].titulo, "Deletreo");
    premios[1].fecha = 2024;
    strcpy(premios[1].titulo, "Ciencias");
    premios[2].fecha = 2024;
    strcpy(premios[2].titulo, "Nerd del año");
    premios[3].fecha = 2021;
    strcpy(premios[3].titulo, "Mejor programadora");
    premios[4].fecha = 2019;
    strcpy(premios[4].titulo, "Mejor presentadora");

    (*tope) = 5;
}

void imprimir_premios(premio_t premios[MAX_PREMIO], int tope){
    for (int i = 0; i < tope; i++){
        printf("Premio: %s, Fecha: %d\n", premios[i].titulo, premios[i].fecha);
    }
}

bool es_mayor(premio_t premio_1, premio_t premio_2){
    if (premio_1.fecha > premio_2.fecha) {
        return true;
    }
    if (premio_1.fecha == premio_2.fecha) {
        return strcmp(premio_1.titulo, premio_2.titulo) < 0;
    }
    return false; 
}

void agregar_premio(premio_t premios[MAX_PREMIO], int* tope_premios, premio_t premio_a_agregar){
    if(*tope_premios >= MAX_PREMIO){
        return;
    }

    int i = (*tope_premios) - 1;
    while(i >= 0 && es_mayor(premio_a_agregar, premios[i])){
        premios[i+1] = premios[i];
        i--;
    }

    premios[i+1] = premio_a_agregar;
    (*tope_premios)++;
}

int main(){
    premio_t premios[MAX_PREMIO];
    int tope = 0;
    inicializar_premios(premios, &tope);
    imprimir_premios(premios, tope);

    premio_t premio_nuevo = {"Mejor alumna", 2024};

    agregar_premio(premios, &tope, premio_nuevo);

    imprimir_premios(premios, tope);

    return 0;
}
// 3
// [1, 2, 3, 4, 6, 7]