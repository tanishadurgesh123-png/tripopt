#ifndef GREEDY_H
#define GREEDY_H

#include "input.h"

// sorts selected places by enjoyment/time ratio (greedy ordering)
// fills order[] with indices in visit order
void greedyOrder(Place places[], int count, int selected[], int order[], int *orderCount);

void showGreedyRoute(Place places[], int order[], int orderCount);

#endif
