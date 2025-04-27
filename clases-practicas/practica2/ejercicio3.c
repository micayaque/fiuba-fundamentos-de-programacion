#include <stdio.h>
#include <stdlib.h> //para usar malloc, realloc y free
#include <stdbool.h> //para usar el tipo bool

typedef struct{
    unsigned int cantidad;
    float datos[];
} Vector;

void cargar_gastos(Vector* gastos){
    float gasto = 0;
    printf("Ingrese los gastos administrativos (ingrese -1 para finalizar):\n");

    while(true){
        printf("Gasto %d: ", gastos->cantidad + 1);
        scanf("%f", &gasto);
        if(gasto == -1) break;

        //realloc redimensiona el vector
        Vector* temp = realloc(gastos, sizeof(Vector) + (gastos->cantidad + 1) * sizeof(float));
        gastos = temp;

        gastos->datos[gastos->cantidad] = gasto;
        gastos->cantidad++;
    }
}

float promedio(Vector* gastos){
    if(gastos->cantidad == 0) return 0;

    float suma = 0;
    for(int i = 0; i < gastos->cantidad; i++){
        suma += gastos->datos[i];
    }
    return suma / (float)gastos->cantidad;
}

int posicion_mayor_gasto(Vector* gastos){
    if(gastos->cantidad == 0) return -1;

    int pos_mayor = 0;
    for(int i = 1; i < gastos->cantidad; i++){
        if(gastos->datos[i] > gastos->datos[pos_mayor]){
            pos_mayor = i;
        }
    }
    return pos_mayor;
}

// 	d. Eliminar el gasto más alto del vector y calcular nuevamente el promedio.

void eliminar_gasto_mayor(Vector* gastos){
    if(gastos->cantidad == 0) return;

    int posicion_mayor = posicion_mayor_gasto(gastos);
    for(int i = posicion_mayor; i < gastos->cantidad - 1; i++){
        gastos->datos[i] = gastos->datos[i + 1];
    }
    gastos->cantidad--;
    
    //realloc redimensiona el vector para que se libere la memoria ocupada por el último elemento
    Vector* temp = realloc(gastos, sizeof(Vector) + (gastos->cantidad) * sizeof(float));
    gastos = temp;
}

int main(){
    Vector* gastos = malloc(sizeof(Vector)); // al principio sólo tiene la parte fija
    gastos->cantidad = 0;  
    
    cargar_gastos(gastos);

    //float promedio_gastos = promedio(gastos);

    //int posicion_mayor = posicion_mayor_gasto(gastos);

    //float nuevo_promedio = promedio(gastos);

    return 0;
}