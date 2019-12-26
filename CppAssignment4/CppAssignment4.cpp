#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "SolarPlanet.h"

void CheckPlanets();
void CoordinatesOfPlanets();
void DaysAroundSun();

int main()
{
	//CheckPlanets();
	//CoordinatesOfPlanets();
	
	DaysAroundSun();

	return 0;
}

//method to check planets all get obtained correctly from the file
//Part 1
void CheckPlanets() {
	std::ifstream myfile("Planets_data.txt");
	std::vector<Planet> planets;

	int line = 0;

	while (!myfile.eof())
	{
		std::string name;
		double mass, coordinateX, coordinateY;
		if (!myfile.eof())
		{
			line++;
		}
		myfile >> name >> mass >> coordinateX >> coordinateY;
		Planet p;
		p.SetName(name);
		p.SetMass(mass);
		p.SetCoordinates(coordinateX, coordinateY);
		planets.push_back(p);
	}

	for (int i = 0; i < planets.size(); i++)
	{
		Planet &p = planets.at(i);
		std::cout << p.GetName() << std::endl;
		std::cout << p.GetMass() << std::endl;
		std::cout << p.GetCoordinateX() << std::endl;
		std::cout << p.GetCoordinateY() << std::endl;
		std::cout << std::endl;
	}
}

//Method to write a csv file for each planet and output planets coordinates every set seconds for a set amount of time.
//Both delta time and duration are inputs
//Part's 2 3 4 5
void CoordinatesOfPlanets() {
	int timePerIteration, numberOfIterations;
	std::cout << "Enter how many seconds per iteration: ";
	std::cin >> timePerIteration;
	std::cout << "Enter how many times to iterate: ";
	std::cin >> numberOfIterations;

	std::ifstream myfile("Planets_data.txt");
	std::vector<SolarPlanet> planets;

	int line = 0;

	while (!myfile.eof())
	{
		std::string name;
		double mass, coordinateX, coordinateY;
		if (!myfile.eof())
		{
			line++;
		}
		myfile >> name >> mass >> coordinateX >> coordinateY;
		SolarPlanet p;
		p.SetName(name);
		p.SetMass(mass);
		p.SetCoordinates(coordinateX, coordinateY);
		p.SetSunMass(1.9890e+30);

		planets.push_back(p);
	}

	for (SolarPlanet &p : planets)
	{
		std::cout << p.GetName() << ", X: ";
		std::cout << p.GetCoordinateX() << ", Y: ";
		std::cout << p.GetCoordinateY() << std::endl;
	}

	//looping through a year calculating new positions hourly
	for (SolarPlanet &p : planets)
	{
		std::ofstream myfile(p.GetName() + ".csv");
		for (int i = 0; i < numberOfIterations; i++)
		{
			p.Evolve(timePerIteration);
			myfile << p.GetTime() << "," << p.GetCoordinateX() << "," << p.GetCoordinateY() << "\n";
		}
	}

	std::cout << std::endl;

	for (SolarPlanet &p : planets)
	{
		std::cout << p.GetName() << ", X: ";
		std::cout << p.GetCoordinateX() << ", Y: ";
		std::cout << p.GetCoordinateY() << std::endl;
	}
}

//method to find how many earth days it takes each planets to go around the Sun
//calculate 1 year for each planet
//iterate 1 day at a time and if x coordinate is positive and y goes from negative to positive, then its back to the starting point
//Part 6
void DaysAroundSun() {
	std::ifstream myfile("Planets_data.txt");
	std::vector<SolarPlanet> planets;

	int line = 0;

	const int secondsInADay = 86400;

	while (!myfile.eof())
	{
		std::string name;
		double mass, coordinateX, coordinateY;
		if (!myfile.eof())
		{
			line++;
		}
		myfile >> name >> mass >> coordinateX >> coordinateY;
		SolarPlanet p;
		p.SetName(name);
		p.SetMass(mass);
		p.SetCoordinates(coordinateX, coordinateY);
		p.SetSunMass(1.9890e+30);

		planets.push_back(p);
	}

	for (SolarPlanet &p : planets) 
	{
		bool yearComplete = false;
		bool yPositive = false;
		int days = 0;

		while (!yearComplete)
		{
			if (yPositive)
			{
				if (p.GetCoordinateY() > 0)
				{
					std::cout << p.GetName() << " completed orbit in " << days << " days." << std::endl;
					yearComplete = true;
				}
			}

			if (!yPositive && p.GetCoordinateY() < 0)
			{
				yPositive = true;
			}
			
			p.Evolve(86400);
			days++;
		}

	}
}