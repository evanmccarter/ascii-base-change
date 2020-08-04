#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void putNumeral(char*result, int i) {
	switch(i) {
		case 0: *result = '0'; break;
		case 1: *result = '1'; break;
		case 2: *result = '2'; break;
		case 3: *result = '3'; break;
		case 4: *result = '4'; break;
		case 5: *result = '5'; break;
		case 6: *result = '6'; break;
		case 7: *result = '7'; break;
		case 8: *result = '8'; break;
		case 9: *result = '9'; break;
		case 10: *result = 'X'; break;
		case 11: *result = 'E'; break;
	}
}

void rebase(char*string, int decimal, int base) {
	if (decimal != 0) {
		char*negative = calloc(1, sizeof(char));
		if (decimal < 0) {
			*negative = '-';
			decimal = -decimal;
		}

		int ones = (decimal % base);
		int powers = (decimal - ones) / base;
		char*substring = calloc(100, sizeof(char));
		if (powers)
			rebase(substring, powers, base);
		char*numeral = calloc(1, sizeof(char));
		putNumeral(numeral, ones);

		strncpy(string, negative, 1);
		strncat(string, substring, 100);
		strncat(string, numeral, 1);

		free(negative);
		free(substring);
		free(numeral);
	}
	else
		strcpy(string, "0");
}

int main (int argc, char**argv) {
	if (argc > 1) {
		int decimal = atoi(argv[1]);
		int base = argc > 2 ? atoi(argv[2]) : 12;
		char string[100];
		rebase(string, decimal, base);
		printf("%s\n", string);
	}
}
