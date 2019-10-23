#!/usr/bin/env python3
"""
   Programarea Calculatoarelor CA, 2019-2020

   Programul calculeaza suma a 2 numere și afisează rezultatul în baza 10 și în baza 16.
"""


def main():
    # Citim primul rand din input (un șir de caractere), împărțim rezultatul după spațiu,
    # apoi transformăm fiecare componentă în număr întreg folosind map.
    # Rezultatul (2 int-uri, dacă input-ul este corect) se asignează variabilelor a și b.
    a, b = map(int, input().split())

    # Calculăm suma dintre a și b
    sum = a + b

    # Afișăm rezultatul în baza 10, cu un mesaj corespunzător
    print('Baza zece: {}'.format(sum))
    # Puteam folosi și print('Baza zece: ' + str(sum)), dar varianta cu format este mai flexibilă

    # Afișăm rezultatul în baza 16 (folosind litere mici)
    print('Baza 16: {:x}'.format(sum))

    # Afișăm rezultatul în baza 16 (folosind litere mari)
    print('Baza 16: {:X}'.format(sum))

if __name__ == '__main__':
    main()

# rulare: ./02-sum.py sau python3 ./02-sum.py
# Pentru prima variantă, este necesar să avem drepturi de execuție asupra fișierului.
#
# Exemplu:
#
# input:
# 3 8
# output:
# Baza zece: 11
# Baza 16: b
# Baza 16: B
