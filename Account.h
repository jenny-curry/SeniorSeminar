/*
 * Accounts.h
 *
 *  Created on: Jan 20, 2020
 *      Author: jenny
 */

#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>
using namespace std;

class Account {
public:
	Account(string ownerName="Mary Sue", float creditBalance = 0.00f, float availableCredit = 1000.00f);
	string getOwnerName();
	float getCreditBalance();
	float getAvailableCredit();
	void setOwnerName(string temp);
	void setCreditBalance(float temp);
	void setAvailableCredit(float temp);
	float calculatePayment();
	void modify(int array[]);
	bool isLessThan(int first, int second);
private:
	string ownerName;
	float creditBalance;
	float availableCredit;
	int array[];


};
#endif
