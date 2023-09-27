#include "devicemouse.h"

DeviceMouse::DeviceMouse()
{

}

void DeviceMouse::setPrimaryButton()
{
    cout << "Anna Mouse Primary Button arvo \n";
    cin >> primaryButton;

}

short DeviceMouse::getPrimaryButton()
{
    return primaryButton;
}
