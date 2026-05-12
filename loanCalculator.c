#include <stdio.h>
#include <math.h>
#include "loanCalculator.h"

float getInterestRate(int rating) {
    if (rating == 1) return 0.04f; // excellent credit
    if (rating == 2) return 0.06f; // good credit
    if (rating == 3) return 0.08f; // fair credit
    if (rating == 4) return 0.12f; // poor credit
    if (rating == 5) return 0.10f; // unknown/default credit

    return 0.10f; // default if invalid choice
}

void loanCalculator() {
    float loanAmount;
    int months;
    int rating;
    int hasSpecificRate;
    float annualRate;
    float monthlyRate;
    float monthlyPayment;

    printf("How much $ do you want to borrow: ");
    scanf("%f", &loanAmount);

    printf("Do you have a specific interest rate for this loan?\n");
    printf("1. Yes\n");
    printf("2. No\n");
    printf("Enter choice: ");
    scanf("%d", &hasSpecificRate);

    if (hasSpecificRate == 1) {
        printf("Enter annual interest rate as a percent: ");
        scanf("%f", &annualRate);

        annualRate = annualRate / 100.0f;
    } else {
        printf("What is your approximate credit rating:\n");
        printf("1. Excellent\n");
        printf("2. Good\n");
        printf("3. Fair\n");
        printf("4. Poor\n");
        printf("5. Unknown\n");
        printf("Enter choice (1-5): ");
        scanf("%d", &rating);

        annualRate = getInterestRate(rating);
    }

    printf("How long is this loan duration (months)? ");
    scanf("%d", &months);

    monthlyRate = annualRate / 12.0f;

    monthlyPayment = loanAmount * (monthlyRate * pow(1 + monthlyRate, months)) /
                     (pow(1 + monthlyRate, months) - 1);

    printf("\nMonthly Payment: $%.2f\n", monthlyPayment);
}