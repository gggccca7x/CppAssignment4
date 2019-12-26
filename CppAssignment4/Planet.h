#pragma once

#include <string>

class Planet
{
	//variables
private:
	std::string m_Name;
	double m_Mass;
	double m_CoordinateX;
	double m_CoordinateY;

	//functions:
public:
	Planet();
	virtual ~Planet();

	void SetName(std::string name);
	void SetMass(double mass);
	void SetCoordinates(double coX, double coY);
	void SetCoordinateX(double coX);
	void SetCoordinateY(double coY);

	std::string GetName() { return m_Name; }
	double GetMass() { return m_Mass; }
	double GetCoordinateX() { return m_CoordinateX; }
	double GetCoordinateY() { return m_CoordinateY; }
};

