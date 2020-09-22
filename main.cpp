#include <iostream>
#include "GradeBook.h"
#include "Account.h"
#include "Invoice.h"
#include "Employee.h"
#include "Date.h"

using namespace std;

int main(){
    // GradeBook myGradeBook("Linux Programming", "Noor Muhammad");
    // myGradeBook.displayMessage();

    // Account myAccount(100);
    // cout << "My account balance is: " << myAccount.getBalance() << endl;

    // Invoice myInvoice("A0123BK90", "Absolute Zero Centrifuge", 10, 199);
    // cout << "Invoice amount is: $" << myInvoice.getInvoiceAmount() << endl;

    // Employee myEmployee("John", "Doe", 1000);
    // cout << "Yearly salary of " << myEmployee.getFirstName() << " " << myEmployee.getLastName()
    //      << " is $" << myEmployee.getSalary()*12 << endl;
    
    Date myDate(9, 22, 2020);
    cout << "Today is "; myDate.displayDate(); cout << endl;

    return 0;
}