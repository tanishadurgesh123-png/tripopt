#include <stdio.h>
#include <string.h>
#include "input.h"

void readPlaces(Place places[], int *count) {
    printf("Enter number of places (max %d): ", MAX_PLACES);
    scanf("%d", count);

    if (*count > MAX_PLACES) *count = MAX_PLACES;

    for (int i = 0; i < *count; i++) {
        printf("\n--- Place %d ---\n", i + 1);

        printf("Name: ");
        scanf(" %[^\n]", places[i].name);

        printf("Cost (in $): ");
        scanf("%d", &places[i].cost);

        printf("Time needed (in hours): ");
        scanf("%d", &places[i].time_hrs);

        printf("Enjoyment score (1-100): ");
        scanf("%d", &places[i].enjoyment);
    }
}

void printPlaces(Place places[], int count) {
    printf("\n%-25s %6s %6s %8s\n", "Place", "Cost", "Time", "Enjoy");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-25s %6d %6d %8d\n",
            places[i].name,
            places[i].cost,
            places[i].time_hrs,
            places[i].enjoyment);
    }
}
