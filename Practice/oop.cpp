#include <iostream>
#include <string>

using namespace std;

class Device {
protected:
    string deviceID;
    string location;
public:
    Device(string deviceID, string location) : deviceID(deviceID), location(location) {}
    
    virtual void statusReport() const {
        cout << "Device ID: " << deviceID << endl;
        cout << "Location: " << location << endl;
    }

    virtual ~Device() {}
};

class Sensor : virtual public Device {
private:
    float batteryLevel;
    bool isActive;
public:
    Sensor(string deviceID, string location, float batteryLevel, bool isActive)
        : Device(deviceID, location), batteryLevel(batteryLevel), isActive(isActive) {}

    void setActiveStatus() {
        isActive = true;
    }

    bool getActiveStatus() const {
        return isActive;
    }

    float getBatteryLevel() const {
        return batteryLevel;
    }

    void statusReport() const override {
        Device::statusReport();
        cout << "Battery Level: " << batteryLevel << "%" << endl;
        cout << "Active: " << (isActive ? "Yes" : "No") << endl;
    }
};

class Controller : virtual public Device {
private:
    bool networkStatus;
public:
    Controller(string deviceID, string location, bool networkStatus)
        : Device(deviceID, location), networkStatus(networkStatus) {}

    virtual void resetStatus() {
        networkStatus = false;
    }

    bool getNetworkStatus() const {
        return networkStatus;
    }

    void statusReport() const override {
        Device::statusReport();
        cout << "Network Status: " << (networkStatus ? "Connected" : "Disconnected") << endl;
    }

    virtual ~Controller() {}
};

class Thermostat : public Sensor, public Controller {
private:
    float temperature;
public:
    Thermostat(string deviceID, string location, float batteryLevel, bool isActive, float temperature)
        : 
        Device(deviceID, location),
        Sensor(deviceID, location, batteryLevel, isActive), 
          Controller(deviceID, location, true), 
          temperature(temperature) {}

    void statusReport() const override {
        Device::statusReport();
        cout << "Battery Level: " << getBatteryLevel() << "%" << endl;
        cout << "Active: " << (getActiveStatus() ? "Yes" : "No") << endl;
        cout << "Network Status: " << (getNetworkStatus() ? "Connected" : "Disconnected") << endl;
        cout << "Temperature: " << temperature << "°C" << endl;
    }

    ~Thermostat() {}
};

int main() {
    Thermostat thermostat("T001", "Living Room", 80.5, true, 22.5);
    thermostat.statusReport();

    return 0;
}
