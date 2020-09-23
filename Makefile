gradebook : GradeBook.h GradeBook.cpp
	c++ -c GradeBook.h GradeBook.cpp

account : Account.h Account.cpp
	c++ -c Account.h Account.cpp

invoice : Invoice.h Invoice.cpp
	c++ -c Invoice.h Invoice.
	
employee : Employee.h Employee.cpp
	c++ -c Employee.h Employee.cpp

date : Date.h Date.cpp
	c++ -c Date.h Date.cpp

heartrates: HeartRates.h HeartRates.cpp
	c++ -c HeartRates.h HeartRates.cpp

healthprofile: HealthProfile.h HealthProfile.cpp
	c++ -c HealthProfile.h HealthProfile.cpp

all:
	g++ *.h *.cpp
	./a.out

clean: 
	rm *.o a.out