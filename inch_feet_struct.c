#include <stdio.h>
#include <math.h>
struct Distance {
    int feet;
    float inch;
};

struct Distance addDistances(struct Distance distances[], int numDistances);

int main() {
    int numDistances, i;
    
    printf("Enter the number of distances: ");
    scanf("%d", &numDistances);
    
    struct Distance distances[numDistances];
    
    printf("\nEnter distances in inch-feet system:\n");
    for (i = 0; i < numDistances; i++) {
        printf("Distance %d:\n", i + 1);
        printf("Feet: ");
        scanf("%d", &distances[i].feet);
        printf("Inches: ");
        scanf("%f", &distances[i].inch);
    }
    
    struct Distance totalDistance = addDistances(distances, numDistances);
    
    printf("\nTotal Distance: %d feet %.2f inches\n", totalDistance.feet, totalDistance.inch);
    
    return 0;
}

struct Distance addDistances(struct Distance distances[], int numDistances) {
    struct Distance totalDistance;
    int totalFeet = 0;
    float totalInch = 0.0;
    
    for (int i = 0; i < numDistances; i++) {
        totalFeet += distances[i].feet;
        totalInch += distances[i].inch;
    }
    
    totalFeet += (int)(totalInch / 12);
    totalInch = fmod(totalInch, 12.0);
    
    totalDistance.feet = totalFeet;
    totalDistance.inch = totalInch;
    
    return totalDistance;
}
