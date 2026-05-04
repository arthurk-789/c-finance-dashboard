#ifndef TAX_CALCULATOR_H
#define TAX_CALCULATOR_H

enum MaritalStatus { SINGLE, MARRIED };
enum State { CA, TX, NY, FL, UNKNOWN_STATE };

struct TaxBracket {
	double min;
	double max;
	double rate;
};

struct TaxProfile {
	double income;
	enum MaritalStatus status;
	enum State state;
	int numDependents;
};

struct TaxResult {
	double federalTax;
	double stateTax;
	double ficaTax;
	double totalTax;
	double effectiveRate;
	double afterTax;
};

struct TaxResult calculatetax(struct TaxProfile *p);
void taxCalculator();

#endif