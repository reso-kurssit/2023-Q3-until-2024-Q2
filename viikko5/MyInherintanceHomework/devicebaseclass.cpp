#include "devicebaseclass.h"

DeviceBaseClass::DeviceBaseClass()
{
    deviceID = -1;
}

void DeviceBaseClass::setDeviceID()
{
    cin >> deviceID;
}

short DeviceBaseClass::getDeviceID()
{
    return deviceID;
}
