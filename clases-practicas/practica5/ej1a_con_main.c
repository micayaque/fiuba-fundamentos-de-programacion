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


int cantidad_teclas_buenas(tecla_t teclado[MAX_TECLAS], int tope_teclas){
	if (tope_teclas == 0){
		return 0;
	}

	int contador = 0;
	for (int i = 0; i < tope_teclas; i++){
		if (!(teclado[i].esta_rota)){
			contador++;
		}
	}

	return contador;
}

bool teclas_andan(tecla_t teclado[MAX_TECLAS], int tope_teclas){
	bool ctrl_anda = false;
	bool shift_anda = false;

	int i = 0;

	while ((i < tope_teclas) && !(ctrl_anda && shift_anda)){
		tecla_t tecla = teclado[i];
		if ((strcmp(tecla.descripcion, DESCRIPCION_CTRL) == 0) && !(tecla.esta_rota))
			ctrl_anda = true;
		else if ((strcmp(tecla.descripcion, DESCRIPCION_SHIFT) == 0) && !(tecla.esta_rota))
			shift_anda = true;
		i++;
	}

	return (ctrl_anda && shift_anda);
}

int mejor_compu(laboratorio_t laboratorio){
	int id_mejor_computadora = -1;
	int maximo_teclas_buenas = 0;

	for (int i = 0; i < laboratorio.cantidad_compus; i++){
		compu_t compu_actual = laboratorio.computadoras[i];
		int cantidad_actual = cantidad_teclas_buenas(compu_actual.teclado, compu_actual.cantidad_teclas);
		bool andan_teclas_importantes = teclas_andan(compu_actual.teclado, compu_actual.cantidad_teclas);

		if ((cantidad_actual > maximo_teclas_buenas) && (andan_teclas_importantes)){
			id_mejor_computadora = compu_actual.id;
			maximo_teclas_buenas = cantidad_actual;
		}
	}
	return id_mejor_computadora;
}


int main() {
	laboratorio_t lab;
	strcpy(lab.nombre, "Lab Principal");
	lab.cantidad_compus = 3;


	lab.computadoras[0].id = 1;
	lab.computadoras[0].cantidad_teclas = 5;
	strcpy(lab.computadoras[0].teclado[0].descripcion, DESCRIPCION_CTRL);
	lab.computadoras[0].teclado[0].esta_rota = false;
	strcpy(lab.computadoras[0].teclado[1].descripcion, DESCRIPCION_SHIFT);
	lab.computadoras[0].teclado[1].esta_rota = false;
	strcpy(lab.computadoras[0].teclado[2].descripcion, "A");
	lab.computadoras[0].teclado[2].esta_rota = false;
	strcpy(lab.computadoras[0].teclado[3].descripcion, "B");
	lab.computadoras[0].teclado[3].esta_rota = false;
	strcpy(lab.computadoras[0].teclado[4].descripcion, "C");
	lab.computadoras[0].teclado[4].esta_rota = true;


	lab.computadoras[1].id = 2;
	lab.computadoras[1].cantidad_teclas = 4;
	strcpy(lab.computadoras[1].teclado[0].descripcion, DESCRIPCION_CTRL);
	lab.computadoras[1].teclado[0].esta_rota = false;
	strcpy(lab.computadoras[1].teclado[1].descripcion, "X");
	lab.computadoras[1].teclado[1].esta_rota = false;
	strcpy(lab.computadoras[1].teclado[2].descripcion, "Y");
	lab.computadoras[1].teclado[2].esta_rota = false;
	strcpy(lab.computadoras[1].teclado[3].descripcion, "Z");
	lab.computadoras[1].teclado[3].esta_rota = false;


	lab.computadoras[2].id = 3;
	lab.computadoras[2].cantidad_teclas = 3;
	strcpy(lab.computadoras[2].teclado[0].descripcion, DESCRIPCION_CTRL);
	lab.computadoras[2].teclado[0].esta_rota = false;
	strcpy(lab.computadoras[2].teclado[1].descripcion, DESCRIPCION_SHIFT);
	lab.computadoras[2].teclado[1].esta_rota = false;
	strcpy(lab.computadoras[2].teclado[2].descripcion, "Enter");
	lab.computadoras[2].teclado[2].esta_rota = true;

	int mejor_id = mejor_compu(lab);

	if (mejor_id != -1)
		printf("La mejor computadora es la ID %d\n", mejor_id);
	else
		printf("No hay computadora que cumpla con las condiciones.\n");

	return 0;
}