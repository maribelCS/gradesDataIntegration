#ifndef MENU_H_
#define MENU_H_

class Menu
{
	//private:
		
	public:
		Menu();
		int printMenu();
		void handleAddDataRequest();
		void handleSaveDataRequest();
		int exitProgram();
		void promptUserChoice();
};

#endif
