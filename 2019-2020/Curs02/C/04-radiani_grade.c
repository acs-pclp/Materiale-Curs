/* Programarea Calculatoarelor CA, 2019-2020

   Programul transforma o valoare din radiani in grade
   !!! Programul functioneaza doar pentru valori >= 0 !!! */

#include <stdio.h>
#include <math.h> // pentru a folosi M_PI

int main() {
    double radiani, grade, minute, secunde, sutimi;
    scanf("%lf", &radiani);

    /* pi (radiani) = 180 (grade) => daca n este valoarea in radiani a unui
       unghi, valoarea unghiului in grade = n * 180 / pi */
    grade = radiani * 180 / M_PI;

    /*  Introducem notiunea de cast = converteste o variabila dintr-un tip
        de date in altul. Se foloseste punand tipul de date pe care vrem
        sa il obtinem in paranteze rotunde inaintea variabilei.
        De exemplu : double a, b;
                    a = 14.53;
                    b = (int) a; => b = 14.00 (b este in continuare double)
        Se realizeaza cast automat in urmatoarea situatie:
            int a;
            double b = 12.486;
            a = b; => a = 12 (se realizeaza cast automat din double in int)

        Pentru un numar n, vom folosi cast pentru a afla:
            - partea intreaga: (int) n
            - partea zecimala: n - (int) n;  */

    minute = (grade - (int) grade) * 60;
    grade = (int) grade;

    secunde = (minute - (int) minute) * 60;
    minute = (int) minute;

    sutimi = (secunde - (int) secunde) * 100;
    secunde = (int) secunde;

    printf("%d grade %d minute %d secunde %d sutimi de secunda\n",
        (int) grade, (int) minute, (int) secunde, (int) sutimi);

    return 0;
}

/*  compile: gcc 04-radiani_grade.c -o radiani_grade -lm
    run    : ./radiani_grade

    Exemplu:
    input : 20
    output: 1145 grade 27 minute 16 secunde 36 sutimi de secunda

    input : 3.1415926535
    output: 179 grade 55 minute 39 secunde 28 sutimi de secunda
    (eroare de aproximare)                                       */
