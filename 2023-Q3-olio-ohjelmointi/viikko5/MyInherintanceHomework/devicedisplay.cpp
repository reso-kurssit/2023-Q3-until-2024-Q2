#include "devicedisplay.h"


DeviceDisplay::DeviceDisplay()
{
    displayResolution = -1;
    supportedResolutions[0] = "640x480";
    supportedResolutions[1] = "800x600";
    supportedResolutions[2] = "960x720";
    supportedResolutions[3] = "1024x768";
    supportedResolutions[4] = "1280x960";
    supportedResolutions[5] = "1400x1050";
    supportedResolutions[6] = "1440x1080";
    supportedResolutions[7] = "1600x1200";
    supportedResolutions[8] = "1856x1392";
    supportedResolutions[9] = "1920x1440";
}

void DeviceDisplay::setDisplayResolution()
{
    do {
        for (int i=0; i < 10; i++)
        {
            cout << i+1 << " = " << supportedResolutions[i] << endl;
        }
        cin >> displayResolution;
    } while (displayResolution < 1 || displayResolution > 10);
}

short DeviceDisplay::getDisplayResolution()
{
    return displayResolution;
}

string DeviceDisplay::getDisplayResolutionAsText()
{
    return supportedResolutions[displayResolution-1];
}
