#include <stdio.h>

const int MIN_NOTA_APROBADO = 4;
const int MAX_NOTA_APROBADO = 10;

int main() {
   int nota = MIN_NOTA_APROBADO;

   if(nota = MAX_NOTA_APROBADO) {
      printf("APROBASTEEE!!! Sacaste la mayor calificación!\n");
   } else if (nota < MIN_NOTA_APROBADO) {
      printf("No aprobaste :(\n");
   } else {
      printf("Aprobasteee\n");
   }

   return 0;
}