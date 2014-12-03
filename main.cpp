#include <iostream>
#include <fstream>
#include "Gradebook.h"
#include "GradebookUI.h"

int main()
{
	Gradebook gb = Gradebook();
	ifstream file("data/380-spring-2002.csv");
	gb.addCourse(file, "IT380", 2002, Spring);
	ifstream file2("data/437-fall-2003.csv");
	gb.addCourse(file2, "IT437", 2003, Fall);
	ifstream file3("data/467-fall-2002.csv");
	gb.addCourse(file3, "IT467", 2003, Fall);
	//gb.printAll();
	gb.exportStudent("1wvs78", "file2.csv");
	GradebookUI menu = GradebookUI();
	menu.printMenu();
	return 0;
}
