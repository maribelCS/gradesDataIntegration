#include <iostream>
#include <fstream>
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

	while (getStudentSet().find(studentID) == getStudentSet().end()) {
		cout << "Student " << studentID << " not found. Please try again." << endl;
		cin >> studentID;
	}
	
	cout << "ENTER FILE NAME THAT EXPORTED DATA WILL BE SENT TO\n";
	cin >> fileName;

	CSVFilename(fileName);

	exportStudent(studentID,fileName);
}

void GradebookUI::promptUserChoice() {
	cout << "\n\nEnter the key (in parenthesis) your choice of: \n"<<endl;
	cout <<  "ADD DATA ('a' or 'A')"<<endl;
	cout << "SAVE DATA ('s' or 'S')"<<endl;
	cout << "EXIT PROGRAM ('e' or 'E')\n"<<endl;
}

int GradebookUI::printMenu() {

	string userChoice = "";

	//loop forever or until choice is 'e' which returns from the function
	while (1) {  

		promptUserChoice();
		cin >> userChoice;

		if (userChoice.compare("a") == 0 || userChoice.compare("A") == 0) { //adding
			handleAddDataRequest();
		}

		else if (userChoice.compare("s") == 0 || userChoice.compare("S") == 0) { //exporting
			handleSaveDataRequest();
		}

		else if (userChoice.compare("e") == 0 || userChoice.compare("E") == 0) { //exit
			cout << "Exiting" << endl;
			return 0;;
		}

		else { //invalid choice
			cout << "\nINVALID MENU CHOICE \n\t\tRestarting Main Menu . .";
		}



	}

}

bool GradebookUI::isNumber(const std::string& s)
{
	std::string::const_iterator it = s.begin();
	while (it != s.end() && std::isdigit(*it)) ++it;
	return !s.empty() && it == s.end();
}

