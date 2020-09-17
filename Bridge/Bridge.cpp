#include "Bridge.h"

Calculator::Calculator()
{
	this->language = nullptr;
	this->TAX = 20;
}

Calculator::Calculator(Language* language)
{
	this->language = language;
	this->TAX = 20;
}

size_t Calculator::getSalary(Language* language)
{
	if (language != nullptr)
		this->language = language;

	if (this->language == nullptr)
		return 0;

	cout << "1. work in the company\n";
	cout << "2. works as a freelancer\n";
	cout << "enter your choose: ";

	char choose;
	size_t quantity;
	size_t salary;

	cin >> choose;

	switch (choose)
	{
	case '1':
		cout << "enter quantity of hours: ";
		cin >> quantity;
		salary = quantity * this->language->getSalaryPerHour();
		salary = (salary / 100) * (100 - this->TAX);
		break;
	case '2':
		cout << "enter quantity of lines: ";
		cin >> quantity;
		salary = quantity * this->language->getSalaryPerLine();
		break;
	default:
		return 0;
		break;
	}

	return salary;
}

void Calculator::Menu()
{
	cout << "1. C++\n";
	cout << "2. C#\n";
	cout << "3. Python\n";
	cout << "4. JavaScript\n";
	cout << "enter your choice: ";

	char choice;
	cin >> choice;

	Language* language = nullptr;

	switch (choice)
	{
	case '1':
		language = new CPlusPlus;
		break;
	case '2':
		language = new CSharp;
		break;
	case '3':
		language = new Python;
		break;
	case '4':
		language = new JavaScript;
		break;
	default:
		return;
		break;
	}

	Calculator calculator(language);
	cout << "salary : " << calculator.getSalary() << endl;
}

Calculator::~Calculator()
{
	delete this->language;
}
