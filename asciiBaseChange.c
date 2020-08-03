#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char*numeral(int i) {
	char*result = NULL;
	switch(i) {
		default: result = NULL; break;
		case 0: result = "0"; break;
		case 1: result = "1"; break;
		case 2: result = "2"; break;
		case 3: result = "3"; break;
		case 4: result = "4"; break;
		case 5: result = "5"; break;
		case 6: result = "6"; break;
		case 7: result = "7"; break;
		case 8: result = "8"; break;
		case 9: result = "9"; break;
		case 10: result = "X"; break;
		case 11: result = "E"; break;
	}
	return result;
}

int main (int argc, char**argv) {
	if (argc > 1) {
		int decimal = atoi(argv[1]);
		int base = argc > 2 ? atoi(argv[2]) : 12;

		char number[100] = "";
		char temp[100] = "";
		while (decimal > 0)
		{
			strcpy(temp, number);
			strcpy(number, numeral(decimal % base));
			strcat(number, temp);
			decimal = (decimal - decimal % base) / base;
		}
		printf("%s\n", number);
	}
}
