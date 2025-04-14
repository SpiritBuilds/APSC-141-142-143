#include <stdio.h>
#include <math.h>

//Defining constant values used in the program
#define K 0.0965
#define TIME_INTERVAL 0.01 //In seconds

//Reaction function declaration
float reaction(float NH3, float O2, float N2, float H2O, float time);

int main(void) {
    float NH3, O2;
    //Prompt user for input, the initial concentrations of NH3, and O2.
    printf("Enter initial ammonia and oxygen concentrations:");
    scanf("%f %f", &NH3, &O2); // Assign input to corresponding variables
    //simulate the reaction using the initial values inputted by the user.
    reaction(NH3, O2, 0, 0, 0);//call the reaction function
    return 0;
}

// Reaction function that computes the concentration changes over time
// It takes the current concentrations of reactants and products as arguments
float reaction(float NH3, float O2, float N2, float H2O, float time) {
    float rate = K*NH3*(pow(O2, 2)); //Calculate the rate of reaction given the reactants

    // Calculate changes in concentration for each chemical using the rate and time interval
    float deltaNH3 = -1.0*rate*(4*TIME_INTERVAL);//delta signifies change
    float deltaO2 = -1.0*rate*(3*TIME_INTERVAL);
    float deltaN2 = rate*2.0*TIME_INTERVAL;
    float deltaH2O = rate*6.0*TIME_INTERVAL;
    // Assign new concentrations after applying changes
    // New variables created for clarity
    float newNH3 = NH3 + deltaNH3;
    float newO2 = O2 + deltaO2;
    float newN2 = N2 + deltaN2; // Initially Zero(0)
    float newH2O = H2O + deltaH2O; // Initially Zero(0)
    //When the rate drops below the threshold, print the numbers to users and exit the function.
    if (rate <= 0.001) {
        printf("Final Reaction Molarities:\n");
        printf("NH3: %.2f M\n", NH3);
        printf("O2:  %.2f M\n", O2);
        printf("N2:  %.2f M\n", N2);
        printf("H2O: %.2f M\n", H2O);
        printf("The reaction will take %.2f seconds to reach a rate 0.001 M/s.\n", time);
        return time; // Return elapsed time when condition is met
    }
    // Recursively call the function with updated concentrations and incremented time
    return reaction(newNH3, newO2, newN2, newH2O, (time+TIME_INTERVAL));
}