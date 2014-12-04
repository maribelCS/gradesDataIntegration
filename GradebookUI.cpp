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
	
	cout << "ENTER THE FILE NAME: ";
	string filename;
	cin >> filename;
	CSVFilename(filename);
	file.open(filename.c_str());
	while(!file.is_open())
	{
		cout << "Unable to open file. Enter another file name or type 'cancel'.\n";
		cin >> filename;
		if(filename.compare("cancel") == 0) return;
		CSVFilename(filename);
		file.open(filename.c_str());
	}

	cout << "\nSELECT A COURSE SEMESTER:\n";
	for(int i=Spring; i<=Fall; i++)
	{
		cout << " [" << i << "] " << SemesterString[i] << endl;
	}
	string choice;
	cin >> choice;
	semester = static_cast<Semester>(atoi(choice.c_str()));
	while(!(isNumber(choice) && semester >= Spring && semester <= Fall))
	{
		cout << "Invalid input. Try again." << endl;
		cin >> choice;
		semester = static_cast<Semester>(atoi(choice.c_str()));
	}


	cout << "\nENTER THE COURSE YEAR: ";
	cin >> year;

	while(cin.fail() || year < 1000 || year > 9999 ) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		cout << "Invalid year entry.\nENTER THE COURSE YEAR: ";
		cin >> year;
	}
	
	cout << "\nENTER THE COURSE NAME (format: XX123): ";
	cin >> course;

	addCourse(file, course, year, semester);
}

void GradebookUI::handleSaveDataRequest() {
	
	string studentID;
	string fileName;

	cout << "STUDENT ID: ";
	cin >> studentID;
	
	cout << "\nOUTPUT FILENAME: ";
	cin >> fileName;

	CSVFilename(fileName);

	exportStudent(studentID,fileName);
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
				cout << "Goodbye!\n\n";
				return;

			default: 
				cout << "INVALID MENU CHOICE" << endl;
				break;
		}
	}
}

bool GradebookUI::isNumber(const std::string& s)
{
	std::string::const_iterator it = s.begin();
	while (it != s.end() && std::isdigit(*it)) ++it;
	return !s.empty() && it == s.end();
}
