// GradeBook class definition. This only contains the public interface of the GradeBook class
// without revealing any implementation details
#include <string>
using namespace std;

//Class definition
class GradeBook {
    public:

    static const int students = 10; // number of students who took the test
    static const int tests = 3; // number of tests

        GradeBook(string, string, const int [][tests]);  // constructor that initializes courseName and instructorName
       
        void setCourseName(string); // function to set courseName
        string getCourseName(); // function to get courseName
       
        void displayMessage(); //function to print welcome message
        void processGrades();   // perform various operations on grades

        string getInstructorName(); // function to get instructorName
        void setInstructorName(string); // function to set instructorName

        void determineClassAverage(); // average grades entered by user

        void inputGrades();    // input arbitrary number of grades from user
        void displayGradeReport(); // display a report based on the grades
        int maximum(int, int, int); // determine maximum of 3 values

        int getMinimum();   // find the minimum grade for the test
        int getMaximum();   // find the maximum grade for the test
        double getAverage(const int [], const int);    // determine the average grade for the test
        void outputBarChart();  // output bar chart of grade distribution
        void outputGrades();    // output the contents of the grades array
    private:
        string courseName; // courseName for GradeBook
        string instructorName; // instructorName for GradeBook
        // int aCount; // count of A grades
        // int bCount; // count of B grades
        // int cCount; // count of C grades
        // int dCount; // count of D grades
        // int fCount; // count of F grades
        int maximumGrade;
        int grades[students][tests];
};