// By Arthur Damm@Holberton School 11/22/18
// K&R ch 1 e-1-13-wchist
// vertical word-lengths histogram

#include <stdio.h>

#define OUT 0
#define IN 1
#define MAX_WORD 13
#define MAX_HIST 15
#define HIST_CHAR "*"

int main() {

	int state = OUT;
	int words = 0;
	int chars = 0;
	int lines = 0;
	int spaces = 0;
	int word_lengths[MAX_WORD];
	int this_word = 0;
	int c = 0;

	for (int i=0; i < MAX_WORD; i++) {
		word_lengths[i] = 0;
	}


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
			this_word = 1;
			words++;
		} else {
			this_word++;
		}

		if (state == OUT) {
			if (this_word) {
				if (this_word < MAX_WORD)
					++word_lengths[this_word-1];
				else
					++word_lengths[MAX_WORD-1];
				this_word = 0;
			}
		}
	}

	printf("%8s%8s%8s%8s\n", "Lines:", "Words:", "Chars:", "Spaces:");
	printf("%8d%8d%8d%8d\n", lines, words, chars, spaces);

	printf("Word Length Histogram:\n");
	for (int i=0; i < MAX_WORD; i++) {
		printf("%d: %3d\n", i+1, word_lengths[i]);
	}
	printf("\n");

	for (int i = MAX_HIST; i > 0; i--) {
		printf("%s%2d ", (i == MAX_HIST ? "+" : " "), i);
		for (int j = 0; j < MAX_WORD; j++) {
			if(word_lengths[j] >= i) {
				printf("%2s", HIST_CHAR);
			} else {
				printf("%2s", "");
			}
			printf(" ");
		}
		printf("\n");
	}
	printf("    ");
	for (int i=1; i < MAX_WORD; i++) {
		printf("%2d ", i);
	}
	printf("%2d+\n", MAX_WORD);

}
