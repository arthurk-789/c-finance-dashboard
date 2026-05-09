#include <stdio.h>
#include <math.h>
#include "retirementCalculator.h"

void retirementCalculator(){
    int currentAge, retirementAge;
    double annualSalary, currentBalance, contributionPercent, employerMatchPercent, employerMatchLimit;
    double salaryIncrease, annualReturn, inflationRate;
    double employeeContribution;
    double employerContribution;
    
    double totalEmployeeContribution = 0;
    double totalEmployerContribution = 0;
    // Get user input
    
    // Basic information
    printf("\n-----BASIC INFORMATION-----\n");
    printf("Current age: ");
    scanf("%d", &currentAge);

    printf("Current annual salary: ");
    scanf("%lf", &annualSalary);
    printf("Current 401k balance: ");
    scanf("%lf", &currentBalance);
    printf("Contribution (%% of salary): ");
    scanf("%lf", & contributionPercent);
    printf("Employer match: ");
    scanf("%lf", &employerMatchPercent);
    printf("Employer match limit: ");
    scanf("%lf", &employerMatchLimit);

    // Projections
    printf("\n-----PROJECTIONS INFORMATION-----\n");    
    printf("Retirement age: ");
    scanf("%d", &retirementAge);

    printf("Expected salary increase: ");
    scanf(" %lf", &salaryIncrease);
    printf("Expected annual return: ");
    scanf("%lf", &annualReturn);
    printf("Expected inflation rate: ");
    scanf("%lf", &inflationRate);

    for (int year = currentAge; year < retirementAge; year++){

        employeeContribution = annualSalary * (contributionPercent / 100.0); //employee contributes to the retirement accoutn

        //Determine employer matched percentage
        double matchPercent;
        if(contributionPercent < employerMatchLimit){
            matchPercent = contributionPercent;
        }   
        else {
            matchPercent = employerMatchLimit;
        }

        // Calculate employer contribution
        employerContribution = annualSalary * (matchPercent / 100.0) * (employerMatchPercent / 100.0);

        totalEmployeeContribution += employeeContribution;
        totalEmployerContribution += employerContribution;

        //Grow retirement balance
        currentBalance = currentBalance * (1 + annualReturn / 100.0) + employerContribution + employeeContribution;

        //Update salary yearly
        annualSalary = annualSalary * (1 + salaryIncrease / 100.0);

    }
    //Investment return 
    double investmentReturns = currentBalance - totalEmployeeContribution - totalEmployerContribution;

    //Handle inflation
    double balanceAfterInflation = currentBalance / pow(1 + inflationRate / 100.0, retirementAge - currentAge);

    // 4% withdrawal rule
    double yearlyRetirementIncome = currentBalance * 0.04;

    //Print result 
    printf("\n-----RETIREMENT SUMMARY-----\n\n");
    printf("Retirement Age: %d\n", retirementAge);
    printf("Employee Contributions: $%.2f\n", totalEmployeeContribution);
    printf("Employer Contributions: $%.2f\n", totalEmployerContribution);
    printf("\nInvestment Returns: $%.2f\n", investmentReturns);
    printf("Estimated retirement balance: $%.2f\n", currentBalance);
    printf("Inflation-adjusted balance: $%.2f\n", balanceAfterInflation);
    printf("Estimated yearly retirement income: $%.2f\n", yearlyRetirementIncome);

    printf("\nPress enter to return to main menu...\n");
    getchar();
}
