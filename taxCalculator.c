#include "taxCalculator.h"
#include <stdio.h>
#include <string.h>
#include <conio.h>

struct TaxBracket federalSingle[] = {
    {0, 11925, 0.10}, {11926, 48475, 0.12}, {48476, 103350, 0.22},
    {103351, 197300, 0.24}, {197301, 250525, 0.32}, {250526, 626350, 0.35},
    {626351, -1, 0.37}
};

struct TaxBracket federalMarried[] = {
    {0, 23850, 0.10}, {23851, 96950, 0.12}, {95951, 206700, 0.22},
    {206701, 394600, 0.24}, {394601, 501050, 0.32}, {501051, 751600, 0.35},
    {751601, -1, 0.37}
};

// --- State Brackets ---

// California (simplified)
struct TaxBracket stateBrackets_CA[] = {
    {0, 10412, 0.01}, {10412, 24684, 0.02}, {24684, 38959, 0.04},
    {38959, 54081, 0.06}, {54081, 68350, 0.08}, {68350, 349137, 0.093},
    {349137, 418961, 0.103}, {418961, 698274, 0.113}, {698274, -1, 0.123}
};

// New York (simplified, single)
struct TaxBracket stateBrackets_NY[] = {
    {0, 17150, 0.04}, {17150, 23600, 0.045}, {23600, 27900, 0.0525},
    {27900, 161550, 0.0585}, {161550, 323200, 0.0625},
    {323200, 2155350, 0.0685}, {2155350, -1, 0.0882}
};

// Texas and Florida have no state income tax

double calcFromBrackets(double income, struct TaxBracket *brackets, int numBrackets) {
	double tax = 0.0;
	for (int i = 0; i < numBrackets; i++) {
		if (income <= brackets[i].min) break;

		double top = (brackets[i].max == -1) ? income : brackets[i].max;
		double taxable = ((income < top) ? income: top) - brackets[i].min;
		tax += taxable * brackets[i].rate;
	}
	return tax;
}

double calcFederalTax(struct TaxProfile *p) {
	double deduction;
	switch (p->status) {
		case MARRIED: deduction = 29200; break;
		default: deduction = 14600; break;
	}

	// Dependents deduction (2000 per child)
	deduction += p->numDependents * 2000;

	double taxableIncome = p->income - deduction;
	if (taxableIncome < 0) taxableIncome = 0;

	switch (p->status) {
		case MARRIED:
			return calcFromBrackets(taxableIncome, federalMarried, 7);
		default:
			return calcFromBrackets(taxableIncome, federalSingle, 7);
	}
}

double calcStateTax(struct TaxProfile *p) {
	switch (p->state) {
		case CA:
			return calcFromBrackets(p->income, stateBrackets_CA, 9);
		case NY:
			return calcFromBrackets(p->income, stateBrackets_NY, 7);
		case TX:
		case FL:
		default:
			return 0.0;
	}
}

double calcFICA(double income) {
	double ss_wage_base = 168600;
	double ss = ((income < ss_wage_base) ? income : ss_wage_base) * 0.062;
	double med = income * 0.0145;

	// Additional Medicare tax (0.9%) over $200k
	if (income > 200000) {
		med += (income - 200000) * 0.009;
	}

	return ss + med;
}

struct TaxResult calculateTax(struct TaxProfile *p) {
	struct TaxResult r;
	r.federalTax = calcFederalTax(p);
	r.stateTax = calcStateTax(p);
	r.ficaTax = calcFICA(p->income);
	r.totalTax = r.federalTax + r.stateTax + r.ficaTax;
	r.effectiveRate = (p->income > 0) ? (r.totalTax / p->income) * 100 : 0;
	r.afterTax = p->income - r.totalTax;
	return r;
}

enum State parseState(const char* input) {
	if (strcmp(input, "CA") == 0) return CA;
	if (strcmp(input, "TX") == 0) return TX;
	if (strcmp(input, "NY") == 0) return NY;
	if (strcmp(input, "FL") == 0) return FL;
	return UNKNOWN_STATE;
}

void fillTaxProfile(struct TaxProfile *profile) {
	printf("\n--- Constructing Tax Profile ---\n");
	printf("What is your yearly income: ");
	scanf("%lf", &profile->income);
	printf("\nWhat is your marital status (m = MARRIED, s = SINGLE): ");
	int validInput = 0;
	while (!validInput) {
		char marritalStatusChar;
		scanf(" %c", &marritalStatusChar);
		switch(marritalStatusChar) {
			case 'm':
				profile->status = MARRIED;
				validInput = 1;
				break;
			case 's':
				profile->status = SINGLE;
				validInput = 1;
				break;
			default:
				printf("\nInvalid choice. Choose m = MARRIED or s = SINGLE.");
				break;
		}
	}
	enum State state = UNKNOWN_STATE;
	char input[2];
	while (state == UNKNOWN_STATE) {
		printf("\nWhat state are you in. Use 2 letter state code (i.e. CA): ");
		scanf("%2s", input);
		state = parseState(input);
	}
	profile->state = state;
	printf("\nHow many dependents do you have: ");
	scanf("%d", &profile->numDependents);
}

void taxCalculator() {
	struct TaxProfile profile;

	// Get information from user
	fillTaxProfile(&profile);

	struct TaxResult result = calculateTax(&profile);

	const char *stateNames[] = {"CA", "TX", "NY", "FL"};
	const char *statusNames[] = {"Single", "Married"};

	printf("\n====== Tax Summary ======\n");
	printf("Income $%-5.2f\n", profile.income);
	printf("Marital Status: %-5s\n", statusNames[profile.status]);
	printf("State: %-5s\n", stateNames[profile.state]);
	printf("Dependents: %-5d\n", profile.numDependents);
	printf("-------------------------\n");
	printf("Federal Tax: $%-5.2f\n", result.federalTax);
	printf("State Tax: $%-5.2f\n", result.stateTax);
	printf("FICA Tax: $%-5.2f\n", result.ficaTax);
	printf("-------------------------\n");
	printf("Total Tax: $%-5.2f\n", result.totalTax);
	printf("Effective Rate: %-5.2f%%\n", result.effectiveRate);
	printf("After-tax: $%-5.2f\n", result.afterTax);

	printf("\nHit any key to continue...\n");
	getch();

	return;
}