gradebook : GradeBook.h GradeBook.cpp
	c++ -c GradeBook.h GradeBook.cpp

account : Account.h Account.cpp
	c++ -c Account.h Account.cpp

invoice : Invoice.h Invoice.cpp
	c++ -c Invoice.h Invoice.cpp

all:
	g++ *.h *.cpp
	./a.out

clean: 
	rm *.o a.out