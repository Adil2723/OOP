#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class Shape {
public:
    string name;

    Shape(string n) : name(n) {}

    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    
    virtual void display() const {
        cout << "Shape: " << name << endl;
        cout << "Area: " << area() << endl;
        cout << "Perimeter: " << perimeter() << endl;
    }

    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : Shape("Circle"), radius(r) {}

    double area() const override {
        return M_PI * radius * radius;
    }

    double perimeter() const override {
        return 2 * M_PI * radius;
    }

    bool operator==(const Circle& other) const {
        return radius == other.radius;
    }

    void resize(double factor) {
        if (factor > 0) {
            radius *= factor;
        } else {
            cout << "Resize factor must be greater than 0!" << endl;
        }
    }

    void display() const override {
        Shape::display();
        cout << "Radius: " << radius << endl;
    }
};

int main() {
    Circle circle1(5.0);
    Circle circle2(5.0);
    Circle circle3(10.0);

    cout << "Details of Circle 1:" << endl;
    circle1.display();
    
    cout << "\nResizing Circle 1 by a factor of 2:" << endl;
    circle1.resize(2);
    circle1.display();

    cout << "\nComparing Circle 1 and Circle 2:" << endl;
    if (circle1 == circle2) {
        cout << "Circle 1 and Circle 2 are the same!" << endl;
    } else {
        cout << "Circle 1 and Circle 2 are different!" << endl;
    }

    cout << "\nComparing Circle 1 and Circle 3:" << endl;
    if (circle1 == circle3) {
        cout << "Circle 1 and Circle 3 are the same!" << endl;
    } else {
        cout << "Circle 1 and Circle 3 are different!" << endl;
    }

    return 0;
}
