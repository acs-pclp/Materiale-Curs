#!/usr/bin/env python3
"""
   Programarea Calculatoarelor CA, 2019-2020

   Programul transforma o valoare din radiani in grade.
   
   Se observa ca programul acesta obtine rezultate cu precizie mai mare decat cel scris in C.
"""

# Analog C, in Python putem avea biblioteci, numite pachete (packages).
# De exemplu, pachetul "math" este cel analog bibliotecii matematice din C.
# Spunem ca importam un pachet, folosind una din urmatoarele sintaxe:
# 1. "import <package>"
#       Importa pachetul fara a mentiona care sunt resursele folosite
#       (analog "#include <stdio.h>" din C), caz in care vom utiliza "package.function"
#       (exemplu: math.degrees - este identificatorul pentru functia degrees).
# 2. "from <package> import <function>"
#      Se va importa doar functiile specificate.
#      Exemplu: "from math import degrees", urmand ca functia sa se apeleze folosind
#      identificatorul "degrees".
import math

def main():
    print('Introduceti numarul de radiani:')

    # Citim numarul de radiani
    rad = float(input())

    # Transformam in grade, folosing functia degrees (rezultatul va fi de tip float)
    grd = math.degrees(rad)

    # Calculam numarul de grade, minute, secunde si sutimi de secunda
    # Folosim formulele potrivite si facem cast la int
    grade = int(grd)
    min = (grd - grade) * 60
    minute = int(min)
    sec = (min - minute) * 60
    secunde = int(sec)
    sutimi = int((sec - secunde) * 100)
    print('{} grade {} minute {} secunde {} sutimi'.format(grade, minute, secunde, sutimi))

if __name__ == '__main__':
    main()

# rulare: ./04-radiani_grade.py sau python3 04-radiani_grade.py sau python3 ./04-radiani_grade.py
# Pentru prima variantă, este necesar să avem drepturi de execuție asupra fișierului.
#
# Exemple:
#
# input : 20
# output: 1145 grade 54 minute 56 secunde 12 sutimi
#
# input : 3.1415926535
# output: 179 grade 59 minute 59 secunde 99 sutimi
