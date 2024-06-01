/*
Daniel Yanez (#5535343)
February 14, 2024
The purpose of this lab is to be able to create a program which uses array structures to hold
contact information. The program will ask the user for the first and last name of a person, as
well as the phone number if they want to add that person to the phonebook, or it will ask the user
for the first and last name of a contact to delete them. It will also show the whole phonebook
with all of the contacts added by the user.
*/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//structure to define contacts
typedef struct {
    char *firstName;
    char *lastName;
    char *phone;
} Contact; //name

//pointer called phonebook of type Contact which points to nothing
Contact *phoneBook = NULL;
int size = 0;

//function definitions
void menu();
void addEntry(char *firstName, char *lastName, char *phone);
void deleteEntry(char *firstName, char *lastName);
void printPhoneBook();

int main() {
	//arrays to store the user's info as strings, and an ans initialization of -1
	int ans = -1; char firstName[30]; char lastName[30]; char numb[20];
	//runs while the input from the user is not 4
	while (ans != 4) { 
		menu();
		scanf("%d", &ans);
		if (ans == 1) {
			//asks for first name, last name, and phone number
			printf("First name: ");
			scanf("%s", firstName);
			printf("Last name: ");
			scanf("%s", lastName);
			printf("Phone number: ");
			scanf("%s", numb);
			//passes the values to the function
			addEntry(firstName, lastName, numb);
			printf("Record added to the phone book");
			printf("\n");
		} else if (ans == 2) {
			//asks for first name and last name
			printf("First name: ");
			scanf("%s", firstName);
			printf("Last name: ");   
			scanf("%s", lastName);
			//passes the values to the function
			deleteEntry(firstName, lastName);
		} else if (ans == 3) {
			//prints phonebook
			printPhoneBook();
		} else {
			printf("Invalid input\n");
		}
	}
	//while size is greater than i, we add 1 to i; runs as long as there are contacts in the phonebook
    for (int i = 0; i < size; i++) {
    	//deletes the first name, last name, and phone number of a certain contact at the i index
        free(phoneBook[i].firstName);
        free(phoneBook[i].lastName);
        free(phoneBook[i].phone);
    }
    //frees the phonebook itself
    free(phoneBook);
    return 0;
}

//displays menu
void menu() {
	printf("Phone Book Application\n");
	printf("\t1) Add friend\n");
	printf("\t2) Delete friend\n");
	printf("\t3) Show phonebook\n");
	printf("\t4) Exit\n");
	printf("\nWhat do you want to do: ");
}

void addEntry(char *firstName, char *lastName, char *phone) {
	/*way of allocating memory for a given contact using the realloc function. We do this by selecting the variable where we want to store the information,
	adding one place to size so that we can record any given contact, and then multiply that times the memory of a contact so that
	we have the proper space allocated*/
    phoneBook = realloc(phoneBook, (size + 1) * sizeof(Contact));
    //copies the information input by the user into the struct format of the new contact
    phoneBook[size].firstName = strdup(firstName);
    phoneBook[size].lastName = strdup(lastName);
    phoneBook[size].phone = strdup(phone);
    //increments size of phonebook
    size++;
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
            printf("Record deleted from the phone book\n");
            return;
        }
    }
}

void printPhoneBook() {
	//loops through the amount of contacts in the phonebook
    for (int i = 0; i < size; i++) {
    	//makes sure that all the entries in the phonebook are not empty
        if (phoneBook[i].firstName != NULL && phoneBook[i].lastName != NULL && phoneBook[i].phone != NULL) {
            //if they are not empty, it prints the information it has
			printf("%s %s %s\n", phoneBook[i].firstName, phoneBook[i].lastName, phoneBook[i].phone);
        }
    }
    printf("\n");
}