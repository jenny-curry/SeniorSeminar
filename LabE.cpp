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
	Account* AmountAvailable[5];
	for(int i = 0; i < 5; i++)
	{
		AmountOwed[i] = &Accounts[i];
		AmountAvailable[i] = &Accounts[i];
	}
	sort(AmountOwed, AmountOwed+ 5, isBalanceLessThan);
	sort(AmountAvailable, AmountAvailable+ 5, isAvailableLessThan);
	bool going = true;
	bool retrieve = true;
	char selected;
	Account** whichIndexToUse;

	do{
		cout << "Would you like to view the unsorted accounts (type U), sorted by balance (type B), "
					"sorted by available credit (type A), or exit (type E)." << endl;
		cin >> selected;
		if(selected == "U" || selected == "u"){
			for(int i = 0; i < 5; i++)
				{
					cout << i << " Location- " << &Accounts[i] << endl
							<<" Name- " << Accounts[i].getOwnerName() << endl << " Balance- " << Accounts[i].getCreditBalance()
							<< endl << " Available Credit- " << AmountOwed[i]->getAvailableCredit() << endl;
				}
			retrieve = false;

		}
		else if(selected == "B" || selected == "b"){
			whichIndexToUse = AmountOwed;
			retrieve = true;
		}
		else if(selected == "A" || selected == "a"){
			whichIndexToUse = AmountAvailable;
			retrieve = true;
		}
		else if(selected == "E" || selected == "e"){
			going = false;
			retrieve = false;
		}
		else{
			cout << "Not a valid response. Please try again." << endl;
			retrieve = false;
		}

		if(retrieve){

		}

	} while(going);

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
