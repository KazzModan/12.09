#include "Hash.h"

Hash::Hash()
{
	this->hash = "\0";
}

Hash::Hash(string pass)
{
	set(pass);
}

string Hash::get() const
{
	return string(hash);
}

void Hash::set(string pass)
{
	//65 - 90
	string base;
	size_t length = pass.length();
	string* hash = new string[length];

	base += pass[0];
	base += pass[length - 1];

	for (size_t i = 0; i < length; i++)
		for (size_t j = 0; j < base.length(); j++)
			hash[i] += base[j] + pass[i];

	help(hash, length);

	for (size_t i = 1; i < length; i++)
		swap(hash[i], hash[length - 1 - i]);

	help(hash, length);

	string newHash;

	for (size_t i = 0; i < length; i++)
	{
		newHash += hash[i];
		if (i != length - 1)
			newHash += ':';
	}

	delete[] hash;
	this->hash = newHash;
}

void Hash::print()
{
	cout << this->hash << endl;
}

bool Hash::operator==(string text)
{
	Hash hash(text);
	return (this->hash == hash.get());
}

bool Hash::isEmpty() const
{
	if (this->hash == "\0")
		return false;
	return true;
}

void Hash::clear()
{
	this->hash = "\0";
}

void Hash::help(string* hash, size_t length)
{
	for (size_t i = 0; i < length; i++)
		for (size_t j = 0; j < hash[i].length(); j++)
			while ((hash[i][j] < 'A' || hash[i][j] > 'Z') && (hash[i][j] < '0' || hash[i][j] > '9'))
			{
				if (i != 0)
				{
					if (j < hash[i].length() - 1)
						hash[i][j] += hash[i - 1][j + 1];
					else
						hash[i][j] += hash[i - 1][j - 1];
				}
				else
				{
					if (j < hash[i].length() - 1)
						hash[i][j] += hash[i + 1][j + 1];
					else
						hash[i][j] += hash[i + 1][j - 1];
				}
			}
}
