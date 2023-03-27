#include <MyGpio.hpp>
#include <stm32f1xx_hal.h>
class HalGpio : public MyGpio
{
private:
    /* data */
    int pinSet = 0;
    int pinMode;
    void setMode(bool input);

public:
    HalGpio(/* args */);
    void setPinAsInput(uint8_t pin) override;
    int setPin(uint8_t pin);
    int getPin();
    int getMode();
    ~HalGpio();
};
