/*
 *Economic Feasibility Calculator
 *
 * This code should determine whether a project is economically feasible and worth pursuing
 * by determining the present value and payback period
 *
 * APSC 143 Assignment 1
 *
 */

// Including the necessary libraries
#include <stdio.h> // gives us functionality to handle inputs and outputs
#include <math.h> // gives us mathe functions line pow()

int main() {

    //Declaring variables that represent the project parameters
    double initialCost, annuity, interestRate;
    short lifeSpan;

    //User input section
    //Prompting User to enter values and assigning them to the corresponding variables
    printf("Enter the initial cost of the project: $");
    scanf("%lf", &initialCost);

    printf("Enter the annuity of the project: $");
    scanf("%lf", &annuity);

    printf("Enter the interest rate in %%:");
    scanf("%lf", &interestRate);

    printf("Enter the lifespan of the project in years:");
    scanf("%hd", &lifeSpan);

    //Calculating present value

    interestRate = interestRate/100; //Converting interest rate to decimal

    float presentValue = -initialCost; //Starting value is the negative because it is an expense

    //Keep looping till the lifespan of the project is reached
    for (short year = 1; year <= lifeSpan; year++) {
        //Sum up the present value of each year's annuity
        presentValue += annuity/pow(1+interestRate, year);
    }

    //Determine and output economic feasibility
    if (presentValue > 0) {
        printf("Present worth of the project = $%.2f\n", presentValue);
        printf("The project is economically feasible.\n");
    }else {
        printf("Present worth of the project = -$%.2f\n", -presentValue); //negative sign before dollar sign
        printf("The project is not economically feasible.\n");
    }

    //Determining the payback period
    float total = -initialCost; // start in debt, once paid back, net total is 0
    short paybackTime = 0; //Acts as a counter that counts the years (iterations of the while loop)
    //loop as long as net value is less than 0
    while (total <= 0) {
        paybackTime++; //add one year every time, counting
        total += annuity/pow(1+interestRate, paybackTime);
    }
    printf("The payback period for this project is %hd years.\n", paybackTime);

    return 0;
}
