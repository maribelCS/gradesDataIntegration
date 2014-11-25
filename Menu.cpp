#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "Gradebook.h"
#include "Menu.h"

using namespace std;

Menu::Menu() {
}

void Menu::printMenu() {
	char userChoice;
	
	cout << "Enter the key (in parenthesis) your choice of: \n" <<endl;
	cout <<  "ADD DATA ('a' or 'A')"<<endl;
	cout << "SAVE DATA ('s' or 'S')"<<endl;
	cout << "EXIT PROGRAM ('e' or 'E')"<<endl;

	userChoice = cin.get();
	
	switch(userChoice) {
	
	case 'A':
	case 'a':
	cout << "add '\n'"<<endl;
	break;

	case 'S':
	case 's':
	cout << "save \n "<<endl;
	break;

	case 'E':
	case 'e':
	cout << "exit"<<endl;
	System.exit(0);
	break;

	}
}



