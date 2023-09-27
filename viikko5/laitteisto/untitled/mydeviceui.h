#ifndef MYDEVICEUI_H
#define MYDEVICEUI_H
#include "devicemouse.h"


class MyDeviceUI
{
public:
    MyDeviceUI();
    ~MyDeviceUI();

    void uiShowMenu();


private:
    DeviceMouse * pDeviceMouse;

};

#endif // MYDEVICEUI_H
