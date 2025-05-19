#include <stdio.h>
#include <string.h>

#define MAX_NOMBRE 20
#define MAX_PREMIOS 12

typedef struct premio {
    char titulo[MAX_NOMBRE]; // "Deletreo", "Ciencias", "Nerd del año", etc
    int fecha; //formato AAAA
} premio_t;
// 0  1  2  3  4  5
//[a, b, h, j, j] basura

void inicializar_premios(premio_t premios[MAX_PREMIOS], int* cantidad_premios) {
    premio_t deletreos = {"Deletreo", 2025};
    premio_t ciencias = {"Ciencias", 2024};
    premio_t nerd = {"Nerd del año", 2024};
    premio_t matematicas = {"Matematicas", 2024};
    premio_t historia = {"Ajedrez", 2023};
    premio_t geografia = {"Geografia", 2021};
    premio_t literatura = {"Literatura", 2020};
    premio_t arte = {"Arte", 2020};
    premio_t musica = {"Jazz", 2018};
    premio_t deportes = {"Ajedrez", 2017};

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

    *cantidad_premios = 10; 
}

int encontrar_premio(premio_t premios[MAX_PREMIOS], premio_t premio_robado, int tope){
    int posicion_premio = 0;
    for (int i = 0; i < tope; i++){
        if(strcmp(premios[i].titulo, premio_robado.titulo) == 0 && premios[i].fecha == premio_robado.fecha){
            posicion_premio = i;
        }
    }
    return posicion_premio;
}

void eliminar_premio(int posicion_premio, premio_t premios[MAX_PREMIOS], int *tope){
    for (int i = posicion_premio; i < (*tope)-1; i++){
        premios[i] = premios[i+1];
    }
    (*tope)--;
}

int main(){
    int tope = 0;
    premio_t premios[MAX_PREMIOS];
    inicializar_premios(premios, &tope);
    premio_t premio_robado;
    strcpy(premio_robado.titulo, "Ajedrez");
    premio_robado.fecha = 2023;
    int posicion_premio = encontrar_premio(premios, premio_robado, tope);
    eliminar_premio(posicion_premio, premios, &tope);
    for (int i = 0; i < tope; i++)
    {
        printf("%s, ",premios[i].titulo);
    }
}