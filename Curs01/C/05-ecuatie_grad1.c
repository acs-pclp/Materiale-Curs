/* Programarea Calculatoarelor CA, 2019-2020

   Programul rezolva o ecuatie de gradul I : ax + b = 0 */

#include <stdio.h>
#include <math.h>  // pentru functia fabs(modulul numerelor reale)

int main() {
    double a, b, x, eps;
    /* eps este eroarea pe care o folosim cand comparam numere reale (float, double) 
       vom considera ca x == y, daca |x - y| < eps (ex: eps = 0.0001)  */
    scanf("%lf%lf", &a, &b);
    eps = 0.0001;

    // a = 0
    if (fabs(a - 0) < eps) {
        // b = 0
        if (fabs(b - 0) < eps) {
            printf("Ecuatia are un numar infinit de solutii reale\n");
        } else { // b != 0
            printf("Ecuatia nu are nici o solutie reala\n");
        }
    } else { // a != 0
        x = -b / a;
        printf("x = %lf\n", x);
    }
    return 0;
}

/* compile: gcc 05-ecuatie_grad1.c -o ecuatie1
   run    : ./ecuatie1

   Exemplu:

   input:
   0 5
   output:
   Ecuatia nu are nici o solutie reala

   input:
   0 0
   output:
   Ecuatia are un numar infinit de solutii reale

   input:
   4 10
   output:
   x = -2.5   */
