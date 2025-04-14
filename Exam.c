#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//
// #define MAX_ITEMS 100
// #define MAX_NAME_LENGTH 50
//
// // Function prototypes
// void readInventory(int ids[], char names[][MAX_NAME_LENGTH], int quantities[], int *itemCount);
// void sortInventory(int ids[], char names[][MAX_NAME_LENGTH], int quantities[], int itemCount);
// int binarySearch(int ids[], int itemCount, int searchId);
// void displayInventory(int ids[], char names[][MAX_NAME_LENGTH], int quantities[], int itemCount);
//
//
// int main(void) {
//     int ids[MAX_ITEMS];
//     char names[MAX_ITEMS][MAX_NAME_LENGTH];
//     int quantities[MAX_ITEMS];
//     int itemCount = 0;
//
//     //Read inventory from file
//     readInventory(ids, names, quantities, &itemCount);
//
//     //sort inventory
//     sortInventory(ids, names, quantities, itemCount);
//
//     printf("Sorted Inventory:\n");
//     displayInventory(ids, names, quantities, itemCount);
//
//     int searchId;
//     printf("\nEnter an item ID to search for: ");
//     scanf("%d", &searchId);
//
//     int foundIndex = binarySearch(ids, itemCount, searchId);
//     if (foundIndex != -1) {
//         printf("Item found: ID: %d, Name: %s, Quantity: %d\n",
//                ids[foundIndex], names[foundIndex], quantities[foundIndex]);
//     } else {
//         printf("Item not found.\n");
//     }
//
//     return 0;
// }
//
// void readInventory(int ids[], char names[][MAX_NAME_LENGTH], int quantities[], int *itemCount) {
//     //Open file and check if it worked
//     FILE *file = fopen("inventory.txt", "r");
//     if (file == NULL) {
//         printf("Error opeining file or File not found.\n");
//         fclose(file);//making sure
//         exit(1);//google search on out to end code execution
//     }
//     //AI helped with the formating of fscanf statements and troubleshooting the use of "&"
//     while (*itemCount < MAX_ITEMS && fscanf(file, "%d,%[^,],%d\n", &ids[*itemCount], names[*itemCount], &quantities[*itemCount]) == 3) {
//         (*itemCount)++;
//     }
//     fclose(file);
// }
//
// //Bubble sort from course notes
// void sortInventory(int ids[], char names[][MAX_NAME_LENGTH], int quantities[], int itemCount) {
//     int swapped;
//     for (int i = 0; i < itemCount - 1; i++) {
//         swapped = 0;
//         for (int j = 0; j < itemCount - i - 1; j++) {
//             if (ids[j] > ids[j + 1]) {
//                 // Swap IDs
//                 int tempId = ids[j];
//                 ids[j] = ids[j + 1];
//                 ids[j + 1] = tempId;
//
//                 // Swap names
//                 char tempName[MAX_NAME_LENGTH];
//                 strcpy(tempName, names[j]);
//                 strcpy(names[j], names[j + 1]);
//                 strcpy(names[j + 1], tempName);
//
//                 // Swap quantities
//                 int tempQuantity = quantities[j];
//                 quantities[j] = quantities[j + 1];
//                 quantities[j + 1] = tempQuantity;
//
//                 swapped = 1;
//             }
//         }
//         // If no swapping, array is already sorted
//         if (swapped == 0)
//             break;
//     }
// }
//
// //Binary search from course notes
// int binarySearch(int ids[], int itemCount, int searchId) {
//     int startIndex = 0;
//     int endIndex = itemCount - 1;
//     int middleIndex;
//
//     while (1) {
//         middleIndex = startIndex + (endIndex - startIndex) / 2;
//
//         if (searchId == ids[middleIndex]) {
//             return middleIndex;  // Desired element found
//         } else if ((endIndex - startIndex) < 1) {
//             return -1;  // Desired element is not in the array
//         } else if (searchId < ids[middleIndex]) {
//             endIndex = middleIndex - 1;
//         } else {
//             startIndex = middleIndex + 1;
//         }
//     }
// }
//
//
// void displayInventory(int ids[], char names[][MAX_NAME_LENGTH], int quantities[], int itemCount) {
//     printf("ID\tName\t\tQuantity\n");//AI used for the formatting of print statements (\t functionality creates horizontal tabs
//     //The horizontal tabs improve readability
//     printf("--------------------------------\n");
//     for (int i = 0; i < itemCount; i++) {
//         printf("%d\t%-15s\t%d\n", ids[i], names[i], quantities[i]);
//         //AI helped with spacing of the output
//     }
// }

// int recursiveSum(int array[], int size);
//
// int main() {
//     // Declare and initialize array with 10 integers
//     int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//
//     // Calculate sum using recursive function
//     int sum = recursiveSum(array, 10);
//
//     // Print the array elements, helps debugging and makes the functionality of the program more clear
//     printf("Elements to be summed: ");
//     for (int i = 0; i < 10; i++) {
//         printf("%d ", array[i]);
//     }
//     printf("\n");
//
//     // Print the sum
//     printf("Sum of all elements: %d\n", sum);
//
//     return 0;
// }
//
// int recursiveSum(int array[], int size) {
//     // Base case: if size is 0, the array is empty
//     if (size <= 0) {
//         return 0;
//     }
//
//     //Recursion:
//     /*
//      * add the value at the current index to the sum of the rest of the values of the other indices
//      * so to add the other values, it needs to call the function again using recursion
//      * repeat the process until we reach the base case, when there is no array left
//      */
//
//     return array[size - 1] + recursiveSum(array, size - 1);
// }

// #define MAX_NAME_LENGTH 50
// #define MAX_NAMES 100
//
// void processNames(char names[][MAX_NAME_LENGTH], int *size) {
//     int i, j, k;
//     for (i = 0; i < *size; i++) {
//         // Convert first letter to uppercase and rest to lowercase
//         if (names[i][0] != '\0') {
//             names[i][0] = toupper(names[i][0]);
//             for (j = 1; names[i][j] != '\0'; j++) {
//                 names[i][j] = tolower(names[i][j]);
//             }
//         }
//
//         // Remove names shorter than 3 characters
//         if (strlen(names[i]) < 3) {
//             for (k = i; k < *size - 1; k++) {
//                 strcpy(names[k], names[k + 1]);
//             }
//             (*size)--;
//             i--; // Recheck the current index as it now contains the next name
//         }
//     }
// }
//
// int main() {
//     char names[MAX_NAMES][MAX_NAME_LENGTH];
//     int numNames, i;
//
//     printf("How many names will you input? ");
//     scanf("%d", &numNames);
//     getchar(); // Consume the newline character
//
//     if (numNames > MAX_NAMES) {
//         printf("Too many names. Maximum allowed is %d.\n", MAX_NAMES);
//         return 1;
//     }
//
//     printf("Enter the names:\n");
//     for (i = 0; i < numNames; i++) {
//         fgets(names[i], MAX_NAME_LENGTH, stdin);
//         names[i][strcspn(names[i], "\n")] = 0; // Remove newline character
//     }
//
//     processNames(names, &numNames);
//
//     printf("After processing: ");
//     for (i = 0; i < numNames; i++) {
//         printf("%s", names[i]);
//         if (i < numNames - 1) {
//             printf(", ");
//         }
//     }
//     printf("\n");
//
//     return 0;
// }

// void processNames(char names[][100], int *size);
//
// int main() {
//     int numberOfNames;
//     printf("Enter the number of names: ");
//     scanf("%d", &numberOfNames);
//
//     char names[numberOfNames][100];
//
//     printf("Enter the names:\n");
//     for (int i = 0; i < numberOfNames; i++) {
//         scanf("%s", names[i]);
//     }
//
//     processNames(names, &numberOfNames);
//
//     // Print the processed names
//     printf("Processed names: ");
//     for (int i = 0; i < numberOfNames; i++) {
//         printf("%s", names[i]);
//         if (i < numberOfNames - 1) {
//             printf(", ");
//         }
//     }
//     printf("\n");
//
//     return 0;
// }
//
// // Function to process names
// void processNames(char names[][100], int *size) {
//     //using a pointer for size allows us to change the size of the array more easily
//     int validNameCounter = 0;
//     char processedNames[*size][100];
//
//     for (int i = 0; i < *size; i++) {
//         int len = strlen(names[i]);
//         if (len < 3) {
//             // Skip names shorter than 3 characters
//             continue; //google search skipping iterations in a loop in c, and c equivalent of python "pass" keyword
//         }
//         // Convert first character to uppercase if it's lowercase
//         if (names[i][0] >= 'a' && names[i][0] <= 'z') {
//             names[i][0] -= 32;//Google search on unicode and switching for lowercase to upper, without using new library
//         }
//         // Convert the rest of the characters to lowercase, j starts at 1
//         for (int j = 1; j < len; j++) {
//             if (names[i][j] >= 'A' && names[i][j] <= 'Z') {
//                 names[i][j] += 32;
//             }
//         }
//         // Add processed name to a temporary list
//         strcpy(processedNames[validNameCounter], names[i]);
//         validNameCounter++;
//     }
//
//     // Update the original array and size with valid names
//     for (int i = 0; i < validNameCounter; i++) {
//         strcpy(names[i], processedNames[i]);
//     }
//     *size = validNameCounter;//updates the size of the array with the valid names only
// }

// int main() {
//     int unsortedArray[5]= {7, 4, 5, 2};
//     int insertionElement;
//     int j;
//     for(int i = 1; i< sizeof(unsortedArray)/ sizeof(unsortedArray[0]); i++){
//         insertionElement = unsortedArray[i];
//         for(j = i-1; j > -1; j--){
//             if(insertionElement< unsortedArray[j]){
//                 unsortedArray[j+1] = unsortedArray[j];
//             }else{
//                 break;
//             }
//         }
//         unsortedArray[j+1] = insertionElement;
//     }
//     for(int i=0; i< sizeof(unsortedArray)/ sizeof(unsortedArray[0]); i++){
//         printf("%d\n", unsortedArray[i]);
//     }
// }

// #include <stdio.h>
// #include <stdlib.h>
//
// int* f(int size) {
//     int* arr = (int*)malloc(size * sizeof(int));
//     for (int i = 0; i < size; i++) {
//         arr[i] = i + 1;
//     }
//     return arr;
// }
//
// int main(void) {
//     int* arr = f(4);
//     arr[0] = 7;
//     arr[1] = 8;
//     free(arr);
//
//     arr = f(2);
//     printf("%d %d\n", arr[0], arr[1]);
//     return 0;
// }

int f(int n) {
    if(n <= 1) return 1;
    return n * f(n - 1);
}

int main(void) {
    int x = 4;
    int y = f(x);
    printf("%d\n", y);
}