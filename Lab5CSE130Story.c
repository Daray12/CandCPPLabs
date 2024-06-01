/*
Daniel Yanez (#5535343), dayane01@louisville.edu
February 10, 2024
The purpose of this program is to generate a story whose aspects can change randomly everytime the code is run. To do so, 
I ask the user to answer 4 different questions: "What is your name?", "How old are you?", "What is your favorite color?" and "Who
is your best friend?" Then, I stored the value using a pointer to an array named info, and I also created another array which stores 
different objects based on the location where the character is. Finally, I finalize this program by printing the story using
the input of the user, as well as some random objects due to the creation of randomNum, which can be added to scenarios when printing
and which will give a result out of the four possible objects available.
*/
#include <stdio.h>
#include <ctype.h>
#include <time.h>

int main() {
	//generates a random number from 0 to 3. Useful for the scenarios array
	srand(time(NULL));
	int randomNum = rand() % 4;
	// 2D array initialized to null characters
	char info[4][30] = {'\0'}; //20 characters max
	//pointer to array 
	char (*ptrInfo)[30] = info;
	// 2D array of pointers to strings where each row represents a set of strings 
	char *scenarios[3][4] = {{"dumbbell", "bar", "band", "mat"}, {"soda", "snack", "ice cream bucket", "lottery ticket"}, {"box", "gift", "envelope", "bucket"} };
	//prompts the user for useful infomation in the story. Uses the pointer as a means to store the info
    printf("What is your first name? ");
    scanf("%s", * (ptrInfo + 0));
    printf("How old are you? ");
    scanf("%s", * (ptrInfo + 1));
    printf("What is your favorite color? ");
    scanf("%s", * (ptrInfo + 2));
    printf("Who is your best friend? ");
    scanf("%s", * (ptrInfo + 3));
	
	printf("\n");
	//prints the story. * (info + x) represents the location in the array of info where the user provided certain information via the pointer. Ex. * (info + 0) = name inputted by user
	printf("%s, age %s, really likes the color %s, so they decided to look for things that had that color.\n", * (ptrInfo + 0), * (ptrInfo + 1), * (ptrInfo + 2));
	//same as before, but now we access the 2d array of scenarios with the pointer notation and add a random number (randomNum) to get a different element everytime
	printf("First, %s went to a sport store and asked for a %s %s, but unfortunately %s could not find it there.\n",  * (ptrInfo + 0), * (ptrInfo + 2), * (scenarios[0] + randomNum), * (ptrInfo + 0));
	printf("Then, %s went to a convenience store to find a %s %s, but sadly %s didn\'t see find anything either.\n", * (ptrInfo + 0),* (ptrInfo + 2), * (scenarios[1] + randomNum), * (ptrInfo + 0));
	printf("Defeated, %s decided to go home when, suddenly, %s saw a %s %s at the door step and picket it up:\n", * (ptrInfo + 0), * (ptrInfo + 0), * (ptrInfo + 2), * (scenarios[2] + randomNum));
	printf("\"from your friend, %s\" it said in a letter next to it, and %s was very happy.", * (ptrInfo + 3), * (ptrInfo + 0)); 
	return 0;
}