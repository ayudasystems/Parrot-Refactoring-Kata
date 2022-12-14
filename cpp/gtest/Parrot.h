#ifndef PARROT_PARROT_H
#define PARROT_PARROT_H

#include <memory>

enum ParrotType { DEBUG_MIN, EUROPEAN, AFRICAN, NORWEGIAN_BLUE};

class Parrot {
public:
    Parrot(ParrotType parrotType, double voltage, bool isNailed);

    virtual double getSpeed();

protected:
    double getBaseSpeed(double voltage);
    double getLoadFactor();
    double getBaseSpeed();

private:
    ParrotType parrotType = DEBUG_MIN;
    double voltage = 0.0;
    bool isNailed = false;
};

class EuropeanParrot: public Parrot {
public:
    EuropeanParrot(double voltage, bool isNailed)
        : Parrot(EUROPEAN, voltage, isNailed)
    {
    }

    virtual double getSpeed();
};

class AfricanParrot: public Parrot {
public:
    AfricanParrot(int numberOfCoconuts, double voltage, bool isNailed)
        : Parrot(AFRICAN, voltage, isNailed), numberOfCoconuts(numberOfCoconuts)
    {
    }
    double getSpeed() override;

private:
    int numberOfCoconuts = 0u;
};

class NorwegianParrot: public Parrot {
public:
    NorwegianParrot(double voltage, bool isNailed)
        : Parrot(NORWEGIAN_BLUE, voltage, isNailed)
    {
    }
    // virtual double getSpeed();
};

inline
std::unique_ptr<Parrot> parrot_factory(ParrotType parrotType, int numberOfCoconuts, double voltage, bool isNailed)
{
    switch (parrotType) {
    case EUROPEAN:
        return std::unique_ptr<Parrot>(new EuropeanParrot(voltage, isNailed));
    case AFRICAN:
        return std::unique_ptr<Parrot>(new AfricanParrot(numberOfCoconuts, voltage, isNailed));
    case NORWEGIAN_BLUE:
        return std::unique_ptr<Parrot>(new NorwegianParrot(voltage, isNailed));
    };

    return {};
}

#endif //PARROT_PARROT_H
