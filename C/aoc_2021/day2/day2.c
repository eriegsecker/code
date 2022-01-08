/**
 * Author: Ethan Riegsecker
 *
 * Date: 1/5/2022
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../../utils/file_utils/file_utils.h"
#include "../../utils/string_utils/string_utils.h"

int main(int argc, char **argv) {
	char *filepath;
	if(argc == 2) {
		filepath = argv[1];
	} else {
		filepath = "in.txt";
	}

	int h = 0;
	int d = 0;
	int a = 0;

	int numLines = getNumLines(filepath);
	char **lines = getFileLines(filepath, numLines);
	for(int i=0; i<numLines; i++) {
		char **tokens = getTokens(lines[i], " ", 2);
		if(strcmp(tokens[0], "forward") == 0) {
			h += atoi(tokens[1]);
			d += a * atoi(tokens[1]);
		} else if(strcmp(tokens[0], "down") == 0) {
			a += atoi(tokens[1]);
		} else {
			a -= atoi(tokens[1]);
		}
		freeStrings(tokens, 2);
	}

	printf("%d\n", h * d);
	return 0;
}
