#include <stdio.h>
#include <stdbool.h>

// Ejercicio 1 
// Homero fue a comprar a la tienda de Apu un par de cervezas y justo se encontró con que pagando en efectivo 
// tenía un 10% de descuento. 

// a. Crear un programa que dado el total de la compra de Homero, imprima por pantalla cuánto debería pagar 
// si paga en efectivo y cuánto si paga con tarjeta.  


const float DESCUENTO = 0.9; // como el descuento es un 10%, debe pagar el 90% del total

int calculo_descuento(int total, bool paga_en_efectivo){
    if(paga_en_efectivo){
        return total * DESCUENTO;
    }
    return total;
}

void mostrar_total(int total, bool paga_en_efectivo){
    printf("El total que tenes que pagar es: %i\n", calculo_descuento(total, paga_en_efectivo));
}

void preguntar_plata(int* plata){
    printf("Hola, cuanta plata tenes\n");
    scanf("%i", plata);
    while(*plata < 0){
        printf("no, nene, mayor a cero\n");
        scanf("%i", plata);
    }
}

// int main(){
//     bool paga_en_efectivo = true;
//     int total_c = 0;
    
//     preguntar_plata(&total_c);
//     mostrar_total(total_c, paga_en_efectivo);
//     return 0;
// }

// b. Homero es bastante malo en matemáticas así que ahora quiere saber si le alcanza la plata para pagar 
// en efectivo. Crear un procedimiento que le pida a Homero la cantidad de dinero que tiene e imprima por 
// pantalla si le alcanza para pagar en efectivo o no.

void le_alcanza_la_plata(int total, int plata){
    if(total * DESCUENTO <= plata){
        printf("Le alcanza la plata para pagar en efectivo\n");
    } else {
        printf("No le alcanza la plata para pagar en efectivo\n");
    }
}

/********************************************************************************************************
 * Ejercicio 2 
Edna Krabappel tiene que corregir demasiados exámenes y nos pidió ayuda para hacerlo.  
El examen consta de las siguientes 3 preguntas con sus opciones: 
1. ¿Qué día es Navidad? 
    A. 25 de diciembre 
    B. 5 de mayo 
    C. 18 de abril 
2. ¿Qué dinosaurio podía volar? 
    - Tiranosaurio Rex (T) 
    - Pterodactylus (P) 
    - Brachiosaurus (B) 
3. En km, ¿A qué distancia está el Sol (la estrella, no Diaz Real) de la Tierra? 
(esta pregunta no tiene opciones, se ingresa el número de la distancia). 

Las respuestas correctas son: 1. A, 2. P y 3. 150000000 

Crear un programa que permita a Edna cargar las respuestas de sus alumnos, y le imprima por pantalla la nota que 
sacaron, dadas sus respuestas. 
Aclaración: en el caso de las preguntas 1 y 2, la respuesta cargada puede ser únicamente una de las 3 opciones. 
Si se carga algo incorrecto, se debe volver a preguntar. 

Las notas son: 
    - 10 si las 3 respuestas son correctas. 
    - 7 si 2 respuestas son correctas. 
    - 4 si 1 respuesta es correcta. 
    - 1 si ninguna respuesta es correcta.
*/

void preguntar_navidad(char* respuesta){
    printf("¿Qué día es Navidad?\n");
    printf("A. 25 de diciembre\n");
    printf("B. 5 de mayo\n");
    printf("C. 18 de abril\n");
    scanf(" %c", respuesta);
    while(*respuesta != 'A' && *respuesta != 'B' && *respuesta != 'C'){
        printf("Respuesta incorrecta, por favor ingrese una respuesta válida\n");
        scanf(" %c", respuesta);
    }
}

void preguntar_dinosaurio(char* respuesta){
    printf("¿Qué dinosaurio podía volar?\n");
    printf("T. Tiranosaurio Rex\n");
    printf("P. Pterodactylus\n");
    printf("B. Brachiosaurus\n");
    scanf(" %c", respuesta);
    while(*respuesta != 'T' && *respuesta != 'P' && *respuesta != 'B'){
        printf("Respuesta incorrecta, por favor ingrese una respuesta válida\n");
    }
}

void preguntar_distancia(int* respuesta){
    printf("En km, ¿A qué distancia está el Sol de la Tierra?\n");
    scanf("%i", respuesta);
}

int corregir_examen(char respuesta_navidad, char respuesta_dinosaurio, int respuesta_distancia){
    int cantidad_correctas = 0;
    if(respuesta_navidad == 'A'){
        cantidad_correctas += 1;
    }
    if(respuesta_dinosaurio == 'P'){
        cantidad_correctas += 1;
    }
    if(respuesta_distancia == 150000000){
        cantidad_correctas += 1;
    }
    int nota = 1;

    switch(cantidad_correctas){
        case 3:
            nota = 10;
            break;
        case 2:
            nota = 7;
            break;
        case 1:
            nota = 4;
            break;
        case 0:
            nota = 1;
            break;
    }
    return nota;
}

int main(){
    char respuesta_navidad;
    char respuesta_dinosaurio;
    int respuesta_distancia;
    int nota = 0;
    
    preguntar_navidad(&respuesta_navidad);
    preguntar_dinosaurio(&respuesta_dinosaurio);
    preguntar_distancia(&respuesta_distancia);
    nota = corregir_examen(respuesta_navidad, respuesta_dinosaurio, respuesta_distancia);
    printf("La nota del examen es: %i\n", nota);
    return 0;
}