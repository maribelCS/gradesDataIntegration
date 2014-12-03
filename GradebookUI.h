#ifndef UI_H_
#define UI_H_
#include <string>
#include "Gradebook.h"

using namespace std;

class GradebookUI : public Gradebook
{
	public:
		GradebookUI();
		int printMenu();
		void CSVFilename(string& filename);
		void handleAddDataRequest();
		void handleSaveDataRequest();
		int exitProgram();
		void promptUserChoice();
	private:
		static bool isNumber(const string&);
};

#endif
