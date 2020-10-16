// Sales Summary
#include <iostream>
#include <iomanip>

using namespace std;

#define NUMBER_OF_SALESPERSONS 4
#define NUMBER_OF_PRODUCTS 5

int main(void){

    // Sales summary by sales persons by product
    unsigned int sales[NUMBER_OF_SALESPERSONS][NUMBER_OF_PRODUCTS] = {};

    cout << "Enter data in format (product1 product2 product3 product4 product5)" << endl;
    
    for (int person = 0; person < NUMBER_OF_SALESPERSONS; person++){
        cout << "Enter data of sales person " << person + 1 << endl;
        cout << ">";
        cin >> sales[person][0] >> sales[person][1] >> sales[person][2] >> sales[person][3] >> sales[person][4];
    }

    unsigned int productTotal = 0;  // total for each product
    unsigned int personTotal = 0;   // total for each person

    /* Print tabulated data */
    // TODO: make this printable with loop, to make it scalable with #salespersons
    cout << right << setw(11) << "P# 1" << setw(5) << "P# 2" << setw(5) << "P# 3" << setw(5) << "P# 4" << setw(10) << "Total" <<  endl;
    for (int product = 0; product < NUMBER_OF_PRODUCTS; product++){
        cout << left << setw(5) << "Pr#" << product + 1;
        for(int person = 0; person < NUMBER_OF_SALESPERSONS; person++){
            cout << right << setw(5) << sales[person][product];
            productTotal += sales[person][product];
        }
        cout << setw(10) << productTotal << endl;
        productTotal = 0;   // reset product total for next product
    }

    // Compute total per person
    cout << setw(10) << left << "\nTotal";
    for (int person = 0; person < NUMBER_OF_SALESPERSONS; person++){
        for (int product = 0; product < NUMBER_OF_PRODUCTS; product++){
            personTotal += sales[person][product];
        }
        cout << left << setw(5) << personTotal;
    }
    cout << endl;

    return 0;
}