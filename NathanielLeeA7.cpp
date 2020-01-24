//============================================================================
// Name        : NathanielLeeA7.cpp
// Author      : Nathaniel Lee
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <iomanip>
#include "AllVehicles.h" //header file contains vehicle, bus, rail car, and helicopter classes

// NOTE: that there are only 3 vehicles in file that do no need M

using namespace std;

int size = 50; // size of pointer array
int main() {


	Vehicle *vehicleInfo[size]; // pointer array of Vehicle class
	// for loop sets all of pointer array elements to be nullptr
	for (int i = 0; i < size; i++)
	{
		vehicleInfo[i] = nullptr;
	}
	// creating variables that will be used to extract data from files
	ifstream inputFile;

	string vID;
	string manufacturer;
	string service;
	string inspection;
	string capacity;
	string status;
	string get;
	int realCapacity;
	int realMileage;
	char realStatus;

	string mileage;
	string tireSize;
	string fuel;

	string power;
	string motor;

	string air;
	string engine;

	// open file
	inputFile.open("a7data.txt");
	int a = 0;
	// if file exists then proceed
	if(!inputFile.fail())
	{
		//while file can still get line and it has not reached end of file
		while (getline(inputFile, get) && !inputFile.eof())
		{

			// assigning vID variable with substring of get string
			vID = get.substr(0,4);

			// assigning manufacturer variable with substring of get string
			manufacturer=get.substr(4,15);

			// assigning service variable with substring of get string
			service = get.substr(19,8);


			//assigning inspection variable
			inspection = get.substr(27,8);
			// assigning capacity variable with substring of get string
			capacity = get.substr(35,3);
			// converting string to int using stoi
			realCapacity = stoi(capacity);

			// assigning status variable with substring of get string
			status = get.substr(38,2);
			// getting first letter of string
			realStatus = status[0];
			// if vehicle ID matches bus ID, its special variables will be assigned accordingly
			if (vID[0] == 'B')
			{
				mileage = get.substr(39,7);
				realMileage = stoi(mileage);
				tireSize = get.substr(46,9);

				fuel = get.substr(55,2);
				char realFuel = fuel[0];
				// calling bus constructor which calls vehicle constructor by default
				vehicleInfo[a] = new Bus(vID, manufacturer, service, inspection, realCapacity, realStatus, realMileage, tireSize, realFuel);
			}
			// if vehicle ID matches rail car ID, its special variables will be assigned accordingly
			else if (vID[0] == 'R'){

			power = get.substr(39,3);
			int realPower = stoi(power);
			motor = get.substr(42,5);
			// calling rail car constructor which calls vehicle constructor by default
			vehicleInfo[a] = new Railcar(vID, manufacturer, service, inspection, realCapacity, realStatus,realPower, motor);

			}
			// if vehicle ID matches Helicopter ID, it will assign its special values accordingly
			else if (vID[0] == 'H')
			{
				air = get.substr(39,5);
				engine = get.substr(44,4);
				int realAir = stoi(air);
				int realEngine = stoi(engine);
				// calling helicopter constructor which calls vehicle constructor by default
				vehicleInfo[a] = new Helicopter(vID, manufacturer, service, inspection, realCapacity, realStatus, realAir, realEngine);
			}
			// in case text file does not contain any proper vehicles
			else if (vID[0] != 'B' && vID[0] != 'R' && vID[0] != 'H')
			{
				cout << "not working" << endl;
			}
			// Increment count variable
			a++;
		}// end of while loop for reading file

		// close file
		inputFile.close();

		// calls virtual function to display all vehicle pointer array
		for (int i = 0; i < a; i++)
		{
			vehicleInfo[i]->display();
		}
	}
	// if file DNE
	else
	{
		cout << "File not found" << endl;
	}
	// once displayed, prompts user to search for specific vehicle
	cout << "Enter vehicle ID or 0000 to quit" << endl;
	string ID;
	cin >> ID;
	// user validation loop
	while (ID != "B001" && ID != "B002" && ID != "B003" &&ID != "B004" &&
			ID != "B005" && ID != "R001" && ID != "R002" && ID != "R003" &&
			ID != "R004" && ID != "R005" && ID != "H001" && ID != "H002" &&
			ID != "H003" && ID != "H004" && ID != "H005" && ID != "0000"
					)
		{
			cout << "Enter a valid vehicle ID or 0000 to quit" << endl;
			cin >> ID;
		}
	// while loop that runs until 0000 is entered
	while (ID != "0000")
	{
		// search through pointer array
			for (int i = 0; i < a; i++)
			{
				// if vehicle is found, display
				if (vehicleInfo[i] ->getID() == ID)
				{
					vehicleInfo[i]->display();
					// check specific vehicle maintenance requirements
					if (vehicleInfo[i]->checkMe())
					{
						// my own little touch, where program displays reason for changing status to M
						if (vehicleInfo[i]->getID()[0] == 'B')
						{
							cout << vehicleInfo[i] ->getID() << " " << "Mileage is over 25000 miles" << endl;
							vehicleInfo[i]->setStat('M');
						}
						if (vehicleInfo[i]->getID()[0] == 'R')
						{
							cout << vehicleInfo[i] ->getID() << " " << "Power has been on for 100 days or later" << endl;
							vehicleInfo[i]->setStat('M');
						}
						if (vehicleInfo[i]->getID()[0] == 'H')
						{
							cout << vehicleInfo[i] ->getID() << " " << "Airtime is 1000 hours or more or engine time is 750 hours or more" << endl;
							vehicleInfo[i]->setStat('M');
						}

					}
					// end for loop right then when vehicle has been found
					break;
				}
			}
			// prompt user if he or she would like to continue the search or end
			cout << "Enter vehicle ID or 0000 to quit" << endl;
			cin >> ID;
			while (ID != "B001" && ID != "B002" && ID != "B003" &&ID != "B004" &&
						ID != "B005" && ID != "R001" && ID != "R002" && ID != "R003" &&
						ID != "R004" && ID != "R005" && ID != "H001" && ID != "H002" &&
						ID != "H003" && ID != "H004" && ID != "H005" && ID != "0000"
								)
			{
				cout << "Enter a valid vehicle ID or 0 to quit" << endl;
				cin >> ID;
			}

	}
	// once user is done searching, one last display of all the vehicles with their
	// changes are shown
	cout << "Here is your list of vehicles after the update" << endl;
	// using virtual functions to display specific vehicle information
	for (int i = 0; i < a; i++)
	{
		vehicleInfo[i]->display();
	}
	// delete dynamically allocated memory
	for (int i = 0; i < size;i++)
	{
		if (vehicleInfo[i]!=nullptr)
		{
			delete vehicleInfo[i];
		}
	}
	// good bye message, letting user know program has successfully ended
	cout << "Thank you for using this program!" << endl;

	return 0;
}
// end of main function
