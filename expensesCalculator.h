#ifndef EXPENSESCALCULATOR_H
#define EXPENSESCALCULATOR_H

#define MAX_CATEGORIES 10

typedef struct {
  char name[50];
  float percentage;
  float amount;
}

Category;

void inputCategories(Category categories[], int *count);
void calculateExpenses(Category categories[], int count, float income);
void displayExpenses(Category categories[], int count);

void expensesCalculator();

#endif
