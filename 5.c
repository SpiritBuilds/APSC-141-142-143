/*
 * This Code adds stings to a list and transforms them to acronyms
 * After the acronyms can be searched for their matching string
 *
 * APSC 143 Assignment 5 - Strings
 *
 */


//Including necessary libraries
#include <stdio.h>
#include <string.h>

int main(void) {

    //Prompting the use to enter how many entries they want to add
    int numEntries;
    printf("Enter number of acronyms to add to the database:");
    scanf("%d", &numEntries);
    getchar(); // Clearing the buffer of the scanf Statement, without this there is wired behaviour with using fgets afterwards.

    //Creating the two arrays necessary for the program
    char original[numEntries][51];
    char acronyms[numEntries][51];

    //Loop that prompts user, and converts the entries right after
    for (int i = 0; i < numEntries; i++) {
        printf("Enter the string to convert into an acronym:");
        fgets(original[i], 51, stdin);
        //Remove the new line character and replace with the null character for strings
        if (original[i][strlen(original[i]) - 1] == '\n') {
            original[i][strlen(original[i]) - 1] = '\0';
        }
        //Use a separate counter because j counter for the letters and index of acronyms do not match.
        int acronymIndex = 0;
        for (int j = 0; j < strlen(original[i]); j++) {
            if ((original[i][j-1] == ' ' && j > 0) || j == 0) { // if the previous letter is a space, and we are not at the first index, or we are the first index.
                //Using ASCII theory
                if (original[i][j] >= 'A' && original[i][j] <= 'Z') {// check if the letter is uppercase, the code inside will only execute if all requirements are met
                    acronyms[i][acronymIndex] = original[i][j]; //Put the letter in the acronym, make sure index is not mixed with j
                    acronymIndex++;// go to next index for the following iteration
                }
            }
        }
        acronyms[i][acronymIndex] = '\0';//Makes sure the last index contains the null character so strings are properly formatted for c
        printf("Acronym of \"%s\" is \"%s\".\n", original[i], acronyms[i]);// output results to user
    }

    char userInput[51]; // string input to compare with the list of acronyms
    while(1) {
        //prompt user and format the input to respect string requirments
        printf("\nEnter the acronym of the string you would like to see, or enter 0 to exit:");
        fgets(userInput, 51, stdin);
        if (userInput[strlen(userInput) - 1] == '\n') {
            userInput[strlen(userInput) - 1] = '\0';
        }
        //compare input, if it is 0 then exit
        if (strcmp(userInput, "0") == 0) {
            break;
        }
        int found = 0; //tracks if the acronym is found, only checked outside the for loop, so it's now always printed for the non-matching acronyms
        for (int i = 0; i < numEntries; i++) {
            if (strcmp(userInput, acronyms[i]) == 0) {
                printf("The corresponding string to \"%s\" is \"%s\".\n", acronyms[i], original[i]);
                found = 1;
            }
        }
        //Literally: if not found say so, uses the fact that in C 0 represents false and 1 true
        if (!found) {
            printf("Acronym not found.\n");
        }
    }
    return 0;
}
