#include "Car.h"

void Car::start()
{
	this->speed = 100;
}

void Car::stop()
{
	this->speed = 0;
}

void Car::left(int angle)
{
	this->angle += angle;
}

void Car::right(int angle)
{
	this->angle += angle;
}
