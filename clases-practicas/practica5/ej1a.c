#include <stdio.h>
#include <stdbool.h>
#include <string.h>

const char* DESCRIPCION_CTRL = "ctrl";
const char* DESCRIPCION_SHIFT = "shift";
#define MAX_NOMBRE 30
#define MAX_TECLAS 50
#define MAX_COMPUS 20

typedef struct tecla{
	char descripcion[MAX_NOMBRE];
	bool esta_rota;
} tecla_t;

typedef struct compu{
	tecla_t teclado[MAX_TECLAS];
	int cantidad_teclas;
	int id;
} compu_t;

typedef struct laboratorio{
	char nombre[MAX_NOMBRE];
	compu_t computadoras[MAX_NOMBRE];
	int cantidad_compus;
} laboratorio_t;


int cantidad_teclas_buenas(tecla_t teclado[MAX_TECLAS], int cantidad_teclas){
	int contador = 0;
	for (int i = 0; i < cantidad_teclas; i++){
		if (!teclado[i].esta_rota){
			contador++;
		}
	}
	return contador;
}



bool andan_teclas_importantes(tecla_t teclado[MAX_TECLAS], int cantidad_teclas){
	bool shift_anda = false;
	bool ctrl_anda = false;
	int i = 0;

	while((i < cantidad_teclas) && (!(shift_anda && ctrl_anda))){
		if ((strcmp(teclado[i].descripcion, DESCRIPCION_SHIFT) == 0) && !(teclado[i].esta_rota)){
			shift_anda = true;
		}
		else if ((strcmp(teclado[i].descripcion, DESCRIPCION_CTRL) == 0) && !(teclado[i].esta_rota)){
			ctrl_anda = true;
		}
		i++;
	}

	return (shift_anda && ctrl_anda);
}

int id_mejor_computadora(laboratorio_t laboratorio){
	int id_mejor_compu = -1;
	int maximo_teclas_buenas = -1;

	for (int i = 0; i < laboratorio.cantidad_compus; i++){
		compu_t compu_actual = laboratorio.computadoras[i];
		int cantidad_actual = cantidad_teclas_buenas(compu_actual.teclado, compu_actual.cantidad_teclas);
		bool andan_teclas = andan_teclas_importantes(compu_actual.teclado, compu_actual.cantidad_teclas);
		if (andan_teclas && (cantidad_actual > maximo_teclas_buenas)){
			id_mejor_compu = compu_actual.id;
			maximo_teclas_buenas = cantidad_actual;
		}
	}

	return id_mejor_compu;
}
