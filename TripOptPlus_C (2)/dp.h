#ifndef DP_H
#define DP_H

#include "input.h"

// runs knapsack DP with two constraints: budget and time
// fills selected[] with 1 if that place is chosen, 0 otherwise
// returns total enjoyment achieved
int runKnapsack(Place places[], int count, int maxBudget, int maxTime, int selected[]);

void showDPResult(Place places[], int count, int selected[], int totalEnjoy);

#endif
