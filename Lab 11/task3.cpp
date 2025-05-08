#include <iostream>
#include <exception>

using namespace std;

class InvalidTemperatureException : public exception {};

class TemperatureConverter {
public:
    template <typename T>
    static T convertToFahrenheit(T celsius) {
        if (celsius < -273.15) {
            throw InvalidTemperatureException();
        }
        return (celsius * 9.0 / 5.0) + 32.0;
    }
};

int main() {
    try {
        double tempCelsius = -300;
        cout << "Attempting to convert " << tempCelsius << "C..." << endl;
        double tempFahrenheit = TemperatureConverter::convertToFahrenheit(tempCelsius);
        cout << tempCelsius << "C is " << tempFahrenheit << "F" << endl;
    } catch (const InvalidTemperatureException& e) {
        cout << "Caught InvalidTemperatureException\nwhat(): " << e.what() << endl;
    }

    return 0;
}
