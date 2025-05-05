#include <iostream>
#include <string>
using namespace std;

class Apartment {
private:
    int ID;
    string address;
    string* ownername;

public:
    // Constructor
    Apartment(int id, string address, const string& ownername) {
        ID = id;
        this->address = address;
        this->ownername = new string(ownername); // dynamic memory
    }

    // Shallow copy (ownership is shared)
    Apartment(const Apartment& other) {
        ID = other.ID;
        address = other.address;
        ownername = other.ownername; // shared pointer
    }

    // Destructor
    ~Apartment() {
        delete ownername;
    }

    string* getOwnerName() {
        return ownername;
    }

    void display() {
        cout << "ID: " << ID << endl;
        cout << "Address: " << address << endl;
        cout << "Owner Name: " << *ownername << endl; // dereference to print actual name
    }
};

int main() {
    Apartment a1(1, "123 Main St", "Adil");
    Apartment a2 = a1;  // shallow copy

    cout << "Original apartment (a1):" << endl;
    a1.display();

    // Change owner name via a2
    *a2.getOwnerName() = "Adil Saeed";

    cout << "\nAfter ownership transfer via a2:" << endl;
    cout << "" << endl;
    a1.display();


    return 0;
}
