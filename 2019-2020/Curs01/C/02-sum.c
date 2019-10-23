/* Programarea Calculatoarelor CA, 2019-2020

   Programul calculeaza suma a 2 numere si afiseaza rezultatul 
   in baza 10 si in baza 16 */

#include <stdio.h>

int main() {
    int a, b, sum;
    scanf("%d%d", &a, &b);

    sum = a + b;

    // %d se foloseste pentru afisarea unui intreg in baza 10
    printf("Baza 10: %d\n", sum);
    // %X se foloseste pentru afisarea unui intreg in baza 16 (litere mari)
    printf("Baza 16: %X\n", sum);
    // %x se foloseste pentru afisarea unui intreg in baza 16 (litere mici)
    printf("Baza 16: %x\n", sum);
    return 0;
}

/* compile: gcc 02-sum.c -o sum
   run    : ./sum

   Exemplu:

   input:
   3 8
   output:
   Baza 10: 11
   Baza 16: B  
   Baza 16: b  */
