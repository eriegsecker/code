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

	int numLines = getNumLines(filepath);
	char **lines = getFileLines(filepath, numLines);

	for(int i=0; i<numLines; i++) {
		printf("%s\n", lines[i]);
	}

	return 0;
}
