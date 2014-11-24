Gradebook: main.o Gradebook.o
	g++ -o Gradebook main.o Gradebook.o

main.o: main.cpp Gradebook.o
	g++ -c main.cpp

Gradebook.o: Gradebook.cpp Gradebook.h
	g++ -c Gradebook.cpp


run: Gradebook
	./Gradebook

clean:
	rm *.o Gradebook
