//Mickie Blair
//Final Project
//ParkingMeter Class
//Class Specification File

#ifndef PARKINGMETER_H
#define PARKINGMETER_H

#include <iostream>
#include <string>

using namespace std;

class ParkingMeter {

private:
	int minPaid;

public:
	//constructor - no args
	ParkingMeter();

	//constructor
	ParkingMeter(int);

	//setters
	void setMinPaid(int);

	//getters
	int getMinPaid();
	
	//friends
	friend ostream& operator<<(ostream&, const ParkingMeter&);
	friend istream& operator>>(istream&, ParkingMeter&);
};

#endif