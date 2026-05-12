#include <stdio.h>
#include <math.h>
#include "savingsTracker.h"

void savingsTracker() {
  double goal;
  double currentSavings;
  double monthlySavings;
  double amountLeft;
  double monthsLeft;

  while (1) {

  printf("\n----- Savings Tracker -----\n");
  printf("Enter the amount of money you want to save: $");

  if (scanf("%lf", &goal) != 1) {
    printf("This is an invalid input, please enter a number.\n");

    while (getchar() != '\n');
    continue;
  }

  printf("How much do you currently have saved: $");
  
  if (scanf("%lf", &currentSavings) != 1) {
    printf("This is an invalid input, please enter a number.\n");

    while (getchar() != '\n');
    continue;
  }

  printf("How much are you willing to save every month: $");
  
  if (scanf("%lf", &monthlySavings) != 1) {
    printf("This is an invalid input, please enter a number.\n");

    while (getchar() != '\n');
    continue;
  }

  // Prompting user if they select numbers that will never finish the actual goal
  if (goal <= 0 || currentSavings < 0 || monthlySavings <= 0) {
    printf("Please enter values that will lead to completing your savings goal.\n");
    continue;
  }

  amountLeft = goal - currentSavings;

  if (amountLeft <= 0) {
    printf("Congrats you have hit your savings goal.\n");
    return;
  }

  monthsLeft = amountLeft/monthlySavings;

  //Summary report of the savings
  printf("\n-----Summary of your savings-----\n");
  printf("Goal: $%.2f\n", goal);
  printf("Your current savings: $%.2f\n", currentSavings);
  printf("Amount left to save: $%.2f\n", amountLeft);
  printf("Months left to reach goal: %.0f months\n", ceil(monthsLeft));

  break;
  }
}
