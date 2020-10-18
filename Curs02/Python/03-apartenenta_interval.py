#!/usr/bin/env python3
"""
   Programarea Calculatoarelor CA, 2019-2020

   Programul verifica daca un numar se afla intr-un interval.
"""


def main():
    # Citim inputul: primul rand contine capetele intervalului
    left_number, right_number = map(int, input().split())

    # Al doilea rand: numarul pentru care se va calcula apartenenta la interval
    number = int(input())

    # Al treilea rand: tipul capetelor intervalului (d = deschis, i = inchis)
    left, right = input().split()

    # Variabilele ok_left si ok_right vor verifica daca numarul este mai mare (mai mic) decat
    # capatul stanga (dreapta) al intervalului
    ok_left = False
    ok_right = False

    # Verificam daca numarul respecta constrangerile intervalului, tinand cont de tipul capetelor
    if left == 'i' and number >= left_number:
        ok_left = True

    if left == 'd' and number > left_number:
        ok_left = True

    if right == 'i' and number <= right_number:
        ok_right = True

    if right == 'd' and number < right_number:
        ok_right = True

    # Daca ambele variabile ok_left si ok_right sunt True, numarul apartine intervalului
    if ok_left and ok_right:
        print('Numarul apartine intervalului')
    else:
        print('Numarul nu se afla in interval')

if __name__ == '__main__':
    main()

# rulare: ./01-apartenenta_interval.py sau python3 01-apartenenta_interval.py sau python3 ./01-apartenenta_interval.py
# Pentru prima variantă, este necesar să avem drepturi de execuție asupra fișierului.
#
# Exemple:
#
# input:
# 2 7
# 5
# d i
# output:
# Numarul apartine intervalului
#
# input:
# 2 7
# 9
# i i
# output:
# Numarul nu se afla in interval
#
# input:
# 2 7
# 7
# i d
# output:
# Numarul nu se afla in interval
