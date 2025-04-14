#include <stdio.h>

int main(void) {


    int CityTemps[5][7];

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 7; j++) {
            printf("Enter the temperature for city %d for day %d\n", i+1, j+1);
            scanf("%d", &CityTemps[i][j]);
        }
    }

    float averages[5];
    for (int i = 0; i < 5; i++) {
        int sum = 0;
        for (int j = 0; j < 7; j++) {
            sum += CityTemps[i][j];
        }
        float average = (float) sum / 7;
        averages[i] = average;
    }

    float highestAverage = -100000000.0;
    int AverageIndexCounter = 0;
    for (int i = 0; i < 5; i++) {
        if (averages[i] > highestAverage) {
            highestAverage = averages[i];
            AverageIndexCounter = i +1;
        }
    }
    printf("The city with the highest average is city %d with an Average of %f\n", AverageIndexCounter, highestAverage);

    float highestValue = -1000000000.0;
    float lowestValue = 1000000000.0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 7; j++) {
            if (CityTemps[i][j] > highestValue) {
                highestValue = CityTemps[i][j];
            }
            if(CityTemps[i][j] < lowestValue) {
                lowestValue = CityTemps[i][j];
            }
        }
    }
    float range = highestValue - lowestValue;
    printf("The overall temperature range is: %.2f\n", range);
    return 0;
}
