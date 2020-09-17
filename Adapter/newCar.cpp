#include "newCar.h"

void newCar::run()
{
	car.start();
}

void newCar::stop()
{
	car.stop();
}

void newCar::rotate(int angle)
{
	if (angle > 0)
		car.right(angle);
	else
		car.left(angle);
}
