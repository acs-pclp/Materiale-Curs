#!/usr/bin/env python3
"""
   Programarea Calculatoarelor CA, 2019-2020

   Programul determină minimul și maximul a două numere,
   evitând compararea numerelor folosind instrucțiunea if.
"""


def main():
    # Citim primul rand din input (un șir de caractere), împărțim rezultatul după spațiu,
    # apoi transformăm fiecare componentă în numerăr întreg folosind map.
    # Rezultatul (2 int-uri, dacă input-ul este corect) se asignează variabilelor a și b.
    a, b = map(int, input().split())

    min = (a + b + abs(a - b)) / 2
    max = a + b - min

    # Afișăm minimul, cu un mesaj corespunzător
    print('Minim: {}'.format(min))
    # Puteam folosi și print('Minim: ' + str(min)), dar varianta cu format este mai flexibilă

    # Afișăm maximul
    print('Maxim: {}'.format(max))


if __name__ == '__main__':
    main()

# rulare: ./03-min_max.py sau python3 ./03-min_max.py
# Pentru prima variantă, este necesar să avem drepturi de execuție asupra fișierului.
#
# Exemplu:
#
# input:
# 3 8
# output:
# Minim: 3.0
# Maxim: 8.0
