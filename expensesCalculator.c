#include <stdio.h>
#include "expensesCalculator.h"

void inputCategories(Catergory categories[], int *count){
  printf("How many Categories do you need to fill out? (Car, Gas, Housing, etc) ");
  scanf("%d", count);

  if(*count > MAX_CATEGORIES || *count <= 0){
    printf("Invalid number of categories.\n");
    *count = 0;
    return;
  }

  float totalPercent = 0;

  for (int i = 0; i< *count; i++){
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
