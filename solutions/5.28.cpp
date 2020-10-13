// This program uses the evaluation structure of switch statement in C++ to
// print the "Twelve Days of Christmas" carol, have fun!
#include <iostream>
#include <string>

using namespace std;

#define DAYS_OF_CHIRSTMAS 12

int main(){
    string dayStr;

    for (int day=1; day<=DAYS_OF_CHIRSTMAS; day++){

        // translate day of Christmas to ordinal numbers
        switch(day){
            case 1:
                dayStr = "first";
                break;
            case 2:
                dayStr = "second";
                break;
            case 3:
                dayStr = "third";
                break;
            case 4:
                dayStr = "fourth";
                break;
            case 5:
                dayStr = "fifth";
                break;
            case 6:
                dayStr = "sixth";
                break;
            case 7:
                dayStr = "seventh";
                break;
            case 8:
                dayStr = "eightth";
                break;
            case 9:
                dayStr = "nineth";
                break;
            case 10:
                dayStr = "tenth";
                break;
            case 11:
                dayStr = "eleventh";
                break;
            case 12:
                dayStr = "twelveth";
                break;
        }

        cout << "On the " << dayStr << " day of Christmas my true love sent to me" << endl;
        
        // Print each verse that collapses onto the previous verses 
        switch (day){
            case 12:
                cout << "12 drummers drumming, " << endl;
            case 11:
                cout << "11 pipers piping, " << endl;
            case 10:
                cout << "10 lords a-leaping, " << endl;
            case 9:
                cout << "9 ladies dancing, " << endl;
            case 8:
                cout << "8 maids a-milking, " << endl;
            case 7:
                cout << "7 swans a-swimming, " << endl;
            case 6:
                cout << "6 geese a-laying, " << endl;
            case 5:
                cout << "5 gold rings, " << endl;
            case 4:
                cout << "4 calling birds, " << endl;
            case 3:
                cout << "3 French hens, " << endl;
            case 2:
                cout << "2 turtle doves, " << endl;
            case 1:
                cout << (day != 1? "And a" :"A") << " patridge in a pear tree." << endl;
                cout << endl;
        }
    }

    return 0;
}