#include<iostream>
#include<string>

using namespace std;

class Car{
    string brand;
    string model;
    float rental_price;
    bool availability;
public:
    Car(){
        brand = "Unknown";
        model = "Generic";
        rental_price = 0.0;
        availability = true;
    }
    
}