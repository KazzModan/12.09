#pragma once
#include <iostream>

class Car
{
public: 
	void start();
	void stop();
	void left(int angle);
	void right(int angle);
private:
	int angle;
	std::string name;
	size_t speed;

};

