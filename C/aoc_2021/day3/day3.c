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

void countBits(int *ones, int *zeroes, char **lines, int numLines, int i);

int main(int argc, char **argv) {
	char *filepath;
	if(argc == 2) {
		filepath = argv[1];
	} else {
		filepath = "in.txt";
	}

	int numLines = getNumLines(filepath);
	char **lines = getFileLines(filepath, numLines);
	int numBits = strlen(lines[0]);
	char gamma[30];
	char epsilon[30];
	
	for(int i=0; i<numBits; i++) {
		int ones, zeroes;
		countBits(&ones, &zeroes, lines, numLines, i);
		if(ones > zeroes) {
			gamma[i] = '1';
			epsilon[i] = '0';
		} else {
			gamma[i] = '0';
			epsilon[i] = '1';
		}	
	}
	gamma[numBits] = '\0';
	epsilon[numBits] = '\0';
	
	int gammaRate = strtol(gamma, NULL, 2);
	int epsilonRate = strtol(epsilon, NULL, 2);
	printf("%d\n", gammaRate * epsilonRate);

	

	freeStrings(lines, numLines);

	return 0;
}


void countBits(int *ones, int *zeroes, char **lines, int numLines, int i) {
	*ones = 0;
	*zeroes = 0;
	for(int j=0; j<numLines; j++) {
		if(lines[j][i] == '1') {
			*ones += 1;
		} else {
			*zeroes += 1;
		}
	}

	return;
}

