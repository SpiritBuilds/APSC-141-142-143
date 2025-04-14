#include <stdio.h>

#define DAYS_IN_MONTH 30

int main(void)
{
    float dailyConsumption;
    int first100 = 100;
    int second100 = 200;
    float FirstRate = 0.1;
    float SecondRate = 0.15;
    float ThirdRate = 0.20;
    float bill;
    printf("Please enter your daily electricity consumption in kWh :");
    scanf("%f", &dailyConsumption);

    float monthlyConsumption = dailyConsumption * DAYS_IN_MONTH;

    if (monthlyConsumption <= first100 ) {
        bill = monthlyConsumption * FirstRate;
    }// no need to check if it is smaller than 100 because condition passed
    else if (monthlyConsumption <= second100) {
        bill = (first100 * FirstRate) + ((monthlyConsumption-first100) * SecondRate);
    } else {
        bill = (first100 * FirstRate) + (100 * SecondRate) + (monthlyConsumption-second100) * ThirdRate;
    }

    printf("Your total monthly consumption is: %.2f kWh\n", monthlyConsumption);
    printf("The bill calculated based on tiered pricing is $%.2f\n", bill);

    return 0;
}
