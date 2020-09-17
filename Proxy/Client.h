#pragma once
#include "Account.h"

class Client : public Account
{
protected:
	string name;

public:
	Client() : Account()
	{
		//clear
	}

	Client(string name, size_t accNumber, string password)
		: Account(accNumber, password)
	{
		setName(name);
	}

	Client(string name, size_t accNumber, string password, size_t amount)
		: Account(accNumber, password, amount)
	{
		setName(name);
	}

	bool setName(string name)
	{
		if (!name.empty())
		{
			this->name = name;
			return true;
		}
		return false;
	}

	bool operator==(const size_t& accNumber)
	{
		return (this->accID == accNumber);
	}

	bool operator==(const Client& client)
	{
		return (this->accID == client.accID);
	}

	bool isNull() const
	{
		return (this->name.empty() && Account::isNull());
	}

	string getName() const
	{
		return this->name;
	}

	bool getStatus() const
	{
		return this->access;
	}
};
