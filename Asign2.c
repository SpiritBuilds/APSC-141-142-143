#include <stdio.h>
#include <math.h>

// Defining the constant values that will not change no matter the state of the circuit
// in ohms
#define CIRCUIT_RESISTANCE 10.00
#define BULB_RESISTANCE 8.00

int main(void) {

    //Initializing the variable t which represents time, value is the input from user
    float t;
    printf("Enter time in seconds:"); //Prompting user to enter time
    scanf("%f",&t); //assigning the time value to the "t" variable

    float sourceVoltage = (float) 10*cos((2*M_PI*t)); //function that return the voltage of the circuit as a function of time
    //printf("source voltage: %.f\n", sourceVoltage);
    float current = (float) sourceVoltage/CIRCUIT_RESISTANCE; //calculating the current at that voltage using ohms law
    //printf("current: %.2f\n", current);
    float bulbVoltage = (float) current*BULB_RESISTANCE; // determining the voltage accros the bulb using ohms law
    printf("bulb voltage: %.2f\n", bulbVoltage);

    if(bulbVoltage > 1.00 && bulbVoltage < 5.00) { // checks if the voltage that would be given to the bulb is within the accepted range
        // communicate the necessary info if the condition is true
        printf("Source voltage is positive\n");
        printf("The voltage of the bulb is %.2f\n", bulbVoltage);
        printf("\n");
        printf("The bulb is on");
    } else if (sourceVoltage > -0.01 && sourceVoltage < 0.01) { // checks if the voltage falls within the accepted values considerd as 0
        printf("Source voltage is 0\n");// tells user that Voltage at that time is zero
    }else if (sourceVoltage < -0.64) { //checks to see if the source voltage is too negative and will trigger switch one
        // this condition has to come before the next one because they are checked sequentially and would overwrite each other
        printf("Source voltage is negative\n");
        printf("Switch 1 is closed\n");
        printf("The voltage of the bulb is 0.00 V\n");
        printf("The bulb is not on\n");
    }else if (sourceVoltage < -0.01 && !(sourceVoltage < -0.64)) {//The code checks for voltages smaller than -0,64 before this so the ! (not) statement is just a redundancy to make sure that it works no matter the edge case
        //When voltage is negative but not negative enough to activate the threshold of the switch
        printf("Source voltage is negative\n");
        printf("The bulb is not on");
    }  else if (sourceVoltage > 7) {// This condition checks if switch 2 should is activated
        printf("Source voltage is positive\n");
        printf("Switch 2 is closed\n");
        printf("The voltage of the bulb is 0.00 V\n");
        printf("The bulb is not on\n");
    } else { // The last possible (reasonable) state where the voltage is positive but outside the operating range of the bulb
        printf("Source voltage is positive\n");
        printf("The bulb is not on\n");
    }
    return 0;
}

// A switch case statement was not used because it requires values that evaluate to integers
// and doing this would require other conditionals that assign a value that then gets checked
// so i decided against this course of action.
//
//A possible improvement of this code is using constants  or variable for the switch thresholds
// This would make the code applicable to other circuits and situations
// It would also improve readability

