#include "mydeviceui.h"

MyDeviceUI::MyDeviceUI()
{
    pDeviceMouse = new DeviceMouse;


}

MyDeviceUI::~MyDeviceUI()
{
    delete pDeviceMouse;
    pDeviceMouse = nullptr;

}

void MyDeviceUI::uiShowMenu()
{
    cout << "Devimenu \n";
    cout << "------- \n";
    cout << "1 = Set Mouse Information \n";
    cout << "Choose: \n";
    cin >> valinta;

    cout << "You chose " << valinta ;


}
