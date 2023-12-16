#ifndef UTF8_WINDOWS
#define UTF8_WINDOWS

#include <iostream>
#include <cstdlib>
#include <windows.h>

// Lähde: https://stackoverflow.com/a/45622802
void localeFinnish()
{
    // Set console code page to UTF-8 so console known how to interpret string data
    SetConsoleOutputCP(CP_UTF8);

    // Enable buffering to prevent VS from chopping up UTF-8 byte sequences
    setvbuf(stdout, nullptr, _IOFBF, 1000);
}

#endif
