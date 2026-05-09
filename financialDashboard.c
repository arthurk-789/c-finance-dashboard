// Final Project check-in: Financial Dashboard
// Group 5: Ryan Hoang, Arthur Karapetyan, Ethan Meza, Anthony Keshishian, Jack Schoebel
// 04/19/2026

#include <stdio.h>
#include <math.h>
#include "taxCalculator.h"
#include "loanCalculator.h"

// Functions
void menu();
int getOption();
void loanCalculator();

int main()
{
	menu();

	return 0;
}

void menu(){
	while (1) {
		printf ("----------------------------------------\n");
		printf ("          FINANCIAL DASHBOARD\n");
		printf ("----------------------------------------\n");
		printf ("1. Calculate Tax\n");
		printf ("2. Calculate Loan\n");
		printf ("3. Set Savings Goal\n");
		printf ("4. 401(k) Retirement Plan\n");		
		printf ("4. Exit\n");
		int choice = getOption();
		switch (choice) {
			case 1:
				taxCalculator();
				break;
			case 2:
				loanCalculator();
				break;
			case 3:
				// set savings goal
				break;
			case 4:
				retirementCalculator();
				break;
			case 5: // Exit
				printf("\nThank you for using our program...\n\n");
				return;
		}
	}
}

int getOption(){
	int choice;
	int checkValue;
	do {
	    printf("Please enter your choice: ");
	    checkValue = scanf("%d", &choice); // checkValue = 1 (success) otherwise it is fail
	    while(getchar() != '\n'); //Clear the input buffer
	    if(checkValue != 1){
	        printf("Invalid input. Please re-enter your choice!\n");
	    }
	    else if(choice < 1 || choice > 5){
			printf("Invalid input. Please re-enter your choice!\n");
		}
	} while(checkValue != 1 || choice < 1 || choice > 5);
	
	return choice;
}