#pragma once
#include "Client.h"
#include <vector>
using std::vector;

class BankSystem
{
public:
	bool addClient(Client* client);
	bool removeClient(size_t accNumber);
	Client* getClient(size_t accNumber, string password);
	Client* loginClient(size_t accNumber, string password);

	bool findClient(size_t accNumber);
	bool findClient(Client client);
	bool isEmpty();

	~BankSystem();

private:
	vector<Client*> clients;
};

