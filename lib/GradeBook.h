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

        void inputGrades();    // input arbitrary number of grades from user
        void displayGradeReport(); // display a report based on the grades
        int maximum(int, int, int); // determine maximum of 3 values
    private:
        string courseName; // courseName for GradeBook
        string instructorName; // instructorName for GradeBook
        // int aCount; // count of A grades
        // int bCount; // count of B grades
        // int cCount; // count of C grades
        // int dCount; // count of D grades
        // int fCount; // count of F grades
        int maximumGrade;
};