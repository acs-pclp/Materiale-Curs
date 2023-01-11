# pclp-ca-curs

### Maintainers
* [Radu Nichita](https://github.com/RaduNichita)
* [Darius Neațu](https://github.com/neatudarius)
* [Dorinel Filip](https://github.com/dorinelfilip)

### Contributors

* [Florin Pop](https://github.com/florinpop1981) (2020 - ongoing)
* [Radu Nichita](https://github.com/RaduNichita) (2020 - ongoing)
* [Remus Neațu](https://github.com/RemusNeatu) (2020 - 2022)
* [Darius Neațu](https://github.com/neatudarius) (2020 - ongoing)
* [Dorinel Filip](https://github.com/dorinelfilip) (2020 - ongoing)
* [Andrei Stan](https://github.com/Grizzlly) (2022 - ongoing)

### Descriere

Aici vor fi publicate exemplele de cod pentru cursul de Programarea Calculatoarelor, seria CA.
Pentru fiecare curs `CursXY`, există un folder asociat cu diferite exemple relevante.

#### Compilare + rulare cod C

Pentru a compila sursele C, rulați comanda `make` în folderul `CursXY/C`.
De exemplu, pentru a compila sursele `C` din cursul `05`, rulați comanda:

```console
cd Curs05/C
$ make
gcc -Wall -Wextra -o 01-sortari_vector 01-sortari_vector.c -lm
gcc -Wall -Wextra -o 02-cautare_vector 02-cautare_vector.c -lm
gcc -Wall -Wextra -o 03-element_dominant 03-element_dominant.c -lm
gcc -Wall -Wextra -o 04-romane 04-romane.c -lm
gcc -Wall -Wextra -o 05-sort_diag 05-sort_diag.c -lm
gcc -Wall -Wextra -o 06-mul_matrix 06-mul_matrix.c -lm
```

Pentru a rula unul dintre exemple, folosiți comanda `./<nume_executabil>`.
De exemplu, pentru a rula exemplul 2 din directorul `Curs05/C` folosiți comanda:

```console
$ ./02-cautare_vector
```

#### Rulare cod Python
Pentru a rula exemplele de Python, folosiți comanda `python3 <path>`, unde path este calea către fișierul respectiv. De exemplu, din directorul rădăcină, pentru a rula exemplul 3 din cursul 1, folosiți comanda:

```console
$ python3 Curs01/Python/03-min_max.py
```