#include<iostream>
#include<string>

using namespace std;

class SmartDevice{
    protected:
    string deviceName;
    bool isOnline;
    public:
    SmartDevice(string name, bool status): deviceName(name),isOnline(status){}
    virtual void peformfunction() const{
        if(isOnline){
            cout << deviceName << " is online and performing its function." << endl;
        } else{
            cout << deviceName << " is offline." << endl;
    }
}

virtual void display(){
    cout << "Device Name: " << deviceName << endl;
    cout << "Status: " << (isOnline ? "Online" : "Offline") << endl;
}
virtual ~SmartDevice(){};
};

class SmartLight : public SmartDevice{
    protected:
    int brightnessLevel;
    public:
    SmartLight(string name, bool status, int level): SmartDevice(name, status), brightnessLevel(level) {}
    virtual void performfunction() const{
        if(isOnline){
            cout << deviceName << " is online and performing its function." << endl;
        }
    }
    virtual void display(){
        SmartDevice::display();
        cout << "Brightness Level: " << brightnessLevel << endl;
    }
    virtual ~SmartLight(){}

};

class SmartThermostat : public SmartLight{
    protected:
    float temperature;
    public:
    SmartThermostat(string name, bool status, int level, float temp): SmartLight(name, status, level), temperature(temp) {}
    virtual void performfunction() const{
        if(isOnline){
            cout << deviceName << " is online and performing its function." << endl;
            }
        }
        virtual void display(){
            SmartLight::display();
            cout << "Temperature: " << temperature << endl;
        }
        virtual ~SmartThermostat(){};
    };



class SmartSpeaker : public SmartDevice{
    protected:
    string currentPlaying;
    public:
    SmartSpeaker(string name, bool status, string playing): SmartDevice(name, status), currentPlaying(playing){}
    virtual void performfunction() const{
        if(isOnline){
            cout << deviceName << " is online and performing its function." << endl;
            }
            }
            virtual void display(){
                SmartDevice::display();
                cout << "Current Playing: " << currentPlaying << endl;
            }
        virtual ~SmartSpeaker(){};
        };

int main(){
    SmartLight light("Light", true, 50);
    SmartThermostat thermostat("Thermostat", true, 70, 22.5);
        SmartSpeaker speaker("Speaker", true, "Music");
        light.display();
        thermostat.display();
        speaker.display();
        return 0;

}        