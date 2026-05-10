#include <stdio.h>
#include "savingsTracker.h"

void savingsTracker() {
  double goal;
  double currentSavings;
  double monthlySavings;
  double amountLeft;
  double monthsLeft;

  printf("\n----- Savings Tracker -----\n");
  printf("Enter the amount of money you want to save: $");
  scanf("%lf", &goal);

  printf("How much do you currently have saved: $");
  scanf("%lf", &currentSavings);

  printf("How much are you willing to save every month: $");
  scanf("%lf", &monthlySavings);

  // Prompting user if they select numbers that will never finish the actual goal
  if (goal <= 0 || currentSavings < 0 || monthlySavings <= 0) {
    printf("Please enter values that will lead to completing your savings goal.\n");
    return;
  }

  amountLeft = goal - currentSavings;

  if (amountLeft <= 0) {
    printf("Congrats you have hit your savings goal");
    return;
  }

  
