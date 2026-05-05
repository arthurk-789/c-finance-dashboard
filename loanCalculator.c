#include <stdio.h>
#include <math.h>
#include "loanCalculator.h"

float getInterestRate(int rating) {
    if (rating == 1) return 0.04f; // excellent credit
    if (rating == 2) return 0.06f; // good credit
    if (rating == 3) return 0.08f; // fair credit
    if (rating == 4) return 0.12f; // poor credit
}

void loanCalculator() {
    float loanAmount;
    int months;
    int rating;

    printf("How much $ do you want to borrow: ");
    scanf("%f", & loanAmount);

    printf("What is your approximate credit rating:\n");
    printf("1. Excellent\n");
    printf("2. Good\n");
    printf("3. Fair\n");
    printf("4. Poor\n");
    printf("Enter choice (1-4): ");
    scanf("%d", &rating);

    printf("How long is this loan duration (months)?");
    scanf("%d", &months); 

    float annualRate = getInterestRate(rating);

    float monthlyRate = annualRate / 12.0f;

    float monthlyPayment;

    // interest formula
    monthlyPayment = loanAmount * (monthlyRate * pow(1 + monthlyRate, months)) / (pow(1 + monthlyRate, months) - 1);

    printf("\nMonthly Payment: $%.2f\n", monthlyPayment);
}
