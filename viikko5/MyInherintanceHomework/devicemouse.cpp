#include "devicemouse.h"

DeviceMouse::DeviceMouse()
{
    primaryButton = -1;
}

void DeviceMouse::setPrimaryButton()
{
    do {
        cout << "1 = Left mouse button \n";
        cout << "2 = Right mouse button \n";
        cin >> primaryButton;
    } while (primaryButton < 1 || primaryButton > 2);
}

short DeviceMouse::getPrimaryButton()
{
    return primaryButton;
}

string DeviceMouse::getPrimaryButtonAsText()
{
    if (primaryButton == 1)
    {
        return "Left mouse button";
    }
    else
    {
        return "Right mouse button";
    }
}
