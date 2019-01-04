// By Arthur Damm@Holberton School 1/4/19
// K&R ch1 e-1-16 
// get arbitrary max line length, print as much as allocated

#include <stdio.h>
#include <string.h>

#define MAXLINE 20

int copyline(char *from, char *to);
int getline2(char *to, int max);

char line[MAXLINE];
char maxline[MAXLINE];
int maxlen=0;

int main(int argc, char** argv) {
	int len = 0;
	
	while ((len = getline2(line, MAXLINE)) > 0) {
		if (len > maxlen) {
			copyline(line, maxline);
			maxlen = len;
		}
	}

	printf("Maxline: %d\n%s\n", maxlen, maxline);
	for (int i=0; i < maxlen+1;i++) {
		if (maxline[i] == '\0') {
			//printf("Null at: %d\n", i);
		}
	}
	return 0;
}

int getline2(char *to, int max) {
	int i, c;
 for (i=0; i < max-1 && (c=getchar()) != EOF && c != '\n'; i++) {
		to[i]=c;
	}
	if (c=='\n') {
		to[i] = c;
		i++;
	}
	to[i] = '\0';
	if (c != EOF && c != '\n') { // end not reached

		while ((c=getchar()) != EOF && c != '\n') {
			i++;
		}
		if (c=='\n') i++;
	}
	if (c==EOF) puts("EOF called.");	
	return i;
}

int copyline(char *from, char *to) {
	int i=0;
	while ((to[i] = from[i]) != '\0')
		i++;
	return i;
}
