#ifndef UI_H_
#define UI_H_

#include "Gradebook.h"

class GradebookUI : public Gradebook
{
	//private:
		
	public:
		GradebookUI();
		int printMenu();
		void handleAddDataRequest();
		void handleSaveDataRequest();
		int exitProgram();
		void promptUserChoice();
};

#endif
