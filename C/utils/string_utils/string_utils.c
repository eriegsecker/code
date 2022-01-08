/**
 *
 * Author: Ethan Riegsecker
 *
 * Date: 1/6/22
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **getTokens(char *str, char *delim, int numTokens) {
	
	char **tokens = (char **) malloc(sizeof(char *) * numTokens);
	char *ptr = strtok(str, delim);
	int i = 0;
	while(ptr != NULL && i < numTokens) {
		tokens[i] = strdup(ptr);
		i++;
		ptr = strtok(NULL, delim);
	}

	return tokens;
}

void freeStrings(char **strings, int n) {
	for(int i=0; i<n; i++) {
		free(strings[i]);
	}
	free(strings);
	return;
}
