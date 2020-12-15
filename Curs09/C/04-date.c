/*
Să se calculeze numărul de zile dintre două date calendaristice.
Vom incrementa în mod repetat cea mai mică dintre date, până
când devine egală cu cea de­a doua.
*/

#include <stdio.h>

typedef struct {
	int an, luna, zi;
} DATE;

int bisect(DATE d);
int read_date(DATE *d);
int no_days(DATE d1, DATE d2);
int cmp_date(DATE d1, DATE d2);
int order_date(DATE d1, DATE d2);
void inc_date(DATE *d);

int main(void)
{
	int days;
	DATE d1, d2;
	read_date(&d1);
	read_date(&d2);

	days = no_days(d1, d2);
	if (days > 0)
		printf("Intre cele doua date sunt %d zile\n", days);
	else
		printf("Prima dintre date este dupa cealalta\n");

	return 0;
}

int bisect(DATE d)
{
	return (d.an % 4 == 0 && d.an % 100 != 0) || d.an % 400 == 0;
}

int read_date(DATE *d)
{
	printf("[an luna zi]: ");
	if (scanf("%d%d%d", &d->an, &d->luna, &d->zi) == 3 &&
		d->an > 0 && d->luna > 0 && d->luna < 13 && d->zi > 0 && d->zi < 32){
		return 1;
	}

	printf("Data incorecta.\n");
	return -1;
}

int no_days(DATE d1, DATE d2)
{
	int days = 0;
	if (order_date(d1, d2)) {
		while (!cmp_date(d1, d2)) {
			inc_date(&d1);
			days++;
		}
		return days;
	}
	
	return 0;
}

int cmp_date(DATE d1, DATE d2)
{
	return (d1.an == d2.an) && (d1.luna == d2.luna) && (d1.zi == d2.zi);
}

int order_date(DATE d1, DATE d2)
{
	return ((d1.an < d2.an) ||
			((d1.an == d2.an) && (d1.luna < d2.luna)) ||
		    ((d1.an == d2.an) && (d1.luna == d2.luna) && (d1.zi < d2.zi)));
}

void inc_date(DATE *d)
{
	static const int last_day[2][13] = {
		{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
		{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
	};

	if (d->zi < last_day[bisect(*d)][d->luna]) {
		d->zi++;
	} else {
		d->zi = 1;
		if (d->luna < 12) {
			d->luna++;
		} else {
			d->luna = 1;
			d->an++;
		}
	}
}

/*  compile: gcc 04-date.c -o 04-date
    run    : ./04-date

    Exemple:

	[an luna zi]: 1981 9 25
	[an luna zi]: 2020 10 24
	Intre cele doua date sunt 14274 zile

	[an luna zi]: 2010 9 10
	[an luna zi]: 2020 10 23
	Intre cele doua date sunt 3696 zile

	[an luna zi]: 2012 12 21
	[an luna zi]: 2020 10 23
	Intre cele doua date sunt 2863 zile

	[an luna zi]: 1946 4 22
	[an luna zi]: 2020 10 23
	Intre cele doua date sunt 27213 zile

	[an luna zi]: 1981 9 25
	[an luna zi]: 1981 9 24
	Prima dintre date este dupa cealalta

*/
