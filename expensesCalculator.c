#include <stdio.h>
#include "expensesCalculator.h"

void inputCategories(Category categories[], int *count){
  while (1){
    printf("How many Categories do you need to fill out? (Car, Gas, Housing, etc) ");
    
    if (scanf("%d", count) != 1){
      printf("Invaild response: Please enter a valid number.\n");

      while (getchar() != '\n');

      continue;
    }

    if(*count > MAX_CATEGORIES || *count <= 0){
      printf("Invalid number of categories.\n");
      continue;
    }
      break;
  }

  float totalPercent = 0;

  for (int i = 0; i < *count; i++){
    printf("\n Enter category %d name: ", i +1);
    scanf(" %[^\n]", categories[i].name);

    printf("Enter the percentage for %s: ", categories[i].name);
    scanf("%f", &categories[i].percentage);

    totalPercent += categories[i].percentage;
  }
  if (totalPercent > 100){
    printf("\nWarning: Percentage exceed 100%%!\n");
  }
}

void calculateExpenses(Category categories[], int count, float income){
  for(int i = 0; i < count; i++){
    categories[i].amount = (categories[i].percentage / 100) * income;
  }
}

void displayExpenses(Category categories[], int count){
  printf("\n==== Expenses Breakdown ====\n");

  for (int i = 0; i < count; i++){
    printf("%s: %.2f%% -> $%.2f\n", categories[i].name, categories[i].percentage, categories[i].amount);
  }
}

void expensesCalculator(){

  Category categories[MAX_CATEGORIES];
  int count = 0;
  float income;

  printf("\nEnter your monthly income: $");
  scanf("%f", &income);

  inputCategories(categories, &count);

  if(count == 0){
    return;
  }

  calculateExpenses(categories, count, income);
  displayExpenses(categories, count);
}
