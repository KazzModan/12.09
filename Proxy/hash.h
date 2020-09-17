#pragma once
#include <iostream>
using std::string;
using std::cout;
using std::endl;

class Hash
{
public:
	Hash();
	Hash(string pass);

	string get() const;
	void set(string pass);

	void print();
	bool operator==(string text);
	bool isEmpty() const;
	void clear();

private:
	string hash;

	void help(string* hash, size_t length);

};