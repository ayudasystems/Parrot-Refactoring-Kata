#include <stdexcept>
#include <algorithm>

#include "Parrot.h"

using namespace std;

Parrot::Parrot(ParrotType parrotType)
    : parrotType(parrotType)
{
}

double Parrot::getBaseSpeed() const
{
    return 12.0;
}

double EuropeanParrot::getSpeed() const
{
    return getBaseSpeed();
}

double AfricanParrot::getSpeed() const
{
    return std::max(0.0, Parrot::getBaseSpeed() - LOAD_FACTOR * numberOfCoconuts);
}

double NorwegianParrot::getSpeed() const
{
    return (isNailed) ? 0 : getBaseSpeed(voltage);
}

double NorwegianParrot::getBaseSpeed(double current_voltage) const
{
    return min(24.0, current_voltage * Parrot::getBaseSpeed());
}