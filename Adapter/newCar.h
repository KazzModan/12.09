#pragma once
#include "Car.h"
#include "iCar.h"
class newCar : public iCar
{
private:
	Car car;
public:
	void run() override;
	void stop() override;
	void rotate(int angle) override;
};

