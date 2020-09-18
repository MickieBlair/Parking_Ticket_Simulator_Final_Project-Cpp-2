//Mickie Blair
//Final Project
//ParkedCar Class
//Implementation File

#include "ParkedCar.h"
#include "Validation.h"

#include <iostream>
#include <string>
#include <algorithm>


//constructor - no args;
ParkedCar::ParkedCar()
{
	make = "";
	model = "";
	color = "";
	license = "";
	minParked = 0;
}

//constructor;
ParkedCar::ParkedCar(string cMake, string cModel, string cColor,
					string cLisc, int cMinParked)
{
	make = cMake;
	model = cModel;
	color = cColor;
	license = cLisc;
	minParked = cMinParked;
}

//set Make
void ParkedCar::setMake(string cMake)
{
	make = cMake;
}

//set Model
void ParkedCar::setModel(string cModel)
{
	model = cModel;
}

//set Color
void ParkedCar::setColor(string cColor)
{
	color = cColor;
}

//set License
void ParkedCar::setLicense(string cLisc)
{
	license = cLisc;
}

//set minutes parked
void ParkedCar::setMinParked()
{
	string carMinParked;			//string of minutes parked	
	bool validMinParked = false;	//valid min parked
	bool isValid = false;			//is valid boolean

	// do with try catch for validation
	do
	{
		try
		{
			cout << "\n   Enter Minutes Car Parked: ";
			getline(cin, carMinParked);

			if (carMinParked.empty())
			{
				throw Validation::EmptyInput();
			}

			validMinParked = Validation::isInteger(carMinParked);
			
			if (!validMinParked)
			{
				throw Validation::NumbersOnly();
			}

			minParked = stoi(carMinParked);
			
			isValid = true;
		}

		catch (Validation::EmptyInput)
		{
			cout << "\n\n   Invalid Input: Field was empty\n" << endl;
		}

		catch (Validation::NumbersOnly)
		{
			cout << "\n\n   Invalid Input: Positive Integers Only\n" << endl;
		}
				
		catch (out_of_range)
		{
			cout << "\n\n   Max Length is 9 digits\n" << endl;
		}

	} while (!isValid);
}

//get make
string ParkedCar::getMake()
{
	return make;
}

//get model
string ParkedCar::getModel()
{
	return model;
}

//get color
string ParkedCar::getColor()
{
	return color;
}

//get license
string ParkedCar::getLicense()
{
	return license;
}

//get minutes parked
int ParkedCar::getMinParked()
{
	return minParked;
}


//overloaded cout
ostream& operator<<(ostream& strm, const ParkedCar& obj)
{
	//create strm of officer Name and Badge
	strm << "Make: " << obj.make << endl
		<< "Model: " << obj.model << endl
		<< "Color: " << obj.color << endl
		<< "License: " << obj.license << endl
		<< "Minutes Parked: " << obj.minParked << endl;

	return strm;
}

//overloaded cin
istream& operator>>(istream& strm, ParkedCar& obj)
{
	string carMake;					//car make		
	string carModel;				//car model
	string carColor;				//car color
	string carLicense;				//car license
		
	bool isValid = false;			//bool for is Valid
	bool validCarMake = false;		//bool for valid car make
	bool validCarModel = false;		//bool for valid car model
	bool validCarColor = false;		//bool for valid car color
	bool validCarLicense = false;	//bool for valid car license
	bool validLength = false;		//bool for valid length
		
	//get car info and validate information
	do
	{
		try
		{   
			//set car make if not valid
			do
			{
				
				if (!validCarMake)
				{
					cout << "\n   Enter Car Make: ";
					getline(cin, carMake);

					if (carMake.empty())
					{
						throw Validation::EmptyInput();
					}

					validLength = Validation::isValidLength(carMake, 16);

					if (!validLength)
					{
						throw Validation::MaxLength();
					}

					transform(carMake.begin(), carMake.end(), carMake.begin(), toupper);

					validCarMake = Validation::isValidName(carMake);

					if (!validCarMake)
					{
						throw Validation::InvalidInput();
					}

					validCarMake = true;

				}

			} while (!validCarMake);

			obj.setMake(carMake);

			//set car model if not valid
			do
			{

				if (!validCarModel)
				{
					cout << "\n   Enter Car Model: ";
					getline(cin, carModel);

					if (carModel.empty())
					{
						throw Validation::EmptyInput();
					}

					validLength = Validation::isValidLength(carModel, 16);

					if (!validLength)
					{
						throw Validation::MaxLength();
					}

					transform(carModel.begin(), carModel.end(), carModel.begin(), toupper);

					validCarModel = Validation::isValidName(carModel);

					if (!validCarModel)
					{
						throw Validation::InvalidInput();
					}

					validCarModel = true;

				}

			} while (!validCarModel);

			obj.setModel(carModel);

			//set car color if not valid
			do
			{

				if (!validCarColor)
				{
					cout << "\n   Enter Car Color: ";
					getline(cin, carColor);

					if (carColor.empty())
					{
						throw Validation::EmptyInput();
					}

					validLength = Validation::isValidLength(carColor, 16);

					if (!validLength)
					{
						throw Validation::MaxLength();
					}

					transform(carColor.begin(), carColor.end(), carColor.begin(), toupper);

					validCarColor = Validation::isValidName(carColor);

					if (!validCarColor)
					{
						throw Validation::InvalidInput();
					}

					validCarColor = true;

				}

			} while (!validCarColor);

			obj.setColor(carColor);

			//set car license if not valid
			do
			{
				if (!validCarLicense)
				{
					cout << "\n   Enter Car License: ";
					getline(cin, carLicense);

					if (carLicense.empty())
					{
						throw Validation::EmptyInput();
					}

					validLength = Validation::isValidLength(carLicense, 16);

					if (!validLength)
					{
						throw Validation::MaxLength();
					}

					transform(carLicense.begin(), carLicense.end(), carLicense.begin(), toupper);

					validCarLicense = Validation::isLettersOrNumbers(carLicense);

					if (!validCarLicense)
					{
						throw Validation::NumbersOrLetters();
					}

					validCarLicense = true;

				}

			} while (!validCarLicense);

			obj.setLicense(carLicense);

			isValid = true;
		}

		catch (Validation::InvalidInput)
		{
			cout << "\n\n   Invalid Input: Only letters, spaces, and hyphens\n" << endl;
		}

		catch (Validation::EmptyInput)
		{
			cout << "\n\n   Invalid Input: Field was empty\n" << endl;
		}

		catch (Validation::NumbersOnly)
		{
			cout << "\n\n   Invalid Input: Positive Integers Only\n" << endl;
		}

		catch (Validation::NumbersOrLetters)
		{
			cout << "\n\n   Invalid Input: Letters and Digits Only\n" << endl;
		}

		catch (out_of_range)
		{
			cout << "\n\n   Max Length is 9 digits\n" << endl;
		}

		catch (Validation::MaxLength)
		{
			cout << "\n\n   Invalid Input: Maximum Length of Input is 16 characters\n" << endl;
		}


	} while (!isValid);

	return strm;
}
