/* Programarea Calculatoarelor CA, 2020-2021

	Să se obţină reprezentarea ca fracţie zecimală a numărului m/n. Eventuala
	perioadă se afişează între paranteze.

Reprezentarea zecimală a fracţiei ordinare se obţine prin simularea împărţirii
cifră cu cifră. In prealabil se simplifică fracţia şi se separă partea
întreagă. Lungimea părţii neperiodice a fracţiei zecimale reprezintă maximul
dintre multiplicităţile cifrelor 2 şi 5 din descompunerea numitorului.
Dacă fracţia zecimală are şi parte periodică, atunci descompunerea numitorului
conţine şi alţi factori primi în afară de 2 şi 5. O condiţie mai simplă
care stabileşte dacă există parte periodică este ca restul parţial rămas după
obţinerea cifrelor din partea neperiodică sa fie diferit de 0. Operaţia de
împărţire se încheie în momentul în care apare un rest parţial egal cu primul
rest parţial din partea periodică. La citirea datelor (m si n) se asigură
verificarea n != 0.

Algorithm:
---------
Pas 1 : citire m si n si validare n != 0
Pas 2 : simplificarea fractiei cu cmmdc
Pas 3 : separarea partii intregi si afisarea ei determinarea lungimii partii
		neperiodice
Pas 4 : simularea impartirii pe lungimea partii neperiodice
if (exista parte periodica)
	salveaza primul rest partial din partea periodica afisare paranteza deschisa
	pentru partea periodica
	do
      calcul cifra din partea periodica si afisare
      obtinerea urmatorului rest partial
	while (restul partial != primul rest partial) afisare paranteza inchisa
	pentru partea periodica

In efectuarea împărţirii, o cifră a câtului se obţine prin împărţirea întreagă
a restului parţial cu numitorul. Următorul rest parţial se obţine ca restul
împărţirii cu numitorul a restului parţial curent, completat în ultima poziţie
cu un zero (înmulţit cu 10). Primul rest parţial din partea neperiodică este
numărătorul înmulţit cu 10. Simularea împărţirii pe lungimea părţii neperiodice
se exprimă prin:

rest_partial = 10 * m
for (i = 1 ; i<=lungime_parte_neperiodica; i++)
	printf("%d", rest_partial / n); rest_partial = rest_partial % n * 10

*/

#include <stdio.h>

int main(void)
{
	int m, n;	/* numarator si numitor fractie */
	int rp;		/* restul partial */
	int lfn;	/* lungimea fractiei neperiodice */
	int m2, m5;	/* multiplicitati 2 si 5 in numitor */
	int c, d, r;

	/* citire date cu fortare n != 0*/
	scanf("%d%d", &m, &n);
	while (n == 0) {
		scanf("%d", &n);
	}

	/* simplificarea fractiei cu cmmdc calculat cu algoritmul lui Euclid */
	c = m;
	d = n;
	do {
		r = c % d;
		c = d;
		d = r;
	} while (r);
	m /= c;
	n /= c;

	/* separare parte intreaga */
	printf("%d / %d = %d.", m, n, m / n);
	m %= n;

	/* lungimea fractiei neperiodice */
	m2 = 0;	/* multiplicitate 2 */
	c = n;

	/* simplificare fractie */
	while (c % 2 == 0) {
		m2++;
		c /= 2;
	}

	m5 = 0; /* multiplicitate 5 */
	c = n;

	/* simplificare fractie */
	while (c % 5 == 0) {
		m5++;
		c /= 5;
	}

	/* lfn = max(m2, m5) */
	lfn = m2;
	if (m5 > lfn) {
		lfn = m5;
	}
	/* efectuarea impartirii pentru partea neperiodica */
	rp = 10 * m; /* primul rest partial */
	for (int i = 0; i < lfn; ++i) {
		printf("%1d", rp / n);  /* cifra din partea neperiodica */
		rp = rp % n * 10; /* urmatorul rest partial */
	}
	/* efectuarea impartirii pentru partea periodica */
	if (rp) {              /* exista parte periodica */
		printf("(");
		c = rp; /* salvare primul rest partial */
		do {
			printf("%1d", c / n);  /* cifra din partea periodica */
			c = c % n * 10; /* urmatorul rest partial */
		} while (c != rp);
		printf(")");
	}
	printf("\n");
	return 0;
}

/* compile: gcc 06-fractie.c -o fractie
   run    : ./fractie

   Exemplu: fractie

   input  :
   2 7

   output :
   2 / 7 = 0.(285714)

   input  :
   1 4

   output :
   1 / 4 = 0.25

   input  :
   4 3

   output :
   4 / 3 = 1.(3) */
