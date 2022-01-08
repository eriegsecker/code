/**
 * Author: Ethan Riegsecker
 *
 * Date: 1/5/22
 *
 */

/**
 * This function returns the contents of a file in
 * the form of a dynamically allocated array of 
 * strings. It will return a number of strings
 * equal to numLines from the file whose path is
 * filepath.
 */
char **getFileLines(char *filepath, int numLines);

/**
 * This function returns the number of lines
 * in the given file.
 */
int getNumLines(char *filepath);
