#ifndef PARROT_PARROT_H
#define PARROT_PARROT_H

#include <memory>

enum ParrotType { DEBUG_MIN, EUROPEAN, AFRICAN, NORWEGIAN_BLUE };

class Parrot {
public:
    Parrot(ParrotType parrotType);

    virtual double getSpeed() const = 0;

protected:
    double getBaseSpeed() const;

protected:
    ParrotType parrotType = DEBUG_MIN;
};

class EuropeanParrot: public Parrot {
public:
    EuropeanParrot()
        : Parrot(EUROPEAN)
    {
    }

    double getSpeed() const override;
};

class AfricanParrot: public Parrot {
public:
    static constexpr double LOAD_FACTOR = 9.0;

public:
    AfricanParrot(int numberOfCoconuts)
        : Parrot(AFRICAN), numberOfCoconuts(numberOfCoconuts)
    {
    }
    double getSpeed() const override;

private:
    int numberOfCoconuts = 0u;
};

class NorwegianParrot: public Parrot {
public:
    NorwegianParrot(double voltage, bool isNailed)
        : Parrot(NORWEGIAN_BLUE)
        , voltage(voltage)
        , isNailed(isNailed)
    {
    }

    double getSpeed() const override;
    double getBaseSpeed(double voltage) const;

private:
    double voltage = 0.0;
    bool isNailed = false;
};

inline
std::unique_ptr<Parrot> parrot_factory(ParrotType parrotType, int numberOfCoconuts, double voltage, bool isNailed)
{
    switch (parrotType) {
    case EUROPEAN:
        return std::unique_ptr<Parrot>(new EuropeanParrot());
    case AFRICAN:
        return std::unique_ptr<Parrot>(new AfricanParrot(numberOfCoconuts));
    case NORWEGIAN_BLUE:
        return std::unique_ptr<Parrot>(new NorwegianParrot(voltage, isNailed));
    };

    return {};
}

#endif //PARROT_PARROT_H
