// GradeBook class definition. This only contains the public interface of the GradeBook class
// without revealing any implementation details
#include <string>
using namespace std;

//Class definition
class GradeBook {
    public:
        GradeBook(string, string);  // constructor that initializes courseName and instructorName
       
        void setCourseName(string); // function to set courseName
        string getCourseName(); // function to get courseName
       
        void displayMessage(); //function to print welcome message

        string getInstructorName(); // function to get instructorName
        void setInstructorName(string); // function to set instructorName

        void determineClassAverage(); // average grades entered by user
    private:
        string courseName; // courseName for GradeBook
        string instructorName; // instructorName for GradeBook
};