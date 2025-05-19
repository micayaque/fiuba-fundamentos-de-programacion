#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NOMBRE 30
#define MAX_PREMIOS 10

typedef struct premio {
    char titulo[MAX_NOMBRE]; // "Deletreo", "Ciencias", "Nerd del año", etc
    int fecha; //formato AAAA
} premio_t;

void inicializar_premios(premio_t premios[MAX_PREMIOS], int* cantidad_precios) {
    premio_t deletreos = {"Deletreo", 2019};
    premio_t ciencias = {"Ciencias", 2025};
    premio_t nerd = {"Nerd del año", 2024};
    premio_t matematicas = {"Matematicas", 2023};
    premio_t historia = {"Historia", 2024};
    premio_t geografia = {"Geografia", 2021};
    premio_t literatura = {"Literatura", 2020};
    premio_t arte = {"Arte", 2022};
    premio_t musica = {"Jazz", 2018};
    premio_t deportes = {"Ajedrez", 2023};

    premios[0] = deletreos;
    premios[1] = ciencias;
    premios[2] = nerd;
    premios[3] = matematicas;
    premios[4] = historia;
    premios[5] = geografia;
    premios[6] = literatura;
    premios[7] = arte;
    premios[8] = musica;
    premios[9] = deportes;

    *cantidad_precios = 10; 
}

void imprimir_premios(premio_t premios[MAX_PREMIOS], int cantidad_premios) {
    for (int i = 0; i < cantidad_premios; i++) {
        printf("Premio: %s, Fecha: %4i\n", premios[i].titulo, premios[i].fecha);
    }
}

// Post: devuelve true cuando el premio 1 es mayor al premio 2
bool es_mayor(premio_t premio_1, premio_t premio_2){
    if (premio_1.fecha > premio_2.fecha) {
        return true;
    }
    if (premio_1.fecha == premio_2.fecha) {
        return strcmp(premio_1.titulo, premio_2.titulo) < 0;
    }
    return false; 
}

//Crear una función que ordene los premios de forma tal que queden los más nuevos primero.
// INSERCION 
void ordenar_premios(premio_t premios[MAX_PREMIOS], int cantidad_premios) {
    premio_t premio_aux;
    for(int i = 1; i < cantidad_premios; i++){
        premio_aux = premios[i];
        int j = i;
        while(j > 0 && es_mayor(premio_aux, premios[j - 1])){
            premios[j] = premios[j-1];
            j--;
        }
        premios[j] = premio_aux;
    }
}



int main() {
    premio_t premios[MAX_PREMIOS];
    int cantidad_premios = 0;
    inicializar_premios(premios, &cantidad_premios);
    printf("Premios antes de ordenar:\n");
    imprimir_premios(premios, cantidad_premios);


    printf("\nPremios después de ordenar:\n");
    ordenar_premios(premios, cantidad_premios);
    imprimir_premios(premios, cantidad_premios);
    return 0;
}