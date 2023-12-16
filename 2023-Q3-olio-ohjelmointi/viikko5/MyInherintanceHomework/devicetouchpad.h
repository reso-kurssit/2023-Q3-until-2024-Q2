#ifndef DEVICETOUCHPAD_H
#define DEVICETOUCHPAD_H
#include "devicebaseclass.h"

class DeviceTouchPad: public DeviceBaseClass
{
public:
    DeviceTouchPad();
    void setTouchPadSensitivity();
    short getTouchPadSensitivity();
    string getTouchPadSensitivityAsText();
private:
    short touchPadSensitivity;
    string supportedSensitivities[5];
};

#endif // DEVICETOUCHPAD_H
