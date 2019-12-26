#include "Planet.h"

Planet::Planet()
{
}


Planet::~Planet()
{
}

void Planet::SetName(std::string name)
{
	this->m_Name = name;
}

void Planet::SetMass(double mass)
{
	this->m_Mass = mass;
}

void Planet::SetCoordinates(double coX, double coY)
{
	this->m_CoordinateX = coX;
	this->m_CoordinateY = coY;
}

void Planet::SetCoordinateX(double coX)
{
	this->m_CoordinateX = coX;
}

void Planet::SetCoordinateY(double coY)
{
	this->m_CoordinateY = coY;
}
