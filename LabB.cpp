//============================================================================
// Name        : Test.cpp
// Author      : Jenny Meadowcroft
// Version     :
// Copyright   : Your copyright notice
// Description : This is my C++ driver that tests the basic function of the account class, including calculate payment. WOW!!
//============================================================================

#include <iostream>
#include "Account.h"
using namespace std;

int main() {
	Account myAccount("Jenny Meadowcroft",400,3000);
	cout << "The account of " << myAccount.getOwnerName() << " has a balance of " << myAccount.getCreditBalance() <<
			" with an available credit of " << myAccount.getAvailableCredit() << "." << endl;
	cout << "Enter your name" << endl;
	string yourName;
	cin >> yourName;
	float creditBalance, availableBalance;
	cout << "Enter your credit balance.";
	cin >> creditBalance;
	cout << "Enter your available credit.";
	cin >> availableBalance;
	Account yourAccount(yourName, creditBalance, availableBalance);
	cout << "The account of " << yourAccount.getOwnerName() << " has a balance of " << yourAccount.getCreditBalance() <<
				" with an available credit of " << yourAccount.getAvailableCredit() <<
				". This means that your next payment due is " << yourAccount.calculatePayment() << endl;
	cout << "Now we will simulate your payments for six months, and I will tell you if you still have a lot of debt or not. "
			"If you do you'll have to keep paying until it has become a managable amount." << endl;
	// This for loup will calculate a monthly payment 6 times and pay it off, while adjusting for the new balance
	for(int a = 0; a < 6; a++) {
		float thisPayment = yourAccount.calculatePayment();
		float newCreditBalance = yourAccount.getCreditBalance() - thisPayment;
		float newAvailableCredit = yourAccount.getAvailableCredit() + thisPayment;
		yourAccount.setCreditBalance(newCreditBalance);
		yourAccount.setAvailableCredit(newAvailableCredit);
		cout << "Month " << a << " Statement" << endl;
		cout << "Credit Balance: " << yourAccount.getCreditBalance() << endl;
		cout << "Available Credit: " << yourAccount.getAvailableCredit() << endl << endl;
	}
	bool makePayment = true;
	int month = 6;
	//This do while will test the account to see if the debt is < 100, if it is, they will be done pamking payments, if not they will
	//continue making payments.
	do {
		if(yourAccount.getCreditBalance() < 100)
		{
			makePayment = false;
			cout << "Looks like you have a managable amount of debt! Good job!" << endl<< endl;
		}
		else
		{
			cout << "Well you are still paying..." << endl;
			float thisPayment = yourAccount.calculatePayment();
			float newCreditBalance = yourAccount.getCreditBalance() - thisPayment;
			float newAvailableCredit = yourAccount.getAvailableCredit() + thisPayment;
			yourAccount.setCreditBalance(newCreditBalance);
			yourAccount.setAvailableCredit(newAvailableCredit);
			cout << "Month " << (month) << " Statement" << endl;
			cout << "Credit Balance: " << yourAccount.getCreditBalance() << endl;
			cout << "Available Credit: " << yourAccount.getAvailableCredit() << endl << endl;
			month++;
		}
	}
	while(makePayment);

	return 0;
}
