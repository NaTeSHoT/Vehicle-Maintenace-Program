/*
 * AllVehicleFunctions.cpp
 *
 *  Created on: Nov 9, 2019
 *      Author: nateshot
 */
#include "AllVehicles.h" // function definitions of classes in header file
#include <string>
#include <iomanip>
#include <iostream>
using namespace std;

// Vehicle constructor
Vehicle::Vehicle(string vID, string manu, string serv, string in, int cap, char stat)
{
		vehicleID = vID;
		manufacturer = manu;
		service = serv;
		inspection = in;
		capacity = cap;
		status = stat;
}
// vehicle getter functions
	string Vehicle::getID()
	{
		return vehicleID;

	}
	string Vehicle::getManu(){
		return manufacturer;
	}
	string Vehicle::getServ()
	{
		return service;
	}
	string Vehicle::getIn()
	{
		return inspection;
	}
	int Vehicle::getCap(){
		return capacity;
	}
	char Vehicle::getStat(){
		return status;
	}
	// vehicle setter functions
	void Vehicle::setStat(char c)
	{
		status = c;
	}
	// bus getter functions that are also derived from base class
		int Bus::getMile()
		{
			return mileage;
		}
		string Bus::getTire()
		{
			return tireSize;
		}
		char Bus::getFuel()
		{
			return fuel;
		}
		// helicopter getter functions that are also derived from base class
		int Helicopter::getFlight()
		{
				return flightTime;
		}
		int Helicopter::getEngine()
		{
				return engineTime;
		}
		// railcar getter functions that are also derived from base class
		int Railcar::getPower()
		{
				return powerOn;
		}
		string Railcar::getMotor()
		{
				return motor;
		}

		// required virtual functions for assignment
		void Vehicle::display(){};
		// virtual destructor
		Vehicle::~Vehicle(){};
		bool Vehicle::checkMe(){};
		// displaying a bus object derived from base class vehicle
		void Bus::display()
		{
			cout << "______________________________________________________________________________________________________________________________________";
																		cout << endl;

			cout << "ID Number";
			cout << setw(15) << fixed;
			cout << "Manufacturer";
			cout << setw(15) << fixed;
			cout << "Service";
			cout << setw(15) << fixed;
			cout << "Inspection";
			cout << setw(15) << fixed;
			cout << "Capacity";
			cout << setw(15);
			cout << "Status";
			cout << setw(15);
			cout << "Mileage";
			cout << setw(15);
			cout << "Tire Size";
			cout << setw(15);
			cout << "Gas type";
			//cout << ""
			cout << endl;



			cout <<getID();
			cout << setw(20) << fixed;
			cout << getManu();
			cout << setw(15) << fixed;

			cout << setw(10) << fixed;
			cout << getServ();

			cout << setw(15) << fixed;
			cout << getIn();
			cout << setw(15) << fixed;
			cout << getCap();
			cout << setw(15);
			cout << getStat();
			cout << setw(15) << fixed;
			cout <<mileage;
			cout << setw(15) << fixed;
			cout << tireSize;
			cout << setw(15) << fixed;
			cout << fuel;
			cout << endl;
			cout << "______________________________________________________________________________________________________________________________________";
															cout << endl;
		}
		// bool virtual function that checks if vehicle requires maintenance
		bool Bus::checkMe()
		{
			bool status = false;
			if (this->mileage > 25000)
			{
				status = true;
			}
			return status;
		}
		// displaying a rail car object derived from base class vehicle
		void Railcar::display()
		{
			cout << "______________________________________________________________________________________________________________________________________";
																		cout << endl;

			cout << "ID Number";
												cout << setw(15) << fixed;
												cout << "Manufacturer";
												cout << setw(10);
												cout << "Service";
												cout << setw(15) << fixed;
												cout << "Inspection";
												cout << setw(15) << fixed;
												cout << "Capacity";
												cout << setw(15) << fixed;
												cout << "Status";
												cout << setw(15) << fixed;
												cout << "Power";
												cout << setw(15) << fixed;
												cout << "Motor Type";
												cout << endl;

												cout <<getID();
												cout << setw(23) << fixed;
												cout << getManu();
												cout << setw(8) << fixed;
												cout << getServ();
												cout << setw(13) << fixed;
												cout << getIn();
												cout << setw(15) << fixed;
												cout << getCap();
												cout << setw(15) << fixed;
												cout << getStat();
												cout << setw(15) << fixed;

						cout <<powerOn;
						cout << setw(15) << fixed;
						cout << motor;

						cout << endl;
						cout << "_______________________________________________________________________________________________________________";
																											cout << endl;
		}
		// bool virtual function that checks if vehicle requires maintenance
		bool Railcar::checkMe()
		{
			bool status = false;
			if (this->powerOn >= 100)
			{
				status = true;
			}
			return status;
		}
		// displaying a helicopter object derived from base class vehicle
		void Helicopter::display()
		{
			cout << "______________________________________________________________________________________________________________________________________";
																		cout << endl;


									cout << "ID Number";
									cout << setw(15) << fixed;
									cout << "Manufacturer";
									cout << setw(10);
									cout << "Service";
									cout << setw(15) << fixed;
									cout << "Inspection";
									cout << setw(15) << fixed;
									cout << "Capacity";
									cout << setw(15) << fixed;
									cout << "Status";
									cout << setw(15) << fixed;
									cout << "AirTime";
									cout << setw(15) << fixed;
									cout << "Engine time";
									cout << endl;

									cout <<getID();
									cout << setw(23) << fixed;
									cout << getManu();
									cout << setw(8) << fixed;
									cout << getServ();
									cout << setw(13) << fixed;
									cout << getIn();
									cout << setw(15) << fixed;
									cout << getCap();
									cout << setw(15) << fixed;
									cout << getStat();
									cout << setw(15) << fixed;
			cout <<flightTime;
			cout << setw(10) << fixed;
			cout << engineTime<< " ";

			cout << endl;
			cout << "_______________________________________________________________________________________________________________";
																								cout << endl;
		}
		// bool virtual function that checks if vehicle requires maintenance
		bool Helicopter::checkMe()
		{
			bool status = false;
			if (this->flightTime >= 1000 || this->engineTime >= 750)
			{
				status = true;
			}
			return status;
		}
