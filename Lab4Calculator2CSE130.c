/*
Daniel Yanez (#5535343), dayane01@louisville.edu
February 3, 2024
The purpose of this program is to create a functioning calculator capable of performing addition;
subtraction; multiplication; division; as well as finding remainders (modulo); whether a number
is prime or not, with the latter showing the numbers which make a number not be prime 
(Ex "Not Prime: 5 x 3 = 15"); the factorial of a given number; the result of a given number to a given power;
and the fibonacci result of a given number (my function).
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
int factorial(int iNumber1);
float power(float iNumber1, float iNumber2);
int fibonacci(float iNumber1);

//Main function
int main() {
	//Four variables: Answer guides through the decision process while num1 and num2 store values for future calculations and iNumber1 is used for single-number functions
	int answer = -1; float num1 = 0; float num2 = 0; int iNumber1;
	//Two arrays which hold functions which require two numbers or one number respectively
	int twoNum[6] = {1,2,3,4,5,8}; int oneNum[3] = {6,7,9};
	//If the input of the user is equal to 7 for the choosing phase, the program ends
	while (answer != 0) {
		menu();
		printf("Please choose an operation: ");
		scanf("%d", &answer);
		//For loop runs 6 times and checks if the answer number is in the array of two numbers. If so, it asks for input
		for (int i = 0; i < 6; i++) {
			if (answer == twoNum[i]) {
				printf("Enter the first number:\n ");
				scanf("%f", &num1);
				printf("Enter the second number:\n ");
				scanf("%f", &num2);
			}
		}
		
		//For loop runs 3 times and checks if the answer number is in the array of one number. If so, it asks for input
		for (int i = 0; i < 3; i++) {
			if (answer == oneNum[i]) {
				printf("Enter the number to be tested: ");
				scanf("%d", &iNumber1);
			}
		}
		//Easy basic calculations which take the input of num1 and num2, pass it through their respective funtions, and print the result to .2 decimal places
		if (answer == 1) {
			printf("%.2f + %.2f = %.2f\n", num1, num2, addition(num1, num2));
		} else if (answer == 2) {
			printf("%.2f - %.2f = %.2f\n", num1, num2, subtraction(num1, num2));
		} else if (answer == 3) {
			printf("%.2f * %.2f = %.2f\n", num1, num2, multiplication(num1, num2));
		} else if (answer == 4) {
			printf("%.2f / %.2f = %.2f\n", num1, num2, division(num1, num2));
		} else if (answer == 5){
			printf("%.0f %% %.0f = %d\n", num1, num2, modulus(num1, num2));		
		} else if (answer == 6) {
			//We call on the function prime passing iNumber1 and store that result in the variable iResult
			int iResult = prime(iNumber1);
			//If iResult is 0, that means the function prime was never able to run the "not prime" section and thus the number is prime
			if (iResult == 0) {
				printf("%d is a prime number\n", iNumber1);
			}
		} else if (answer == 7)	{
			//For loop prints numbers from 1 to the pre last user inputted number...
			for (int i = 1; i < iNumber1; i++) {
				printf("%d * ", i);	
			}
			// and then it prints the inputted number by the user, as well as its factorial value
			printf("%d = %d\n", iNumber1, factorial(iNumber1));
		} else if (answer == 8)	{
			if (power(num1, num2) == -1) {
				printf("Undefined\n");
				continue;
			}
			//prints the value of a number to a certain power
			printf("%.0f^%.0f = %.2f\n", num1, num2, power(num1, num2));
		} else if (answer == 9) {
			//Prints the user number and its fibonacci value
			printf("The fibonacci number of %d is %d\n", iNumber1, fibonacci(iNumber1));
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
	printf("(7) Factorial (integers only)\n");
	printf("(8) Power\n");
	printf("(9) Fibonacci\n");
	printf("(0) Exit\n");
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
	if (iNumber1 == 0) {
		printf("0 is not a prime number\n");
		iRes = 1;
		return iRes;
	} else if (iNumber1 == 1) {
		printf("1 is not a prime number\n");	
		iRes = 1;
		return iRes;
	}
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

//Integer type function
int factorial(int iNumber1) {
	//two variables: i for moving the for loop and num to perform calculations
	int i; int num = 1;
	//Starting at 1, this loop will run until the user inputted number is reached
	for (i = 1; i <= iNumber1; i++) {
		//as the loop runs, we will multiply the initial number 1 to the ever-increasing i values (factorial formula)
		num = num * i;
	}
	//returns the factorial value
	return num;
}

//Float type function
float power(float iNumber1, float iNumber2) {
	int result = 1;
	//0^0 is undefined, so this returns a value which is not possible for powers and then it is analyzed in the main function
	if (iNumber1 == 0 && iNumber2 == 0) {
		return -1;
	}
	//Any number to the 0 power will give a result of 1
	if (iNumber2 == 0) {
		return 1;
	}
	//starting at 1, while i is smaller than or equal to iNumber2, increment by 1
	for (int i = 1; i <= iNumber2; i++) {
		//result will be equal to itself times iNumber1, i amount of times
		result = result * iNumber1;
	}
	//returns result
	return result;
}

int fibonacci(float iNumber1) {
	//three variables to perform calculations
	int temp; int num1 = 1; int num2 = 1;
	//any number smaller than 2 will have a fibonacci of itself
	if (iNumber1 < 2) {
		return iNumber1;
	}
	//starting at 2, while the counting variable is smaller than the actual number, keep counting by 1
	for (int i = 2; i < iNumber1; i++) {
		//temporarily stores the value of num1
		temp = num1;
		//num1 is set to the sum of itself and num2
		num1 = num1 + num2;
		//num2 takes on the old value of num1 to keep the sequence of f(n-1) + f(n-2) going
		num2 = temp;
	}
	//returns the value of fibonacci
	return num1;
}