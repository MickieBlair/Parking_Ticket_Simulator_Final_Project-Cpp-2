
//Mickie Blair
//Final Project
//ParkingMeter Class
//Implementation File
#include "ParkingMeter.h"
#include "Validation.h"

//constructor
ParkingMeter::ParkingMeter()
{
	minPaid = 0;
}

//constructor with minutes paid
ParkingMeter::ParkingMeter(int paid)
{
	minPaid = paid;
}

//set minutes paid
void ParkingMeter::setMinPaid(int paid)
{
	minPaid = paid;
}

//get minutes paid
int ParkingMeter::getMinPaid()
{
	return minPaid;
}

//overload the cout
ostream& operator<<(ostream& strm, const ParkingMeter& obj)
{
	//create strm of officer Name and Badge
	strm << "Minutes Paid: " << obj.minPaid << endl;

	return strm;
}

//overload the cing
istream& operator>>(istream& strm, ParkingMeter& obj)
{
	string meterMinPaid;

	bool isValid = false;
	bool validMinPaid = false;
	
	//get parking meter info and validate information
	do
	{
		try
		{
			//set minutes parked
			
			cout << "\n   Enter Minutes Paid at the Meter: ";
			getline(cin, meterMinPaid);

			if (meterMinPaid.empty())
			{
				throw Validation::EmptyInput();
			}

			validMinPaid = Validation::isInteger(meterMinPaid);
			if (!validMinPaid)
			{
				throw Validation::NumbersOnly();
			}

			obj.setMinPaid(stoi(meterMinPaid));

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

	return strm;
}
