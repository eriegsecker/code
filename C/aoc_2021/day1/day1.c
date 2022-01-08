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

int main(int argc, char **argv) {
	char *filepath;
	if(argc == 2) {
		filepath = argv[1];
	} else {
		filepath = "in.txt";
	}

	int numLines = getNumLines(filepath);
	char **lines = getFileLines(filepath, numLines);
	int *num = (int *) malloc(sizeof(int) * numLines);
	for(int i=0; i<numLines; i++) {
		num[i] = atoi(lines[i]);
		free(lines[i]);
	}
	free(lines);

	int ans1 = 0;
	int ans2 = 0;
	for(int i=0; i<numLines; i++) {
		if(i >= 1 && num[i] > num[i-1]) {
			ans1++;
		}
	       	if(i >= 3 && (num[i] + num[i-1] + num[i-2]) > 
				(num[i-1] + num[i-2] + num[i-3])) {
			ans2++;
		}
	}

	printf("answer #1 = %d\nanswer #2 = %d\n",ans1 , ans2);
	return 0;

}
