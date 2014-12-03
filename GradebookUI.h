#ifndef UI_H_
#define UI_H_
#include <string>
#include "Gradebook.h"

using namespace std;

class GradebookUI : public Gradebook
{
	public:
		GradebookUI();
		void startUI();
	private:
		static void CSVFilename(string& filename);
		static bool isNumber(const string&);
		void handleAddDataRequest();
		void handleSaveDataRequest();
};

#endif
