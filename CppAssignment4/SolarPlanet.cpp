#include "SolarPlanet.h"
#include <math.h>
//#include <iostream>

SolarPlanet::SolarPlanet()
{
}

SolarPlanet::~SolarPlanet()
{
}

void SolarPlanet::SetTime(double time)
{
	this->m_Time = time;
}

void SolarPlanet::SetSunMass(double sunMass)
{
	this->m_SunMass = sunMass;
}

void SolarPlanet::SetSunRadius(double sunRadius)
{
	this->m_SunRadius = sunRadius;
}

void SolarPlanet::SetAngularSpeed(double speed)
{
	this->m_AngularSpeed = speed;
}

//calculate the new coordinates of the planet after a certain amount of time.
//force due to gravity = centripetal force, you can use this to calculate the angular speed.
//angular speed = angle / time, with angular speed already calculated and time passed in, you can rearrange
//the equation to calculate the angle.
//angle = angular speed * time
//using this calculated angle, we know how much x and y 's positions have changed by with:
//change_x = r cos(theta), change_y = r sin(theta)
void SolarPlanet::Evolve(double dt)
{
	//in this example both these values constant, but in the real universe, planets distances from the Sun vary and so does the angular speed
	//so if this was used in the real world, these would have to be calculated at the time of working out the calculation
	this->CalculateRadiusFromSun();
	this->CalculateAngularSpeed();

	//use sohcahtoa to find the current value of theta
	double currentTheta = atan2(GetCoordinateY(), GetCoordinateX());

	double changeInTheta = GetAngularSpeed() * dt;
	double newTheta = changeInTheta + currentTheta;

	double newX = GetSunRadius() * cos(newTheta);
	double newY = GetSunRadius() * sin(newTheta);

	//set time += dt 
	this->SetTime(this->GetTime() + dt);

	//set new coordinates
	this->SetCoordinates(newX, newY);
} 

//simply pythagoras theorem, as we have coordinates (x,y) of planet, can use these values
//to form a right angle triangle between Sun and planet.
//root(x^2 + y^2)
void SolarPlanet::CalculateRadiusFromSun()
{
	double x2 = pow(GetCoordinateX(), 2);
	double y2 = pow(GetCoordinateY(), 2);
	double sum = x2 + y2;
	double radius = pow(sum, 0.5);

	//std::cout << "Radius from Sun is : " << radius << std::endl;
	SetSunRadius(radius);
}

//angular = root(GM/r^3)
//G = 6.673 x10-23
//M = mass of Sun
//r = radius from Sun
//*requires the radius from Sun to already be calculated*
void SolarPlanet::CalculateAngularSpeed()
{
	double angularSquared = UNIVERSAL_GRAVITATION * GetSunMass() / (pow(GetSunRadius(),3));
	double angular = pow(angularSquared, 0.5);

	//std::cout << "angular speed is : " << angular << std::endl;
	SetAngularSpeed(angular);
}
