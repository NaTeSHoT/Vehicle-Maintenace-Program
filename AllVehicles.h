/*
 * AllVehicles.h
 *
 *  Created on: Nov 9, 2019
 *      Author: Nathaniel Lee
 */

#ifndef ALLVEHICLES_H_
#define ALLVEHICLES_H_

#include <string>
using namespace std;
// Base class called Vehicle
class Vehicle
{
// private members that hold vehicle attributes
private:
	string vehicleID;
	string manufacturer;
	string service;
	string inspection;
	int capacity;
	char status;

// public member that give access to private members
public:

	// constructor
	Vehicle(string vID, string manu, string serv, string in, int cap, char stat);

	// getters
	string getID();
	string getManu();
	string getServ();
	string getIn();
	int getCap();
	char getStat();

	// on setter for part 2
	void setStat(char);

	// virtual functions that allow access to derived class variables
	virtual int getPower()
	{
		return 0;
	}
	virtual string getMotor(){
		return "";
	}
	virtual int getFlight()
	{
		return 0;
	}
	virtual int getEngine()
	{
		return 0;
	}
	virtual int getMile()
	{
		return 0;
	}
	virtual string getTire()
	{
		return "";
	}
	virtual char getFuel()
	{
		return 'A';
	}
	// virtual destructor needed, but does not need to do anything
	~Vehicle();
	// two required virtual functions as instructed
	virtual bool checkMe();
	virtual void display();

};

// Bus class is a derived class from base Vehicle class
class Bus : public Vehicle
{
private:
	int mileage;
	string tireSize;
	char fuel;
public:
	Bus(string vID, string manu, string serv, string in, int cap, char stat, int x, string y, char z):Vehicle(vID, manu, serv, in,  cap, stat)
		{
				mileage = x;
				tireSize = y;
				fuel = z;

		}
	int getMile();
	string getTire();
	char getFuel();
	//  virtual functions derived from base class
	void display();
	bool checkMe();
	// virtual destructor
	~Bus();
};
// Helicopter class is a derived class from base Vehicle class
class Helicopter : public Vehicle
{
private:
	int flightTime;
	int engineTime;
public:
	// constructor also calls base constructor by default
	Helicopter(string vID, string manu, string serv, string in, int cap, char stat,int x, int y):Vehicle(vID, manu, serv, in,  cap, stat)
	{
		flightTime = x;
		engineTime = y;

	}
	int getFlight();
	int getEngine();
	// two virtual functions derived from base class
	void display();
	bool checkMe();
	~Helicopter();
};
// Railcar class is a derived class of base Vehicle class
class Railcar : public Vehicle
{
private:
	int powerOn;
	string motor;
public:
	// constructor that calls base constructor also
	Railcar(string vID, string manu, string serv, string in, int cap, char stat,int x, string y) : Vehicle(vID, manu, serv, in,  cap, stat)
	{

		powerOn = x;
		motor = y;

	}
	int getPower();
	string getMotor();
	// virtual functions derived from base class
	void display();
	bool checkMe();
	~Railcar();
};


#endif /* ALLVEHICLES_H_ */
