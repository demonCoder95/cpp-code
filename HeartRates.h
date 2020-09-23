// Class HeartRates public interface specification. This hides implementation details.
#include <string>
#include "Date.h"
using namespace std;

// Struct for TargetHeartRateRange with min and max values
struct TargetHeartRateRange {
    int minTargetHeartRate;
    int maxTargetHeartRate;
};

class HeartRates{
    public:
        HeartRates(string, string, Date);   // constructor for class

        string getFirstName(); // function to get firstName
        void setFirstName(string); // function to set firstName

        string getLastName(); // function to get lastName
        void setLastName(string); // function to set lastName

        Date getDateOfBirth(); // function to get dateOfBirth
        void setDateOfBirth(Date); // function to set dateOfBirth

        int getAge(); // function to compute age in years
        int getMaximumHeartRate(); // function to get maximum Heart Rate in Beats per Minute
        TargetHeartRateRange getTargetHeartRate(); // function to get target Heart Rate in Beats per Minute
    private:
        string firstName;
        string lastName;
        Date dateOfBirth;

};