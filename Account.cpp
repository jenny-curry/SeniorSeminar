/*
 * Accounts.cpp
 *
 *  Created on: Jan 20, 2020
 *      Author: jenny
 */
#include "Account.h"
#include <cmath>
#include <Algorithm>

Account::Account(string ownerNameRecieved, float creditBalanceRecieved, float availableCreditRecieved){
	ownerName = ownerNameRecieved;
	creditBalance = creditBalanceRecieved;
	availableCredit = availableCreditRecieved;
}

string Account::getOwnerName() {
	return ownerName;
}

float Account::getCreditBalance() {
	return creditBalance;
		}

float Account::getAvailableCredit() {
	return availableCredit;
}

void Account::setOwnerName(string ownerNameRecieved) {
	ownerName = ownerNameRecieved;
	return;
}

void Account::setCreditBalance(float creditBalanceRecieved) {
	creditBalance = creditBalanceRecieved;
	return;
}

void Account::setAvailableCredit(float availableCreditRecieved) {
	availableCredit = availableCreditRecieved;
	return;
}

float Account::calculatePayment() {
	return creditBalance/5;
}

void Account::modify(int arrayRecieved[]){

	return;
}

bool Account::isLessThan(int first, int second){
	bool isSmaller = true;
	if(first > second) {
		isSmaller = false;
	}
		return isSmaller;
}

