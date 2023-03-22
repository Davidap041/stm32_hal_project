#include "MyGpio.hpp"
MyGpio::MyGpio(/* args */)
{
    this->dump = true;
}

bool MyGpio::dumpTrue()
{
    this->dump = true;
    return this->dump;
}

bool MyGpio::dumpFalse()
{
    this->dump = false;
    return this->dump;
}
bool MyGpio::dumpStatus(){
    return this->dump;
}
MyGpio::~MyGpio()
{
}
