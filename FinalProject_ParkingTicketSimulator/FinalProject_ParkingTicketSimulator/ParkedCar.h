//Mickie Blair
//Final Project
//ParkedCar Class
//Class Specification File

#ifndef PARKEDCAR_H
#define PARKEDCAR_H

#include <iostream>
#include <string>

using namespace std;

class ParkedCar {

private:
	string make;		//car make
	string model;		//car model
	string color;		//car color
	string license;		//car license
	int minParked;		//minutes parked

public:
	//constructor - no args
	ParkedCar();

	//constructor
	ParkedCar(string, string, string, string, int);

	//setters
	void setMake(string);
	void setModel(string);
	void setColor(string);
	void setLicense(string);
	void setMinParked();

	//getters
	string getMake();
	string getModel();
	string getColor();
	string getLicense();
	int getMinParked();


	//friends;
	friend ostream& operator<<(ostream&, const ParkedCar&);
	friend istream& operator>>(istream&, ParkedCar&);

};

#endif