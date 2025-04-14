/*
 * Assignment 4 APSC 143
 * Limestone Arrays
 * This program compares physical properties of different limestones,
 * calculates flow velocities, and determines relationships between
 * porosity and flow velocity.
 *
 */

//Including the necessary library
#include <stdio.h>

// Initializing constant values
#define GRADIENT -0.725
#define CROSS_SECTION 1200
//#define CONVERSION_FACTOR 1000000 //This makes it easier to output answers in different units

int main(void){

    // Get the number of limestone samples from user, prompt and store the value in the matching variable
    int numLimeStones;

    printf("Enter the number of limestones to compare: ");
    scanf("%d", &numLimeStones);

    // Declare the 2D arrays that will store the limestone data
    // index reference: data[i][0] = porosity, data[i][1] = hydraulic conductivity, data[i][2] = specific gravity
    double data[numLimeStones][3];

    //Additional column for flow velocitites
    double DataWithFlow[numLimeStones][4];

    //loop: For each limestone, prompt user to enter its corresponding information
    for(int i = 0; i < numLimeStones; i++) {
        printf("Enter the porosity %%, hydraulic conductivity (m/s), and specific gravity for Limestone %d: ", i+1);
        scanf("%lf %lf %lf", &data[i][0], &data[i][1], &data[i][2]);
    }

    //Determine which limestone has the smallest specific gravity
    int limeStoneCount = 0;
    double lowestSpecificGravity = 1;
    for(int i = 0; i < numLimeStones; i++) {
        if(data[i][2] < lowestSpecificGravity) {
            lowestSpecificGravity = data[i][2];
            limeStoneCount = i+1; //Human friendly output to user, accounting for base 0 indexing
        }
    }
    //output result of the lowest specific gravity
    printf("The limestone with the lowest specific gravity is Limestone %d with a specific gravity of %.4lf\n", limeStoneCount, lowestSpecificGravity);

    //Manually copy the data from the initial data list to the array that stores the data with flow
    for(int i = 0; i < numLimeStones; i++) {
        for(int j =0; j < 3; j++) {
            DataWithFlow[i][j] = data[i][j];
        }
    }

    //Calculate the flow velocities and put them in the right spots in the new array
    for(int i = 0; i < numLimeStones; i++) {
        double flowVelocity = (-DataWithFlow[i][1]* CROSS_SECTION * GRADIENT)*1000000;
        DataWithFlow[i][3] = flowVelocity;
    }

    //Print the calculated flow velocities in cm^3
    printf("\nFLow velocities:\n");
    for(int i = 0; i < numLimeStones; i++) {
        printf("Limestone %d: %.2lf cm^3/s\n", i+1, DataWithFlow[i][3]);
    }

    //Determine which stone has the highest flow rate
    double highestFlow = -1;
    int highestFlowCounter=0;
    for(int i = 0; i < numLimeStones; i++) {
        if(DataWithFlow[i][3] > highestFlow) {
            highestFlow = DataWithFlow[i][3];
            highestFlowCounter = i;
        }
    }
    //printf("%d", highestFlowCounter);

    //Determine which stone has the highest porosity
    double highestPorosity = 0;
    int highestPorosityCounter=0;
    for(int i = 0; i < numLimeStones; i++) {
        if(DataWithFlow[i][0] > highestPorosity) {
            highestPorosity = DataWithFlow[i][0];
            highestPorosityCounter = i;
        }
    }
    //printf("%d", highestPorosityCounter);

    //Check if the stone with the highest porosity is the same as the one with the highest flow and print the matching output
    if(highestPorosityCounter == highestFlowCounter) {
        printf("The rock with the highest porosity has the highest flow velocity.\n");
    }else {
        printf("The rock with the highest porosity does not have the highest flow velocity.\n");
    }

    return 0;
}
