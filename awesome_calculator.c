#include <stdio.h>
#include <math.h>

void operations() {
    float Value[99];
    int Num, i;
    float mean = 0, var = 0, DP = 0, sum = 0, sum_var = 0;
    int scanf_result;

    printf("\nEnter the number of values: ");
    scanf_result = scanf("%d", &Num);
    if (scanf_result != 1 || Num <= 0 || Num > 99) {
        printf("Invalid entry for number of values. Please enter a positive integer less than or equal to 99.\n");
        return;
    }
    while (getchar() != '\n'); // Clear input buffer

    printf("\nEnter %d values, pressing the enter key after each value:\n", Num);
    for (i = 0; i < Num; i++) {
        printf("Value %d: ", i + 1);
        while (scanf("%f", &Value[i]) != 1) {
            printf("Invalid input. Please enter a numeric value.\n");
            while (getchar() != '\n'); // Clear input buffer
            printf("Value %d: ", i + 1);
        }
        sum += Value[i];
    }

    mean = sum / (float)Num;

    for (i = 0; i < Num; i++) {
        float difer = Value[i] - mean;
        sum_var += pow(difer, 2);
    }
  
    var = sum_var / (float)Num;
    DP = sqrt(var);
    
    printf("\nMean = %.2f\n", mean);
    printf("Variance = %.2f\n", var);
    printf("Standard Deviation = %.2f\n", DP);
}

int main() {
    char input = 'y'; // Initialize input to 'y' to enter the loop
    int scanf_result; // Variable to store the result of scanf

    printf("\n*************************************");
    printf("\n*         AWESOME CALCULATOR        *");
    printf("\n*************************************\n");

    do {
        printf("\nWould you like to do an operation?\n\"Y\" = Yes\t\"N\" = No\n");
        scanf_result = scanf(" %c", &input);
        if (scanf_result != 1 || (input != 'y' && input != 'Y' && input != 'n' && input != 'N')) { // Check for valid input
            printf("Invalid input. Please enter 'Y' or 'N'.\n");
            input = 'y'; // Reset input to avoid infinite loop
            while (getchar() != '\n'); // Clear input buffer
            continue; // Skip the rest of the loop and restart
        }
        if (input == 'y' || input == 'Y') {
            operations(); // Call the function to calculate standard deviation
        }
    } while (input == 'y' || input == 'Y');
    
    printf("\nThe program ended");
    
    return 0;
}