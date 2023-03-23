#pragma once
#include "MyUsart.hpp"
#define MAX_BAUD_RATE 115200

class MockUsart : public MyUsart
{
private:
    int pinRX = 9;
    int pinTX = 10;
    int baudRate = 9600;
    bool setBaudRate(int baudRate);
    bool setPins(int rx, int tx);
public:
    MockUsart();
    ~MockUsart();
    bool begin();
    bool begin(int baudRate);
    bool begin(int rx, int tx);
    bool begin(int rx, int tx, int baudRate);
    int dumpImplementation() const override;
};
