/*
 * This code reads values from external and external file, to calculate the value of the Ores
 * Then the program sorts the values and puts them in an output file
 *
 * Student #: 20454310
 * Student Name: Mark Gebraiel
 * APSC 143 Assignment 6 - Searching & Sorting, Memory Management
 *
 */


//Including necessary libraries
#include <stdio.h>
#include<stdlib.h>

#define ORE_PRICE 8500.0 // Price per kg in dollars, the ability to change this value makes the program more useful as it can apply to other contexts

int main(void) {

    //Initializing variables and creating the input file
    int numPayloads;
    FILE* inputfile = fopen("payloads.txt", "r");//open the input file in read only mode, we do not want to modify this file (using the program)

    //Check if file exists
    if (inputfile == NULL) {
        printf("File not found.\n");
        fclose(inputfile);
        return 1;
    }

    //Determine the number of payloads
    fscanf(inputfile, "%d", &numPayloads);
    if(numPayloads <= 0) {
        printf("No payloads in file.\n");
        fclose(inputfile);
        return 2;//Tracking the return value can help with debugging other return statements will have different values
    }

    //Memory allocation using malloc for 2D array
    float** payLoadData = (float**)malloc(numPayloads * sizeof(float*));
    //Check if memory allocation was successful
    if(payLoadData == NULL) {
        printf("Memory allocation error.\n");
        fclose(inputfile);
        return 3;
    }

    //for each row, initialize/allocate memory for the columns
    for (int i = 0; i < numPayloads; i++) {
        payLoadData[i] = (float*)malloc(3*sizeof(float));
        //Check if the memory allocation was successful, otherwise close files, free up any memory and end program.
        if(payLoadData[i] == NULL) {
            //Notify user of the error, then loop through a free any allocated memory
            printf("Memory allocation error.\n");
            for(int j = 0; j < i; j++) {
                free(payLoadData[j]);
            }
            //free memory allocated to payLoadData list and close the input file.
            free(payLoadData);
            fclose(inputfile);
            return 4;
        }
    }

    //For each payload read the value in the input file by respecting format specification and assign those values to the first 2 columns.
    //of the array
    for (int i = 0; i < numPayloads; i++) {
        //Read the total mass and grade of ores
        fscanf(inputfile, "%f %f", &payLoadData[i][0], &payLoadData[i][1]);
        //Calculate ore value (third column): total mass * ore grade * ore price
        payLoadData[i][2] = payLoadData[i][0] * payLoadData[i][1] * ORE_PRICE;
    }

    //Close the input file as it is no longer of use, the next section of the program will move from input to output
    fclose(inputfile);

    //Printing the unsorted values to the console
    printf("Payload Data:\n");
    printf("Total Mass / Grade / Ore Value\n");
    for (int i = 0; i < numPayloads; i++) {
        printf("   %.0f      %.2f    $%.0f\n", payLoadData[i][0], payLoadData[i][1], payLoadData[i][2]);
        //printf("%.0f %.2f $%.0f\n", payLoadData[i][0], payLoadData[i][1], payLoadData[i][2]);
    }

    //No need to sort if there is one or less entries
    if(numPayloads > 1) {
        //Bubble sort algorithm
        for(int i = 0; i < numPayloads - 1; i++) {
            int swapped = 0;//Track if a swap has occurred
            for(int j = 0; j < numPayloads - i - 1; j++) {
                //Compare the ore values of row "j" with the next row and check if swap should happen
                if(payLoadData[j][2] < payLoadData[j + 1][2]) {
                    //Swap entire row
                    float* temp = payLoadData[j];
                    payLoadData[j] = payLoadData[j + 1];
                    payLoadData[j + 1] = temp;
                    swapped = 1;
                }
            }
            //If no swap occurs, this means the array is sorted and the program can move on
            if(!swapped) {
                break;
            }
        }
    }

    //Open or create a new output file and output the sorted data in the desired output/spacing format
    FILE* outputfile = fopen("ores.txt", "w");

    //will only proceed to output values to the file if it exists
    if (outputfile != NULL) {
        fprintf(outputfile, "Sorted Payload Data:\n");
        fprintf(outputfile, "Total Mass / Grade / Ore Value\n");
        for (int i = 0; i < numPayloads; i++) {
            //Outputting the table in correct spacing format
            fprintf(outputfile, "   %.0f      %.2f    $%.0f\n", payLoadData[i][0], payLoadData[i][1], payLoadData[i][2]);
        }
        //Close the file, it is no longer in use
        fclose(outputfile);
    } else {
        printf("Error with output file\n");
        free(payLoadData);
        return 5;
    }

    //Because the rows of each array were created independently, here they are freed independently
    for (int i = 0; i < numPayloads; i++) {
        free(payLoadData[i]);
    }

    //The main block of allocated memory for the payload data is finally freed.
    free(payLoadData);

    return 0;
}
