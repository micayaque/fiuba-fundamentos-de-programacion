#include <stdio.h>
#include <stdbool.h>
#include <string.h>


#define MAX_NOMBRE 100
#define MAX_MEDICIONES 500
#define PLANETA_FRINKON "Frinkon-7"

const int MIN_OXIGENO = 100;

typedef struct medicion {
    char planeta[MAX_NOMBRE];
    bool es_estable;
    int nivel_oxigeno;
} medicion_t;

bool es_habitable_frinkon_rec(medicion_t mediciones[MAX_MEDICIONES], int tope_mediciones, int pos_actual){
    if(pos_actual >= tope_mediciones){
        return true;
    }

    if(strcmp(mediciones[pos_actual].planeta, PLANETA_FRINKON) == 0 && mediciones[pos_actual].es_estable && mediciones[pos_actual].nivel_oxigeno <= MIN_OXIGENO){
        return false;
    }

    return es_habitable_frinkon_rec(mediciones, tope_mediciones, pos_actual + 1);
}

bool es_habitable_frinkon(medicion_t mediciones[MAX_MEDICIONES], int tope_mediciones){
    return es_habitable_frinkon_rec(mediciones, tope_mediciones, 0);
}

void inicializar_mediciones(medicion_t mediciones[MAX_MEDICIONES], int* cantidad) {
    mediciones[0].es_estable = true;
    mediciones[0].nivel_oxigeno = 100;
    strcpy(mediciones[0].planeta, "Planeta1");

    mediciones[1].es_estable = false;
    mediciones[1].nivel_oxigeno = 50;
    strcpy(mediciones[1].planeta, "Planeta2");

    mediciones[2].es_estable = true;
    mediciones[2].nivel_oxigeno = 30;
    strcpy(mediciones[2].planeta, "Frinkon-7");

    mediciones[3].es_estable = false;
    mediciones[3].nivel_oxigeno = 0;
    strcpy(mediciones[3].planeta, "Frinkon-7");

    mediciones[4].es_estable = true;
    mediciones[4].nivel_oxigeno = 130;  
    strcpy(mediciones[4].planeta, "Frinkon-7");

    (*cantidad) = 5;
}

void mostrar_mediciones(medicion_t mediciones[MAX_MEDICIONES], int tope){
    for (int i = 0; i < tope; i++) {
        printf("Medicion %d:\n", i + 1);
        printf("Planeta: %s\n", mediciones[i].planeta);
        printf("Es estable: %s\n", mediciones[i].es_estable ? "Si" : "No");
        printf("Nivel de oxigeno: %d\n", mediciones[i].nivel_oxigeno);
        printf("\n");
    }
}

int main(){
    medicion_t mediciones[MAX_MEDICIONES];
    int tope_mediciones = 0;
    inicializar_mediciones(mediciones, &tope_mediciones);
    mostrar_mediciones(mediciones, tope_mediciones);

    bool es_habitable = es_habitable_frinkon(mediciones, tope_mediciones);
    if (es_habitable){
        printf("Es habitable \n");
    }else{
        printf("No es habitable\n");
    }

    return 0;
}