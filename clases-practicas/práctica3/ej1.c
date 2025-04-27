#include <stdio.h>
#include <stdbool.h>

#define MAX_COSECHAS 100

const char TOMACO = 'T';
const char YUYO = 'Y';
const char HIEDRA = 'H';
const char FRUTO_SALVAJE = 'F';

typedef struct cosecha {
    char tipo_planta;
    int cantidad;
    bool es_comestible;
} cosecha_t;

// PRE: recibe un vector de cosechas con su tope y sus campos correctamente inicializados.
// POST: devuelve la cantidad de plantas de las cosechas que son comestibles.
int cantidad_comestibles(cosecha_t cosechas_del_dia[MAX_COSECHAS], int tope_cosechas){
    int contador_comestibles = 0;
    for(int i=0; i<tope_cosechas; i++){
        if(cosechas_del_dia[i].es_comestible) {
            contador_comestibles += cosechas_del_dia[i].cantidad;
        }
    }

    return contador_comestibles;
}

cosecha_t nueva_cosecha(char tipo, int cantidad, bool es_comestible){

    cosecha_t nueva_cosecha;

    nueva_cosecha.tipo_planta = tipo;
    nueva_cosecha.cantidad = cantidad;
    nueva_cosecha.es_comestible = es_comestible;

    return nueva_cosecha;
}

// SON LO MISMO:
// (*cosecha).tipo_planta
// cosecha->tipo_planta
void corregir_cantidad(cosecha_t* cosecha, int cantidad_nueva, int cantidad_vieja, char tipo){
    if((*cosecha).tipo_planta == tipo && (*cosecha).cantidad == cantidad_vieja){
        (*cosecha).cantidad = cantidad_nueva;
    }
}

// PRE: las cantidades tienen que ser positivas. El vector de cosechas tiene su tope y sus campos correctamente inicializados.
// POST: modifica la cantidad de plantas de la cosecha del tipo y la cantidad vieja recibida. Si hay más de una con el mismo tipo y la misma cantidad, modifica ambas.
void modificar_cosecha(cosecha_t cosechas[MAX_COSECHAS], int tope_cosechas, char tipo, int cantidad_vieja, int cantidad_nueva){
    for(int i=0; i<tope_cosechas; i++){
        corregir_cantidad(&cosechas[i], cantidad_nueva, cantidad_vieja, tipo);
    }
}

int main() {
    /*Crear un vector que represente todas las cosechas de un día. Luego, crear una función que calcule cuántas plantas comestibles tiene la familia para comer ese día.*/

    cosecha_t cosechas_del_dia[MAX_COSECHAS];

    cosechas_del_dia[0] = nueva_cosecha(TOMACO, 4, true);
    cosechas_del_dia[1] = nueva_cosecha(HIEDRA, 3, false);
    cosechas_del_dia[2] = nueva_cosecha(FRUTO_SALVAJE, 4, true);
    cosechas_del_dia[3] = nueva_cosecha(YUYO, 1, false); 

    int tope_cosechas = 4;

    int cantidad_comestible = cantidad_comestibles(cosechas_del_dia, tope_cosechas);

    printf("Te podes comer %i plantas\n", cantidad_comestible);

    modificar_cosecha(cosechas_del_dia, tope_cosechas, TOMACO, 4, 14);

    int nueva_cantidad_comestible = cantidad_comestibles(cosechas_del_dia, tope_cosechas);

    printf("JOdaaaa te podes comer %i plantas\n", nueva_cantidad_comestible);

    return 0;
}