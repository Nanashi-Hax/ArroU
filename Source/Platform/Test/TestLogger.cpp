#include "Platform/Test/TestLogger.hpp"
#include <iostream>

TestLogger::TestLogger()
{

}

void TestLogger::log(std::string msg)
{
    std::cout << msg << std::endl;
}