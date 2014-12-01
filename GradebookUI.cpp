#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include "Gradebook.h"
#include "GradebookUI.h"

using namespace std;

GradebookUI::GradebookUI() {
}

void GradebookUI::handleAddDataRequest() {

	string filename;
	Semester semester;
	int year;
	string course;
	
	cout << "ENTER THE FILE NAME: \n";
	cin >> filename;

	int choice;
	do
	{
		cout << "ENTER THE COURSE SEMESTER:" << endl;
		for(int i=Spring; i<=Fall; i++)
		{
			cout << "[" << i << "] " << SemesterString[i] << endl;
		}
		cin >> choice;
	} while(!(choice >= Spring && choice <= Fall));
	semester = static_cast<Semester>(choice);

	cout << "ENTER THE COURSE YEAR: \n";
	cin >> year;
	
	cout << "ENTER THE COURSE NAME in the format XX123: \n";
	cin >> course;

	addCourse(filename, course, year, semester);
}

void GradebookUI::handleSaveDataRequest() {
	
	string studentID;
	string fileName;

	cout << "ENTER STUDENT ID: \n";
	cin >> studentID;
	
	cout << "ENTER FILE NAME THAT EXPORTED DATA WILL BE SENT TO\n";
	cin >> fileName;
}

int GradebookUI::exitProgram() {
	return 0;

}

void GradebookUI::promptUserChoice() {
	cout << "\n\nEnter the key (in parenthesis) your choice of: \n"<<endl;
	cout <<  "ADD DATA ('a' or 'A')"<<endl;
	cout << "SAVE DATA ('s' or 'S')"<<endl;
	cout << "EXIT PROGRAM ('e' or 'E')\n"<<endl;
}

int GradebookUI::printMenu() {

	
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



