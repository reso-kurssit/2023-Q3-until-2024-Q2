#ifndef DEVICEDISPLAY_H
#define DEVICEDISPLAY_H
#include "devicebaseclass.h"

class DeviceDisplay: public DeviceBaseClass
{
public:
    DeviceDisplay();
    void setDisplayResolution();
    short getDisplayResolution();
    string getDisplayResolutionAsText();
private:
    short displayResolution;
    string supportedResolutions[10];
};

#endif // DEVICEDISPLAY_H
