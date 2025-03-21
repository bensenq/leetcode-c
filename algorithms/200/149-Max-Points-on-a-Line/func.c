#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "uthash.h"

#define MAX_KEY_SIZE 32

typedef struct SlopeKey {
    char key[MAX_KEY_SIZE];
} SlopeKey;

typedef struct SlopeEntry {
    SlopeKey slope;
    int count;
    UT_hash_handle hh;
} SlopeEntry;

// Calculate the slope between two points and return its string representation
void calculate_slope(int x1, int y1, int x2, int y2, char* slope_key) {
    if (x1 == x2) {
        strcpy(slope_key, "inf"); // Vertical line
    } else if (y1 == y2) {
        strcpy(slope_key, "0");   // Horizontal line
    } else {
        double slope = ((double)(y2 - y1)) / (x2 - x1);
        snprintf(slope_key, MAX_KEY_SIZE, "%.6f", slope);
    }
}

// Main function to find the maximum number of collinear points
int maxPoints(int** points, int pointsSize, int* pointsColSize) {
    if (pointsSize == 0) {
        return 0;
    }

    int max_points = 1;
    SlopeEntry* slopes = NULL;

    for (int i = 0; i < pointsSize; i++) {
        for (int j = i + 1; j < pointsSize; j++) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            int x2 = points[j][0];
            int y2 = points[j][1];

            char slope_key[MAX_KEY_SIZE];
            calculate_slope(x1, y1, x2, y2, slope_key);

            SlopeEntry* entry;
            HASH_FIND_STR(slopes, slope_key, entry);
            if (!entry) {
                entry = (SlopeEntry*)malloc(sizeof(SlopeEntry));
                strncpy(entry->slope.key, slope_key, MAX_KEY_SIZE);
                entry->count = 2; // Initialize count to 2 as we have found one pair
                HASH_ADD_STR(slopes, slope.key, entry);
            } else {
                entry->count++;
            }

            max_points = fmax(max_points, entry->count);
        }

        // Clean up the hash table after processing each point
        SlopeEntry* current;
        SlopeEntry* tmp;
        HASH_ITER(hh, slopes, current, tmp) {
            HASH_DEL(slopes, current);
            free(current);
        }
    }

    return max_points;
}
