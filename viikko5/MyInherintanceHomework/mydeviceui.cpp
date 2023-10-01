#include "mydeviceui.h"

MyDeviceUI::MyDeviceUI()
{
    pMouse = new DeviceMouse;
    pTouchPad = new DeviceTouchPad;
    pDisplay = new DeviceDisplay;
}

MyDeviceUI::~MyDeviceUI()
{
    delete pMouse;
    pMouse = nullptr;

    delete pTouchPad;
    pTouchPad = nullptr;
}

void MyDeviceUI::uiShowMenu()
{
    int choice;
    bool finished = false;
    do {

        cout << "DEVICE MENU\n";
        cout << "============================ \n";
        cout << "1 = Set Mouse Information \n";
        cout << "2 = Set Touch Pad Information \n";
        cout << "3 = Set Display Information \n";
        cout << "4 = Show Devices Information \n";
        cout << "5 = Finish \n";
        cout << "============================ \n";
        cin >> choice;
        cout << "============================ \n";
        //cout << "You chose " << choice ;

        switch(choice)
        {
            case 1:
                uiSetMouseInformation();
                break;
            case 2:
                uiSetTouchPadInformation();
                break;
            case 3:
                uiSetDisplayInformation();
                break;
            case 4:
                uiShowDeviceInformation();
                break;
            case 5:
                finished = true;
                break;
        }
    } while (!finished);
}

void MyDeviceUI::uiSetMouseInformation()
{
    cout << "SET MOUSE INFORMATION \n";
    cout << "============================ \n";
    cout << "Set Mouce Device ID: \n";
    pMouse->setDeviceID();
    cout << "Set Mouse Primary Button: \n";
    pMouse->setPrimaryButton();
    cout << "============================ \n";
}

void MyDeviceUI::uiSetTouchPadInformation()
{
    cout << "SET TOUCH PAD INFORMATION \n";
    cout << "============================ \n";
    cout << "Set Touch Pad ID: \n";
    pTouchPad->setDeviceID();
    cout << "Set Touch Pad Sensitivity: \n";
    pTouchPad->setTouchPadSensitivity();
    cout << "============================ \n";
}

void MyDeviceUI::uiSetDisplayInformation()
{
    cout << "SET DISPLAY INFORMATION \n" ;
    cout << "============================ \n";
    cout << "Set Display ID: \n";
    pDisplay->setDeviceID();
    cout << "Set Display Resolution: \n";
    pDisplay->setDisplayResolution();
    cout << "============================ \n";
}

void MyDeviceUI::uiShowDeviceInformation()
{
    cout << "MOUSE \n" ;
    if (pMouse->getPrimaryButton() == -1)
    {
        cout << "Undefined ID. Please define your device settings. \n";
    } else {
        cout << "ID: " << pMouse->getDeviceID() << endl;
        cout << "Primary Button: " << pMouse->getPrimaryButtonAsText() << endl;
    }
    cout << "TOUCH PAD \n" ;
    if (pTouchPad->getTouchPadSensitivity() == -1)
    {
        cout << "Undefined ID. Please define your device settings. \n";
    } else {
        cout << "ID: " << pTouchPad->getDeviceID() << endl;
        cout << "Sensitivity: " <<pTouchPad->getTouchPadSensitivityAsText() << endl;
    }
    cout << "DISPLAY \n" ;
    if (pDisplay->getDisplayResolution() == -1)
    {
        cout << "Undefined ID. Please define your device settings. \n";
    } else {
        cout << "ID: " <<pDisplay->getDeviceID() << endl;
        cout << "Resolution: " <<pDisplay->getDisplayResolutionAsText() << endl;
    }
    cout << "============================ \n";
}

