#include "ATM.h"

BankMachine::BankMachine()
{
	this->bank = nullptr;
	this->currentClient = nullptr;
}

BankMachine::BankMachine(BankSystem* bank)
{
	if (bank != nullptr)
		this->bank = bank;
	else
		this->bank = nullptr;
	this->currentClient = nullptr;
}

bool BankMachine::authorization()
{
	if (!checkBank())
		return false;

	bool correct = false;
	size_t tempNumber;
	string tempPassword;

	cout << "Enter your account number(8 digits):\n";
	do
	{
		ClearBuffer();
		cin >> tempNumber;
		if (to_string(tempNumber).length() != this->passLenght)
			cout << "Error! account number incorrect. \nEnter again: \n";
		else
			correct = true;
	} while (!correct);

	if (this->bank->findClient(tempNumber))
	{
		correct = false;

		Client* client = nullptr;
		cout << "Enter your password:\n";
		for (int i = 2; i >= 0; i--)
		{
			cin >> tempPassword;
			client = this->bank->loginClient(tempNumber, tempPassword);
			if (client != nullptr)
			{
				correct = true;
				break;
			}
			else
				cout << "Error! password incorrect. \nEnter again(" << i << " attempts): \n";
		}
		if (correct)
		{
			if (this->currentClient != nullptr)
			{
				delete this->currentClient;
				this->currentClient = nullptr;
			}
			this->currentClient = client;
			cout << "Authorized! \n";
			return true;
		}
		else
		{
			cout << "Incorrect password! \n Not authorized! \n";
			return false;
		}
	}
	cout << "User don't found! \n";
	return false;

}

bool BankMachine::authorization(size_t accNumber, string password)
{
	if (!checkBank())
		return false;

	if (to_string(accNumber).length() != this->passLenght)
	{
		cout << "Error! account number incorrect. \nEnter again: \n";
		return false;
	}

	if (this->bank->findClient(accNumber))
	{
		Client* client = this->bank->loginClient(accNumber, password);
		if (client == nullptr)
		{
			cout << "Error! password incorrect!\n";
			return false;
		}
		if (this->currentClient != nullptr)
		{
			delete this->currentClient;
			this->currentClient = nullptr;
		}
		this->currentClient = client;
		cout << "Authorized! \n";
		return true;
	}
	cout << "User not found! \n";
	return false;
}

bool BankMachine::addMoney(size_t amount)
{
	if (this->currentClient != nullptr)
	{
		if (this->currentClient->getStatus())
		{
			this->currentClient->addMoney(amount);
			return true;
		}
		cout << "Not access\n";
	}
	cout << "No authorized user\n";
	return false;
}

bool BankMachine::takeMoney(size_t amount)
{
	if (this->currentClient != nullptr)
	{
		if (this->currentClient->getStatus())
		{
			this->currentClient->takeMoney(amount);
			return true;
		}
		cout << "Not access\n";
	}
	cout << "No authorized user\n";
	return false;
}

bool BankMachine::showInfo()
{
	if (this->currentClient != nullptr)
	{
		if (this->currentClient->getStatus())
		{
			this->currentClient->showInfo();
			return true;
		}
		cout << "Not access\n";
	}
	cout << "No authorized user\n";
	return false;
}

void BankMachine::exit()
{
	if (this->currentClient != nullptr)
	{
		this->currentClient->exit();
		this->currentClient = nullptr;
	}
}

BankMachine::~BankMachine()
{
	if (this->bank != nullptr)
	{
		delete this->bank;
		this->bank = nullptr;
	}

	if (this->currentClient != nullptr)
	{
		delete this->currentClient;
		this->currentClient = nullptr;
	}
}

bool BankMachine::checkBank() const
{
	if (this->bank != nullptr)
	{
		if (!this->bank->isEmpty())
			return true;
		cout << "Users not found! Bank empty!\n";
	}
	return false;
}
