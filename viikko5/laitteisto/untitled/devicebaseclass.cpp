#include "devicebaseclass.h"

DeviceBaseClass::DeviceBaseClass()
{

}

void DeviceBaseClass::setDeviceID()
{
    cout << "Anna Device ID \n";
    cin >> deviceID;

}

short DeviceBaseClass::getDeviceID()
{
    return deviceID;
}
