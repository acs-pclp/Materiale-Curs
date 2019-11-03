/* Programarea Calculatoarelor CA, 2019-2020

   Programul verifica daca un numar se afla intr-un interval  */

#include <stdio.h>

int main() {
    double a, b, x;
    char stanga, dreapta;  /* variabilele stanga si dreapta vor defini
                              tipul de interval(deschis sau inchis)
                              d - interval deschis
                              i - interval inchis                    */
    int ok_stanga = 0, ok_dreapta = 0;

    scanf("%lf%lf%lf\n", &a, &b, &x);
    scanf("%c %c", &stanga, &dreapta);

    if (stanga == 'i') {
        if (x >= a) {
            ok_stanga = 1;
        }
    } else {
        if (x > a) {
            ok_stanga = 1;
        }
    }

    if (dreapta == 'i') {
        if (x <= b) {
            ok_dreapta = 1;
        }
    } else {
        if (x < b) {
            ok_dreapta = 1;
        }
    }

    if (ok_stanga && ok_dreapta) {
        printf("Numarul apartine intervalului\n");
    } else {
        printf("Numarul nu se afla in interval\n");
    }

    return 0;
}

/* compile: gcc 01-apartenenta_interval.c -o apartenenta_interval
   run    : ./apartenenta_interval

   Exemplu: apartenenta_interval
   input : 2 7
           5
           d i
   output: Numarul apartine intervalului

   input : 2 7
           9
           i i
   output: Numarul nu se afla in interval

   input : 2 7
           7
           i d
           Numarul nu se afla in interval   */
