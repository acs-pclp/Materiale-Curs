#!/usr/bin/env python3
"""
   Programarea Calculatoarelor CA, 2019-2020

   Programul rezolvă o ecuație de gradul II (ax^2 + bx + c = 0) presupunand ca a este diferit de 0.
   Exercitiu suplimentar: tratati cazul a cand a este 0 (ecuatie de gradul I)
"""

import math  # pentru sqrt()


def main():
    # eps este eroarea pe care o vom folosi la compararea numerelor reale
    eps = 0.0001

    # Citim primul rand din input (un șir de caractere), împărțim rezultatul după spațiu,
    # apoi transformăm fiecare componentă în numerăr real folosind map.
    # Rezultatul (2 numere reale, dacă input-ul este corect) se asignează variabilelor a, b și c.
    a, b, c = map(float, input().split())

    delta = b * b - 4 * a * c

    if abs(delta - 0) < eps:
        x = -b / 2 * a
        print('x1 = x2 = {}'.format(x))
    elif delta < 0:
        print('Ecuatia nu are solutii reale')
    else:
        x1 = (-b + math.sqrt(delta)) / (2 * a)
        x2 = (-b - math.sqrt(delta)) / (2 * a)
        print('x1={}\nx2={}'.format(x1, x2))


if __name__ == '__main__':
    main()

# rulare: ./06-ecuatie_gradul2.py sau python3 ./06-ecuatie_gradul2.py
# Pentru prima variantă, este necesar să avem drepturi de execuție asupra fișierului.
# Exemple:
#
# Input:
# -1 4 4
# Output:
# x1 = x2 = 2.0
#
# Input:
# 5 3 2
# Output:
# Ecuatia nu are solutii reale
#
# Input:
# -2 -7 5
# Output:
# x1=-4.10849528301415
# x2=0.6084952830141508
