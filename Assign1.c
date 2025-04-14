/*
 * This Code should figure out how many students we need
 * it should also tell the user how long it will take to complete the challenge
 * based on that info
 *
 * APSC 143 Assignment 1
 *
 */

// Including the necessary libraries
#include <math.h> // gives us the e constant and other useful math functions
#include <stdio.h> // gives us functionality to handle inputs and outputs
//#include <stdlib.h>

// defining constant values used throughout the program
#define GRAVITY 9.81
#define MAX_LOAD 250

int main(void)
{
    //Variable initialization
    float boxSpringMass;
    float massThrone;

    //Prompting User to enter info
    printf("Enter the mass of the box spring in kg:");
    //getting that input, then assign it to a variable
    scanf("%f", &boxSpringMass);
    printf("Enter the mass of the throne in kg:");
    scanf("%f", &massThrone);
    printf("\n");

    // Initializing variable and assigning values (in the same line)
    const float totalLoad = (boxSpringMass + massThrone)*(GRAVITY); //in newtons (N)
    const float totalMass = boxSpringMass + massThrone; //in Kg
    const short numberStudents = ceil(totalLoad/MAX_LOAD); //Whole number for minimum students required to respect max load of 250N
    const float time = (totalMass*(4-(pow(M_E,(0.1*numberStudents)))))/60; //divide by 60 for time in minutes ex: 5.30 minutes
    const int minutes = floor(time); //returns on the calculated minutes of the time
    const float seconds = floor((time-minutes)*60); //eliminates minutes, converts minutes to seconds and removes decimals

    printf("The ThunderMugz will need a minimum of %d students to carry it.\n", numberStudents);
    printf("It will take %d minutes and %0.0f seconds to complete the ThunderMugz challenge.", minutes, seconds);
    printf("\n");
    return 0;
}
