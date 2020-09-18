//Mickie Blair
//Final Project
//PoliceOfficer Class
//Implementation File

#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>

#include "PoliceOfficer.h"
#include "Validation.h"
#include "ParkingTicket.h"



//constructor - no args
PoliceOfficer::PoliceOfficer()
{
	officerName = "";
	officerBadge = 0;
}

//constructor
PoliceOfficer::PoliceOfficer(string n, int b)
{
	officerName = n;
	officerBadge = b;
}

// Copy constructor
PoliceOfficer::PoliceOfficer(const PoliceOfficer& officer2)
{
	officerName = officer2.officerName;
	officerBadge = officer2.officerBadge;
}

//set officer name
void PoliceOfficer::setOfficerName(string n)
{
	officerName = n;
}

//set officer badge
void PoliceOfficer::setOfficerBadge(int b)
{
	officerBadge = b;
}

//get officer name
string PoliceOfficer::getOfficerName()
{
	return officerName;
}

//get officer badge
int PoliceOfficer::getOfficerBadge()
{
	return officerBadge;
}

//copy officer
PoliceOfficer PoliceOfficer::copyOfficer(const PoliceOfficer& po)
{
	PoliceOfficer *copy = new PoliceOfficer(po);

	return *copy;
}

//examine car and meter
void PoliceOfficer::examineCarMeter(ParkedCar car, ParkingMeter meter)
{
	//clear console
	system("cls");

	//header
	cout << setw(47) << right << "Inspection Results\n\n";

	//if else to issue a ticket if meter expired
	if (car.getMinParked() > meter.getMinPaid())
	{
		cout << endl;
		cout << endl;

		cout << setw(52) << right << "***Parking Meter Violation***\n\n";

		cout << endl;
		
		//get the rest of the car information
		cin >> car;

		//issue a ticket
		issueTicket(car, meter);

	}

	else
	{
		cout << endl;
		cout << endl;

		cout << setw(47) << right << "***No Violation***\n\n";

		cout << endl;
		cout << endl;
		
		cout << setw(60) << right << "The minutes paid on the meter is currently greater\n";
		cout << setw(57) << "than the minutes the car has been parked.\n\n"<< endl;

		system("pause");
	}
	
}

//issue ticket
void PoliceOfficer::issueTicket(ParkedCar car, ParkingMeter meter)
{

	//create a parking ticket with car, meter, and officer	
	ParkingTicket *ticket = new ParkingTicket(car, meter, copyOfficer(*this));

	//print the ticket
	ticket->printTicket();
}

//overload the cout <<
ostream& operator<<(ostream& strm, const PoliceOfficer& obj)
{
	//create strm of officer Name and Badge
	strm << "Officer Name: " << obj.officerName << endl
		 << "Badge Number: " << obj.officerBadge << endl;
	
	return strm;
}

//overload the cin >>
istream& operator>>(istream& strm, PoliceOfficer& obj)
{
	string name;				//input from user officer name
	string badgeStr;			//input from user badge as a string
	bool isValid = false;		//bool for valid officer info
	bool validName = false;		//bool for valid officer name
	bool validBadge = false;	//bool for valid officer badge
	bool validLength = false;	//bool for valid length

	//do to get officer information
	do
	{
		//try/catch for validation with exceptions
		try
		{
			do
			{
				//get valid name
				if (!validName)
				{
					cout << "\n   Enter Officer Name: ";
					getline(cin, name);

					if (name.empty())
					{
						throw Validation::EmptyInput();
					}

					validLength = Validation::isValidLength(name, 21);
					
					if (!validLength)
					{
						throw Validation::MaxLength();
					}
					
					transform(name.begin(), name.end(), name.begin(), toupper);
					
					validName = Validation::isValidName(name);

					if (!validName)
					{
						throw Validation::InvalidInput();
					}
				
					validName = true;

				} 

			}while (!validName);
			
			obj.setOfficerName(name);	
			
			//get badge number
			do
			{
				cout << "\n   Enter Badge Number: ";
				getline(cin, badgeStr);

				if (badgeStr.empty())
				{
					throw Validation::EmptyInput();
				}

				validBadge = Validation::isInteger(badgeStr);
				
				if (!validBadge)
				{
					throw Validation::NumbersOnly();
				}

				validBadge = true;

			} while (!validBadge);
			
			obj.setOfficerBadge(stoi(badgeStr));
			
			isValid = true;
		}
		
		catch (Validation::InvalidInput)
		{
			cout << "\n\n   Invalid Input: Only letters, spaces, hyphens, and periods" << endl;
			cout << "\n   Example Valid Officer Name: Sgt. Mary Smith-Jones\n" << endl;
		}

		catch (Validation::EmptyInput)
		{
			cout << "\n\n   Invalid Input: Field was empty\n" << endl;
		}

		catch (Validation::NumbersOnly)
		{
			cout << "\n\n   Invalid Input: Positive Integers Only\n" << endl;
		}

		catch (Validation::MaxLength)
		{
			cout << "\n\n   Invalid Input: Maximum Length of Input is 21 characters\n" << endl;
		}
		
		catch (out_of_range)
		{
			cout << "\n\n   Max Length is 9 digits\n" << endl;
		}
		

	} while (!isValid);

	return strm;
}

