// Invoice class public interface. This hides all the implementation details
#include <string>
using namespace std;

class Invoice {
    public:
        Invoice(string, string, int, int); // constructor to initialize the entries

        void setPartNumber(string); // set function for partNumber
        string getPartNumber(); // get function for partNumber

        void setPartDescription(string); // set function for partDescription
        string getPartDescription(); // get function for partDescription

        void setPartQuantity(int); // set function for partQuantity
        int getPartQuantity(); // get function for partQuantity

        void setPricePerItem(int); // set function for pricePerItem
        int getPricePerItem(); //get function for pricePerItem

        int getInvoiceAmount(); // function to compute invoice amount
    private:
        string partNumber;
        string partDescription;
        int partQuantity;
        int pricePerItem;
};