#include <stdexcept>
#include <algorithm>

#include "Parrot.h"

using namespace std;

Parrot::Parrot(ParrotType parrotType, double voltage, bool isNailed)
: parrotType(parrotType), voltage(voltage), isNailed(isNailed) {}

double Parrot::getSpeed() {
    switch (parrotType) {
        case NORWEGIAN_BLUE:
            return (isNailed) ? 0 : getBaseSpeed(voltage);
        default:
            throw std::invalid_argument("Should be unreachable");
    }
}

double Parrot::getBaseSpeed() {
    return 12.0;
}

double Parrot::getLoadFactor() {
    return 9.0;
}

double Parrot::getBaseSpeed(double current_voltage) {
    return min(24.0, current_voltage * getBaseSpeed());
}

double EuropeanParrot::getSpeed()
{
    return getBaseSpeed();
}

double AfricanParrot::getSpeed()
{
    double loadFactor = 9.0;
    return std::max(0.0, Parrot::getBaseSpeed() - loadFactor * numberOfCoconuts);
}