#ifndef PARROT_PARROT_H
#define PARROT_PARROT_H

#include <memory>

enum ParrotType { EUROPEAN, AFRICAN, NORWEGIAN_BLUE};

class Parrot {
public:
    Parrot(ParrotType parrotType, int numberOfCoconuts, double voltage, bool isNailed);

    virtual double getSpeed();

protected:
    double getBaseSpeed(double voltage);
    double getLoadFactor();
    double getBaseSpeed();

private:
    ParrotType parrotType;
    int numberOfCoconuts;
    double voltage;
    bool isNailed;
};

class EuropeanParrot: public Parrot {
public:
    EuropeanParrot(int numberOfCoconuts, double voltage, bool isNailed)
        : Parrot(EUROPEAN, numberOfCoconuts, voltage, isNailed)
    {
    }

    virtual double getSpeed();
};

class AfricanParrot: public Parrot {
public:
    AfricanParrot(int numberOfCoconuts, double voltage, bool isNailed)
        : Parrot(AFRICAN, numberOfCoconuts, voltage, isNailed)
    {
    }

    // virtual double getSpeed();
};

class NorwegianParrot: public Parrot {
public:
    NorwegianParrot(int numberOfCoconuts, double voltage, bool isNailed)
        : Parrot(NORWEGIAN_BLUE, numberOfCoconuts, voltage, isNailed)
    {
    }

    // virtual double getSpeed();
};

inline
std::unique_ptr<Parrot> parrot_factory(ParrotType parrotType, int numberOfCoconuts, double voltage, bool isNailed)
{
    switch (parrotType) {
    case EUROPEAN:
        return std::unique_ptr<Parrot>(new EuropeanParrot(numberOfCoconuts, voltage, isNailed));
    case AFRICAN:
        return std::unique_ptr<Parrot>(new AfricanParrot(numberOfCoconuts, voltage, isNailed));
    case NORWEGIAN_BLUE:
        return std::unique_ptr<Parrot>(new NorwegianParrot(numberOfCoconuts, voltage, isNailed));
    };

    return {};
}

#endif //PARROT_PARROT_H
