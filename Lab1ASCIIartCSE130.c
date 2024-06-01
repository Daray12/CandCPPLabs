/*
Daniel Yanez (#5535343), dayane01@louisville.edu
This program prints ASCII art of Dr. Yampolskiy
Online lab section
January 10, 2024
*/

#include <stdio.h>

int main()
{
	/*Series of print statements with a variety of characters and spaces aligned
	vertically to give the illusion of a face. The escape sequences included are
	\\ (backspace), \n (new line), and \t (horizontal tab. This last one was for 
	a printed code which looks more centered.)*/
	printf("\n\t      ___________            ");
	printf("\n\t     /|||||||||||\\          ");
	printf("\n\t   /|||||||||||||||\\        ");
	printf("\n\t   ###           ###         ");
	printf("\n\t   ##  ___    ___  ##        ");
	printf("\n\t   #|  ____  ____  |#        ");
	printf("\n\t  ( |--\\__/--\\__/--| )     ");
	printf("\n\t   \\|      |       |/       ");
	printf("\n\t   #|    /([_)\\    |#       ");
	printf("\n\t   ##\\ /########\\ /##      ");
	printf("\n\t    ###:###==###:###         ");
	printf("\n\t      ###::##::###           ");
	printf("\n\t      |  ######  |           ");
	printf("\n\t      /          \\          ");
	printf("\n\t     Dr. Yampolskiy          ");
	return 0;
}