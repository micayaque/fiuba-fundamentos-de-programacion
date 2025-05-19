#include <stdio.h>
#include <string.h>

#define FILAS 3
#define COLUMNAS 2
#define MAX_NOMBRE 100

typedef struct {
    char nombre[MAX_NOMBRE];
    int edad;
    float nota;
} estudiante_t;

void inicializar_matriz(estudiante_t matriz[FILAS][COLUMNAS]) {
    char *nombres[FILAS * COLUMNAS] = {
        "Ana", "Luis", "Sofía", "Pedro", "Clara", "Juan"
    };
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            int idx = i * COLUMNAS + j;
            strcpy(matriz[i][j].nombre, nombres[idx]);
            matriz[i][j].edad = 18 + i + j;
            matriz[i][j].nota = 7.0 + (j * 4) - i;
        }
    }
}

float promedio_fila(estudiante_t fila[], int tam) {
    float suma = 0;
    for (int i = 0; i < tam; i++) {
        suma += fila[i].nota;
    }
    return suma / tam;
}

estudiante_t encontrar_mejor(estudiante_t matriz[FILAS][COLUMNAS]) {
    estudiante_t mejor;
    mejor.nota = 0;
    for (int i = 0; i < COLUMNAS; i++) {
        for (int j = 0; j < FILAS; j++) {
            if (matriz[i][j].nota > mejor.nota) {
                mejor = matriz[i][j];
            }
        }
    }
    return mejor;
}

void copiar_matriz(estudiante_t original[FILAS][COLUMNAS], estudiante_t copia[FILAS][COLUMNAS]) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            copia[j][i] = original[j][i];
        }
    }
}

void imprimir_matriz(estudiante_t matriz[FILAS][COLUMNAS]) {
    for (int i = 0; i < FILAS; i++) {
        printf("Fila %d:\n", i);
        for (int j = 0; j < COLUMNAS; j++) {
            printf("  %s (Edad: %d, Nota: %.1f)\n",
                   matriz[i][j].nombre,
                   matriz[i][j].edad,
                   matriz[i][j].nota);
        }
    }
}

int main() {
    estudiante_t grupo[FILAS][COLUMNAS];
    estudiante_t copia[FILAS][COLUMNAS];



    inicializar_matriz(grupo);
    imprimir_matriz(grupo);

    int cant_filas = 4;
    for (int i = 0; i < cant_filas; i++) {
        float prom = promedio_fila(grupo[i], COLUMNAS);
        printf("Promedio fila %d: %.2f\n", i, prom);
    }

    estudiante_t mejor = encontrar_mejor(grupo);
    printf("Mejor estudiante: %s con nota %.1f\n", mejor.nombre, mejor.nota);

    copiar_matriz(grupo, copia);

    printf("\nDespués de modificar original:\n");
    printf("Original:\n");
    imprimir_matriz(grupo);
    printf("Copia:\n");
    imprimir_matriz(copia);
}
