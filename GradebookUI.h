#ifndef UI_H_
#define UI_H_
#include <string>
#include "Gradebook.h"

using namespace std;

class GradebookUI : public Gradebook
{
	//private:
		
	public:
		GradebookUI();
		int printMenu();
		string fileTypeExtensionCheck(string filename);
		void handleAddDataRequest();
		void handleSaveDataRequest();
		int exitProgram();
		void promptUserChoice();
};

#endif
