#include<iostream>

using namespace std;

class MyClass {
private:
    int* data;

public:
    MyClass(int value) {
        data = new int(value);  // Dynamically allocate memory
        cout << "Constructor: Data allocated with value " << *data << endl;
    }

    ~MyClass() {
        delete data;  // Free the dynamically allocated memory
        cout << "Destructor: Data deallocated." << endl;
    }

    // Deep copy constructor
    MyClass(const MyClass& obj) {
        data = new int(*obj.data);  // Deep copy: allocate new memory and copy value
        cout << "Deep Copy Constructor: Data copied." << endl;
    }

    void display() const {
        cout << "Data: " << *data << endl;  // Display the value pointed by data
    }

    void changevalue(int value){
        *data = value;
    }
};

int main() {
    MyClass original(100);  // Create the original object

    MyClass shallowCopy = original;  // Create a copy (now deep copy)

    original.display();  // Display data of the original object
    shallowCopy.display();  // Display data of the shallow copy

    cout << "\nModifying shallowCopy's data to 200..." << endl;
    shallowCopy.changevalue(200);

    cout << "After modification:" << endl;
    original.display();
    shallowCopy.display();

    return 0;
}
