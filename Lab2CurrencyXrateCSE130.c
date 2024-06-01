/*
Daniel Yanez (#5535343)
This program aims to create a conversion table for multiple currencies based on
the value entered by the user.
Online Section LAB
January 13, 2024
*/

#include <stdio.h>

int main () {
	float fCurrency = 0;
	//Prompts the user to input a currency
	printf("\nWhat amount of currency would you like to exchange? ");
	//Stores that value in the fCurrency variable
	scanf("%f", &fCurrency);
	
	//Conversion values from the perspective of the United States Dollar
	const float fUSDollar = 1; const float fUSEuro = 0.92; const float fUSPound = 0.79; const float fUSRupee = 83.09; const float fUSAuDollar = 1.52; const float fUSCaDollar = 1.35;
	
	//Conversion values from the perspective of the Euro
	const float fEURUSDollar = 1.09; const float fEuro = 1; const float fEURPound = 0.86; const float fEURRupee = 90.42; const float fEURAUDollar = 1.65; const float fEURCaDollar = 1.47;
	
	//Conversion values from the perspective of the British Pound
	const float fGBPUSDollar = 1.27; const float fGBPEuro = 1.16; const float fPound = 1; const float fGBPRupee = 105.18; const float fGBPAUDollar = 1.92; const float fGBPCaDollar = 1.71;
	
	//Conversion values from the perspective of the Indian Rupee
	const float fINRUSDollar = 0.012; const float fINREuro = 0.011; const float fINRPound = 0.0095; const float fRupee = 1; const float fINRAUDollar = 0.018; const float fINRCaDollar = 0.016;
	
	//Conversion values from the perspective of the Australian Dollar
	const float fAUUSDollar = 0.66; const float fAUEuro = 0.61; const float fAUPound = 0.52; const float fAURupee = 54.92; const float fAUDollar = 1; const float fAUCaDollar = 0.89;
	
	//Conversion values from the perspective of the Canadian Dollar
	const float fCADUSDollar = 0.74; const float fCADEuro = 0.68; const float fCADPound = 0.59; const float fCADRupee = 61.69; const float fCADAUDollar = 1.12; const float fCADollar = 1;
	
	//prints the headers
	printf("\n|\t|United States Dollar\t|Euro\t|British Pound\t|Indian Rupee\t|Australian Dollar\t|Canadian Dollar|\n");
	//prints the values from the United States Dollar perspective, to a third decimal place by multiplying the user's value to the convertion rates
	printf("|USD\t|%.3f\t\t\t|%.3f\t|%.3f\t\t|%.2f\t|%.2f\t\t\t|%.3f\t\t|\n", 
	fCurrency * fUSDollar, fCurrency * fUSEuro, fCurrency * fUSPound, fCurrency * fUSRupee, fCurrency * fUSAuDollar, fCurrency * fUSCaDollar);
	
	//prints the values from the Euro perspective, to a third decimal place by multiplying the user's value to the convertion rates
	printf("|EUR\t|%.3f\t\t\t|%.3f\t|%.3f\t\t|%.2f\t|%.2f\t\t\t|%.3f\t\t|\n", 
	fCurrency * fEURUSDollar, fCurrency * fEuro, fCurrency * fEURPound, fCurrency * fEURRupee, fCurrency * fEURAUDollar, fCurrency * fEURCaDollar);
	
	//prints the values from the British Pound perspective, to a third decimal place by multiplying the user's value to the convertion rates
	printf("|GBP\t|%.3f\t\t\t|%.3f\t|%.3f\t\t|%.2f\t|%.2f\t\t\t|%.3f\t\t|\n", 
	fCurrency * fGBPUSDollar, fCurrency * fGBPEuro, fCurrency * fPound, fCurrency * fGBPRupee, fCurrency * fGBPAUDollar, fCurrency * fGBPCaDollar);
	
	//prints the values from the Indian Rupee perspective, to a third decimal place by multiplying the user's value to the convertion rates
	printf("|INR\t|%.3f\t\t\t|%.3f\t|%.3f\t\t|%.2f\t\t|%.2f\t\t\t|%.3f\t\t|\n", 
	fCurrency * fINRUSDollar, fCurrency * fINREuro, fCurrency * fINRPound, fCurrency * fRupee, fCurrency * fINRAUDollar, fCurrency * fINRCaDollar);
	
	//prints the values from the Australian Dollar perspective, to a third decimal place by multiplying the user's value to the convertion rates
	printf("|AUD\t|%.3f\t\t\t|%.3f\t|%.3f\t\t|%.2f\t|%.2f\t\t\t|%.3f\t\t|\n", 
	fCurrency * fAUUSDollar, fCurrency * fAUEuro, fCurrency * fAUPound, fCurrency * fAURupee, fCurrency * fAUDollar, fCurrency * fAUCaDollar);
	
	//prints the values from the Canadian Dollar perspective, to a third decimal place by multiplying the user's value to the convertion rates
	printf("|CAD\t|%.3f\t\t\t|%.3f\t|%.3f\t\t|%.2f\t|%.2f\t\t\t|%.3f\t\t|\n", 
	fCurrency * fCADUSDollar, fCurrency * fCADEuro, fCurrency * fCADPound, fCurrency * fCADRupee, fCurrency * fCADAUDollar, fCurrency * fCADollar);
	return 0;
}