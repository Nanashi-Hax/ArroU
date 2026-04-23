#include "Platform/Test/TestLogger.hpp"
#include <iostream>

void TestLogger::log(std::string msg)
{
    std::cout << msg << std::endl;
}