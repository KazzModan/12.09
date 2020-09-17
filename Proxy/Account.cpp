#include "Account.h"

Account::Account()
{
	this->pass;
	this->accID = 0;
	this->amount = 0;
	this->access = false;
}

Account::Account(size_t accNumber, string password) : Account()
{
	registration(accNumber, password);
}

Account::Account(size_t accNumber, string password, size_t amount) : Account()
{
	if (registration(accNumber, password))
	{
		this->access = !this->access;
		setAmount(amount);
		this->access = !this->access;
	}
}

bool Account::registration(size_t accNumber, string password)
{
	if (setAccNumber(accNumber))
	{
		if (setPassword(password))
		{
			cout << "Account registration complete!\n";
			return true;
		}

		cout << "Incorrect account password!\n";
		this->accID = 0;
		return false;
	}
	cout << "Incorrect account number!\n";
	return false;

}

bool Account::checkPassword(string password)
{
	return (this->pass == password);
}

bool Account::login(string password)
{
	if (this->accID != 0)
	{
		if (checkPassword(password))
		{
			this->access = true;
			return true;
		}
		return false;
	}
}

void Account::exit()
{
	if (!this->access)
		cout << "You are already out!\n";
	else
	{
		cout << "You got out.\n";
		this->access = false;
	}
}

bool Account::addMoney(size_t amount)
{
	if (!this->access)
		return false;

	if (this->amount + amount <= this->maxAmount)
	{
		this->amount += amount;
		cout << "Money added! New amount " << this->amount << endl;
		return true;
	}
	cout << "Limit exceeded\n";
	return false;
}

bool Account::takeMoney(size_t amount)
{
	if (!this->access)
		return false;

	if (static_cast<int>(this->amount - amount) > 0)
	{
		this->amount -= amount;
		cout << "Money taken! New amount " << this->amount << endl;
		return true;
	}
	cout << "Limit exceeded\n";
	return false;
}

void Account::showInfo() const
{
	if (!this->access)
		return;
	cout << "Account number: " << this->accID << endl;
	cout << "Money amount: " << this->amount << endl;
}

bool Account::setAmount(size_t amount)
{
	if (!this->access)
		return false;
	if (amount <= this->maxAmount)
	{
		this->amount = amount;
		return true;
	}
	return false;
}

size_t Account::getAmount() const
{
	return this->amount;
}

bool Account::setPassword(string password)
{
	if (password.length() >= this->passLenght)
	{
		this->pass.set(password);
		return true;
	}
	cout << "Password haven't 8 symbols\n";
	return false;
}

bool Account::setAccNumber(size_t accNumber)
{
	if (this->accID != 0)
		return false;

	if (to_string(accNumber).length() == this->numLenght)
	{
		this->accID = accNumber;
		return true;
	}
	return false;
}

size_t Account::getAccNumber() const
{
	return this->accID;
}

bool Account::isNull() const
{
	return ((this->accID == 0) && this->pass.isEmpty());
}

Account::~Account()
{
	this->accID = 0;
	this->amount = 0;
}
