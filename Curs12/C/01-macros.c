/* Programarea Calculatoarelor CA, 2022-2023
 *
 *	Diferite macro definitii pentru suma si produs
 *
 */

#include <stdio.h>

#define BAD_ADD(a, b) a + b
#define GOOD_ADD(a, b) ((a) + (b))

#define BAD_MUL(a, b) a * b
#define GOOD_MUL(a, b) ((a) * (b))

#define ADD_2(a, b) ((a) + (b))
#define ADD_3(a, ...) ((a) + ADD_2(__VA_ARGS__))
#define ADD_4(a, ...) ((a) + ADD_3(__VA_ARGS__))

#define EXPAND(...) __VA_ARGS__

int main(void)
{
	int a, b;
	scanf("%d%d", &a, &b);
	printf("\n");

	printf("BAD_ADD:\n\t(%d + %d) * 10 = %d\n\n", a, b,
		   BAD_ADD(a, b) * 10);
	printf("GOOD_ADD:\n\t(%d + %d) * 10 = %d\n\n", a, b,
		   GOOD_ADD(a, b) * 10);

	printf("BAD_MUL:\n\t(%d + %d) * (%d + %d) = %d\n\n", a, b, a, b,
		   BAD_MUL(a + b, a + b));
	printf("GOOD_MUL:\n\t(%d + %d) * (%d + %d) = %d\n\n", a, b, a, b,
		   GOOD_MUL(a + b, a + b));

	// How many variables can I have?
	printf("1 + 2 + 3 + 4 = %d can someone explain?\n",
		   EXPAND(EXPAND(EXPAND(EXPAND(ADD_4(1, 2, 3, 4))))));

	/*
	 *	Conclusion:
	 *
	 *	Take the pre-processor for what it is: FIND & REPLACE. No more and no less.
	 */

	return 0;

	/*
	 *	Further reading:
	 *
	 *	https://github.com/pfultz2/Cloak/wiki/C-Preprocessor-tricks,-tips,-and-idioms
	 *	https://github.com/pfultz2/Cloak/wiki/Is-the-C-preprocessor-Turing-complete%3F
	 */
}

/*
 *	compile: gcc 01-macros.c -o macros
 *	run: ./macros
 *
 *	Output:
 *		10 12
 *
 *		BAD_ADD:
 *				(10 + 12) * 10 = 130
 *
 *		GOOD_ADD:
 *				(10 + 12) * 10 = 220
 *
 *		BAD_MUL:
 *				(10 + 12) * (10 + 12) = 142
 *
 *		GOOD_MUL:
 *				(10 + 12) * (10 + 12) = 484
 *
 *		1 + 2 + 3 + 4 = 10 can someone explain?
 *
 * * * * * * * * * * * * * * * * * * * * * * * * *
 * 
 * 	Preprocessing phase: gcc -E 01-macros.c
 * 		int main(void)
 *		{
 *			int a, b;
 *			scanf("%d%d", &a, &b);
 *			printf("\n");
 *
 *			printf("BAD_ADD:\n\t(%d + %d) * 10 = %d\n\n", a, b,
 *				a + b * 10);
 *			printf("GOOD_ADD:\n\t(%d + %d) * 10 = %d\n\n", a, b,
 *				((a) + (b)) * 10);
 *
 *			printf("BAD_MUL:\n\t(%d + %d) * (%d + %d) = %d\n\n", a, b, a, b,
 *				a + b * a + b);
 *			printf("GOOD_MUL:\n\t(%d + %d) * (%d + %d) = %d\n\n", a, b, a, b,
 *				((a + b) * (a + b)));
 *
 *			printf("1 + 2 + 3 + 4 = %d can someone explain?\n",
 *				((1) + ((2) + ((3) + (4)))));
 *			return 0;
 *		}
 */
