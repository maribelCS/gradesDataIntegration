#ifndef GRADEBOOK_H
#define GRADEBOOK_H

#include <set>
#include <string>
#include <vector>

enum Semester {Spring, Summer, Fall};
const std::string SemesterString[3] = {"Spring", "Summer", "Fall"};

class Gradebook
{
	private:
		class Course
		{
		public:
			Course(const std::string&, const int&, const Semester&);
			~Course();
			void printAll() const;
			int m_year;
			Semester m_semester;
			std::vector<std::string> m_fields;
			std::vector< std::vector<std::string> > m_students;
		};
		std::set<Course> m_courses;
	public:
		Gradebook();
		~Gradebook();
		void addCourse(const std::string, const int year, const Semester);
		void printAll() const;
		friend bool operator<(const Course&, const Course&);
};

#endif