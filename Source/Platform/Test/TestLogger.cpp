#include "Platform/Test/TestLogger.hpp"
#include <iostream>
#include <windows.h>

void TestLogger::info(std::string msg)
{
    std::cout << msg << std::endl;
}

void TestLogger::error(std::string msg)
{
    HANDLE h = GetStdHandle(STD_ERROR_HANDLE);
    SetConsoleTextAttribute(h, FOREGROUND_RED);

    std::cerr << msg << std::endl;

    SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}