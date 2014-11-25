#include <iostream>
#include "Gradebook.h"

int main()
{
	Gradebook gb = Gradebook();
	gb.addCourse("data/380-spring-2002.csv", 2002, Spring);
	//gb.printAll();
	gb.exportStudent("3xr9yx", "file2");
}
