#ifndef PARROT_PARROT_H
#define PARROT_PARROT_H

enum ParrotType { EUROPEAN, AFRICAN, NORWEGIAN_BLUE};

class Parrot {
public:
	Parrot(ParrotType parrotType, int numberOfCoconuts, double voltage, bool isNailed);
	virtual ~Parrot() {}

	virtual double getSpeed();

protected:
	int numberOfCoconuts;
	double voltage;
	bool isNailed;

	double getBaseSpeed();
	double getBaseSpeed(double voltage);
	double getLoadFactor();

private:
	ParrotType parrotType;
};

class EuropeanParrot : public Parrot {
public:
	EuropeanParrot()
		: Parrot(EUROPEAN, 0, 0, false)
	{}

	// Parrot interface
public:
	double getSpeed();
};

class AfricanParrot : public Parrot {
public:
	AfricanParrot(int numberOfCoconuts)
		: Parrot(AFRICAN, numberOfCoconuts, 0, false)
	{}

	// Parrot interface
public:
	double getSpeed();
};

class NorwegianParrot : public Parrot {
public:
	NorwegianParrot(double voltage, bool isNailed)
		: Parrot(NORWEGIAN_BLUE, 0, voltage, isNailed)
	{}

	// Parrot interface
public:
	double getSpeed();
};

inline Parrot *european_parrot_factory()
{
	return new EuropeanParrot();
}

inline Parrot *african_parrot_factory(int numberOfCoconuts)
{
	return new AfricanParrot(numberOfCoconuts);
}

inline Parrot *norwegian_blue_parrot_factory(double voltage, bool isNailed)
{
	return new NorwegianParrot(voltage, isNailed);
}

#endif //PARROT_PARROT_H
