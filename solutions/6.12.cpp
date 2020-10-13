// This solves the parking fee exercise, since we don't have to use arrays, this has a lot of repetition
#include <iostream>
#include <iomanip>

using namespace std;

const double minimumFee = 2.00;   // for upto 3 hours of parking
const double hourlyFee = 0.50; // for each hour in excess of 3
const double maximumFee = 10.00; // for a 24-hr period

int main(void){

    // # hours each customer is parked, will always be <= 24hrs
    double hoursFirst, hoursSecond, hoursThird;
    cout << "Enter parked hours of 3 customers: " << endl;
    cin >> hoursFirst >> hoursSecond >> hoursThird;

    double feeFirst, feeSecond, feeThird;
    if (hoursFirst <= 3){
        feeFirst = minimumFee;
    }else if(hoursFirst >= 24){
        feeFirst = maximumFee;
    }else{
        feeFirst = minimumFee + hourlyFee*(3.0-hoursFirst);
    }

    if (hoursSecond <= 3){
        feeSecond = minimumFee;
    }else if(hoursSecond >= 24){
        feeSecond = maximumFee;
    }else{
        feeSecond = minimumFee + hourlyFee*(3.0-hoursSecond);
    }

    if (hoursThird <= 3){
        feeThird = minimumFee;
    }else if(hoursThird >= 24){
        feeThird = maximumFee;
    }else{
        feeThird = minimumFee + hourlyFee*(hoursThird-3.0);
    }

    cout << left << setw(5) << "Car" << right << setw(10) << "Hours" << setw(10) << "Charge" << endl;
    
    cout << fixed << left << setw(5) << 1 << right << setw(10) << setprecision(1) << hoursFirst << setw(10) << setprecision(2) << feeFirst << endl;    
    cout << fixed << left << setw(5) << 2 << right << setw(10) << setprecision(1) << hoursSecond << setw(10) << setprecision(2) << feeSecond << endl;
    cout << fixed << left << setw(5) << 3 << right << setw(10) << setprecision(1) << hoursThird << setw(10) << setprecision(2) << feeThird << endl;

    cout << fixed << left << setw(5) << "TOTAL" << right << setw(10) << setprecision(1) << hoursFirst+hoursSecond+hoursThird << setw(10) << setprecision(2) << feeFirst+feeSecond+feeThird << endl;

    return 0;
}
