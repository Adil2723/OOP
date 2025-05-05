#include<iostream>
#include<string>

using namespace std;

class Animal {
public:
    string name;

    Animal(string n) : name(n) {}

    virtual void makeSound() {
        cout << "The animal makes a sound...." << endl;
    }

    virtual ~Animal() {}
};

class Mammal : public Animal {
public:
    bool isWarmBlooded;

    Mammal(string n, bool warmBlooded) : Animal(n), isWarmBlooded(warmBlooded) {}

    virtual void makeSound() override {
        cout << "The mammal makes a sound." << endl;
    }
};

class Dog : public Mammal {
public:
    string breed;

    Dog(string n, bool warmBlooded, string b) : Mammal(n, warmBlooded), breed(b) {}

    void makeSound() override {
        cout << "The dog barks." << endl;
    }
};

int main() {
    Dog dog("Hook", true, "German Shepherd");
    dog.makeSound();
    cout << "Is the dog warm-blooded? " << (dog.isWarmBlooded ? "Yes" : "No") << endl;
    cout << "Breed: " << dog.breed << endl;

    return 0;
}
