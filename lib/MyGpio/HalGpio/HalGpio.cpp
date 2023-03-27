#include "HalGpio.hpp"
HalGpio::HalGpio(/* args */)
{
}

void HalGpio::setPinAsInput(uint8_t pin)
{
    setPin(pin); // ! redudante
    setMode(0);  // set as input
}

void HalGpio::setMode(bool input)
{
    if (input)
    {
        this->pinMode = GPIO_MODE_INPUT;
    }
    else
    {
        this->pinMode = GPIO_MODE_OUTPUT_PP;
    }
}

int HalGpio::setPin(uint8_t pin)
{
    uint16_t hexaPin;
    hexaPin = (uint16_t)1 << pin;
    this->pinSet = hexaPin;
    return this->pinSet;
}

int HalGpio::getPin()
{
    return this->pinSet;
}
int HalGpio::getMode()
{
    return this->pinMode;
}

HalGpio::~HalGpio()
{
}
