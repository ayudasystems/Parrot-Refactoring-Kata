#ifndef PARROT_PARROT_H
#define PARROT_PARROT_H

#include <memory>


class Parrot {
public:
    Parrot();
    virtual double getSpeed() const = 0;

protected:
    double getBaseSpeed() const;
};

class EuropeanParrot: public Parrot {
public:
    EuropeanParrot()
        : Parrot()
    {
    }

    double getSpeed() const override;
};

class AfricanParrot: public Parrot {
public:
    AfricanParrot(int numberOfCoconuts)
        : Parrot(), numberOfCoconuts(numberOfCoconuts)
    {
    }

    double getSpeed() const override;

private:
    int numberOfCoconuts = 0u;
};

class NorwegianParrot: public Parrot {
public:
    NorwegianParrot(double voltage, bool isNailed)
        : Parrot()
        , voltage(voltage)
        , isNailed(isNailed)
    {
    }

    double getSpeed() const override;

private:
    double getBaseSpeed(double voltage) const;

private:
    double voltage = 0.0;
    bool isNailed = false;
};

#endif //PARROT_PARROT_H
