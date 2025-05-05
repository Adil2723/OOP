#include<iostream>
#include<string>

using namespace std;

class Vehicle{
	public:
		string model;
		int year;
	
	Vehicle(string m, int y) : model(m), year(y){
	}	
	virtual void displayInfo(){
		cout << "Model : " << model << endl;
		cout << "Year : " << year << endl;
	}
};

class Car : public Vehicle {
	public:
		int numDoor;
		
	Car(string m, int y,int d) : Vehicle(m, y), numDoor(d){
	}	
	
	virtual void displayInfo() override{
		Vehicle::displayInfo();
		cout << "Number of Door: " <<  numDoor << endl;
	}
};

class Truck : public Vehicle {
	public:
		double payloadcapacity;
	
	Truck(string m, int y,double c) : Vehicle(m, y), payloadcapacity(c){
	}
	virtual void displayInfo() override{
		Vehicle::displayInfo();
		cout << "NPayload Capacity: " <<  payloadcapacity << endl;
	}
};

int main(){
	Car c1("Sedan", 2005, 4);
	c1.displayInfo();
	
	Truck t1("Pickup", 2009, 1000.98);
	t1.displayInfo();
	
	}
	
	
