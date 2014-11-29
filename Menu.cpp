#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include "Gradebook.h"
#include "Menu.h"

using namespace std;

Menu::Menu() {
}

void Menu::handleAddDataRequest() {

	string filename;
	string semester;
	int year;
	string courseDept;
	int courseNumber;
	
	cout << "ENTER THE FILE NAME: \n";
	cin >> filename;

	cout << "ENTER THE COURSE SEMESTER: \n";
	cin >> semester;

	cout << "ENTER THE COURSE YEAR: \n";
	cin >> year;
	
	cout << "ENTER THE COURSE DEPARTMENT: \n";
	cin >> courseDept;
	
	cout << "ENTER THE COURSE NUMBER: \n";
	cin >> courseNumber;
}

void Menu::handleSaveDataRequest() {
	
	string studentID;
	string fileName;

	cout << "ENTER STUDENT ID: \n";
	cin >> studentID;
	
	cout << "ENTER FILE NAME THAT EXPORTED DATA WILL BE SENT TO\n";
	cin >> fileName;
}

int Menu::exitProgram() {
	return 0;

}

void Menu::promptUserChoice() {
	cout << "\n\nEnter the key (in parenthesis) your choice of: \n"<<endl;
	cout <<  "ADD DATA ('a' or 'A')"<<endl;
	cout << "SAVE DATA ('s' or 'S')"<<endl;
	cout << "EXIT PROGRAM ('e' or 'E')\n"<<endl;
}

int Menu::printMenu() {

	
	char userChoice;
	int firstPrompt = 0;
	cout << "userchoice" + userChoice;
	promptUserChoice();	
	userChoice = cin.get();

	while (userChoice != 'e' && userChoice != 'E') {

		if (firstPrompt != 0) {
			promptUserChoice();
			userChoice = cin.get();	
		}

		firstPrompt++; 

		switch(userChoice) {	

		case 'A':
		case 'a':
		handleAddDataRequest();
		break;

		case 'S':
		case 's':
		cout << "save \n "<<endl;
		handleSaveDataRequest();
		break;

		case 'E':
		case 'e':
		//cout << "exit"<<endl;
		//return 0;
		break;

		default: 
		cout << "INVALID MENU CHOICE \n\t\tRestarting Main Menu . .";

		} // END of switch
	}  // END do in do while

	 
	cout << "after"<<endl;

}



