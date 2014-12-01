#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include "Gradebook.h"

using namespace std;

Gradebook::Gradebook()
{
}

Gradebook::~Gradebook()
{
}

void Gradebook::addCourse(
	const string& filename,
	const string& courseName,
	const int& year,
	const Semester& semester)
{
	ifstream file (filename.c_str());
	if (!file.is_open())
	{
		cout << "Unable to open file" << endl;
		return;
	}
	Course course = Course(file, courseName, year, semester);
	m_courses.insert(course);
	cout << "Successfully added "
		<< course.m_year << " "
		<< course.m_courseName << " "
		<< SemesterString[course.m_semester] << endl;
}

void Gradebook::printAll() const
{
	for(set<Course>::const_iterator course = m_courses.begin(); course != m_courses.end(); ++course)
	{
		course->printAll();
	}
}

void Gradebook::exportStudent(const string studentID,  string saveLocation) const
{
	vector<string> newFields;
	vector<string> newData;

	for(set<Course>::const_iterator course = m_courses.begin(); course != m_courses.end(); ++course)
	{
		string courseName = course->m_courseName;
		int year = course->m_year;
		string semester = SemesterString[course->m_semester];
		int idField = 0;
		int nameField = 0;

		//get the user ID / Student ID field
		for(Student::const_iterator field = course->m_fields.begin(); field != course->m_fields.end(); ++field)
		{
			string f = *field;
			if (f.compare("Student Id") == 0 || f.compare("User ID") == 0) {
				break;
			}
			else idField++;
		}

		//iterating through the students
		for(vector<Student>::const_iterator student = course->m_students.begin(); student != course->m_students.end(); ++student)
		{
			Student s = *student;

			//checking every student ID for a match
			if (s[idField].compare(studentID) == 0)
			{

				if (newData.size() == 0) newData.push_back(s[idField]); //first entry of the created csv is always the id
				if (newFields.size() == 0) newFields.push_back("User ID");

				//get iterators for the fields and for the data
				Student::const_iterator sit = s.begin();
				Student::const_iterator f = course->m_fields.begin();

				//we can iterate through both vectors together since the fields and data should always match at a given index
				while ((sit != s.end()) && (f != course->m_fields.end()))
				{
					string fval = *f; //current header title
					std:transform(fval.begin(), fval.end(), fval.begin(), ::tolower); //makes fval lower case for more accurate checking

					//we only keep the fields that aren't related to the names and user ids
					if (fval.find("name") == string::npos && fval.find("student id") == string::npos && fval.find("user id") == string::npos)
					{
						stringstream ss;
						//building new header titles in the form courseName-semester-year-title
						ss << courseName << "-" << semester << "-" << year << "-" << *f;
						string sout = ss.str();
						sout.erase(remove(sout.begin(), sout.end(), '\r'), sout.end()); //removes newlines
						newFields.push_back(sout);
						ss.str("");

						string dout = *sit;
						dout.erase(remove(dout.begin(), dout.end(), '\r'), dout.end()); //removes newlines
						
						newData.push_back("\""+dout+"\"");

					}

					f++;
					sit++;

				}
			}
		}
	}
	
	if (newData.size() == 0) {
		cout << "No match found for student " << studentID << endl;
		return;
	}

	//writing out

	//appends .csv. and saves to /data/

	ofstream outfile(("data/"+saveLocation).c_str());

	int ctr = 0;

	//writing the fields
	for (vector<string>::const_iterator fw = newFields.begin(); fw != newFields.end(); ++fw) {
		outfile << *fw;
		if (ctr != newFields.size()-1) outfile << ",";
		ctr++;
	}
		ctr = 0;
		outfile << endl;

	//writing the data
	for (vector<string>::const_iterator dr = newData.begin(); dr != newData.end(); ++dr) {
		outfile << *dr;
		if (ctr != newData.size()-1) outfile << ",";
		ctr++;
	}
	outfile.close();
	cout << "Added student " << studentID << " to " << saveLocation << endl;
}


Gradebook::Course::Course(ifstream& file, const string& courseName, const int& year, const Semester& semester)
	:m_courseName(courseName), m_year(year), m_semester(semester)
{
	string line;
	while (getline(file, line))
	{
		m_students.push_back(Student());
		stringstream linestream(line);
		while (!linestream.eof()) {
			string record;
			while(linestream.peek()==' ') linestream.get(); // remove space after comma
			if(linestream.peek() == '"')
			{
				linestream.get();
				getline(linestream, record, '"');
				while(linestream.peek() == '"') {
					record += linestream.get();
					string piece;
					getline(linestream, piece, '"');
					record += piece;
				}
				if(linestream.peek()==',') linestream.get();
			}
			else
			{
				getline(linestream, record, ',');
			}
			m_students.back().push_back(record);
		}
	}
	file.close();
	m_fields = *m_students.begin();
	m_students.erase(m_students.begin());
}

void Gradebook::Course::printAll() const
{
	cout << endl << SemesterString[m_semester] << " " << m_year << endl;
	for(Student::const_iterator field = m_fields.begin(); field != m_fields.end(); ++field)
	{
		cout << *field << ", ";
	}
	cout << "\b \b " << endl;
	for(vector< Student >::const_iterator student = m_students.begin(); student != m_students.end(); ++student)
	{
		for(Student::const_iterator item = student->begin(); item != student->end(); ++item)
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
