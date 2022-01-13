/**
 * Author: Ethan Riegsecker
 *
 * Date: 10/20/21
 *
 * Calculates the expected win percentage of a baseball team
 * based off of their runs scored and runs allowed. Also compares
 * the number of expected wins to the actual wins. The runs scored,
 * runs allowed, and actual wins are read as command line arguments.
 */

#include<stdlib.h>
#include<stdio.h>
#include<math.h>

int main(int argc, char **argv) {
    if(argc != 4) {
        printf("Usage: a.out runsScored runsAllowed actualWins\n");
        return 1;
    }
    double expectedWinPercentage;
    double runsScored, runsAllowed;
    double runsScoredAdjusted, runsAllowedAdjusted;
    int actualWins, expectedWins;
    int performance;

    //reading the command arguments and storing them in variables.
    runsScored = atof(argv[1]);
    runsAllowed = atof(argv[2]);
    actualWins = atof(argv[3]);

    //caculating the p values and storing them in an array.
    double *p = (double *) malloc(sizeof(double) * 4);
    p[0] = 2;
    p[1] = 1.83;
    p[2] = 1.5*(log((runsScored + runsAllowed)/162)/log(10)) + 0.45;
    p[3] = pow(((runsScored + runsAllowed)/162), 0.287);

    for(int i=0; i<4; i++) {
	    printf("%.2f\n", p[i]);
    }

    printf("p value  Win Percentage  Predicted Wins  Performance\n");
    printf("====================================================\n");

    for(int i=0; i<4; i++) {
        //essentially using the formula given but it is broken up into multiple steps.
        runsScoredAdjusted = pow(runsScored, p[i]);
        runsAllowedAdjusted = pow(runsAllowed, p[i]);
        expectedWinPercentage = runsScoredAdjusted/(runsScoredAdjusted + runsAllowedAdjusted);
        expectedWins = round(expectedWinPercentage*162);
        performance = actualWins - expectedWins;
        printf("%2.2f     %2.6f       %2d             %2d\n", p[i], 100*expectedWinPercentage, expectedWins, performance);
    }

    return 0;
}
