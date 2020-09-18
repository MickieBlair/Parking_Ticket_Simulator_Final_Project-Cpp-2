//Mickie Blair
//Final Project
//Parking Ticket Simulator

#include "Prototypes.h"
#include "ParkedCar.h"
#include "ParkingMeter.h"
#include "ParkingTicket.h"
#include "PoliceOfficer.h"

#include <iostream>
#include <string>
#include <iomanip>
#include <new>
#include <algorithm>
#include <Windows.h>

using namespace std;

//main function
int main() {

	//set the console size
	HWND console = GetConsoleWindow();
	RECT r;

	GetWindowRect(console, &r);
	MoveWindow(console, r.top, r.left, 550, 750, TRUE);

	try
	{
		//repeat the program
		repeatProgram();

		//display complete message
		cout << "\n   Program run complete.\n";

	}
	catch (bad_alloc)
	{
		cout << "\n   Insufficient Memory.\n";
	}


	return 0;

}

//repeat Program
void repeatProgram() {

	string again;					//variable for again loop 

	//do while loop
	do
	{
		//display introduction
		showIntro();

		//ParkingTicket Demo
		parkingTicketDemo();
			
		//ask user if they would like to go again
		cout << "\n   Would you like to run the program again? (Enter Y or N): ";
		getline(cin, again);

		//validate entry
		while (again != "Y" && again != "N" && again != "y" && again != "n")
		{
			cout << "\n   Invalid entry:" << endl;
			cout << "\n   Would you like to run the program again? (Enter Y or N): ";
			getline(cin, again);
		}

		cout << endl;

		//clear
		system("CLS");
	}

	while (again == "Y" || again == "y");
}

//show Intro
void showIntro() {
	//display introduction
	cout << "                     Parking Ticket Simulator\n" << endl;
	cout << "   The program will simulate an officer inspecting cars and parking \n"
		<< "   meters to determine if a ticket needs to be issued.\n\n"
		<< "   When a parking ticket is issued, it will include the following:\n\n"
		<< "    - the car make, model, color, and license number \n"
		<< "    - the amount of the fine ($25 for the first hour or part of\n"
		<< "      an hour that the car exceeds the paid meter, plus $10 for \n"
		<< "      every additional hour or part an hour).\n"
		<< "    - the name and badge number of the issuing officer\n\n"
		<< endl;

	system("pause");
}

//parking ticket Demo
void parkingTicketDemo() {
	//clear the screen
	system("CLS");
	
	//get officer information with loop for new officer
	inputOfficerInfo();
}

//input Officer info with the option to choose a different issuing officer
void inputOfficerInfo() {

	string again;					//variable for again loop 
	PoliceOfficer officer;			//officer object
	
	//do while loop
	do
	{
		cout << setw(50) << right << "Inspecting Officer Information\n\n";

		//get officer info
		getOfficerDetails(officer);

		//demonstrate the ticket simulation program
		inspectCarMeter(officer);

		system("cls");

		//change color
		system("Color 0F");

		//ask user if they would like to choose from the menu again
		cout << "\n   Would a different officer like to log in? (Enter Y or N): ";
		getline(cin, again);

		//validate entry
		while (again != "Y" && again != "N" && again != "y" && again != "n")
		{
			cout << "\n\n   Invalid entry:" << endl;
			cout << "\n   Would a different officer like to log in? (Enter Y or N): ";
			getline(cin, again);
		}

		//clear the screen
		system("CLS");
	}

	while (again == "Y" || again == "y");
}

//get officer info
void getOfficerDetails(PoliceOfficer & po) {
	
	//overloaded cin for officer
	cin >> po;

}

//demo ticket simulator to examine car and meter
void inspectCarMeter(PoliceOfficer& patrol) {
	system("cls");
	
	string again;					//variable for again loop 
	ParkedCar car;					//parked car object
	ParkingMeter meter;				//parking meter object

	//do while loop
	do
	{
		//header
		cout << setw(50) << right << "Inspection Information\n\n";

		//set the car minutes parked
		cout << "   Parking Meter Information \n";
		car.setMinParked();

		//set the meter
		cin >> meter;

		//officer examines car and meter
		patrol.examineCarMeter(car, meter);

		//clear the console
		system("cls");

		//change color
		system("Color 0F");
		
		//ask user if they would like to choose from the menu again
		cout << "\n   Would you like to enter information for"
			<< " a different meter?\n\n   Enter Y or N: ";
		getline(cin, again);

		//validate entry
		while (again != "Y" && again != "N" && again != "y" && again != "n")
		{
			cout << "\n\n   Invalid entry:" << endl;
			cout << "\n   Would you like to enter information for"
				<< " a different meter?\n\n   Enter Y or N: ";
			getline(cin, again);
		}

		//clear the screen
		system("CLS");
	}

	while (again == "Y" || again == "y");
	
}
