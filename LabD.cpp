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
bool isBalanceLessThan(Account* first, Account* second);
bool isAvailableLessThan(Account* first, Account* second);

int main() {
	Account myAccount("Jenny Meadowcroft",400,3000);
	cout << "The account of " << myAccount.getOwnerName() << " has a balance of " << myAccount.getCreditBalance() <<
			" with an available credit of " << myAccount.getAvailableCredit() << "." << endl;
	cout << "Enter 5 numbers separated by spaces" << endl;

	Account Accounts[5] = {Account("Bobby Frank", 200, 3500),
							Account("Billy Frank", 300, 1000),
							Account("Rebecca Frank", 1000, 1500),
							Account("Anna Frank", 800, 500),
							Account("Renee Frank", 700, 3500)};
	Account* AmountOwed[5];

	for(int i = 0; i < 5; i++)
	{
		AmountOwed[i] = &Accounts[i];

	}
	sort(AmountOwed, AmountOwed+ 5, isBalanceLessThan);


	for(int i = 0; i < 5; i++)
	{
		cout << i << " Location- " << &AmountOwed[i] << " " << AmountOwed[i] << " " << &*AmountOwed[i]<< endl
				<<" Name- " << AmountOwed[i]->getOwnerName() << endl << " Balance- " << AmountOwed[i]->getCreditBalance()
				<< endl << " Available Credit- " << AmountOwed[i]->getAvailableCredit() << endl;
	}


	return 0;

}

bool isBalanceLessThan(Account* first, Account* second){
	bool isSmaller = true;
	if((*first).getCreditBalance() > (*second).getCreditBalance()) {
		isSmaller = false;
	}
		return isSmaller;
}

bool isAvailableLessThan(Account* first, Account* second){
	bool isSmaller = true;
	if((*first).getAvailableCredit() > (*second).getAvailableCredit()) {
		isSmaller = false;
	}
		return isSmaller;
}
