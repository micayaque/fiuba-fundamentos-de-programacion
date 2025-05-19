## El olvido de Homero

Homero Simpson estaba saliendo de su auto cuando, por accidente, se golpeó la cabeza con la puerta.

El golpe fue tan fuerte que su memoria se reinició y olvidó qué es lo que siempre dice en estas situaciones.

Crear un programa que imprima por pantalla la expresión que Homero utiliza en estos casos. 
(Ayuda: Empieza con D).

```c
#include <stdio.h>

int main(){
	// Aqui va tu codigo…
	printf("D'oh!");
	return 0;
}
```

## Marge preocupada

Marge Simpson está preocupada porque se hace tarde y Homero no regresa de la taberna de Moe.

Este suceso está haciendo que, cada vez que se toca la cabeza, se le caigan 78 pelos.

Crear un programa que, dadas las veces que Marge se tocó la cabeza, imprima por pantalla cuántos pelos perdió.

```c
#include <stdio.h>
// Aquí deberías definir una constante...
#define PELOS_QUE_PIERDE 78

int main(){
	int veces;
	scanf("%i", &veces);
	// Aquí va tu código…

	printf("%d pelos.\n", veces * PELOS_QUE_PIERDE);

	return 0;
}
```

## Los cachorros del señor Burns

El perro de los Simpson, Huesos, tuvo 25 cachorros. 

Como la familia Simpson no puede cuidarlos, el Sr. Burns accede a hacerse cargo de ellos (son geniales para hacer abrigos de piel!).

Burns le pidió a Smithers que se encargue de comprarle alimento balanceado a los cachorros para la cena de hoy. 

El problema es que a Smithers se le complica sacar cuentas sobre cuántas bolsas debe comprar para que alcance para todos, por lo que le pidió ayuda a la facultad de ingeniería.

Teniendo en cuenta que cada bolsa rinde para `5` cachorros, se pide:

Crear un programa que de acuerdo a la cantidad de cachorros que querrán cenar, imprima por pantalla cuántas bolsas de alimento balanceado Smithers tendrá que comprar.

```c
#include <stdio.h>

int main(){
	int cachorros;
	scanf("%i", &cachorros);
	// Aquí va tu código…

	float bolsas = (float) cachorros / 5;
	int bolsas_redondeado = (int)bolsas;
	if ((float)bolsas_redondeado < bolsas) {
    	bolsas_redondeado += 1;
	}

	printf("%d bolsas.", bolsas_redondeado);

	return 0;
}
```

## En busca del tesoro

Los Simpsons se perdieron en una cueva intentando encontrar un tesoro que le perteneció a Snake. 

Afortunadamente, Lisa posee anotaciones en su cuaderno que indican el camino al tesoro, pero se encuentran cifradas.

Haciendo memoria de los libros que leyó acerca de cartógrafía y lingüistíca, Lisa tendrá que guiar a su familia hacia el tesoro.

Crear un programa que dado `un caracter` que representa cifrado del cuaderno de Lisa, imprima por pantalla qué camino deben tomar.

Se espera entonces que:
* Si recibe una `I (izquierda)` se imprima: **“Por la izquierda!”**.
* Si recibe una `D (derecha)` se imprima: **“Por la derecha!”**.
* Si recibe otra letra, es porque encontraron el tesoro y debe imprimirse: **“Tesoro!”**.

```c	
#include <stdio.h>

// Aquí deberías definir las constantes para las opciones...
#define IZQUIERDA 'I'
#define DERECHA 'D'

int main(){
	char cifrado;
	scanf(" %c", &cifrado);

// Aquí va tu código. Lisa debe seleccionar un camino, por lo que deberías usar una estructura selectiva…
	if (cifrado == IZQUIERDA) {
		printf("Por la izquierda!\n");
	} else if (cifrado == DERECHA) {
		printf("Por la derecha!\n");
	} else {
		printf("Tesoro!\n");
	}

	return 0;
}
```

## Bart y Milhouse en la escuela

Bart y Milhouse se dieron cuenta que no hay ninguna chance de que aprueben todas las materias que les corresponden, por lo que llegaron a un acuerdo con sus padres.

Entre los dos deben poder aprobar un total de `20 materias`.

Crear un programa que, a partir de la cantidad de materias aprobadas por cada uno, imprima por pantalla **“Lo logramos!!!”** si entre los dos lograron llegar a `20` o **“Skinner ganó esta vez!”** en caso contrario.

```c
#include <stdio.h>

int main(){
	int cantidad_bart;
	int cantidad_milhouse;
	scanf("%i", &cantidad_bart);
	scanf("%i", &cantidad_milhouse);
	// Aquí va tu código…
	if (cantidad_bart + cantidad_milhouse >= 20) {
		printf("Lo logramos!!!\n");
	} else {
		printf("Skinner ganó esta vez!\n");
	}
	return 0;
}
```

## Sorteo de vacaciones 1

Patty y Selma tienen ganas de irse de vacaciones, pero no se deciden ni cuándo ni a dónde ir. 

Por esta razón, acordaron sortear la época en la que irán (`Enero (E)` o `febrero (F)`), y el paisaje que tendrán a la vista (`Montaña (M)` o `playa (P)`). 

De acuerdo a lo que salga, una de las dos elegirá el destino.

* Crear un programa que a partir de los resultados del sorteo, imprima por pantalla **“Selma”** si le toca elegir a ella, o **“Patty”** en caso contrario.

Selma elige cuando el mes es Enero y la vista es Montaña o cuando el mes es Febrero y la vista Playa. 

En otro caso, elige Patty.

Ejemplo:
```
	enero
	si es montaña elige Selma
	si es playa elige Patty
```

```c	
#include <stdio.h>
// Aqui deberias definir las constantes…
#define ENERO 'E'
#define FEBRERO 'F'

#define MONTAÑA 'M'
#define PLAYA 'P'

int main(){
	char epoca;
	char paisaje;
	scanf(" %c", &epoca);
	scanf(" %c", &paisaje);
	// Aqui va tu codigo…
	if (epoca == ENERO && paisaje == MONTAÑA) {
		printf("Selma\n");
	} else if (epoca == FEBRERO && paisaje == PLAYA) {
		printf("Selma\n");
	} else {
		printf("Patty\n");
	}

	return 0;
}
```

## Sorteo de vacaciones 2

Una vez que Patty y Selma por fin tienen un destino a donde ir, decidieron contarle a su hermana Marge. 

Al escuchar los planes, se quiso sumar a sus vacaciones. 

Pero no le convencía el destino, por lo que tuvieron que hacer el sorteo nuevamente. 

Y para ser justos y que cada una tenga la posibilidad de elegir, incorporaron como opción el mes de marzo y la vista de una laguna.

En esta oportunidad elige:
* Patty: Si el mes es enero y la vista es laguna, si el mes es marzo y la vista es playa, o si el mes es febrero y la vista es montaña.
* Selma: Si el mes es marzo y la vista es laguna, si el mes es febrero y la vista es playa, o si el mes es enero y la vista es montaña.
* Marge: Si el mes es febrero y la vista es laguna, si el mes es enero y la vista es playa, o si el mes es marzo y la vista es montaña.

* Imprimir por pantalla “Patty”, “Selma” o “Marge” según a quien le toque elegir esta vez.

* Convenciones:
Enero(E), febrero(F), marzo(X), playa(P), montaña (M), laguna (L).

```c
#include <stdio.h>
// Aquí deberias definir las constantes…

#define ENERO 'E'
#define FEBRERO 'F'
#define MARZO 'X'

#define PLAYA 'P'
#define MONTAÑA 'M'
#define LAGUNA 'L'

int main(){
    char epoca;
    char paisaje;
    scanf(" %c", &epoca);
    scanf(" %c", &paisaje);
    // Aqui va tu codigo donde deberias usar un switch…

    if((epoca == ENERO && paisaje == LAGUNA) || 
        (epoca == MARZO && paisaje == PLAYA) || 
            (epoca == FEBRERO && paisaje == MONTAÑA)){
                printf("Patty\n");
    }
    if((epoca == MARZO && paisaje == LAGUNA) || 
        (epoca == FEBRERO && paisaje == PLAYA) || 
            (epoca == ENERO && paisaje == MONTAÑA)){
                printf("Selma\n");
    }
    if((epoca == FEBRERO && paisaje == LAGUNA) || 
        (epoca == ENERO && paisaje == PLAYA) || 
            (epoca == MARZO && paisaje == MONTAÑA)){
                printf("Marge\n");
    }
        
	return 0;
}
```

## El castigo de Bart

Bart Simpson suele portarse mal siempre que va al colegio, por lo que casi siempre le toca cumplir con el mismo castigo, llenar pizarrones con la misma frase una y otra vez.

Para agilizar el castigo Bart necesita un programa que imprima por pantalla **“No debo patinar en las aulas.”** las veces necesarias.

(https://www.youtube.com/watch?v=Y4ceuJYZBB4).

Si se recibe 4, debe imprimirse:
* **No debo patinar en las aulas.**
* **No debo patinar en las aulas.**
* **No debo patinar en las aulas.**
* **No debo patinar en las aulas.**

```c
#include <stdio.h>

int main(){
	int veces_necesarias;
	scanf("%i", &veces_necesarias);
	// Aqui va tu codigo donde deberias usar un while..

	for(int i=0; i<veces_necesarias; i++){
		printf("No debo patinar en las aulas.\n");
	}

	return 0;
}
```

## Haz la tarea

Homero Simpson está intentando que Bart haga su tarea, pero Bart aprovecha para molestarlo repitiendo lo que dice en un tono más fuerte. 

Lisa, sorprendida, decide contar cuántas veces se repitió este diálogo entre los dos. 

Por eso se pide:

* Imprimir por pantalla esta discusión, sabiendo la cantidad total que contó Lisa.

Ejemplos:

* Si se recibe 1, debe imprimirse:
```	
Haz la tarea
Haz la tarea!
```

* Si se recibe 2, debe imprimirse:
```	
Haz la tarea
Haz la tarea!
Haz la tarea!!
Haz la tarea!!!
```

```c
#include <stdio.h>

int main(){
	int veces_repetidas;
	scanf("%i", &veces_repetidas);
	// Aqui va tu codigo...

	for(int i=0; i<veces_repetidas*2; i++){
		printf("Haz la tarea");

		for(int j=0; j<i; j++){
			printf("!");
		}

		printf("\n");
	}

	return 0;
}
```

## Cletus y sus hijos

Cletus tiene 31 hijos (https://www.youtube.com/watch?v=9bEvqAG2nDo) y tiene que decirles que se vayan a dormir uno por uno.

* Imprimir por pantalla la frase **"Es hora de ir a dormir, mañana hay que ordeñar las vacas!"**, según la cantidad de veces recibida que la dijo.

```c	
#include <stdio.h>

int main(){
	int cantidad_repetidas;
	scanf("%i", &cantidad_repetidas);
	// Aqui va tu codigo donde deberias usar un for..

	for(int i=0; i<cantidad_repetidas; i++){
		printf("Es hora de ir a dormir, mañana hay que ordeñar las vacas!\n");
	}

	return 0;
}
```