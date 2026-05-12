#include "taxCalculator.h"
#include <stdio.h>
#include <string.h>

// --- Forward declarations for bracket data (defined at bottom of file) ---

extern struct TaxBracket federalSingle[];   extern int federalSingle_n;
extern struct TaxBracket federalMarried[];  extern int federalMarried_n;

extern struct TaxBracket stateBrackets_AL_single[];  extern int stateBrackets_AL_single_n;
extern struct TaxBracket stateBrackets_AL_married[]; extern int stateBrackets_AL_married_n;
extern struct TaxBracket stateBrackets_AZ_single[];  extern int stateBrackets_AZ_single_n;
extern struct TaxBracket stateBrackets_AZ_married[]; extern int stateBrackets_AZ_married_n;
extern struct TaxBracket stateBrackets_AR_single[];  extern int stateBrackets_AR_single_n;
extern struct TaxBracket stateBrackets_AR_married[]; extern int stateBrackets_AR_married_n;
extern struct TaxBracket stateBrackets_CA_single[];  extern int stateBrackets_CA_single_n;
extern struct TaxBracket stateBrackets_CA_married[]; extern int stateBrackets_CA_married_n;
extern struct TaxBracket stateBrackets_CO_single[];  extern int stateBrackets_CO_single_n;
extern struct TaxBracket stateBrackets_CO_married[]; extern int stateBrackets_CO_married_n;
extern struct TaxBracket stateBrackets_CT_single[];  extern int stateBrackets_CT_single_n;
extern struct TaxBracket stateBrackets_CT_married[]; extern int stateBrackets_CT_married_n;
extern struct TaxBracket stateBrackets_DE_single[];  extern int stateBrackets_DE_single_n;
extern struct TaxBracket stateBrackets_DE_married[]; extern int stateBrackets_DE_married_n;
extern struct TaxBracket stateBrackets_GA_single[];  extern int stateBrackets_GA_single_n;
extern struct TaxBracket stateBrackets_GA_married[]; extern int stateBrackets_GA_married_n;
extern struct TaxBracket stateBrackets_HI_single[];  extern int stateBrackets_HI_single_n;
extern struct TaxBracket stateBrackets_HI_married[]; extern int stateBrackets_HI_married_n;
extern struct TaxBracket stateBrackets_ID_single[];  extern int stateBrackets_ID_single_n;
extern struct TaxBracket stateBrackets_ID_married[]; extern int stateBrackets_ID_married_n;
extern struct TaxBracket stateBrackets_IL_single[];  extern int stateBrackets_IL_single_n;
extern struct TaxBracket stateBrackets_IL_married[]; extern int stateBrackets_IL_married_n;
extern struct TaxBracket stateBrackets_IN_single[];  extern int stateBrackets_IN_single_n;
extern struct TaxBracket stateBrackets_IN_married[]; extern int stateBrackets_IN_married_n;
extern struct TaxBracket stateBrackets_IA_single[];  extern int stateBrackets_IA_single_n;
extern struct TaxBracket stateBrackets_IA_married[]; extern int stateBrackets_IA_married_n;
extern struct TaxBracket stateBrackets_KS_single[];  extern int stateBrackets_KS_single_n;
extern struct TaxBracket stateBrackets_KS_married[]; extern int stateBrackets_KS_married_n;
extern struct TaxBracket stateBrackets_KY_single[];  extern int stateBrackets_KY_single_n;
extern struct TaxBracket stateBrackets_KY_married[]; extern int stateBrackets_KY_married_n;
extern struct TaxBracket stateBrackets_LA_single[];  extern int stateBrackets_LA_single_n;
extern struct TaxBracket stateBrackets_LA_married[]; extern int stateBrackets_LA_married_n;
extern struct TaxBracket stateBrackets_ME_single[];  extern int stateBrackets_ME_single_n;
extern struct TaxBracket stateBrackets_ME_married[]; extern int stateBrackets_ME_married_n;
extern struct TaxBracket stateBrackets_MD_single[];  extern int stateBrackets_MD_single_n;
extern struct TaxBracket stateBrackets_MD_married[]; extern int stateBrackets_MD_married_n;
extern struct TaxBracket stateBrackets_MA_single[];  extern int stateBrackets_MA_single_n;
extern struct TaxBracket stateBrackets_MA_married[]; extern int stateBrackets_MA_married_n;
extern struct TaxBracket stateBrackets_MI_single[];  extern int stateBrackets_MI_single_n;
extern struct TaxBracket stateBrackets_MI_married[]; extern int stateBrackets_MI_married_n;
extern struct TaxBracket stateBrackets_MN_single[];  extern int stateBrackets_MN_single_n;
extern struct TaxBracket stateBrackets_MN_married[]; extern int stateBrackets_MN_married_n;
extern struct TaxBracket stateBrackets_MS_single[];  extern int stateBrackets_MS_single_n;
extern struct TaxBracket stateBrackets_MS_married[]; extern int stateBrackets_MS_married_n;
extern struct TaxBracket stateBrackets_MO_single[];  extern int stateBrackets_MO_single_n;
extern struct TaxBracket stateBrackets_MO_married[]; extern int stateBrackets_MO_married_n;
extern struct TaxBracket stateBrackets_MT_single[];  extern int stateBrackets_MT_single_n;
extern struct TaxBracket stateBrackets_MT_married[]; extern int stateBrackets_MT_married_n;
extern struct TaxBracket stateBrackets_NE_single[];  extern int stateBrackets_NE_single_n;
extern struct TaxBracket stateBrackets_NE_married[]; extern int stateBrackets_NE_married_n;
extern struct TaxBracket stateBrackets_NJ_single[];  extern int stateBrackets_NJ_single_n;
extern struct TaxBracket stateBrackets_NJ_married[]; extern int stateBrackets_NJ_married_n;
extern struct TaxBracket stateBrackets_NM_single[];  extern int stateBrackets_NM_single_n;
extern struct TaxBracket stateBrackets_NM_married[]; extern int stateBrackets_NM_married_n;
extern struct TaxBracket stateBrackets_NY_single[];  extern int stateBrackets_NY_single_n;
extern struct TaxBracket stateBrackets_NY_married[]; extern int stateBrackets_NY_married_n;
extern struct TaxBracket stateBrackets_NC_single[];  extern int stateBrackets_NC_single_n;
extern struct TaxBracket stateBrackets_NC_married[]; extern int stateBrackets_NC_married_n;
extern struct TaxBracket stateBrackets_ND_single[];  extern int stateBrackets_ND_single_n;
extern struct TaxBracket stateBrackets_ND_married[]; extern int stateBrackets_ND_married_n;
extern struct TaxBracket stateBrackets_OH_single[];  extern int stateBrackets_OH_single_n;
extern struct TaxBracket stateBrackets_OH_married[]; extern int stateBrackets_OH_married_n;
extern struct TaxBracket stateBrackets_OK_single[];  extern int stateBrackets_OK_single_n;
extern struct TaxBracket stateBrackets_OK_married[]; extern int stateBrackets_OK_married_n;
extern struct TaxBracket stateBrackets_OR_single[];  extern int stateBrackets_OR_single_n;
extern struct TaxBracket stateBrackets_OR_married[]; extern int stateBrackets_OR_married_n;
extern struct TaxBracket stateBrackets_PA_single[];  extern int stateBrackets_PA_single_n;
extern struct TaxBracket stateBrackets_PA_married[]; extern int stateBrackets_PA_married_n;
extern struct TaxBracket stateBrackets_RI_single[];  extern int stateBrackets_RI_single_n;
extern struct TaxBracket stateBrackets_RI_married[]; extern int stateBrackets_RI_married_n;
extern struct TaxBracket stateBrackets_SC_single[];  extern int stateBrackets_SC_single_n;
extern struct TaxBracket stateBrackets_SC_married[]; extern int stateBrackets_SC_married_n;
extern struct TaxBracket stateBrackets_UT_single[];  extern int stateBrackets_UT_single_n;
extern struct TaxBracket stateBrackets_UT_married[]; extern int stateBrackets_UT_married_n;
extern struct TaxBracket stateBrackets_VT_single[];  extern int stateBrackets_VT_single_n;
extern struct TaxBracket stateBrackets_VT_married[]; extern int stateBrackets_VT_married_n;
extern struct TaxBracket stateBrackets_VA_single[];  extern int stateBrackets_VA_single_n;
extern struct TaxBracket stateBrackets_VA_married[]; extern int stateBrackets_VA_married_n;
extern struct TaxBracket stateBrackets_WV_single[];  extern int stateBrackets_WV_single_n;
extern struct TaxBracket stateBrackets_WV_married[]; extern int stateBrackets_WV_married_n;
extern struct TaxBracket stateBrackets_WI_single[];  extern int stateBrackets_WI_single_n;
extern struct TaxBracket stateBrackets_WI_married[]; extern int stateBrackets_WI_married_n;
extern struct TaxBracket stateBrackets_DC_single[];  extern int stateBrackets_DC_single_n;
extern struct TaxBracket stateBrackets_DC_married[]; extern int stateBrackets_DC_married_n;

// --- Tax calculation ---

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
			return calcFromBrackets(taxableIncome, federalMarried, federalMarried_n);
		default:
			return calcFromBrackets(taxableIncome, federalSingle, federalSingle_n);
	}
}

// Helper: pick the single or married bracket array based on filing status.
#define STATE_TAX(STATE_CODE) \
	((p->status == MARRIED) \
		? calcFromBrackets(p->income, stateBrackets_##STATE_CODE##_married, stateBrackets_##STATE_CODE##_married_n) \
		: calcFromBrackets(p->income, stateBrackets_##STATE_CODE##_single,  stateBrackets_##STATE_CODE##_single_n))

double calcStateTax(struct TaxProfile *p) {
	switch (p->state) {
		case AL: return STATE_TAX(AL);
		case AZ: return STATE_TAX(AZ);
		case AR: return STATE_TAX(AR);
		case CA: return STATE_TAX(CA);
		case CO: return STATE_TAX(CO);
		case CT: return STATE_TAX(CT);
		case DE: return STATE_TAX(DE);
		case GA: return STATE_TAX(GA);
		case HI: return STATE_TAX(HI);
		case ID: return STATE_TAX(ID);
		case IL: return STATE_TAX(IL);
		case IN: return STATE_TAX(IN);
		case IA: return STATE_TAX(IA);
		case KS: return STATE_TAX(KS);
		case KY: return STATE_TAX(KY);
		case LA: return STATE_TAX(LA);
		case ME: return STATE_TAX(ME);
		case MD: return STATE_TAX(MD);
		case MA: return STATE_TAX(MA);
		case MI: return STATE_TAX(MI);
		case MN: return STATE_TAX(MN);
		case MS: return STATE_TAX(MS);
		case MO: return STATE_TAX(MO);
		case MT: return STATE_TAX(MT);
		case NE: return STATE_TAX(NE);
		case NJ: return STATE_TAX(NJ);
		case NM: return STATE_TAX(NM);
		case NY: return STATE_TAX(NY);
		case NC: return STATE_TAX(NC);
		case ND: return STATE_TAX(ND);
		case OH: return STATE_TAX(OH);
		case OK: return STATE_TAX(OK);
		case OR: return STATE_TAX(OR);
		case PA: return STATE_TAX(PA);
		case RI: return STATE_TAX(RI);
		case SC: return STATE_TAX(SC);
		case UT: return STATE_TAX(UT);
		case VT: return STATE_TAX(VT);
		case VA: return STATE_TAX(VA);
		case WV: return STATE_TAX(WV);
		case WI: return STATE_TAX(WI);
		case DC: return STATE_TAX(DC);
		// No income tax: AK, FL, NV, NH, SD, TN, TX, WA, WY
		case AK:
		case FL:
		case NV:
		case NH:
		case SD:
		case TN:
		case TX:
		case WA:
		case WY:
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

// Ordered to match enum State in taxCalculator.h.
static const char *stateNames[] = {
	"AL", "AK", "AZ", "AR", "CA", "CO", "CT", "DE", "FL", "GA",
	"HI", "ID", "IL", "IN", "IA", "KS", "KY", "LA", "ME", "MD",
	"MA", "MI", "MN", "MS", "MO", "MT", "NE", "NV", "NH", "NJ",
	"NM", "NY", "NC", "ND", "OH", "OK", "OR", "PA", "RI", "SC",
	"SD", "TN", "TX", "UT", "VT", "VA", "WA", "WV", "WI", "WY",
	"DC"
};

enum State parseState(const char* input) {
	for (int i = 0; i < (int)(sizeof(stateNames) / sizeof(stateNames[0])); i++) {
		if (strcmp(input, stateNames[i]) == 0) return (enum State)i;
	}
	return UNKNOWN_STATE;
}

void fillTaxProfile(struct TaxProfile *profile) {
	printf("\n--- Constructing Tax Profile ---\n");

	// Validate income
	printf("What is your yearly income: ");
	while (scanf("%lf", &profile->income) != 1) {
		printf("Invalid input. Please enter a number: ");
		while (getchar() != '\n'); // clear bad inputs
	}
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
	char input[3];
	while (state == UNKNOWN_STATE) {
		printf("\nWhat state are you in. Use 2 letter state code (i.e. CA): ");
		scanf("%2s", input);
		state = parseState(input);
	}
	profile->state = state;

	// Validate dependents
	printf("\nHow many dependents do you have: ");
	while (scanf("%d", &profile->numDependents) != 1) {
		printf("Invalid input. Please enter a number: ");
		while (getchar() != '\n'); // clear bad inputs
	}
}

void taxCalculator() {
	struct TaxProfile profile;

	// Get information from user
	fillTaxProfile(&profile);

	struct TaxResult result = calculateTax(&profile);

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

	printf("\nHit enter to continue...\n");
	while (getchar() != '\n'); // clear any previous inputs or new lines
	while (getchar() != '\n'); // Wait for enter key

	return;
}

// ============================================================================
// Tax bracket data (2026)
// Source: Tax Foundation, "2026 State Income Tax Rates and Brackets"
// Convention: each row is {min, max, rate}. `max == -1` means "and over".
// Rates apply marginally: a bracket's `min` equals the previous bracket's `max`.
// ============================================================================

// --- Federal (2026 projections, based on existing values in this file) ---

struct TaxBracket federalSingle[] = {
	{0, 11925, 0.10}, {11925, 48475, 0.12}, {48475, 103350, 0.22},
	{103350, 197300, 0.24}, {197300, 250525, 0.32}, {250525, 626350, 0.35},
	{626350, -1, 0.37}
};
int federalSingle_n = 7;

struct TaxBracket federalMarried[] = {
	{0, 23850, 0.10}, {23850, 96950, 0.12}, {96950, 206700, 0.22},
	{206700, 394600, 0.24}, {394600, 501050, 0.32}, {501050, 751600, 0.35},
	{751600, -1, 0.37}
};
int federalMarried_n = 7;

// --- States (alphabetical) ---

// Alabama
struct TaxBracket stateBrackets_AL_single[] = {
	{0, 500, 0.02}, {500, 3000, 0.04}, {3000, -1, 0.05}
};
int stateBrackets_AL_single_n = 3;
struct TaxBracket stateBrackets_AL_married[] = {
	{0, 1000, 0.02}, {1000, 6000, 0.04}, {6000, -1, 0.05}
};
int stateBrackets_AL_married_n = 3;

// Arizona (flat)
struct TaxBracket stateBrackets_AZ_single[]  = { {0, -1, 0.025} };
int stateBrackets_AZ_single_n  = 1;
struct TaxBracket stateBrackets_AZ_married[] = { {0, -1, 0.025} };
int stateBrackets_AZ_married_n = 1;

// Arkansas
struct TaxBracket stateBrackets_AR_single[] = {
	{0, 4600, 0.02}, {4600, -1, 0.039}
};
int stateBrackets_AR_single_n = 2;
struct TaxBracket stateBrackets_AR_married[] = {
	{0, 4600, 0.02}, {4600, -1, 0.039}
};
int stateBrackets_AR_married_n = 2;

// California
struct TaxBracket stateBrackets_CA_single[] = {
	{0, 11079, 0.01}, {11079, 26264, 0.02}, {26264, 41452, 0.04},
	{41452, 57542, 0.06}, {57542, 72724, 0.08}, {72724, 371479, 0.093},
	{371479, 445771, 0.103}, {445771, 742953, 0.113},
	{742953, 1000000, 0.123}, {1000000, -1, 0.133}
};
int stateBrackets_CA_single_n = 10;
struct TaxBracket stateBrackets_CA_married[] = {
	{0, 22158, 0.01}, {22158, 52528, 0.02}, {52528, 82904, 0.04},
	{82904, 115084, 0.06}, {115084, 145448, 0.08}, {145448, 742958, 0.093},
	{742958, 891542, 0.103}, {891542, 1000000, 0.113},
	{1000000, 1485906, 0.123}, {1485906, -1, 0.133}
};
int stateBrackets_CA_married_n = 10;

// Colorado (flat)
struct TaxBracket stateBrackets_CO_single[]  = { {0, -1, 0.044} };
int stateBrackets_CO_single_n  = 1;
struct TaxBracket stateBrackets_CO_married[] = { {0, -1, 0.044} };
int stateBrackets_CO_married_n = 1;

// Connecticut
struct TaxBracket stateBrackets_CT_single[] = {
	{0, 10000, 0.02}, {10000, 50000, 0.045}, {50000, 100000, 0.055},
	{100000, 200000, 0.06}, {200000, 250000, 0.065},
	{250000, 500000, 0.069}, {500000, -1, 0.0699}
};
int stateBrackets_CT_single_n = 7;
struct TaxBracket stateBrackets_CT_married[] = {
	{0, 20000, 0.02}, {20000, 100000, 0.045}, {100000, 200000, 0.055},
	{200000, 400000, 0.06}, {400000, 500000, 0.065},
	{500000, 1000000, 0.069}, {1000000, -1, 0.0699}
};
int stateBrackets_CT_married_n = 7;

// Delaware (same thresholds for single and married)
struct TaxBracket stateBrackets_DE_single[] = {
	{0, 2000, 0.0}, {2000, 5000, 0.022}, {5000, 10000, 0.039},
	{10000, 20000, 0.048}, {20000, 25000, 0.052},
	{25000, 60000, 0.0555}, {60000, -1, 0.066}
};
int stateBrackets_DE_single_n = 7;
struct TaxBracket stateBrackets_DE_married[] = {
	{0, 2000, 0.0}, {2000, 5000, 0.022}, {5000, 10000, 0.039},
	{10000, 20000, 0.048}, {20000, 25000, 0.052},
	{25000, 60000, 0.0555}, {60000, -1, 0.066}
};
int stateBrackets_DE_married_n = 7;

// Georgia (flat)
struct TaxBracket stateBrackets_GA_single[]  = { {0, -1, 0.0519} };
int stateBrackets_GA_single_n  = 1;
struct TaxBracket stateBrackets_GA_married[] = { {0, -1, 0.0519} };
int stateBrackets_GA_married_n = 1;

// Hawaii
struct TaxBracket stateBrackets_HI_single[] = {
	{0, 9600, 0.014}, {9600, 14400, 0.032}, {14400, 19200, 0.055},
	{19200, 24000, 0.064}, {24000, 36000, 0.068}, {36000, 48000, 0.072},
	{48000, 125000, 0.076}, {125000, 175000, 0.079},
	{175000, 225000, 0.0825}, {225000, 275000, 0.09},
	{275000, 325000, 0.10}, {325000, -1, 0.11}
};
int stateBrackets_HI_single_n = 12;
struct TaxBracket stateBrackets_HI_married[] = {
	{0, 19200, 0.014}, {19200, 28800, 0.032}, {28800, 38400, 0.055},
	{38400, 48000, 0.064}, {48000, 72000, 0.068}, {72000, 96000, 0.072},
	{96000, 250000, 0.076}, {250000, 350000, 0.079},
	{350000, 450000, 0.0825}, {450000, 550000, 0.09},
	{550000, 650000, 0.10}, {650000, -1, 0.11}
};
int stateBrackets_HI_married_n = 12;

// Idaho (effectively flat above a zero-bracket exemption)
struct TaxBracket stateBrackets_ID_single[] = {
	{0, 4811, 0.0}, {4811, -1, 0.053}
};
int stateBrackets_ID_single_n = 2;
struct TaxBracket stateBrackets_ID_married[] = {
	{0, 9622, 0.0}, {9622, -1, 0.053}
};
int stateBrackets_ID_married_n = 2;

// Illinois (flat)
struct TaxBracket stateBrackets_IL_single[]  = { {0, -1, 0.0495} };
int stateBrackets_IL_single_n  = 1;
struct TaxBracket stateBrackets_IL_married[] = { {0, -1, 0.0495} };
int stateBrackets_IL_married_n = 1;

// Indiana (flat)
struct TaxBracket stateBrackets_IN_single[]  = { {0, -1, 0.0295} };
int stateBrackets_IN_single_n  = 1;
struct TaxBracket stateBrackets_IN_married[] = { {0, -1, 0.0295} };
int stateBrackets_IN_married_n = 1;

// Iowa (flat)
struct TaxBracket stateBrackets_IA_single[]  = { {0, -1, 0.038} };
int stateBrackets_IA_single_n  = 1;
struct TaxBracket stateBrackets_IA_married[] = { {0, -1, 0.038} };
int stateBrackets_IA_married_n = 1;

// Kansas
struct TaxBracket stateBrackets_KS_single[] = {
	{0, 23000, 0.052}, {23000, -1, 0.0558}
};
int stateBrackets_KS_single_n = 2;
struct TaxBracket stateBrackets_KS_married[] = {
	{0, 46000, 0.052}, {46000, -1, 0.0558}
};
int stateBrackets_KS_married_n = 2;

// Kentucky (flat)
struct TaxBracket stateBrackets_KY_single[]  = { {0, -1, 0.035} };
int stateBrackets_KY_single_n  = 1;
struct TaxBracket stateBrackets_KY_married[] = { {0, -1, 0.035} };
int stateBrackets_KY_married_n = 1;

// Louisiana (flat)
struct TaxBracket stateBrackets_LA_single[]  = { {0, -1, 0.03} };
int stateBrackets_LA_single_n  = 1;
struct TaxBracket stateBrackets_LA_married[] = { {0, -1, 0.03} };
int stateBrackets_LA_married_n = 1;

// Maine
struct TaxBracket stateBrackets_ME_single[] = {
	{0, 27399, 0.058}, {27399, 64849, 0.0675}, {64849, -1, 0.0715}
};
int stateBrackets_ME_single_n = 3;
struct TaxBracket stateBrackets_ME_married[] = {
	{0, 54849, 0.058}, {54849, 129749, 0.0675}, {129749, -1, 0.0715}
};
int stateBrackets_ME_married_n = 3;

// Maryland
struct TaxBracket stateBrackets_MD_single[] = {
	{0, 1000, 0.02}, {1000, 2000, 0.03}, {2000, 3000, 0.04},
	{3000, 100000, 0.0475}, {100000, 125000, 0.05},
	{125000, 150000, 0.0525}, {150000, 250000, 0.055},
	{250000, 500000, 0.0575}, {500000, 1000000, 0.0625},
	{1000000, -1, 0.065}
};
int stateBrackets_MD_single_n = 10;
struct TaxBracket stateBrackets_MD_married[] = {
	{0, 1000, 0.02}, {1000, 2000, 0.03}, {2000, 3000, 0.04},
	{3000, 150000, 0.0475}, {150000, 175000, 0.05},
	{175000, 225000, 0.0525}, {225000, 300000, 0.055},
	{300000, 600000, 0.0575}, {600000, 1200000, 0.0625},
	{1200000, -1, 0.065}
};
int stateBrackets_MD_married_n = 10;

// Massachusetts
struct TaxBracket stateBrackets_MA_single[] = {
	{0, 1083150, 0.05}, {1083150, -1, 0.09}
};
int stateBrackets_MA_single_n = 2;
struct TaxBracket stateBrackets_MA_married[] = {
	{0, 1083150, 0.05}, {1083150, -1, 0.09}
};
int stateBrackets_MA_married_n = 2;

// Michigan (flat)
struct TaxBracket stateBrackets_MI_single[]  = { {0, -1, 0.0425} };
int stateBrackets_MI_single_n  = 1;
struct TaxBracket stateBrackets_MI_married[] = { {0, -1, 0.0425} };
int stateBrackets_MI_married_n = 1;

// Minnesota
struct TaxBracket stateBrackets_MN_single[] = {
	{0, 33310, 0.0535}, {33310, 109430, 0.068},
	{109430, 203150, 0.0785}, {203150, -1, 0.0985}
};
int stateBrackets_MN_single_n = 4;
struct TaxBracket stateBrackets_MN_married[] = {
	{0, 48700, 0.0535}, {48700, 193480, 0.068},
	{193480, 337930, 0.0785}, {337930, -1, 0.0985}
};
int stateBrackets_MN_married_n = 4;

// Mississippi (flat above $10k)
struct TaxBracket stateBrackets_MS_single[] = {
	{0, 10000, 0.0}, {10000, -1, 0.04}
};
int stateBrackets_MS_single_n = 2;
struct TaxBracket stateBrackets_MS_married[] = {
	{0, 10000, 0.0}, {10000, -1, 0.04}
};
int stateBrackets_MS_married_n = 2;

// Missouri (same thresholds for single and married)
struct TaxBracket stateBrackets_MO_single[] = {
	{0, 1348, 0.0}, {1348, 2696, 0.02}, {2696, 4044, 0.025},
	{4044, 5392, 0.03}, {5392, 6740, 0.035}, {6740, 8088, 0.04},
	{8088, 9436, 0.045}, {9436, -1, 0.047}
};
int stateBrackets_MO_single_n = 8;
struct TaxBracket stateBrackets_MO_married[] = {
	{0, 1348, 0.0}, {1348, 2696, 0.02}, {2696, 4044, 0.025},
	{4044, 5392, 0.03}, {5392, 6740, 0.035}, {6740, 8088, 0.04},
	{8088, 9436, 0.045}, {9436, -1, 0.047}
};
int stateBrackets_MO_married_n = 8;

// Montana
struct TaxBracket stateBrackets_MT_single[] = {
	{0, 47500, 0.047}, {47500, -1, 0.0565}
};
int stateBrackets_MT_single_n = 2;
struct TaxBracket stateBrackets_MT_married[] = {
	{0, 95000, 0.047}, {95000, -1, 0.0565}
};
int stateBrackets_MT_married_n = 2;

// Nebraska
struct TaxBracket stateBrackets_NE_single[] = {
	{0, 4130, 0.0246}, {4130, 24760, 0.0351}, {24760, -1, 0.0455}
};
int stateBrackets_NE_single_n = 3;
struct TaxBracket stateBrackets_NE_married[] = {
	{0, 8250, 0.0246}, {8250, 49530, 0.0351}, {49530, -1, 0.0455}
};
int stateBrackets_NE_married_n = 3;

// New Jersey
struct TaxBracket stateBrackets_NJ_single[] = {
	{0, 20000, 0.014}, {20000, 35000, 0.0175}, {35000, 40000, 0.035},
	{40000, 75000, 0.0553}, {75000, 500000, 0.0637},
	{500000, 1000000, 0.0897}, {1000000, -1, 0.1075}
};
int stateBrackets_NJ_single_n = 7;
struct TaxBracket stateBrackets_NJ_married[] = {
	{0, 20000, 0.014}, {20000, 50000, 0.0175}, {50000, 70000, 0.0245},
	{70000, 80000, 0.035}, {80000, 150000, 0.0553},
	{150000, 500000, 0.0637}, {500000, 1000000, 0.0897},
	{1000000, -1, 0.1075}
};
int stateBrackets_NJ_married_n = 8;

// New Mexico
struct TaxBracket stateBrackets_NM_single[] = {
	{0, 5500, 0.015}, {5500, 16500, 0.032}, {16500, 33500, 0.043},
	{33500, 66500, 0.047}, {66500, 210000, 0.049}, {210000, -1, 0.059}
};
int stateBrackets_NM_single_n = 6;
struct TaxBracket stateBrackets_NM_married[] = {
	{0, 8000, 0.015}, {8000, 25000, 0.032}, {25000, 50000, 0.043},
	{50000, 100000, 0.047}, {100000, 315000, 0.049}, {315000, -1, 0.059}
};
int stateBrackets_NM_married_n = 6;

// New York
struct TaxBracket stateBrackets_NY_single[] = {
	{0, 8500, 0.039}, {8500, 11700, 0.044}, {11700, 13900, 0.0515},
	{13900, 80650, 0.054}, {80650, 215400, 0.059},
	{215400, 1077550, 0.0685}, {1077550, 5000000, 0.0965},
	{5000000, 25000000, 0.103}, {25000000, -1, 0.109}
};
int stateBrackets_NY_single_n = 9;
struct TaxBracket stateBrackets_NY_married[] = {
	{0, 17150, 0.039}, {17150, 23600, 0.044}, {23600, 27900, 0.0515},
	{27900, 161550, 0.054}, {161550, 323200, 0.059},
	{323200, 2155350, 0.0685}, {2155350, 5000000, 0.0965},
	{5000000, 25000000, 0.103}, {25000000, -1, 0.109}
};
int stateBrackets_NY_married_n = 9;

// North Carolina (flat)
struct TaxBracket stateBrackets_NC_single[]  = { {0, -1, 0.0399} };
int stateBrackets_NC_single_n  = 1;
struct TaxBracket stateBrackets_NC_married[] = { {0, -1, 0.0399} };
int stateBrackets_NC_married_n = 1;

// North Dakota
struct TaxBracket stateBrackets_ND_single[] = {
	{0, 48475, 0.0}, {48475, 244825, 0.0195}, {244825, -1, 0.025}
};
int stateBrackets_ND_single_n = 3;
struct TaxBracket stateBrackets_ND_married[] = {
	{0, 80975, 0.0}, {80975, 298075, 0.0195}, {298075, -1, 0.025}
};
int stateBrackets_ND_married_n = 3;

// Ohio (flat above $26,050)
struct TaxBracket stateBrackets_OH_single[] = {
	{0, 26050, 0.0}, {26050, -1, 0.0275}
};
int stateBrackets_OH_single_n = 2;
struct TaxBracket stateBrackets_OH_married[] = {
	{0, 26050, 0.0}, {26050, -1, 0.0275}
};
int stateBrackets_OH_married_n = 2;

// Oklahoma (new graduated structure for 2026)
struct TaxBracket stateBrackets_OK_single[] = {
	{0, 3750, 0.0}, {3750, 4900, 0.025},
	{4900, 7200, 0.035}, {7200, -1, 0.045}
};
int stateBrackets_OK_single_n = 4;
struct TaxBracket stateBrackets_OK_married[] = {
	{0, 7500, 0.0}, {7500, 9800, 0.025},
	{9800, 14400, 0.035}, {14400, -1, 0.045}
};
int stateBrackets_OK_married_n = 4;

// Oregon
struct TaxBracket stateBrackets_OR_single[] = {
	{0, 4550, 0.0475}, {4550, 11400, 0.0675},
	{11400, 125000, 0.0875}, {125000, -1, 0.099}
};
int stateBrackets_OR_single_n = 4;
struct TaxBracket stateBrackets_OR_married[] = {
	{0, 9100, 0.0475}, {9100, 22800, 0.0675},
	{22800, 250000, 0.0875}, {250000, -1, 0.099}
};
int stateBrackets_OR_married_n = 4;

// Pennsylvania (flat)
struct TaxBracket stateBrackets_PA_single[]  = { {0, -1, 0.0307} };
int stateBrackets_PA_single_n  = 1;
struct TaxBracket stateBrackets_PA_married[] = { {0, -1, 0.0307} };
int stateBrackets_PA_married_n = 1;

// Rhode Island
struct TaxBracket stateBrackets_RI_single[] = {
	{0, 82050, 0.0375}, {82050, 186450, 0.0475}, {186450, -1, 0.0599}
};
int stateBrackets_RI_single_n = 3;
struct TaxBracket stateBrackets_RI_married[] = {
	{0, 82050, 0.0375}, {82050, 186450, 0.0475}, {186450, -1, 0.0599}
};
int stateBrackets_RI_married_n = 3;

// South Carolina
struct TaxBracket stateBrackets_SC_single[] = {
	{0, 3640, 0.0}, {3640, 18230, 0.03}, {18230, -1, 0.06}
};
int stateBrackets_SC_single_n = 3;
struct TaxBracket stateBrackets_SC_married[] = {
	{0, 3640, 0.0}, {3640, 18230, 0.03}, {18230, -1, 0.06}
};
int stateBrackets_SC_married_n = 3;

// Utah (flat)
struct TaxBracket stateBrackets_UT_single[]  = { {0, -1, 0.045} };
int stateBrackets_UT_single_n  = 1;
struct TaxBracket stateBrackets_UT_married[] = { {0, -1, 0.045} };
int stateBrackets_UT_married_n = 1;

// Vermont
struct TaxBracket stateBrackets_VT_single[] = {
	{0, 49400, 0.0335}, {49400, 119700, 0.066},
	{119700, 249700, 0.076}, {249700, -1, 0.0875}
};
int stateBrackets_VT_single_n = 4;
struct TaxBracket stateBrackets_VT_married[] = {
	{0, 82500, 0.0335}, {82500, 199450, 0.066},
	{199450, 304000, 0.076}, {304000, -1, 0.0875}
};
int stateBrackets_VT_married_n = 4;

// Virginia
struct TaxBracket stateBrackets_VA_single[] = {
	{0, 3000, 0.02}, {3000, 5000, 0.03},
	{5000, 17000, 0.05}, {17000, -1, 0.0575}
};
int stateBrackets_VA_single_n = 4;
struct TaxBracket stateBrackets_VA_married[] = {
	{0, 3000, 0.02}, {3000, 5000, 0.03},
	{5000, 17000, 0.05}, {17000, -1, 0.0575}
};
int stateBrackets_VA_married_n = 4;

// West Virginia (same thresholds for single and married)
struct TaxBracket stateBrackets_WV_single[] = {
	{0, 10000, 0.0222}, {10000, 25000, 0.0296},
	{25000, 40000, 0.0333}, {40000, 60000, 0.0444},
	{60000, -1, 0.0482}
};
int stateBrackets_WV_single_n = 5;
struct TaxBracket stateBrackets_WV_married[] = {
	{0, 10000, 0.0222}, {10000, 25000, 0.0296},
	{25000, 40000, 0.0333}, {40000, 60000, 0.0444},
	{60000, -1, 0.0482}
};
int stateBrackets_WV_married_n = 5;

// Wisconsin
struct TaxBracket stateBrackets_WI_single[] = {
	{0, 15110, 0.035}, {15110, 51950, 0.044},
	{51950, 332720, 0.053}, {332720, -1, 0.0765}
};
int stateBrackets_WI_single_n = 4;
struct TaxBracket stateBrackets_WI_married[] = {
	{0, 20150, 0.035}, {20150, 69260, 0.044},
	{69260, 443630, 0.053}, {443630, -1, 0.0765}
};
int stateBrackets_WI_married_n = 4;

// District of Columbia (same thresholds for single and married)
struct TaxBracket stateBrackets_DC_single[] = {
	{0, 10000, 0.04}, {10000, 40000, 0.06}, {40000, 60000, 0.065},
	{60000, 250000, 0.085}, {250000, 500000, 0.0925},
	{500000, 1000000, 0.0975}, {1000000, -1, 0.1075}
};
int stateBrackets_DC_single_n = 7;
struct TaxBracket stateBrackets_DC_married[] = {
	{0, 10000, 0.04}, {10000, 40000, 0.06}, {40000, 60000, 0.065},
	{60000, 250000, 0.085}, {250000, 500000, 0.0925},
	{500000, 1000000, 0.0975}, {1000000, -1, 0.1075}
};
int stateBrackets_DC_married_n = 7;
