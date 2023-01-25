#ifndef PARROT_PARROT_H
#define PARROT_PARROT_H

class Parrot {
public:
	virtual ~Parrot() = default;

	virtual double getSpeed() = 0;

protected:
	double getBaseSpeed();
	double getBaseSpeed(double voltage);
	
};

class EuropeanParrot : public Parrot {
public:
	EuropeanParrot() = default;

	// Parrot interface
public:
	double getSpeed();
};

class AfricanParrot : public Parrot {
public:
	AfricanParrot(int numberOfCoconuts)
		: numberOfCoconuts(numberOfCoconuts)
	{}

	// Parrot interface
public:
	double getSpeed();

private:
	double getLoadFactor();
	int numberOfCoconuts;
};

class NorwegianParrot : public Parrot {
public:
	NorwegianParrot(double voltage, bool isNailed)
		: voltage(voltage)
		, isNailed(isNailed)
	{}

	// Parrot interface
public:
	double getSpeed();

private:
	double voltage;
	bool isNailed;
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
