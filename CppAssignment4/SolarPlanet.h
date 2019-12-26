#pragma once

#include "Planet.h"

class SolarPlanet : public Planet
{
	//variables
private:
	double m_Time, m_G, m_SunMass, m_SunRadius, m_AngularSpeed;
	
	//for calculating part 3
	double const UNIVERSAL_GRAVITATION = 6.673e-20;

	//functions
public:
	SolarPlanet();
	virtual ~SolarPlanet();

	double GetTime() { return m_Time; }
	double GetSunMass() { return m_SunMass; }
	double GetSunRadius() { return m_SunRadius; }
	double GetAngularSpeed() { return m_AngularSpeed; }

	void SetTime(double time);
	void SetSunMass(double sunMass);
	void SetSunRadius(double sunRadius);
	void SetAngularSpeed(double speed);

	//double dt is in seconds
	void Evolve(double dt);

private:

	//pre determining variables for the evolve function
	void CalculateRadiusFromSun();
	void CalculateAngularSpeed();
};
