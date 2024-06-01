/*
Daniel Yanez (#5535343)
March 8, 2024
The purpose of this lab is to be able to create a program which uses array structures to hold
contact information. The program will ask the user for the first and last name of a person, as
well as the phone number if they want to add that person to the phonebook, or it will ask the user
for the first and last name of a contact to delete them. It will also show the whole phonebook
with all of the contacts added by the user, as well as provide the option for the user to sort
the contacts by their first name, find the phone number of a specific contact using the first and
last name, select a random contact to call, or delete every single entry in the phonebook to start
over.
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//structure to define contacts
typedef struct {
    char *firstName;
    char *lastName;
    char *phone;
} Contact;

//pointer called phonebook which points to nothing
Contact *phoneBook = NULL;
int size = 0;

//function definitions
void menu();
void addEntry(char *firstName, char *lastName, char *phone);
void deleteEntry(char *firstName, char *lastName);
void sort();
void findPhone(char *firstName, char *lastName);
void randomContact();
void deleteAll();
void printPhoneBook();

int main() {
	//arrays to store the user's info as strings
	int ans = -1; char firstName[30]; char lastName[30]; char numb[20];
	//runs while the input from the user is not 8
	while (ans != 8) { 
		menu();
		scanf("%d", &ans);
		if (ans == 1) {
			printf("First name: ");
			scanf("%s", firstName);
			printf("Last name: ");
			scanf("%s", lastName);
			printf("Phone number: ");
			scanf("%s", numb);
			addEntry(firstName, lastName, numb);
		} else if (ans == 2) {
			printf("First name: ");
			scanf("%s", firstName);
			printf("Last name: ");   
			scanf("%s", lastName);
			deleteEntry(firstName, lastName);
		} else if (ans == 3) {
			printPhoneBook();
		} else if (ans == 4) {
			sort();
		} else if (ans == 5) {
			printf("First name: ");
			scanf("%s", firstName);
			printf("Last name: ");
			scanf("%s", lastName);
			findPhone(firstName, lastName);
		} else if (ans == 6) {
			randomContact();
		} else if (ans == 7) {
			deleteAll();
		}
	}
	//goes over all the phonebok
    for (int i = 0; i < size; i++) {
    	//deletes the first name, last name, and phone number of all contacts
        free(phoneBook[i].firstName);
        free(phoneBook[i].lastName);
        free(phoneBook[i].phone);
    }
    //frees the phonebook itself
    free(phoneBook);
    return 0;
}

//displays menu options
void menu() {
	printf("Phone Book Application\n");
	printf("\t1) Add friend\n");
	printf("\t2) Delete friend\n");
	printf("\t3) Show phonebook\n");
	printf("\t4) Sort alphabetically by first name\n");
	printf("\t5) Find phone number\n");
	printf("\t6) Call random friend\n");
	printf("\t7) Delete everyone\n");
	printf("\t8) Exit\n");
	printf("\nWhat do you want to do: ");
}

void addEntry(char *firstName, char *lastName, char *phone) {
	/*way of allocating memory for a given contact using the realloc function. We do this by selecting the variable where we want to store the information,
	adding one place to size so that we can record any given contact, and then multiply that times the memory of a contact so that
	we have the proper space allocated*/
    phoneBook = realloc(phoneBook, (size + 1) * sizeof(Contact));
    //copies the information input by the user into the struct format of a certain contact
    phoneBook[size].firstName = strdup(firstName);
    phoneBook[size].lastName = strdup(lastName);
    phoneBook[size].phone = strdup(phone);
    //adds size to the phonebook
    size++;
    printf("Record added to the phone book\n\n");
}

void deleteEntry(char *firstName, char *lastName) {
    for (int i = 0; i < size; i++) {
    	//looks for a certain contact to see if the first and last name in the phonebook match the ones input by the user
        if (strcmp(phoneBook[i].firstName, firstName) == 0 && strcmp(phoneBook[i].lastName, lastName) == 0) {
        	//if so, it deletes that entry
            free(phoneBook[i].firstName);
            free(phoneBook[i].lastName);
            free(phoneBook[i].phone);
            phoneBook[i] = phoneBook[size - 1];
            //reduces size of the phonebook
            size--;
            //resizes the memory block, since it is now holding one less
            phoneBook = realloc(phoneBook, size * sizeof(Contact));
            printf("Record deleted from the phone book\n\n");
            return;
        }
    }
}

void printPhoneBook() {
	//loops through the amount of contacts in the phonebook
    for (int i = 0; i < size; i++) {
    	//makes sure that an entry in the phonebook is not empty
        if (phoneBook[i].firstName != NULL && phoneBook[i].lastName != NULL && phoneBook[i].phone != NULL) {
            //if so, it prints the information it has
			printf("%s %s %s\n", phoneBook[i].firstName, phoneBook[i].lastName, phoneBook[i].phone);
        }
    }
    printf("\n");
}

void sort() {
	//runs for all the elements in the phonebook
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
        	//compares the first name of the j element and the j+1 element and ckecks if the j element is greater than the j+1 element
            if (strcmp(phoneBook[j].firstName, phoneBook[j+1].firstName) > 0) {
                // if so, it swaps phoneBook[j] and phoneBook[j+1] using a temporary variable
                Contact temp = phoneBook[j];
                phoneBook[j] = phoneBook[j+1];
                phoneBook[j+1] = temp;
            }
        }
    }
    printf("All of your contacts have now been sorted alphabetically by their first name.\n\n");
}

void findPhone(char *firstName, char *lastName) {
	for (int i = 0; i < size; i++) {
    	//looks for a certain contact to see if the first and last name in the phonebook match the ones input by the user
        if (strcmp(phoneBook[i].firstName, firstName) == 0 && strcmp(phoneBook[i].lastName, lastName) == 0) {
        	printf("The phone number of %s %s is: %s\n\n", phoneBook[i].firstName, phoneBook[i].lastName, phoneBook[i].phone);
		}
	}
}

void randomContact() {
	srand(time(NULL));
	//creates a random number from size 0 to -1 the length of the phonebook (which fits perfectly into the range of phonebook because computers start counting at 0)
	int randomNum = rand() % size;
	//uses the number obtained in randomNum to go to a random contact's first name, last name, and phone number in the phonebook
	printf("Your random friend will be: %s %s %s\n\n", phoneBook[randomNum].firstName, phoneBook[randomNum].lastName, phoneBook[randomNum].phone);
}

void deleteAll() {
    for (int i = 0; i < size; i++) {
    	//goes over a loop the size of the phonebook and deletes all the entries within
        free(phoneBook[i].firstName);
        free(phoneBook[i].lastName);
        free(phoneBook[i].phone);
        phoneBook[i].firstName = NULL;
        phoneBook[i].lastName = NULL;
        phoneBook[i].phone = NULL;
    }
    //frees the phonebook
    free(phoneBook);
    phoneBook = NULL; 
    //Restart the length of the phonebook to 0
    size = 0;
    printf("All records have been deleted from the phonebook.\n\n");
}