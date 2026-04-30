#include <stdio.h>
#include "input.h"
#include "dp.h"
#include "greedy.h"

int main() {
    Place places[MAX_PLACES];
    int count = 0;
    int selected[MAX_PLACES];
    int order[MAX_PLACES];
    int orderCount = 0;

    printf("========================================\n");
    printf("   TripOpt+ : Travel Planner\n");
    printf("========================================\n\n");

    // read places from user
    readPlaces(places, &count);

    if (count == 0) {
        printf("No places entered. Exiting.\n");
        return 0;
    }

    printf("\nPlaces you entered:\n");
    printPlaces(places, count);

    // get constraints
    int budget, maxTime;
    printf("\nEnter your total budget ($): ");
    scanf("%d", &budget);
    printf("Enter total available time (hours): ");
    scanf("%d", &maxTime);

    // Step 1 — DP picks the best combination
    int totalEnjoy = runKnapsack(places, count, budget, maxTime, selected);
    showDPResult(places, count, selected, totalEnjoy);

    // Step 2 — Greedy decides the visit order
    greedyOrder(places, count, selected, order, &orderCount);
    showGreedyRoute(places, order, orderCount);

    printf("\n========================================\n");
    printf("Total enjoyment score: %d\n", totalEnjoy);
    printf("========================================\n");

    return 0;
}
