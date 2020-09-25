// Invoice class interface implementation.
#include <iostream>
#include <string>
#include "Invoice.h"
using namespace std;

// class constructor implementation
Invoice::Invoice(string partNum, string partDesc, int partQuan, int pricePerIt){
    setPartNumber(partNum);
    setPartDescription(partDesc);
    setPartQuantity(partQuan);
    setPricePerItem(pricePerIt);
}

// get function for partNumber
string Invoice::getPartNumber(){
    return partNumber;
}

// set function for partNumber
void Invoice::setPartNumber(string partNum){
    partNumber = partNum;
}

// get function for partDescription
string Invoice::getPartDescription(){
    return partDescription;
}

// set function for partDescription
void Invoice::setPartDescription(string partDesc){
    partDescription = partDesc;
}

// get function for partQuantity
int Invoice::getPartQuantity(){
    return partQuantity;
}

// set function for partQuantity
void Invoice::setPartQuantity(int partQuan){
    if (partQuan <= 0){
        cerr << "Invalid part quantity. Setting to 0." << endl;
        partQuantity = 0;
    }else {
        partQuantity = partQuan;
    }
}

// get function for pricePerItem
int Invoice::getPricePerItem(){
    return pricePerItem;
}

// set function for pricePerItem
void Invoice::setPricePerItem(int pricePerIt){
    if (pricePerIt <= 0){
        cerr << "Invalid price per item. Setting to 0." << endl;
        pricePerItem = 0;
    }else {
        pricePerItem = pricePerIt;
    }
}

// function to compute the invoice amount
int Invoice::getInvoiceAmount(){
    return getPartQuantity() * getPricePerItem();
}