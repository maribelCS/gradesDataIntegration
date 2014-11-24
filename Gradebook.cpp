#include <iostream>
#include <fstream>
#include <sstream>
#include "Gradebook.h"

using namespace std;

Gradebook::Gradebook()
{
}

Gradebook::~Gradebook()
{
}

void Gradebook::addCourse(const string filename, const int year, const Semester semester)
{
	Course course(filename, year, semester);
	m_courses.insert(course);
}

void Gradebook::printAll() const
{
	for(set<Course>::const_iterator course = m_courses.begin(); course != m_courses.end(); ++course)
	{
		course->printAll();
	}
}

Gradebook::Course::Course(const string& filename, const int& year, const Semester& semester)
{
	m_year = year;
	m_semester = semester;
	ifstream file (filename.c_str());
	if (!file.is_open())
	{
		cout << "Unable to open file";
		return;
	}
	string line;
	if(!getline(file, line))
	{
		cout << "Cannot read file";
		return;
	}
	stringstream linestream(line);
	string item;
	while (getline(linestream, item, ',')) {
		m_fields.push_back(item);
	}


	while (getline(file, line))
	{
		m_students.push_back(vector<string>());
		stringstream linestream(line);
		while (getline(linestream, item, ',')) {
			m_students.back().push_back(item);
		}
	}
	file.close();
}

void Gradebook::Course::printAll() const
{
	cout << endl << SemesterString[m_semester] << " " << m_year << endl;
	for(vector<string>::const_iterator field = m_fields.begin(); field != m_fields.end(); ++field)
	{
		cout << *field << ", ";
	}
	cout << "\b \b " << endl;
	for(vector< vector<string> >::const_iterator student = m_students.begin(); student != m_students.end(); ++student)
	{
		for(vector<string>::const_iterator item = student->begin(); item != student->end(); ++item)
		{
			cout << *item << ", ";
		}
		cout << "\b \b " << endl;
	}
}

Gradebook::Course::~Course()
{
}

bool operator<(const Gradebook::Course& a, const Gradebook::Course& b)
{
	if(a.m_year < b.m_year) return true;
	if(a.m_year > b.m_year) return false;
	return a.m_semester < b.m_semester;
}