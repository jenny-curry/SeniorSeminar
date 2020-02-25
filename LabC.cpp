//============================================================================
// Name        : Test.cpp
// Author      : Jenny Meadowcroft
// Version     :
// Copyright   : Your copyright notice
// Description : This is my C++ driver that tests the basic function of the account class, including calculate payment. WOW!!
//============================================================================

#include <iostream>
#include "Account.h"
#include <algorithm>
using namespace std;
bool isLessThan(int first, int second);

int main() {
	Account myAccount("Jenny Meadowcroft",400,3000);
	cout << "The account of " << myAccount.getOwnerName() << " has a balance of " << myAccount.getCreditBalance() <<
			" with an available credit of " << myAccount.getAvailableCredit() << "." << endl;
	cout << "Enter 5 numbers separated by spaces" << endl;
	int a,b,c,d,e;
	cin >> a >> b >> c >> d >> e;
	int array[5];
	array[0] = a;
	array[1] = b;
	array[2] = c;
	array[3] = d;
	array[4] = e;
	cout << "We are now going to sort the array using pass by reference" << endl;
	sort(array,array+ 5, isLessThan);
	cout << array[0] << ", " << array[1] << ", " << array[2] << ", " << array[3] << ", " << array[4]  << endl;
	cout << "To retrieve my available credit, I pass the value" << endl;
	cout << "Available Credit: " << myAccount.getAvailableCredit() << endl;


	return 0;

}

bool isLessThan(int first, int second){
	bool isSmaller = true;
	if(first > second) {
		isSmaller = false;
	}
		return isSmaller;
}
