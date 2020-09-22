gradebook.o : GradeBook.h GradeBook.cpp
	c++ -c GradeBook.h GradeBook.cpp

main : main.cpp gradebook.o
	c++ main.cpp gradebook.o