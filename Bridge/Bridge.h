#pragma once
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class Language
{
public:
	virtual size_t getSalaryPerHour() = 0;
	virtual size_t getSalaryPerLine() = 0;

};

class Calculator
{
public:
	Calculator();
	Calculator(Language* language);

	size_t getSalary(Language* language = nullptr); 
	static void Menu();

	~Calculator();
private:
	size_t TAX;
	Language* language;
};

class CPlusPlus : public Language 
{
public:
	size_t getSalaryPerHour() override { return 1000; }
	size_t getSalaryPerLine() override { return 10; }
};

class CSharp : public Language
{
public:
	size_t getSalaryPerHour() override { return 800; }
	size_t getSalaryPerLine() override { return 8; }
};

class Python : public Language
{
public:
	size_t getSalaryPerHour() override { return 500; }
	size_t getSalaryPerLine() override { return 5; }
};

class JavaScript : public Language
{
public:
	size_t getSalaryPerHour() override { return 300; }
	size_t getSalaryPerLine() override { return 3; }
};