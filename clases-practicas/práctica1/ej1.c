#include <stdio.h>
#include <stdbool.h>

const float DESCUENTO = 0.9;
/*
 pre: el total debe ser mayor a cero. 
 post: devuelve el total que tiene que pagar Homero con o sin descuento.
*/
int calculo_descuento(int total, bool paga_en_efectivo){
    if(paga_en_efectivo){
        return total * DESCUENTO;
    }
    return total;
}

/*
 pre: total debe ser mayor a cero.
 post: muestra por pantalla el total. 
*/
void mostrar_total(int total, bool paga_en_efectivo){
    printf("El total que tenes que pagar es: %i\n", calculo_descuento(total, paga_en_efectivo));
}

void preguntar_plata(int* plata){
    printf("Hola cuanta plata tene\n");
    scanf("%i", plata);
    while(*plata < 0){
        printf("no, nene, mayor a cero\n");
        scanf("%i", plata);
    }
}

int main(){
    bool paga_en_efectivo = false;
    int total_c = 0;
    
    preguntar_plata(&total_c);
    printf("%i\n", total_c);
    mostrar_total(total_c, paga_en_efectivo);
    return 0;
}