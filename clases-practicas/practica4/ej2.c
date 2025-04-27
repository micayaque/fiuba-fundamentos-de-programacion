#include <stdio.h>
#include <stdbool.h>

typedef struct medicion {
	int id;
	bool es_estable;
	int nivel_oxigeno;
} medicion_t;

bool es_habitable(medicion_t* mediciones[], int tope){
	if(tope == 1){
		return (mediciones[0]->es_estable && mediciones[0]->nivel_oxigeno > 100
		| !(mediciones[0]->es_estable));
	}
    medicion_t actual = *mediciones[tope - 1];
	return (actual.es_estable && actual.nivel_oxigeno > 100 | !(actual.es_estable)) && es_habitable(mediciones, tope-1);
}