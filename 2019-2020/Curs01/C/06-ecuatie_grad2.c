/* Programarea Calculatoarelor CA, 2019-2020

   Programul rezolva o ecuatie de gradul 2 : a*x^2 + b*x + c = 0  */

#include <stdio.h>
#include <math.h>  // pentru functia sqrt(radical) si fabs(modul)

int main() {
    double a, b, c, x1, x2, eps = 0.0001;
    /* eps este eroarea pe care o folosim cand comparam numere reale (float, double) 
       vom considera ca x == y, daca |x - y| < eps (ex: eps = 0.0001)  */
    scanf("%lf%lf%lf", &a, &b, &c);

    /* Pentru ca ecuatia sa fie de gradul II consideram ca a este diferit de 0
       Exercitiu suplimentar: tratati cazul in care a = 0 (ecuatie de gradul I);  */

    double delta = b * b - 4 * a * c;

    if (delta < 0) {
        printf("Ecuatia nu are solutii reale\n");
    } else if (fabs(delta - 0) < eps) {
        /* <=> delta == 0, dar pentru numere reale nu putem
           pune conditia == 0, de asemenea pentru a obtine 
           modulul numerelor reale folosim functia fabs()  */
        x1 = x2 = -b / (2 * a);
        printf("x1 = x2 = %lf\n", x1);
    } else {
        // Ecuatia are 2 solutii reale
        x1 = (-b + sqrt(delta)) / (2 * a);
        x2 = (-b - sqrt(delta)) / (2 * a);

        printf("x1 = %lf\nx2 = %lf\n", x1, x2);
    }
    return 0;
}

/* compile: gcc 06-ecuatie_grad2.c -lm -o ecuatie2 
   (folosim flagul -lm pentru biblioteca math.h)
   run    : ./ecuatie2

   Exemplu 
   input:
   5 3 2
   output:
   Ecuatia nu are solutii reale

   input:
   -1 4 -4
   output:
   x1 = x2 = 2

   input:
   -2 -7 5
   output:
   x1 = -4.108495
   x2 = 0.608495    */
