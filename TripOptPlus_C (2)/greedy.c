#include <stdio.h>
#include "greedy.h"

// higher ratio = more enjoyment per hour = visit first
static float ratio(Place *p) {
    if (p->time_hrs == 0) return 0;
    return (float)p->enjoyment / p->time_hrs;
}

void greedyOrder(Place places[], int count, int selected[], int order[], int *orderCount) {
    // collect selected indices
    int pool[MAX_PLACES];
    int poolSize = 0;

    for (int i = 0; i < count; i++) {
        if (selected[i])
            pool[poolSize++] = i;
    }

    // simple insertion sort by ratio (descending)
    // dataset is small so this is fine
    for (int i = 1; i < poolSize; i++) {
        int key = pool[i];
        int j = i - 1;
        while (j >= 0 && ratio(&places[pool[j]]) < ratio(&places[key])) {
            pool[j+1] = pool[j];
            j--;
        }
        pool[j+1] = key;
    }

    for (int i = 0; i < poolSize; i++)
        order[i] = pool[i];

    *orderCount = poolSize;
}

void showGreedyRoute(Place places[], int order[], int orderCount) {
    printf("\n=== Greedy Visit Order (by Enjoy/Time ratio) ===\n");
    printf("%-5s %-25s %8s %8s %8s\n", "Stop", "Place", "Enjoy", "Time", "Ratio");
    printf("------------------------------------------------------------\n");

    for (int i = 0; i < orderCount; i++) {
        Place *p = &places[order[i]];
        float r = ratio(p);
        printf("%-5d %-25s %8d %8d %8.2f\n",
            i + 1, p->name, p->enjoyment, p->time_hrs, r);
    }

    printf("\nVisit in this order to get the most value early in the day.\n");
}
