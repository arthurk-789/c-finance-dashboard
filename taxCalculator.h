#ifndef TAX_CALCULATOR_H
#define TAX_CALCULATOR_H

enum MaritalStatus { SINGLE, MARRIED };
enum State {
	AL, AK, AZ, AR, CA, CO, CT, DE, FL, GA,
	HI, ID, IL, IN, IA, KS, KY, LA, ME, MD,
	MA, MI, MN, MS, MO, MT, NE, NV, NH, NJ,
	NM, NY, NC, ND, OH, OK, OR, PA, RI, SC,
	SD, TN, TX, UT, VT, VA, WA, WV, WI, WY,
	DC,
	UNKNOWN_STATE
};

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