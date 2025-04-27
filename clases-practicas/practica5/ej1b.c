#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NOMBRE 40
#define MAX_COMPUS 100
#define MAX_TECLAS 100
#define MAX_LABORATORIOS 15

#define NOMBRE_BUSCADO "Skinner"
#define NOMBRE_NUEVO "Baboso"

const int NO_ENCONTRADO = -1;


typedef struct tecla {
    char descripción[MAX_NOMBRE]; // "A", "Ctrl", "Insert", etc
    bool esta_rota;
} tecla_t;

typedef struct compu {
	tecla_t teclado[MAX_TECLAS];
	int cantidad_teclas;
	int id;
} compu_t;

typedef struct laboratorio {
	char nombre[MAX_NOMBRE];
    compu_t computadoras[MAX_COMPUS];
	int cantidad_compus;
} laboratorio_t;

// Pre: -
// Post: inicializa los laboratorios alfabeticamente con nombres predefinidos y cantidad de computadoras en 0 
void inicializar_laboratorios(laboratorio_t laboratorios[MAX_LABORATORIOS], int* cantidad_laboratorios) {
    strcpy(laboratorios[0].nombre, "Aulita");
    laboratorios[0].cantidad_compus = 0;

    strcpy(laboratorios[1].nombre, "Byte-nstein");
    laboratorios[1].cantidad_compus = 0;

    strcpy(laboratorios[2].nombre, "Cúbico");
    laboratorios[2].cantidad_compus = 0;

    strcpy(laboratorios[3].nombre, "Da Vinci");
    laboratorios[3].cantidad_compus = 0;

    strcpy(laboratorios[4].nombre, "Einstein");
    laboratorios[4].cantidad_compus = 0;

    strcpy(laboratorios[5].nombre, "Galileo");
    laboratorios[5].cantidad_compus = 0;

    strcpy(laboratorios[6].nombre, "Newton");
    laboratorios[6].cantidad_compus = 0;

    strcpy(laboratorios[7].nombre, "Quimica");
    laboratorios[7].cantidad_compus = 0;

    strcpy(laboratorios[8].nombre, "Skinner");
    laboratorios[8].cantidad_compus = 0;

    strcpy(laboratorios[9].nombre, "Tesla");
    laboratorios[9].cantidad_compus = 0;

    *cantidad_laboratorios = 10;
}

// Pre: recibe un arreglo de laboratorios y su cantidad correctamente inicializados.
// Post: muestra los nombres de los laboratorios.
void mostrar_laboratorios(laboratorio_t laboratorios[MAX_LABORATORIOS], int cantidad_laboratorios) {
    for (int i = 0; i < cantidad_laboratorios; i++) {
        printf("Laboratorio %d: %s\n", i, laboratorios[i].nombre);
    }
}






// Bart quiere hacer una broma en la escuela cambiando el laboratorio llamado “Skinner” a “Baboso”. 
// Sabiendo que los laboratorios están ordenados por orden alfabético, armar un procedimiento que realice este cambio.

// Pre: ...
// Post: devuelve la posición del laboratorio con el nombre buscado, y sino devuelve -1 
int posicion_laboratorio_rec(laboratorio_t laboratorios[MAX_LABORATORIOS], char nombre_buscado[MAX_NOMBRE], int inicio, int fin){
    //condición de corte (si no está en el vector o si lo encontré)
    if(inicio > fin) {
        return NO_ENCONTRADO;
    }
    int centro = (inicio + fin) / 2;
    if(strcmp(laboratorios[centro].nombre, nombre_buscado) == 0){
        return centro;
    }

    // si donde estoy es menor
    if(strcmp(laboratorios[centro].nombre, nombre_buscado) < 0){
        return posicion_laboratorio_rec(laboratorios, nombre_buscado, centro + 1, fin);
    }
    // si donde estoy es mayor
    else {
        return posicion_laboratorio_rec(laboratorios, nombre_buscado, inicio, centro - 1);
    }
}

int posicion_laboratorio(laboratorio_t laboratorios[MAX_LABORATORIOS], int cantidad_laboratorios, char nombre_buscado[MAX_NOMBRE]){
    posicion_laboratorio_rec(laboratorios, nombre_buscado, 0, cantidad_laboratorios - 1);
}



void cambiar_nombre_laboratorio(laboratorio_t laboratorios[MAX_LABORATORIOS], int posicion, char nombre_nuevo[MAX_NOMBRE]){
    strcpy(laboratorios[posicion].nombre, nombre_nuevo);
}


int main() {
    laboratorio_t laboratorios[MAX_LABORATORIOS];
    int cantidad_laboratorios = 0;
    inicializar_laboratorios(laboratorios, &cantidad_laboratorios);
    mostrar_laboratorios(laboratorios, cantidad_laboratorios);
    printf("\n\n\n\n");

    int posicion = posicion_laboratorio(laboratorios, NOMBRE_BUSCADO, cantidad_laboratorios);

    cambiar_nombre_laboratorio(laboratorios, posicion, NOMBRE_NUEVO);

    mostrar_laboratorios(laboratorios, cantidad_laboratorios);

    return 0;
}