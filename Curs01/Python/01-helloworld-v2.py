#!/usr/bin/env python3
"""
   Programarea Calculatoarelor CA, 2019-2020
   Programul afiseaza mesajul "Hello World".
   În versiunea 2, adăugăm toate instrucțiunile într-o funcție (pe care o numim, arbitrar, main).
   Această abordare ne ajută să ne asigurăm că instrucțiunea print nu va fi executată, de exemplu, dacă în acest fișier
   va apărea o nouă funcție și dorim să o importăm (din alt scop). Acesta este un good-practice ce va fi utilizat
   în toate exemplele viitoare.
"""


def main():
    print('Hello World')


if __name__ == '__main__':
    main()

# rulare: ./01-helloworld-v2.py sau python3 ./01-helloworld-v2.py
# Pentru prima variantă, este necesar să avem drepturi de execuție asupra fișierului.
