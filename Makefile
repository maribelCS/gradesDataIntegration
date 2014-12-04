Gradebook: main.o Gradebook.o GradebookUI.o
	g++ -o Gradebook main.o Gradebook.o GradebookUI.o

main.o: main.cpp
	g++ -c main.cpp

Gradebook.o: Gradebook.cpp Gradebook.h
	g++ -c Gradebook.cpp

GradebookUI.o: GradebookUI.cpp GradebookUI.h
	g++ -c GradebookUI.cpp

run: Gradebook
	./Gradebook

clean:
	rm *.o Gradebook
