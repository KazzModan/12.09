#pragma once
#include "Bank.h"
using std::cin;

class BankMachine
{
public:
	BankMachine();
	BankMachine(BankSystem* bank);
	bool authorization();

	bool authorization(size_t accNumber, string password);

	bool addMoney(size_t amount);
	bool takeMoney(size_t amount);
	bool showInfo();
	void exit();
	~BankMachine();

private:
	bool checkBank() const;
	BankSystem* bank;
	Client* currentClient;

	const size_t passLenght = 8;
};

inline void ClearBuffer()
{
	if (char(cin.peek()) == '\n')
		cin.ignore();

	if (cin.fail())
	{
		cin.clear();
		cin.ignore(32767, '\n');
	}
}