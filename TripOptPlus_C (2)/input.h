#ifndef INPUT_H
#define INPUT_H

#define MAX_PLACES 50
#define NAME_LEN 50

typedef struct {
    char name[NAME_LEN];
    int cost;
    int time_hrs;
    int enjoyment;
} Place;

void readPlaces(Place places[], int *count);
void printPlaces(Place places[], int count);

#endif
