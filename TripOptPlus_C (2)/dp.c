#include <stdio.h>
#include <string.h>
#include "dp.h"

// 3D DP table: dp[item][budget][time]
// can't do variable-length on stack for larger inputs, so cap it
#define MAX_BUDGET 500
#define MAX_TIME 50

static int dp[MAX_PLACES + 1][MAX_BUDGET + 1][MAX_TIME + 1];

int runKnapsack(Place places[], int count, int maxBudget, int maxTime, int selected[]) {
    // cap constraints to table limits
    if (maxBudget > MAX_BUDGET) maxBudget = MAX_BUDGET;
    if (maxTime > MAX_TIME) maxTime = MAX_TIME;

    // zero out the table
    memset(dp, 0, sizeof(dp));

    // fill the DP table
    for (int i = 1; i <= count; i++) {
        int c = places[i-1].cost;
        int t = places[i-1].time_hrs;
        int e = places[i-1].enjoyment;

        for (int b = 0; b <= maxBudget; b++) {
            for (int h = 0; h <= maxTime; h++) {
                // default: don't take this place
                dp[i][b][h] = dp[i-1][b][h];

                // take it if we can afford it
                if (b >= c && h >= t) {
                    int withThis = dp[i-1][b-c][h-t] + e;
                    if (withThis > dp[i][b][h])
                        dp[i][b][h] = withThis;
                }
            }
        }
    }

    // backtrack to find which places got selected
    int b = maxBudget, h = maxTime;
    for (int i = count; i >= 1; i--) {
        if (dp[i][b][h] != dp[i-1][b][h]) {
            selected[i-1] = 1;
            b -= places[i-1].cost;
            h -= places[i-1].time_hrs;
        } else {
            selected[i-1] = 0;
        }
    }

    return dp[count][maxBudget][maxTime];
}

void showDPResult(Place places[], int count, int selected[], int totalEnjoy) {
    int totalCost = 0, totalTime = 0, num = 0;

    printf("\n=== DP Selected Places (Best Combo) ===\n");
    printf("%-25s %6s %6s %8s\n", "Place", "Cost", "Time", "Enjoy");
    printf("--------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        if (selected[i]) {
            printf("%-25s %6d %6d %8d\n",
                places[i].name,
                places[i].cost,
                places[i].time_hrs,
                places[i].enjoyment);
            totalCost += places[i].cost;
            totalTime += places[i].time_hrs;
            num++;
        }
    }

    printf("--------------------------------------------------\n");
    printf("%-25s %6d %6d %8d\n", "TOTAL", totalCost, totalTime, totalEnjoy);
    printf("\n%d places selected by DP.\n", num);
}
