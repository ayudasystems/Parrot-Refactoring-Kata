#ifndef PARROT_PARROT_H
#define PARROT_PARROT_H

enum ParrotType { EUROPEAN, AFRICAN, NORWEGIAN_BLUE};

class Parrot {
public:
    Parrot(ParrotType parrotType, int numberOfCoconuts, double voltage, bool isNailed);

    double getSpeed();
private:
    ParrotType parrotType;
    int numberOfCoconuts;
    double voltage;
    bool isNailed;

    double getBaseSpeed(double voltage);
    double getLoadFactor();
    double getBaseSpeed();
};

inline Parrot *european_parrot_factory()
{
    return new Parrot(EUROPEAN, 0, 0, false);
}

inline Parrot *african_parrot_factory(int numberOfCoconuts)
{
    return new Parrot(AFRICAN, numberOfCoconuts, 0, false);
}

inline Parrot *norwegian_blue_parrot_factory(double voltage, bool isNailed)
{
    return new Parrot(NORWEGIAN_BLUE, 0, voltage, isNailed);
}

#endif //PARROT_PARROT_H
