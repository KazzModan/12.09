#pragma once
#include "hash.h"
#include "string"
using std::to_string;
using std::cout;
using std::endl;

class Account
{
public:
	Account();
	Account(size_t accNumber, string password);
	Account(size_t accNumber, string password, size_t amount);

	bool registration(size_t accNumber, string password);
	bool checkPassword(string password);
	bool login(string password);
	void exit();
	bool addMoney(size_t amount);
	bool takeMoney(size_t amount);
	void showInfo() const;
	bool setAmount(size_t amount);

	size_t getAmount() const;
	size_t getAccNumber() const;

	bool isNull() const;
	~Account();

protected:
	bool setPassword(string password);
	bool setAccNumber(size_t accNumber);

	size_t accID;
	Hash pass;
	size_t amount;

	bool access;

private:
	const size_t numLenght = 8;
	const size_t passLenght = 8;
	const size_t maxAmount = 1000000;

};

