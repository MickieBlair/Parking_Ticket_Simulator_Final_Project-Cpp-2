#include "ParkingTicket.h"
#include <iomanip>
//Mickie Blair
//Final Project
//ParkingTicket Class
//Implementation File

#include <stdlib.h>
#include <algorithm>
#include <string>
#include "Validation.h"

using namespace std;

//constructor
ParkingTicket::ParkingTicket(ParkedCar c, ParkingMeter m, PoliceOfficer po)
{
	carInfo = c;
	meterInfo = m;
	officerInfo = po;
	fine = calculateFine();
	citationNumber = getCitationNumber();
	location = getLocation();
	meter = getMeterNumber();
	
}

//set parking ticket
void ParkingTicket::setParkedCar(ParkedCar c)
{
	carInfo = c;
}

//set parking meter
void ParkingTicket::setParkingMeter(ParkingMeter m)
{
	meterInfo = m;
}

//set police officer
void ParkingTicket::setPolicerOfficer(PoliceOfficer po)
{
	officerInfo = po;
}

//set fine
void ParkingTicket::setFine(int f)
{
	fine = f;
}

//get parked care
ParkedCar ParkingTicket::getParkedCar()
{
	return carInfo;
}

//get parking meter
ParkingMeter ParkingTicket::getParkingMeter()
{
	return meterInfo;
}

//get police officer
PoliceOfficer ParkingTicket::getPoliceOfficer()
{
	return officerInfo;
}

//get fine
double ParkingTicket::getFine()
{
	return fine;
}

//get random citation number
string ParkingTicket::getCitationNumber()
{
	string citNumber;
	int random;

	srand((unsigned int)time(NULL));
	
	for (int index = 0; index < 10; index++)
	{
		random = rand() % 9;
		citNumber.append(to_string(random));
	}

	return citNumber;
}

//get location
string ParkingTicket::getLocation()
{
	bool isValid = false;
	bool validLength = false;

	string street;

	do
	{
		try
		{
			cout << "\n   Enter the Location of the Violation: ";
			getline(cin, street);

			if (street.empty())
			{
				throw Validation::EmptyInput();
			}

			validLength = Validation::isValidLength(street, 18);

			if (!validLength)
			{
				throw Validation::MaxLength();
			}

			transform(street.begin(), street.end(), street.begin(), toupper);

			isValid = true;
		}
		
		catch (Validation::EmptyInput)
		{
			cout << "\n\n   Invalid Input: Location was empty\n" << endl;
		}

		catch (Validation::MaxLength)
		{
			cout << "\n\n   Invalid Input: Maximum Length of Input is 18 characters\n" << endl;
		}


	} while (!isValid);
	


	return street;
}

//get meter number
int ParkingTicket::getMeterNumber()
{
	bool isValid = false;
	bool isInteger = true;

	string meterNo;
	int meterNumber;

	do
	{
		try
		{
			cout << "\n   Enter the Meter Number: ";
			getline(cin, meterNo);

			
			if (meterNo.empty())
			{
				throw Validation::EmptyInput();
			}

			isInteger = Validation::isInteger(meterNo);

			if (!isInteger)
			{
				throw Validation::NumbersOnly();
			}

			isInteger = true;

			meterNumber = stoi(meterNo);
			
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

	return meterNumber;
}

//current day, date and time
void ParkingTicket::currentDayDateTime()
{
	string ticketDate = "  ";
	string ticketTime = "  ";
	string ext;

	time_t current_time;
	struct tm  local_time;

	time(&current_time);
	localtime_s(&local_time, &current_time);

	int Year = local_time.tm_year + 1900;
	int Month = local_time.tm_mon + 1;
	int Day = local_time.tm_mday;

	int Hour = local_time.tm_hour;
	int Min = local_time.tm_min;
	int Sec = local_time.tm_sec;
	
	//set the string of the date
	if (Month < 10)
	{
		ticketDate.append("0");
		ticketDate.append(to_string(Month));
		ticketDate.append("/");
	}
	else
	{
		ticketDate.append(to_string(Month));
		ticketDate.append("/");
	}
	
	if (Day < 10)
	{
		ticketDate.append("0");
		ticketDate.append(to_string(Day));
		ticketDate.append("/");
	}
	else
	{
		ticketDate.append(to_string(Day));
		ticketDate.append("/");
	}
	
	ticketDate.append(to_string(Year));

	//set the time
	if (Hour < 12)
	{
		ticketTime.append(to_string(Hour));
		ticketTime.append(":");
		ext = "AM";
	}
	else if (Hour == 12)
	{
		ticketTime.append("12");
		ticketTime.append(":");
		ext = "PM";
	}

	else
	{
		ticketTime.append(to_string(Hour-12));
		ticketTime.append(":");
		ext = "PM";
	}

	if (Min < 10)
	{
		ticketTime.append("0");
		ticketTime.append(to_string(Min));
		ticketTime.append(" ");
	}
	else
	{
		ticketTime.append(to_string(Min));
		ticketTime.append(" ");
	}

	ticketTime.append(ext);
	
	cout << setw(21) << left << ticketDate;
	cout << setw(20) << left << ticketTime;
	

}

//calculate fine
double ParkingTicket::calculateFine() {
	double minutesParked = carInfo.getMinParked();
	double minutesPaid = meterInfo.getMinPaid();
	double minutesOver;
	double hoursOver;
	
	minutesOver = minutesParked - minutesPaid;

	hoursOver = ceil(minutesOver / 60);

	{
		if (minutesOver <= 60)
		{
			fine = BASE_FINE;
		}
		else
		{
			fine = BASE_FINE;

			hoursOver -= 1;

			fine += hoursOver * ADD_FINE;
		}
	}

	return fine;

}

//print ticket
void ParkingTicket::printTicket()
{
	system("cls");
	system("Color F0");
	cout << setw(61) << right << "  _____________________________________________ \n";
		
	cout << setw(14) << right << "|";
	cout << setw(36) << right << "Notice of Parking Violation";
	cout << setw(11) << right << "|\n";
	
	cout << setw(14) << right << "|";
	cout << setw(30) << right << "City of Atlanta";
	cout << setw(17) << right << "|\n";
	
	cout << setw(14) << right << "|" << setw(47) << right << "|\n"; 

	cout << setw(14) << right << "|";
	cout << setw(41) << right << "Notice: You are charged with a parking";
	cout << setw(6) << right << "|\n";

	cout << setw(14) << right << "|";
	cout << setw(39) << right << "violation as indicated below";
	cout << setw(8) << right << "|\n";

	cout << setw(61) << right << " |_____________________________________________|\n";
		
	cout << setw(14) << right << "|" << "  Citation Number:  " 
		 << setw(25) << left << citationNumber << "|\n";

	cout << setw(14) << right << "|"	
		 << "  _________________________________________  "<< "|\n";
	
	cout << setw(16) << right << "| |";
	cout << setw(21) << left << "  Date:" << setw(20) << left 
		 << "  Time:" << "| |\n";

	cout << setw(16) << right << "| |";
	ParkingTicket::currentDayDateTime();
	cout << "| |\n";
	   
	cout << setw(16) << right << "| |" << setw(45) << right << "| |\n";

	cout << setw(16) << right << "| |";
	cout << setw(23) << left << "  Location:" << setw(18) << left
		<< "Meter No:" << "| |\n";

	cout << setw(16) << right << "| |";
	cout << "  " << setw(21) << left << location
		<< setw(17) << left << meter << " | |\n";

	cout << setw(16) << right << "| |" << setw(45) << right << "| |\n";

	cout << setw(16) << right << "| |";
	cout << setw(23) << left << "  Make:" << setw(18) << left
		<< "Color:" << "| |\n";

	cout << setw(16) << right << "| |";
	cout << "  " << setw(21) << left << carInfo.getMake()
		<< setw(18) << left << carInfo.getColor() << "| |\n";

	cout << setw(16) << right << "| |" << setw(45) << right << "| |\n";

	cout << setw(16) << right << "| |";
	cout << setw(23) << left << "  Model:" << setw(18) << left
		<< "License:" << "| |\n";

	cout << setw(16) << right << "| |";
	cout << "  " << setw(21) << left << carInfo.getModel()
		<< setw(18) << left << carInfo.getLicense() << "| |\n";


	cout << setw(14) << right << "|" << " |_____________________"
		 << "____________________| " << "|\n";

	cout << setw(14) << right << "|" << "   VIOLATION" << setw(35) 
		<< right << "  |\n";

	cout << setw(14) << right << "|" << "  ________________________"
		 << "_________________  " << "|\n";

	cout << setw(14) << right << "|" << " |  Code: ATL CODE SEC 150-133"
		 << setw(17) << right << "| |\n";

	cout << setw(14) << right << "|" << " |  PARKING METER VIOLATION"
		 << setw(20) << right << "| |\n";

	cout << setw(16) << right << "| |" << setw(45) << right << "| |\n";

	cout << setw(14) << right << "|" << " |  Meter Expired (minutes):  " 
		<< setw(12) << left << carInfo.getMinParked() - meterInfo.getMinPaid() 
		 << " | |\n";

	cout << setw(16) << right << "| |" << setw(45) << right << "| |\n";

	cout << setw(16) << right << "| |";
	cout << setw(24) << left << "  Due Now:" << setw(14) << left
		<< "After 30 Days:  ";
	cout << " | |\n";
	
	cout << setw(16) << right << "| |";
	cout << "  $ " << setw(20) << left << setprecision(2) << fixed 
		 << fine << "$ " << setw(14) << left
		 << fine * 2;
	cout << " | |\n";

	cout << setw(14) << right << "|" << " |_____________________"
		<< "____________________| " << "|\n";

	cout << setw(14) << right << "|" << "  ________________________"
		<< "_________________  " << "|\n";

	cout << setw(16) << right << "| |";
	cout << setw(23) << left << "  Officer Name:" << setw(18) << left
		<< "  Badge:   ";
	cout << "| |\n";

	cout << setw(16) << right << "| |";
	cout << "  " << setw(23) << left << officerInfo.getOfficerName()
		<< setw(16) << left << officerInfo.getOfficerBadge();
	cout << "| |\n";

	cout << setw(14) << right << "|" << " |_____________________"
		<< "____________________| " << "|\n";

	cout << setw(14) << right << "|" << setw(47) << right << "|\n";

	cout << setw(61) << right << " |   Signature ____________________________    |\n";

	cout << setw(61) << right << " |_____________________________________________|\n";
	
	cout << endl;
	cout << endl;

	system("pause");
}




