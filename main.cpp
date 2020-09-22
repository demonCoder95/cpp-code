#include <iostream>
#include "GradeBook.h"
// #include "Account.h"
// #include "Invoice.h"

using namespace std;

int main(){
    GradeBook myGradeBook("Linux Programming", "Noor Muhammad");
    myGradeBook.displayMessage();

    // Account myAccount(100);
    // cout << "My account balance is: " << myAccount.getBalance() << endl;

    // Invoice myInvoice("A0123BK90", "Absolute Zero Centrifuge", 10, 199);
    // cout << "Invoice amount is: $" << myInvoice.getInvoiceAmount() << endl;

    return 0;
}