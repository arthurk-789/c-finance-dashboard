// Final Project check-in: Financial Dashboard
// Group 5: Ryan Hoang, Arthur Karapetyan, Ethan Meza, Anthony Keshishian, Jack Schoebel
// 04/19/2026

#include <stdio.h>
#include <math.h>

// Functions
void menu();
int getOption();
void taxCalculator();
void loanCalculator();

int main()
{
  int choice;
  do {
    menu();
    choice = getOption();
    switch(choice) {
      case 1:
	 break;
      case 2:
         printf ("Exiting program. Thank you for using our program!\n");
         break;
      }
  } while(choice != 2);

  return 0;          
}

void menu(){
  printf ("----------------------------------------\n");
  printf ("          FINANCIAL DASHBOARD\n");
  printf ("----------------------------------------\n");
  printf ("1. Calculate Tax\n");
  printf (“2. Calculate Loan\n”);
  printf (“3. Set Savings Goal\n”);
  printf ("4. Exit\n");
}

int getOption(){
  int choice;
  int checkValue;
  do {
    printf("Please enter your choice: ");
    checkValue = scanf("%d", &choice); // checkValue = 1 (success) otherwise it is fail
    if(checkValue != 1 || choice < 1 || choice > 2){
      printf("Invalid input. Please re-enter your choice!\n");
    }
  } while(checkValue != 1 || choice < 1 || choice > 2);
  
  return choice;
}

