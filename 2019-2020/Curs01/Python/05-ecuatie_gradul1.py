#!/usr/bin/env python3
"""
   Programarea Calculatoarelor CA, 2019-2020

   Programul rezolvă o ecuație de gradul I:
   ax + b = 0
"""


def main():
    # Citim primul rand din input (un șir de caractere), împărțim rezultatul după spațiu,
    # apoi transformăm fiecare componentă în numerăr real folosind map.
    # Rezultatul (2 numere reale, dacă input-ul este corect) se asignează variabilelor a și b.
    a, b = map(float, input().split())

    # eps este eroarea pe care o vom folosi la compararea numerelor reale
    eps = 0.0001

    if abs(a - 0) < eps:
        # Dacă a este 0
        if abs(b - 0) < eps:
            # Dacă a și b sunt 0
            print('Ecuatia are un număr infinit de soluții reale.')
        else:
            # Dacă doar a este 0 (ecuația este de forma b = 0, cu b != 0)
            print('Ecuația nu are soluții reale.')
    else:
        # a este diferit de 0
        print('x = {}'.format(-b / a))


if __name__ == '__main__':
    main()

# rulare: ./05-ecuatie_gradul1.py sau python3 ./05-ecuatie_gradul1.py
# Pentru prima variantă, este necesar să avem drepturi de execuție asupra fișierului.
# Exemple:
#
# Input:
# 0 5
# Output:
# Ecuația nu are soluții reale.
#
# Input:
# 0 0
# Output:
# Ecuatia are un număr infinit de soluții reale.
#
# Input:
# 2.5 5
# Output:
# x = -2.0
