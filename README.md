# PCLP1 CA - Curs

### Coordinator
* [Florin Pop](https://github.com/florinpop1981) (2020 - ongoing)

* ### Maintainers
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

Aici vor fi publicate exemplele de cod pentru cursul de Programarea calculatoarelor și limbaje de programare 1 (PCLP1), Seria CA.

<details>
<summary> Ierarhie repo (exemplu) </summary>

```shell
Materiale-Curs [main] $ ls -l
total 8
drwxr-xr-x  4 darius  staff   128 Sep 26 21:31 Curs01
drwxr-xr-x  4 darius  staff   128 Sep 26 21:31 Curs02
drwxr-xr-x  3 darius  staff    96 Sep 26 21:31 Curs03
drwxr-xr-x  3 darius  staff    96 Sep 26 21:31 Curs04
drwxr-xr-x  3 darius  staff    96 Sep 26 21:31 Curs05
drwxr-xr-x  3 darius  staff    96 Sep 26 21:31 Curs06
drwxr-xr-x  3 darius  staff    96 Sep 26 21:31 Curs07
drwxr-xr-x  3 darius  staff    96 Sep 26 21:31 Curs08
drwxr-xr-x  3 darius  staff    96 Sep 26 21:31 Curs09
drwxr-xr-x  3 darius  staff    96 Sep 26 21:31 Curs10
drwxr-xr-x  3 darius  staff    96 Sep 26 21:41 Curs11
drwxr-xr-x  3 darius  staff    96 Sep 26 21:41 Curs12
-rw-r--r--  1 darius  staff  1897 Oct  1 00:07 README.md
drwxr-xr-x  4 darius  staff   128 Sep 26 21:31 utils
```
</details>


Pentru fiecare curs `CursXY`, există un director asociat cu diferite exemple relevante. De exemplu, listingul următor arată problemele propuse spre rezolvare pentru primul curs (`Curs01`).


```shell
Materiale-Curs [main] $ tree Curs01
Curs01
├── C
│   ├── 01-helloworld.c
│   ├── 02-sum.c
│   ├── 03-min_max.c
│   ├── 04-min_max_if.c
│   ├── 05-ecuatie_grad1.c
│   ├── 06-ecuatie_grad2.c
│   └── Makefile -> ../../utils/Makefile
└── Python
    ├── 01-helloworld-v2.py
    ├── 01-helloworld.py
    ├── 02-sum.py
    ├── 03-min_max.py
    ├── 04-min_max_if.py
    ├── 05-ecuatie_gradul1.py
    └── 06-ecuatie_gradul2.py

3 directories, 14 files
```


Putem observa ca fiecare problemă este rezolvată atât în limbajul C, dar și în Python.

#### Compilare + rulare cod C

Pentru a compila sursele C, rulați comanda `make` în folderul `CursXY/C`.
De exemplu, pentru a compila sursele `C` din cursul `01`, rulați următoarele comanzi:

```shell
Materiale-Curs/Curs01/C [main] $ make
gcc -Wall -Wextra -o 01-helloworld 01-helloworld.c -lm
gcc -Wall -Wextra -o 02-sum 02-sum.c -lm
gcc -Wall -Wextra -o 03-min_max 03-min_max.c -lm
gcc -Wall -Wextra -o 04-min_max_if 04-min_max_if.c -lm
gcc -Wall -Wextra -o 05-ecuatie_grad1 05-ecuatie_grad1.c -lm
gcc -Wall -Wextra -o 06-ecuatie_grad2 06-ecuatie_grad2.c -lm
```

Puteți analiza fișierul `Curs01/C/Makefile` și comenzile printate în terminal mai sus. Putem utiliza direct `gcc` pentru a compila.

Pentru a rula unul dintre exemple, folosiți comanda `./<nume_executabil>`.
De exemplu, pentru a rula exemplul [Curs01/C
/01-helloworld.c](https://github.com/acs-pclp/private-Materiale-Curs/blob/master/Curs01/C/01-helloworld.c) folosiți comanda:

```shell
Materiale-Curs/Curs01/C [main] $ ./01-helloworld
Hello World!
```

Analog, exemplul [Curs01/C/06-ecuatie_grad2.c](https://github.com/acs-pclp/private-Materiale-Curs/blob/master/Curs01/C/06-ecuatie_grad2.c) se rulează astfel:

```shell
Materiale-Curs/Curs01/C [main] $ ./06-ecuatie_grad2
5 3 2
Ecuatia nu are solutii reale

Materiale-Curs/Curs01/C [main] $ ./06-ecuatie_grad2
-1 4 -4
x1 = x2 = 2.000000

Materiale-Curs/Curs01/C [main] $ ./06-ecuatie_grad2
-2 -7 5
x1 = -4.108495
x2 = 0.608495
```

#### Rulare cod Python

Spre deosebire de C, codul Python se interpretează. Pentru a rula exemplele de Python 3, folosiți comanda `python3 <path>`, unde path este calea către fișierul respectiv.

De exemplu, pentru a rula exemplul [Curs01/Python/01-helloworld.py](https://github.com/acs-pclp/private-Materiale-Curs/blob/master/Curs01/Python/01-helloworld.py) folosiți comanda:

```shell
$ python3 01-helloworld.py
Hello World
```

Analog, pentru a rula exemplul [Curs01/Python/06-ecuatie_gradul2.py
](https://github.com/acs-pclp/private-Materiale-Curs/blob/master/Curs01/Python/06-ecuatie_gradul2.py
) folosiți comanda:

```shell
Materiale-Curs/Curs01/Python [main] $ python3 06-ecuatie_gradul2.py
5 3 2
Ecuatia nu are solutii reale

Materiale-Curs/Curs01/Python [main] $ python3 06-ecuatie_gradul2.py
-1 4 -4
x1 = x2 = 2.0

Materiale-Curs/Curs01/Python [main] $ python3 06-ecuatie_gradul2.py
-2 -7 5
x1=-4.10849528301415
x2=0.6084952830141508
```
