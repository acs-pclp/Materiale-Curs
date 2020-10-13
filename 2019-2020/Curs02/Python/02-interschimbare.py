#!/usr/bin/env python3
"""
   Programarea Calculatoarelor CA, 2019-2020

   Programul realizeaza interschimbarea a 2 numere prin diferite metode.
"""


def main():
    # Citim cele doua numere si le interschimbam folosind o variabila auxiliara
    a, b = map(int, input().split())
    aux = a
    a = b
    b = aux
    print('{} {}'.format(a, b))

    # Citim alte doua numere si le interschimbam folosind xor
    a, b = map(int, input().split())
    a = a ^ b
    b = a ^ b
    a = a ^ b
    print('{} {}'.format(a, b))

    # Citim alte doua numere si le interschimbam folosind adunari
    a, b = map(int, input().split())
    a = a + b
    b = a - b
    a = a - b
    print('{} {}'.format(a, b))
    
    # Citim alte doua numere si le interschimbam (fara a folosi alte variabile sau operatii)
    a, b = map(int, input().split())
    a, b = b, a
    print('{} {}'.format(a, b))

if __name__ == '__main__':
    main()

# rulare: ./02-interschimbare.py sau python3 02-interschimbare.py sau python3 ./02-interschimbare.py
# Pentru prima variantă, este necesar să avem drepturi de execuție asupra fișierului.
#
# Exemplu:
#
# input : 2 5
# output: 5 2
# input : 13 -4
# output: -4 13
# input : 12 13
# output: 13 12
# input : 5 10
# output: 10 5
