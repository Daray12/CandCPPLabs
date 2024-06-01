/*
Daniel Yanez (#5535343), dayane01@louisville.edu
January 27, 2024
The purpose of this program is to create a functioning calculator capable of performing addition,
subtraction, multiplication, division, as well as finding remainders (modulo) and whether a number
is prime or not, with the latter showing the numbers which make a number not be prime. 
Ex "Not Prime: 5 x 3 = 15"
*/
#include <stdio.h>

//Function prototypes
void menu(void);
float addition(float iNumber1, float iNumber2);
float subtraction(float iNumber1, float iNumber2);
float multiplication(float iNumber1, float iNumber2);
float division(float iNumber1, float iNumber2);
int modulus(int iNumber1, int iNumber2);
int prime(int iNumber1); 

//Main function
int main() {
	//Three variables: Answer guides through the decision process while num1 and num2 store values for future calculations
	int answer = 0; float num1 = 0; float num2 = 0;
	//If the input of the user is equal to 7 for the choosing phase, the program ends
	while (answer != 7) {
		menu();
		printf("Please choose an operation: ");
		scanf("%d", &answer);
		//If the answer of the user is a number from 1 to 5...
		if (answer == 1 || answer == 2 || answer == 3 || answer == 4 || answer == 5) {
			//...We get the two numbers that will be used for upcoming calculations. This saves time and lines of code by only asking for values in one place
			printf("Enter the first number:\n ");
			scanf("%f", &num1);
			printf("Enter the second number:\n ");
			scanf("%f", &num2);
			//Depending on the value of answer, we call on multiple functions passing the previous numbers as parameters, and displaying to a second decimal place
			if (answer == 1) {
				printf("%.2f + %.2f = %.2f\n", num1, num2, addition(num1, num2));
			} else if (answer == 2) {
				printf("%.2f - %.2f = %.2f\n", num1, num2, subtraction(num1, num2));
			} else if (answer == 3) {
				printf("%.2f * %.2f = %.2f\n", num1, num2, multiplication(num1, num2));
			} else if (answer == 4) {
				printf("%.2f / %.2f = %.2f\n", num1, num2, division(num1, num2));
			} else {
				printf("%.0f %% %.0f = %d\n", num1, num2, modulus(num1, num2));		
			}
		} 
		// If the answer of the user equals 6, we only ask for one number
		else if (answer == 6) {
			int iNumber1;
			printf("Enter the number to be tested: ");
			scanf("%d", &iNumber1);
			//We call on the function prime passing the previously declared variable and store that result in the variable iResult
			int iResult = prime(iNumber1);
			//If iResult is 0, that means the function prime was never able to run the "not prime" section and thus the number is prime
			if (iResult == 0) {
				printf("%d is a prime number\n", iNumber1);
			}
		}	
	}
	printf("Good Bye!");
	return 0;
}

//Does not return values, just displays a menu of options
void menu() {
	printf("\n");
	printf("Calculator menu:\n");
	printf("(1) Addition\n");
	printf("(2) Subtraction\n");
	printf("(3) Multiplication\n");
	printf("(4) Division\n");
	printf("(5) Modulus (integers only)\n");
	printf("(6) Test if prime (integers only)\n");
	printf("(7) Exit\n");
	printf("\n");
}

//Float type function which takes two floats and returns the addition of both
float addition(float iNumber1, float iNumber2) {
	return iNumber1 + iNumber2;
}	

//Float type function which takes two floats and returns the subtraction of both
float subtraction(float iNumber1, float iNumber2) {
	return iNumber1 - iNumber2;
}	

//Float type function which takes two floats and returns the multiplication of both
float multiplication(float iNumber1, float iNumber2) {
	return iNumber1 * iNumber2;
}	

//Float type function which takes two floats and returns the division of both
float division(float iNumber1, float iNumber2) {
	return iNumber1 / iNumber2;
}	

//Integer type function which takes two integers and returns the modulo (remainder) of both
int modulus(int iNumber1, int iNumber2) {
	return iNumber1 % iNumber2;
}	

//Integer type function
int prime(int iNumber1) {
	//i is an integer type variable. iRes is an integer type variable used to know if the function found a not prime number
	int i; int iRes = 0;
	//i was declared to run through the for loop
	for (i = 2; i < iNumber1; i++) {
		if (iNumber1 % i == 0) {
			printf("Not prime: %d x %d = %d\n", i, iNumber1/i, iNumber1);
			//iRes is used to know if the function found a not prime number
			iRes = 1;
			break;
		}
	}
	//returns the result of iRes to the main function, which tells us if we found prime numbers or not
	return iRes;
}
