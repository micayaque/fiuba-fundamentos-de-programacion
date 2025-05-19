#include <stdio.h>

const int MAX_TEMPERATURAS = 8;

int main(){
    int temperaturas[MAX_TEMPERATURAS];
    int tope = 5;
    // Asumo que ya viene inicializado

    // Agregar un elemento
    temperaturas[tope] = 10;
    tope++;

    for(int i = tope; i < MAX_TEMPERATURAS; i++){
        temperaturas[tope] = 10;
        tope++;
    }

    // Me paso del MAX (está mal conceptualmente)
    temperaturas[tope] = 10;
    tope++;

    // Elimino el úlitmo elemento
    tope--;

    // Elimino un elemento
    int pos_a_eliminar = 1;

    // Version super corta (rompe el ordenamiento)
    temperaturas[n] = temperaturas[tope-1];
    tope--;

    // Intercambiar elementos
    int aux;
    aux = temperaturas[n];
    temperaturas[n] = temperaturas[tope-1];
    temperaturas[tope-1] = aux;

    // Buscar elemento
    int buscado = 8;
    int i = 0;
    while((temperaturas[i] != buscado) && (i < tope)){
        i++;
    }

    // Si llegué acá es que lo encontré o no estaba
    if (i >= tope){
        // Caso triste :(
        printf("El elemento no está\n");
    } else {
        // Caso feliz :)
        printf("El elemento está en: %i\n", i);
    }

    return 0;
}
