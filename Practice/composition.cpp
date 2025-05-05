#include<iostream>
#include<string>
using namespace std;

class Engine {
private:
    int horsepower;
    string type;
public:
    Engine(int horsepower, string type) {
        this->horsepower = horsepower;
        this->type = type;
    }

    void display() {
        cout << "Horsepower: " << horsepower << endl;
        cout << "Type: " << type << endl;
    }
};

class Car {
private:
    string brand;
    string model;
    Engine engine;
public:
    Car(string brand, string model, int horsepower, string type)
        : brand(brand), model(model), engine(horsepower, type) {}

    void display() {
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        engine.display();
    }
};

int main() {
    Car car("Toyota", "Camry", 300, "V6");
    car.display();
    return 0;
   
}
