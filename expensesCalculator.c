#include <stdio.h>
#include "expensesCalculator.h"

void inputCategories(Catergory categories[], int *count){
  printf("How many Categories do you need to fill out? (Car, Gas, Housing, etc) ");
  scanf("%d", count);
