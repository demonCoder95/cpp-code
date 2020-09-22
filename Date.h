// Class Date public interface specification. This hides all the implementation details.

class Date{
    public:
        Date(int, int, int); // constructor to initialize data fields

        int getMonth(); // get function for month
        void setMonth(int); // set function for month

        int getDay(); // get function for day
        void setDay(int); // set function for day

        int getYear(); // get function for year
        void setYear(int); // set function for year

        void displayDate(); // function to print the date in month/day/year format
    private:
        int month;
        int day;
        int year;
};