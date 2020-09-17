#include "Bank.h"

bool BankSystem::addClient(Client* client)
{
	if (client != nullptr)
		if (!client->isNull())
		{
			this->clients.push_back(client);
			cout << "Client added to bank\n";
			return true;
		}

	cout << "Client creation error\n";
	return false;
}

bool BankSystem::removeClient(size_t accNumber)
{
	for (size_t i = 0; i < this->clients.size(); i++)
		if (*this->clients[i] == accNumber)
		{
			this->clients.erase(this->clients.begin() + i);
			cout << "Client removed from bank\n";
			return true;
		}
	cout << "Client remove error\n";
	return false;
}

Client* BankSystem::getClient(size_t accId, string password)
{
	for (Client* client : this->clients)
		if (*client == accId)
			if (client->checkPassword(password))
				return client;
	return nullptr;
}

Client* BankSystem::loginClient(size_t accId, string password)
{
	for (Client* client : this->clients)
		if (*client == accId)
			if (client->login(password))
				return client;
	return nullptr;
}

bool BankSystem::findClient(size_t accId)
{
	for (Client* client : this->clients)
		if (*client == accId)
			return true;
	return false;
}

bool BankSystem::findClient(Client client)
{
	return findClient(client.getAccNumber());
}

bool BankSystem::isEmpty()
{
	return this->clients.empty();
}

BankSystem::~BankSystem()
{
	this->clients.clear();
}
