//Mickie Blair
//Final Project
//ParkingTicket Class
//Class Specification File

#ifndef PARKINGTICKET_H
#define PARKINGTICKET_H

#include <ctime>
#include "ParkedCar.h"
#include "ParkingMeter.h"
#include "PoliceOfficer.h"

using namespace std;

class ParkingTicket {
private:
	ParkedCar carInfo;
	ParkingMeter meterInfo;
	PoliceOfficer officerInfo;
	double fine;
	const double BASE_FINE = 25.00;
	const double ADD_FINE = 10.00;
	string citationNumber;
	string location;
	int meter;
	

public:
	//constructor
	ParkingTicket(ParkedCar, ParkingMeter, PoliceOfficer);

	//setters
	void setParkedCar(ParkedCar);
	void setParkingMeter(ParkingMeter);
	void setPolicerOfficer(PoliceOfficer);
	void setFine(int);

	//getters
	ParkedCar getParkedCar();
	ParkingMeter getParkingMeter();
	PoliceOfficer getPoliceOfficer();
	double getFine();

	//get random citation number
	string getCitationNumber();

	//get location 
	string getLocation();

	//get meter number
	int getMeterNumber();

	//get time
	static void currentDayDateTime();

	//calculate fine
	double calculateFine();

	//print ticket
	void printTicket();
	
};

#endif