#ifndef GRADEBOOK_H
#define GRADEBOOK_H

#include <set>
#include <map>
#include <string>
#include <vector>

typedef std::vector<std::string> Student;

enum Semester {Spring =0, Summer, Fall};
const std::string SemesterString[3] = {"Spring", "Summer", "Fall"};

class Gradebook
{
	private:
		class Course
		{
		public:
			Course(
				std::ifstream& filename,
				const std::string& courseName,
				const int& year,
				const Semester& semester);
			~Course();
			void printAll() const;
			std::string m_courseName;
			int m_year;
			Semester m_semester;
			std::vector<std::string> m_fields;
			std::vector<Student> m_students;
		};
		std::set<Course> m_courses;
	public:
		Gradebook();
		~Gradebook();
		friend bool operator<(const Course&, const Course&);
		void addCourse(
			const std::string& filename,
			const std::string& courseName,
			const int& year,
			const Semester& semester);
		void printAll() const;
		void exportStudent(const std::string studentID, const std::string saveLocation) const;
};

#endif
