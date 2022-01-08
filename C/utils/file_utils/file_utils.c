/**
 * Author: Ethan Riegsecker
 *
 * Date: 1/5/22
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char **getFileLines(char *filepath, int numLines) {
	if(filepath == NULL) {
		return NULL;
	} else if(numLines < 0) {
		return NULL;
	}
	
	
	char **lines = (char **) malloc(sizeof(char *) * numLines);

	FILE *f = fopen(filepath, "r");

	char s[100];
	char *line = fgets(s, 100, f);
	int i = 0;
	while(line != NULL) {
		int n = strlen(s);
		if(s[n-1] == '\n') {
			s[n-1] = '\0';
		}
		
		if(i < numLines) {
			lines[i] = strdup(s);
		}

		i++;
		line = fgets(s, 100, f);
	}

	fclose(f);

	return lines;
}

int getNumLines(char *filepath) {
	if(filepath == NULL) {
		return 0;
	}
	
	int numLines = 0;
	FILE *f = fopen(filepath, "r");
	char c = fgetc(f);
	while(c != EOF) {
		if(c == '\n') {
			numLines++;
		}
		c = fgetc(f);
	}
	fclose(f);
	return numLines;
}
	
