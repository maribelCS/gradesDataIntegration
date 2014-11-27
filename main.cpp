#include <iostream>
#include "Gradebook.h"

int main()
{
	Gradebook gb = Gradebook();
	gb.addCourse("data/380-spring-2002.csv", "IT380", 2002, Spring);
	gb.addCourse("data/437-fall-2003.csv", "IT437", 2003, Fall);
	gb.addCourse("data/467-fall-2002.csv", "IT467", 2003, Fall);
	// gb.printAll();
	gb.exportStudent("1wvs78", "file2");
}
