## Compañeros de Bolos

Luego de haber ganado el torneo, los "Compañeros de Bolos" siguieron practicando pero sin el Señor Burns. 

Una noche, después de intenso entrenamiento, Homero, Moe y Apu quieren sumar sus puntajes para ver el desempeño del equipo pero estan muy cansados para poder hacerlo. 

Ayudalos implementando un procedimiento que les diga el puntaje del equipo.

* Implementar el procedimiento `'imprimir_puntaje'`, la cual reciba tres números e imprima por pantalla el resultado de la suma de estos.

Ejemplos:

* Si se recibe 15, 18 y 17, debe imprimirse "50".
* Si se recibe 21, 20 y 24, debe imprimirse "65".

```c
#include <stdio.h>

void imprimir_puntaje(/*Aca deberias recibir los parametros */
						int numero1, int numero2, int numero3) {
    // Aqui va tu codigo…

	int suma = numero1 + numero2 + numero3;
	printf("%d", suma);
}

int main(){
    int puntaje_homero;
	scanf("%i", &puntaje_homero);
	int puntaje_moe;
	scanf("%i", &puntaje_moe);
	int puntaje_apu;
	scanf("%i", &puntaje_apu);

    imprimir_puntaje(/*Aca deberias enviar los parametros */
						puntaje_homero, puntaje_apu, puntaje_moe);

    return 0;
}
```

## La tierra de Tommy y Daly

Todos saben que la apertura del parque de diversiones de Tomy y Daly no fue la mejor. 

Es por esto que para atraer mas gente decidieron sacar una nueva promoción. 

La oferta consiste en que todos los menores de 10 años pueden entrar gratis. 

Para poder distinguir esto, se somete a los chicos a una simple prueba: se les pide que digan el primer número que le viene a la mente. 

Como todo el mundo sabe, los chicos solo saben contar del 1 al 10 (inclusive), por lo que si su número cae por fuera de este rango, significa que deberá pagar la entrada.

Implementar la función `'es_adulto'` la cual dado un número entero devuelva `'true'` si este es igual/menor a cero o mayor a 10, y devuelva `'false'` en caso contrario.

```c
#include <stdio.h>
#include <stdbool.h>

bool es_adulto(/*Aca deberias recibir los parametros */
                int numero) {
    // Aqui va tu codigo…
    bool res;
    if(numero <= 0 || numero > 10){
        res = true;
    } else {
        res = false;
    }

    return res;
}
```

## La escopeta maquilladora

Homero sigue trabajando en su proyecto millonario: la escopeta maquilladora. 

Para que el proceso de maquillado resulte menos doloroso, desarrolló un Regulador que reduce la fuerza del disparo. 

Aunque no logró eliminar por completo el dolor, sí consiguió disminuirlo significativamente, por lo que quiere medir los efectos de su nueva creación.

Para esto, creó una escala según la fuerza con la que el disparo golpea al momento del impacto:

`Excelente (A)`: si la fuerza reducida es menor o igual a 10.

`Bueno (B)`: si la fuerza reducida es mayor a 10 y menor o igual a 40.

`Malo (C)`: si la fuerza reducida es mayor a 40 y menor o igual a 70.

`Pésimo (D)`: si la fuerza reducida es mayor a 70.

Hay que ayudar a Homero a calcular la calidad de su Regulador según la fuerza con la que golpea el disparo. 

Dado que el cálculo de la fuerza reducida es demasiado complicado, él ya nos dejó una función que lo calcula por nosotros.

Implementar la función `calcular_calidad_regulador`, la cual, dada la fuerza del disparo inicial, devuelve el nivel correspondiente en la escala de calidad.

```c
#include "solucion.h"
// Aqui van las constantes…
#define AMORTIGUAMIENTO 3

#define EXCELENTE 'A'
#define BUENO 'B'
#define MALO 'C'
#define PESIMO 'D'

int fuerza_amortiguada(int fuerza_inicial) {
    return (fuerza_inicial / AMORTIGUAMIENTO);
}

char  calcular_calidad_regulador(int fuerza_inicial) {
    // Aca deberias hacer la llamada a la funcion ´fuerza_amortiguada´.
    int fuerza_reducida = fuerza_amortiguada(fuerza_inicial);
    
    // Aqui va tu codigo…

    char res;

    if(fuerza_reducida <= 10){
        res = EXCELENTE;
    } else if (fuerza_reducida > 10 && fuerza_reducida <= 40){
        res = BUENO;
    } else if (fuerza_reducida > 40 && fuerza_reducida <= 70){
        res = MALO;
    } else if (fuerza_reducida > 70){
        res = PESIMO;
    }

    return res;
}
```

## La venganza de Bob Patiño

Luego de salir de la cárcel, Bob Patiño ideó un plan para poder atrapar a Bart y cumplir su objetivo. 

El plan consiste en atacar el día que bart vuelve solo del colegio para así interceptarlo sin que nadie pueda verlo. 

Él sabe que los dias que Bart vuelve sin compañía son los días lunes, miércoles, viernes y domingo. 

Además, luego de tantos intentos fallidos, Bob quiere que todo salga perfecto por lo que como mínimo debe haber descansado 8 horas ese día para asegurarse que salga según lo planeado.

Implementar la función vuelve_solo, que según un caracter devuelva `true` si ese día Bart vuelve solo o `false` en caso contrario.

Implementar la función `puede_atacar`, la cual recibe un caracter que representa el día de la semana y las horas que Bob descansó, devolviendo `true` si Bart vuelve solo ese día y Bob descansó 8 horas o más.

Los días están representados con los siguientes caracteres:

```
Lunes (L).
Martes (M).
Miércoles (X).
Jueves (J).
Viernes (V).
Sábado (S).
Domingo (D).
```

```c
#include <stdio.h>
#include <stdbool.h>

#define LUNES 'L'
#define MARTES 'M'
#define MIERCOLES 'X'
#define JUEVES 'J'
#define VIERNES 'V'
#define SABADO 'S'
#define DOMINGO 'D'

bool vuelve_solo(char dia) {
	// Aquí va tu código

	bool res = false;
	if(dia == LUNES || dia == MIERCOLES || dia == VIERNES || 
		dia == DOMINGO){
			res = true;
	}
	return res;
}

bool puede_atacar(char dia, int horas_dormidas) {
	// Aquí va tu código
	// (deberías hacer la llamada a la función vuelve_solo)	

	bool res = vuelve_solo(dia) && horas_dormidas >= 8;
	
	return res;
}
```

## El castigo de Bart

En la escuela, Bart se encuentra en detención luego de ser atrapado haciendo una de sus bromas. 

Como es costumbre, Bart debe escribir en todos los pizarrones del colegio la siguiente frase: **"Aguante Fundamendez"**

Como Bart se encuentra cansado, te pide ayuda para poder completar este castigo. 

Un detalle a tener en cuenta, es que hay algunas aulas las cuales se encuentran cerradas con llave o ya fueron escritos sus pizarrones, casos en los cuales no tendría que hacer nada.

Se pide:

Implementar un procedimiento que dado por parámetro el estado del pizarrón, lo escriba (`E`) en caso de que este se encuentre vacío (`V`). 

Los estados posibles son:
* El pizarrón ya está escrito (E).
* El pizarrón se encuentra vacío (V).
* El aula se encuentra cerrada (C).

Pensá cómo debería pasarse y recibir el parámetro del estado al procedimiento ‘`intentar_escribir_pizarron`’ para que el cambio que hagas en este se pueda ver “por fuera” cuando termine de ejecutarse el procedimiento.

```c	
#include <stdio.h>
// Aqui van las constantes...

#define ESCRITO 'E';
#define VACIO 'V'
#define CERRADA 'C'

void intentar_escribir_pizarron(/*Aca deberias recibir la posicion */
                                char* estado_pizarron) {
    // Aqui va tu codigo...

    if (*estado_pizarron == VACIO){
        *estado_pizarron = ESCRITO;
    }
}
```

## Sigue la rosquilla

En la planta nuclear, Karl y Lenny estan jugando al típico juego de los magos de esconder una pelota debajo de un vaso y mezclarlo junto con otros vasos durante un receso. 

Solo que su versión del juego es mucho más rica, ya que esconden una rosquilla en vez de una pelota. 

Si el que elige encuentra la rosquilla se la puede comer, sino, se la queda el que mezcló. 

Después de un par de rondas están un poco demasiado llenos como para mezclar, así que te pidieron implementar un algoritmo que lo realice.

Implementar un procedimiento que dado tres cajas realice la mezcla. 

Cada caja va a ser pasada por referencia y guardan un char que representa si tiene una roquilla(`R`) o si está vacía (`V`). 

El algoritmo para mezclar sigue las siguientes reglas:

* Si la roquilla estaba en la primera caja, esta pasa a estar en la tercera.
* Si la roquilla estaba en la segunda caja esta pasa a estar en la primera.
* Si la roquilla estaba en la tercera caja, esta pasa a estar en la segunda.

Por ejemplo:

```
Entrada: VRV
Salida: RVV
```

```c
#include <stdio.h>
// Aqui van las constantes...

#define ROSQUILLA 'R'
#define VACIA 'V'

void mezclar_cajas(char* primer_caja, char* segunda_caja, char* tercera_caja) {
    // Aqui va tu código...

    if(*primer_caja == ROSQUILLA){
        *tercera_caja = ROSQUILLA;
        *primer_caja = VACIA;
    } else if(*segunda_caja == ROSQUILLA){
        *primer_caja = ROSQUILLA;
        *segunda_caja = VACIA;
    } else {
        *segunda_caja = ROSQUILLA;
        *tercera_caja = VACIA;
    }
}
```

## Apuestas intergalácticas

Kang y Kodos están apostando su dinero intergalactico en adivinar cuantas Duff tomará Barney esta noche en el bar de Moe, el que gana se lleva 10 dolares intergalácticos del que pierde. 

Si hay empate el dinero de ambos está a salvo.

Implementar una función que dadas el dinero de Kang, el dinero de Kodos y la cantidad de Duff que tomó Barney esa noche modifique ambas reservas según corresponda. 

Tener en cuenta que:
* Si Barney tomó más de 10 Duff, Kodos le da 10 dolares intergalácticos Kang.
* Si Barney tomó menos de 10 Duff, Kang le da 10 dolares intergalácticos a Kodos.
* Si tomó exactamente 10 Duff, entonces no pasa nada.
* En caso que el perdedor tenga menos de 10 dolares intergalácticos, deberá darle todo lo que pueda hasta llegar a 0.

```c
#include <stdio.h>
// Aqui van las constantes...

#define APUESTA 10

void realizar_apuesta(int* dinero_kang, int* dinero_kodos, int duff_tomadas) {
    // Aqui va tu codigo...

    if (duff_tomadas > 10){
        if(*dinero_kodos >= APUESTA){
            *dinero_kang += APUESTA;
            *dinero_kodos -= APUESTA;
        } else {
            *dinero_kang += *dinero_kodos;
            *dinero_kodos = 0;
        }
    }
    if (duff_tomadas < 10){
        if(*dinero_kang >= APUESTA){
            *dinero_kang -= APUESTA;
            *dinero_kodos += APUESTA;
        } else {
            *dinero_kodos += *dinero_kang;
            *dinero_kang = 0;
        }
    }
}
```

## Cambios de humor

Marge y sus hermanas (Paty y Selma) atraviesan varios cambios de humor a lo largo de un año según las estaciones. 

Según su madre, por cada estación cada una pasa por un humor diferente:

* `Primavera (P)`: Marge y Paty están contentas, mientras que Selma está meh.
* `Verano (V)`: Selma está triste, Marge está meh y Paty está contenta.
* `Otoño (O)`: las tres hermanas están contentas (obvio, si es la mejor estación).
* `Invierno (I)`: Selma está contenta, Marge está meh y Paty está triste.

Implementar una función que dada la estación del año modifique el humor de cada hermana al correspondiente, y devuelva la cantidad de hermanas que están contentas.

Tener en cuenta que cada humor está representado por un caracter:
* `Contenta (C)`
* `Meh (M)`
* `Triste (T)`

```c
#include <stdio.h>
// Aqui van las constantes…

#define CONTENTA 'C'
#define MEH 'M'
#define TRISTE 'T'

#define PRIMAVERA 'P'
#define VERANO 'V'
#define OTONIO 'O'
#define INVIERNO 'I'

int definir_humor(char* humor_marge, char* humor_paty, char* humor_selma, char estacion){
    // Aqui va tu código...

    int res;

    switch(estacion){
        case PRIMAVERA:
            *humor_marge = CONTENTA;
            *humor_paty = CONTENTA;
            *humor_selma = MEH;
            res = 2;
            break;
        case VERANO:
            *humor_selma = TRISTE;
            *humor_marge = MEH;
            *humor_paty = CONTENTA;
            res = 1;
            break;
        case OTONIO:
            *humor_selma = CONTENTA;
            *humor_marge = CONTENTA;
            *humor_paty = CONTENTA;
            res = 3;
            break;
        case INVIERNO:
            *humor_selma = CONTENTA;
            *humor_marge = MEH;
            *humor_paty = TRISTE;
            res = 1;
            break;
        default:
            break;
    }

    return res;
}
```