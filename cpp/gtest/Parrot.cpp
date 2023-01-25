#include <stdexcept>
#include <algorithm>

#include "Parrot.h"

using namespace std;

double Parrot::getBaseSpeed() {
	return 12.0;
}


double EuropeanParrot::getSpeed()
{
	return getBaseSpeed();
}

double AfricanParrot::getSpeed()
{
	return max(0.0, getBaseSpeed() - getLoadFactor() * numberOfCoconuts);
}

double AfricanParrot::getLoadFactor() {
	return 9.0;
}

double NorwegianParrot::getSpeed()
{
	return (isNailed) ? 0 : getBaseSpeed(voltage);
}

double NorwegianParrot::getBaseSpeed(double current_voltage) {
	return min(24.0, current_voltage * Parrot::getBaseSpeed());
}
