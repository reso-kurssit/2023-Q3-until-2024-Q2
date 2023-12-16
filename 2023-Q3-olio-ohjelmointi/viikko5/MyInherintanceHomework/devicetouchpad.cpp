#include "devicetouchpad.h"

DeviceTouchPad::DeviceTouchPad()
{
    touchPadSensitivity = -1;
    supportedSensitivities[0] = "100% sensitivity";
    supportedSensitivities[1] = "80% sensitivity";
    supportedSensitivities[2] = "60% sensitivity";
    supportedSensitivities[3] = "40% sensitivity";
    supportedSensitivities[4] = "20% sensitivity";
}

void DeviceTouchPad::setTouchPadSensitivity()
{
    do {
        for (int i=0; i < 5; i++)
        {
            cout << i+1 << " = " << supportedSensitivities[i] << endl;
        }
        cin >> touchPadSensitivity;
    } while (touchPadSensitivity < 1 || touchPadSensitivity > 5);
}

short DeviceTouchPad::getTouchPadSensitivity()
{
    return touchPadSensitivity;
}

string DeviceTouchPad::getTouchPadSensitivityAsText()
{
    return supportedSensitivities[touchPadSensitivity-1];
}


