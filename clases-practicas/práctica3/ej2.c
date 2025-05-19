#include <stdio.h>
#include <stdbool.h>

#define MAX_FIL 5
#define MAX_COL 5

#define DERECHA 'D'
#define IZQUIERDA 'A'
#define ARRIBA 'W'
#define ABAJO 'S'

const char TIERRA = 'T';
const char RASTRILLO = 'R';
const char BOB = 'B';
const int POS_NO_VALIDA = -1;

void crear_terreno(char terreno[MAX_FIL][MAX_COL]){
    char temp[MAX_FIL][MAX_COL] = {
        {'T', 'T', 'T', 'R', 'R'},
        {'T', 'T', 'R', 'T', 'R'},
        {'T', 'R', 'R', 'T', 'T'},
        {'R', 'T', 'T', 'R', 'B'},
        {'T', 'T', 'R', 'T', 'T'}
    };
    for (int i = 0; i < MAX_FIL; i++) {
        for (int j = 0; j < MAX_COL; j++) {
            terreno[i][j] = temp[i][j];
        }
    }
}

// Crear una función que devuelva la cantidad de rastrillos que hay en el terreno.

// PRE: se supone que la matriz está llena hasta sus máximos.
// POST: 
int cantidad_rastrillos(char terreno[MAX_FIL][MAX_COL]){
    int cantidad_rastrillos = 0;

    for(int i=0; i<MAX_FIL; i++){
        for(int j=0; j<MAX_COL; j++){
            if(terreno[i][j] == RASTRILLO){
                cantidad_rastrillos++;
            }
        }
    }
    return cantidad_rastrillos;
}

void mostrar_terreno(char terreno[MAX_FIL][MAX_COL]){
    for(int i=0; i<MAX_FIL; i++){
        for(int j=0; j<MAX_COL; j++){
            printf(" %c ", terreno[i][j]);
        }
        printf("\n");
    }
}

// Crear una función que determine si Bob se puede mover a la derecha de donde está.
// PRE: se asume que la fila está dentro del terreno y la columna es mayor o igual a 0.
// POST: devuelve true si se puede mover a la derecha y false si no.
bool se_puede_mover_derecha(char terreno[MAX_FIL][MAX_COL], int fil_bob, int col_bob){
    if(col_bob + 1 >= MAX_COL){
        return false;
    }
    return terreno[fil_bob][col_bob + 1] != RASTRILLO;
}

// movimientos: w a s d
// TAREA: modularizar
bool se_puede_mover(char terreno[MAX_FIL][MAX_COL], int fil_bob, int col_bob, char movimiento){
    int nueva_fil = -1;
    int nueva_col = -1;
    switch(movimiento){
        case IZQUIERDA:
            if(col_bob - 1 < 0){
                return false;
            }
            return terreno[fil_bob][col_bob -1] != RASTRILLO;
        case DERECHA: 
            if(col_bob + 1 >= MAX_COL){
                return false;
            }
            return terreno[fil_bob][col_bob + 1] != RASTRILLO;
        case ARRIBA: 
            if(fil_bob - 1 < 0){
                return false;
            }

            return terreno[fil_bob - 1][col_bob] != RASTRILLO;
        case ABAJO: 
            if(fil_bob + 1 >= MAX_FIL){
                return false;
            }
            return terreno[fil_bob + 1][col_bob] != RASTRILLO;
    }
}


    // for(int i=0; i<MAX_FIL; i++){
    //     for(int j=0; j<MAX_COL; j++){
    //         if(terreno[i][j] == BOB){
    //             (*fil) = i;
    //             (*col) = j;
    //         }
    //         // NO PUEDO PONER UN RETURN
    //     }
    // }

// Los procedimientos se llaman con VERBOS EN INFINITIVO.
// PRE: se asume que la matriz está llena en su totalidad y que va a haber un bob en el terreno.
// POST: se almacena la posición de bob en las variables fil y col.
void buscar_bob(char terreno[MAX_FIL][MAX_COL], int* fil, int* col){
    // PARA NO RECORRER TODO, ME CONVIENE HACERLO CON WHILE
    int i = 0;
    int j = 0;
    bool encontrado = false;

    while(i < MAX_FIL && !encontrado){
        while(j < MAX_COL && !encontrado){
            if(terreno[i][j] == BOB){
                (*fil) = i;
                (*col) = j;
                encontrado = true;
            }
            j++;
        }
        i++;
        j=0;
    }
}


int main(){

    char terreno[MAX_FIL][MAX_COL];
    crear_terreno(terreno);

    mostrar_terreno(terreno);
    
    int fil_bob = POS_NO_VALIDA;
    int col_bob = POS_NO_VALIDA;
    buscar_bob(terreno, &fil_bob, &col_bob);

    if(se_puede_mover_derecha(terreno, fil_bob, col_bob)){
        printf("proceda\n");
    }
    else {
        printf("uy kieto\n");
    }



    // printf("La cantidad de rastrillos en el terreno es %i\n", cantidad_rastrillos(terreno));

}