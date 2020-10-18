#!/usr/bin/env python3
"""
   Programarea Calculatoarelor CA, 2019-2020

   Programul transforma un numar de secunde in zile, ore, minute, secunde.
"""


def main():
    SECUNDE_PE_MINUT = 60
    SECUNDE_PE_ORA = 60 * SECUNDE_PE_MINUT
    SECUNDE_PE_ZI  = 24 * SECUNDE_PE_ORA

    print('Introduceti numarul de secunde:')

    # Citim numarul de secunde
    secunde = int(input())

    # Transformam in zile, ore, minute, secunde
    zile = int(secunde / SECUNDE_PE_ZI)
    secunde %= SECUNDE_PE_ZI
    ore = int(secunde / SECUNDE_PE_ORA)
    secunde %= SECUNDE_PE_ORA
    minute = int(secunde / SECUNDE_PE_MINUT)
    secunde %= SECUNDE_PE_MINUT
    print('{} zile {} ore {} minute {} secunde'.format(zile, ore, minute, secunde))

if __name__ == '__main__':
    main()

# rulare: ./05-secunde.py sau python3 05-secunde.py sau python3 ./05-secunde.py
# Pentru prima variantă, este necesar să avem drepturi de execuție asupra fișierului.
#
# Exemple:
#
# input : 225888
# output: 2 zile 14 ore 44 minute 48 secunde
#
# input : 90061
# output: 1 zile 1 ore 1 minute 1 secunde
