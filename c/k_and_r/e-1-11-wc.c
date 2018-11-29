// By Arthur Damm@Holberton School 11/17/18
// K&R ch1 e-1-11 
// wordcount (wc) clone

#include <stdio.h>

#define OUT 0
#define IN 1

int main() {

	int state = OUT;
	int words = 0;
	int chars = 0;
	int lines = 0;
	int spaces = 0;
	int c = 0;

	while ((c = getchar()) != EOF) {
		chars++;
		if (c == ' ' || c == '\t') {
			state = OUT;
			spaces++;
		} else if (c == '\n') {
			state = OUT;
			lines++;
		} else if (state == OUT) {
			state = IN;
			words++;
		}
	}

	printf("%8s%8s%8s%8s\n", "Lines:", "Words:", "Chars:", "Spaces:");
	printf("%8d%8d%8d%8d\n", lines, words, chars, spaces);


}

