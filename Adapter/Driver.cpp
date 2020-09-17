#include "Driver.h"

Driver::Driver()
{
	car = new newCar;
}

Driver::~Driver()
{
	delete car;
}

void Driver::drive()
{

	car->run();
	car->rotate(100);
	car->rotate(-150);
	car->stop();
}
