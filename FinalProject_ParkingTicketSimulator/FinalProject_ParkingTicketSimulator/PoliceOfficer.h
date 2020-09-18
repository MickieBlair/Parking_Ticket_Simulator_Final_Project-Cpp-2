//Mickie Blair
//Final Project
//PolicerOfficer Class
//Class Specification File

#ifndef POLICEOFFICER_H
#define POLICEOFFICER_H

#include <iostream>
#include <string>
#include "ParkedCar.h"
#include "ParkingMeter.h"

using namespace std;

class PoliceOfficer {

private:
	string officerName;			//string for officer name
	int officerBadge;			//integer for officer badge
	
public:
	//constructor - no args
	PoliceOfficer();

	//constructor
	PoliceOfficer(string, int);

	//copy constructor
	PoliceOfficer(const PoliceOfficer& officer2);

	//setters
	void setOfficerName(string);
	void setOfficerBadge(int);

	//getters
	string getOfficerName();
	int getOfficerBadge();

	//copy officer
	PoliceOfficer copyOfficer(const PoliceOfficer&);
	
	//examine car and meter
	void examineCarMeter(ParkedCar, ParkingMeter);

	//issue ticket
	void issueTicket(ParkedCar, ParkingMeter);
	
	//friends
	friend ostream& operator<<(ostream&, const PoliceOfficer&);
	friend istream& operator>>(istream&, PoliceOfficer&);
};

#endif