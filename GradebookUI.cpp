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

	ifstream file;
	Semester semester;
	int year;
	string course;
	
	cout << "ENTER THE FILE NAME: \n";
	string filename;
	cin >> filename;
	CSVFilename(filename);
	file.open(filename.c_str());
	while(!file.is_open())
	{
		cout << "Unable to open file. Enter another file name or type 'cancel'." << endl;
		cin >> filename;
		cout << filename << endl;
		if(filename.compare("cancel") == 0) return;
		CSVFilename(filename);
		file.open(filename.c_str());
	}

	cout << "\nENTER THE COURSE SEMESTER:" << endl;
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


	cout << "\nENTER THE COURSE YEAR: \n";
	cin >> year;

	while(cin.fail() || year < 1000 || year > 9999 ) {
	    cin.clear();
	    cin.ignore(numeric_limits<streamsize>::max(),'\n');
	    cout << "Invalid year entry.  ENTER THE COURSE YEAR: ";
	    cin >> year;
	}
	
	cout << "\nENTER THE COURSE NAME in the format XX123:" << endl;
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

bool GradebookUI::isNumber(const std::string& s)
{
	std::string::const_iterator it = s.begin();
	while (it != s.end() && std::isdigit(*it)) ++it;
	return !s.empty() && it == s.end();
}

void GradebookUI::startUI()
{
	while(true) {

		cout << "\n\n===== Gradebook Menu =====\n\n"
			<< "Make a selection:\n\n"
			<< " (A) ADD DATA\n"
			<< " (S) SAVE DATA\n"
			<< " (E) EXIT PROGRAM\n\n";

		string choice;
		cin >> choice;
		cout << endl;

		switch(choice[0]) {

			case 'A':
			case 'a':
				cout << "Add Data\n\n";
				handleAddDataRequest();
				break;

			case 'S':
			case 's':
				cout << "Save Data\n\n";
				handleSaveDataRequest();
				break;

			case 'E':
			case 'e':
				cout << "Goodbye!" << endl;
				return;

			default: 
				cout << "INVALID MENU CHOICE" << endl;

		}
	}
}