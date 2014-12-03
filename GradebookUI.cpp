#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <limits>
#include <algorithm>
#include "Gradebook.h"
#include "GradebookUI.h"

using namespace std;

GradebookUI::GradebookUI() {
}

void GradebookUI::CSVFilename(string& filename)
{
	if(filename.length() < 5 || filename.substr(filename.length()-4,4).compare(".csv") != 0)
		filename += ".csv";
}

void GradebookUI::handleAddDataRequest() {

	string filename;
	Semester semester;
	int year;
	string course;
	
	cout << "ENTER THE FILE NAME: \n";
	cin >> filename;
	CSVFilename(filename);
	ifstream file (filename.c_str());
	while(!file.is_open())
	{
		cout << "Unable to open file. Try again" << endl;
		cin >> filename;
		CSVFilename(filename);
		file.open(filename.c_str());
	}

	cout << "ENTER THE COURSE SEMESTER:" << endl;
	for(int i=Spring; i<=Fall; i++)
	{
		cout << "[" << i << "] " << SemesterString[i] << endl;
	}
	string choice;
	cin >> choice;
	semester = static_cast<Semester>(atoi(choice.c_str()));
	while(!(isNumber(choice) && semester >= Spring && semester <= Fall))
	{
		cout << "Enter a valid number." << endl;
		cin >> choice;
		semester = static_cast<Semester>(atoi(choice.c_str()));
	}


	cout << "ENTER THE COURSE YEAR: \n";
	cin >> year;

	while(cin.fail() || year < 1000 || year > 9999 ) {
	    cin.clear();
	    cin.ignore(numeric_limits<streamsize>::max(),'\n');
	    cout << "Invalid year entry.  ENTER THE COURSE YEAR: ";
	    cin >> year;
	}
	
	cout << "ENTER THE COURSE NAME in the format XX123:" << endl;
	cin >> course;

	addCourse(file, course, year, semester);
}

void GradebookUI::handleSaveDataRequest() {
	
	string studentID;
	string fileName;

	cout << "ENTER STUDENT ID: \n";
	cin >> studentID;
	
	cout << "ENTER FILE NAME THAT EXPORTED DATA WILL BE SENT TO\n";
	cin >> fileName;

	CSVFilename(fileName);

	exportStudent(studentID,fileName);
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

bool GradebookUI::isNumber(const std::string& s)
{
	std::string::const_iterator it = s.begin();
	while (it != s.end() && std::isdigit(*it)) ++it;
	return !s.empty() && it == s.end();
}

