// Employee class public interface definition. This hides all the implementation details
#include <string>
using namespace std;

class Employee{
    public:
        Employee(string, string, int); // constructor function for initializing the data fields

        string getFirstName(); // function to get firstName
        void setFirstName(string); // function to set firstName

        string getLastName(); // function to get lastName
        void setLastName(string); // function to set lastName

        int getSalary(); // function to get salary
        void setSalary(int); // function to set salary
    private:
        string firstName;
        string lastName;
        int salary;
};