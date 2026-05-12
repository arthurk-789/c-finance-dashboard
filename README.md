# C Finance Dashboard

A terminal-based financial dashboard written in C, featuring tools like loan and tax calculators.

## Features

- Simple terminal-based user interface
- Loan calculator for estimating monthly payments, total repayment, and total interest
- Tax calculator for basic income tax estimation
- Expenses calculator for tracking or calculating expenses
- Retirement calculator for estimating retirement savings
- Savings tracker for basic savings management
- Modular file structure using separate source and header files for each feature

### How To Run

- In powershell: `gcc financialDashboard.c loanCalculator.c taxCalculator.c expensesCalculator.c retirementCalculator.c savingsTracker.c -o dashboard -lm
./dashboard`
- In BASH: `gcc financialDashboard.c loanCalculator.c taxCalculator.c expensesCalculator.c retirementCalculator.c savingsTracker.c -o dashboard -lm && ./dashboard`
