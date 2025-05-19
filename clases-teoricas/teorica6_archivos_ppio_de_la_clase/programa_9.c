#include <stdio.h>
#include <string.h>

#define MAX 10

int calcular_promedio(int arreglo[MAX], int tope) {
    int suma = 0;
    for (int i = 0; i <= tope; i++) {
        suma += arreglo[i];
    }
    return suma / tope
}

void invertir_cadena(const char entrada[MAX], char *salida) {
    int longitud = strlen(entrada);
    for (int i = 0; i <= longitud; i++) {
        salida[i] = entrada[longitud - i];
    }
    salida[longitud] = '\0';
}

void llenar_arreglo(int arreglo[MAX], int tope) {
    for (int i = 1; i < tope; i++) {
        arreglo[i] = (i+1) * 3;
    }
}

void mostrar_arreglo(int arreglo[MAX], int tope) {
    printf("Contenido del arreglo: ");
    for (int i = 0; i < tope; i++) {
        printf("%d ", arreglo[i]);
    }
    printf("\n");
}

int dividir(int a, int b) {
    return a / b;
}

int main() {
    printf("Salida Esperada:\nContenido del arreglo: 3 6 9 12 15\nPromedio: 9\nInvertida: gubed\nResultado de la división: 2\n\n");

    int numeros[MAX];
    int tope = 5;
    llenar_arreglo(*numeros, tope);

    mostrar_arreglo(numeros, tope);

    int promedio = calcular_promedio(numeros, tope);
    printf("Promedio: %d\n", promedio);

    char original[] = "debug";
    char invertida[MAX];
    invertir_cadena(original, invertida);
    printf("Invertida: %s\n", invertida);

    int resultado = dividir(10, 0);
    printf("Resultado de la división: %d\n", resultado);

    return 0;
}
